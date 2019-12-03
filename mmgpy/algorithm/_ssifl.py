import numpy as np
from math import ceil
from sklearn.base import TransformerMixin
from sklearn.model_selection import train_test_split

from mmgpy.utils import DynamicLogger
from mmgpy.utils import PACCEvaluationLog
from formatting import print_pacc_header
from formatting import print_pacc_iteration

from sampling import InterpolatedMarginalInverseECDF
from sampling import null_mapping
from sampling import s_pacc
from sampling import s_idx_diego
from sampling import s_num_diego
from sampling import cvt
from sampling import random_uniform
from sampling import halton
from sampling import uniform_grid
from sampling import full_factorial


class BaseIncrementalFunctionLearning:

    @staticmethod
    def _not_implemented():
        NotImplementedError("Not implemented in base class.")

    @staticmethod
    def pacc_evaluate(f, f_s, epsilon, delta, with_error_array=False,
                      score_return=False):
        """

        Parameters
        ----------
        f : ndarray, shape (samples,)
            Actual function evaluations of input x.
        f_s : ndarray, shape (samples,)
            Surrogate function evaluations of input x.
        epsilon : float
            Desired accuracy level [0.0, 1.0)
        delta : float
            Desired confidence (1 - delta) level (0.0, 1.0].
        with_error_array : bool, optional
            Determines whether the arrays of abs_error and rel_error are
            returned within the evaluation log.
            Default = False
        score_return : bool, optional

        References
        ----------

        Returns
        -------
        evaluation_log : namedtuple (PACCEvaluationLog)


        """

        assert len(f) == len(f_s)
        _n_samples = len(f)
        _abs_error = np.abs(f - f_s)
        _rel_error = _abs_error / (np.max(f) - np.min(f))
        _n_passing = len(_abs_error[_abs_error <= epsilon])
        _statistic = _n_passing / _n_samples
        _terminate = _statistic >= 1.0 - delta

        if score_return:
            return (1.0 - delta) - _statistic
        elif with_error_array:
            return (PACCEvaluationLog(
                n_samples=_n_samples,
                n_passing=_n_passing,
                statistic=_statistic,
                terminate=_terminate), _rel_error)

        else:
            return PACCEvaluationLog(
                n_samples=_n_samples,
                n_passing=_n_passing,
                statistic=_statistic,
                terminate=_terminate)

    @staticmethod
    def concat_data(d1, d2):
        r"""
        Function to concatenate data format unique to this class.

        Parameters
        ----------
        d1 : tuple of ndarray, size TODO: Size of d1.
            Existing or `first in order` data.
        d2 : tuple of ndarray, size TODO: Size of d2.
            Additional or `second in order` data.

        Returns
        -------
        concatenated_data : tuple of ndarray, size TODO: Size of return.

        """
        return np.vstack((d1[0], d2[0])), np.concatenate((d1[1], d2[1]))

    def __init__(self, func, x_dim, meta_model, sample_num=s_num_diego,
                 sample_idx=s_idx_diego, scaler=None, test_frac=0.2, seed=1,
                 logging=0):
        """
        Parameters
        ----------
        func : function
            Lebesge function to be learning by surrogate model.
        x_dim : int
            Number of input dimensions for the function to be learned
            within the domain of [0,1] for each parameter.
        meta_model :
        sample_num : function, optional
            The sampling sequence in the form of a callable where n is
            the input domain dimension to be sampled from and index
            is the sampling level according to the scheme
            (Default is s_num_diego).
        sample_idx : function, optional
            The function that returns the index of sampling to be used
            of a sampling scheme given a required minimum number of
            samples.
        scaler : TransformerMixin
        logging: {0, 1, 2}, optional
            Determines the level of logging after each iteration.
                - 1 : Minimum required for evaluation
                - 2 : Maximum logging.
                    - Sampled data indices are stored w.r.t. each
                      iteration.
                    - Predictive model is stored for each iteration.
            (Default is 0).

        See Also
        --------
        s_num_diego :
            Sampling sequence used in Diego G. Loyola R et al. [1]_
        s_idx_diego :
            Index of sampling used in Diego G. Loyola R et al. [1]_

        References
        ----------
        ..  [1] Loyola R, D. G., Pedergnana, M., & Gimeno García, S.
            (2016). Smart sampling and incremental function learning
            for very large high dimensional data. Neural Networks, 78,
            75–87. https://doi.org/10.1016/j.neunet.2015.09.001
        """
        self._iteration = 0
        self._logging = logging
        self._scaler = scaler
        self._x_dim = x_dim
        self._log = DynamicLogger(equal_logging=True)
        self._test_frac = test_frac
        self._seed = seed
        self._training_data = None
        self._validation_data = None
        self._meta_model = meta_model
        self._terminate = False

        self.func = func
        self.sample_idx = sample_idx
        self.sample_num = sample_num

    @property
    def meta_model(self):
        return self._meta_model

    @property
    def x_dim(self):
        """

        Returns
        -------
        x_dim : int
            Dimension of the design vector.
        """
        return self._x_dim

    @property
    def scaler(self):
        """

        Returns
        -------
        scaler : TransformerMixin
            Scaler for outputs of function.
        """
        return self._scaler

    def __iter__(self):
        self.n = 0
        return self

    def __len__(self):
        return len(self._log)

    def __next__(self):
        if self.terminate:
            # Iterate terminated algorithm logs.
            if self.n < len(self._log):
                _iter = self._log[self.n]
                self.n += 1
                return _iter
            else:
                raise StopIteration

        elif not self.terminate:
            # Iterate learned iterations.
            if self.n < self._iteration:
                _iter = self._log[self.n]
                self.n += 1
                return _iter
            # Requested index has not been learned.
            elif self.n >= self._iteration:
                self.iterate()
                _iter = self._log[-1]
                self.n += 1
                return _iter

    def sample(self, n, sampling, seed=None, mapping=null_mapping,
               tdmq=False, verbose=False, **kwargs):
        """
        Method to encapsulate sampling methods for incremental
        function learning purposes.

        Parameters
        ----------
        n : list of int or int
            Argument determining number of arguments. Varies depending
            on the sampling method used.
            - Represents integer number of samples for {'cvt',
            'random_uniform', 'halton'}.
            - Represents integer value to sampled for each dimension
            for 'uniform_grid' sampling.
            - Represents list of integer values for 'full_factorial'
            sampling.
        sampling : str
            Sampling method to be used. Available are 'cvt',
            'random_uniform', 'halton', 'uniform_grid' and
            'full_factorial'.
        seed : int
            Seed to be used for algorithms which are pseudo-random.
        mapping : function
            Mapping function for non-uniform sampling. Currently only
            supports non-uniform distribution sampling through mapping
            uniform sampling of the inverse empirical cumulative
            distribution function (Default is null_mapping).
        tdmq : bool, optional
            Progress bar in jupyter lab environment (default = False).
        verbose : int or bool, optional
            Sets verbosity of iterations of algorithm. True for each
            iteration to be printed, integer value for frequency of
            iterations to be printed.
        **kwargs
            Additional arguments that are to replace default
            arguments of the sampling methods.

        See Also
        --------
        tdmq : https://pypi.org/project/tqdm/

        Returns
        -------
        x_sample : ndarray, size (n_samples, self.x_dim)
            Sampled design of experiments array.
        """
        kwargs['tdmq'] = tdmq
        kwargs['verbose'] = verbose
        bounds = np.array([[0.] * self.x_dim, [1.] * self.x_dim])

        if sampling is "cvt":
            return mapping(cvt(self.x_dim, n, seed=seed, **kwargs))

        elif sampling is "random_uniform":
            return mapping(random_uniform(bounds, n, seed=seed, **kwargs))

        elif sampling is "halton":
            return mapping(halton(bounds, n, **kwargs))

        elif sampling is "uniform_grid":
            return mapping(uniform_grid(bounds, n, **kwargs))

        elif sampling is "full_factorial":
            return mapping(full_factorial(bounds, n, **kwargs))

        else:
            raise NameError(f"""
            sampling="{sampling}" is not valid. Accepted are:
            - cvt
            - halton
            - random_uniform
            - uniform_grid
            - full_factorial
            See documentation for details.
            """)

    @property
    def terminate(self):
        """
        Signals completion of algorithm.

        Returns
        -------
        terminate : bool
            Returns the termination signal when the learning has
            stagnated or achieved the required accuracy and
            confidence.

        """
        return self._terminate

    def iterate(self, tdmq=False, verbose=False):
        """
        Carries out next iteration of algorithm.

        Parameters
        ----------
        tdmq : bool, optional
            Progress bar in jupyter lab environment (default = False).
        verbose : int or bool, optional
            Sets verbosity of iterations of algorithm. True for each
            iteration to be printed, integer value for frequency of
            iterations to be printed.

        Returns
        -------

        """
        self._not_implemented()


# class BaseSSIFL(BaseIncrementalFunctionLearning):
#
#     def __init__(self):


class SSIFL(BaseIncrementalFunctionLearning):

    def __init__(self, func, x_dim, meta_model, delta, epsilon,
                 sample_num=s_num_diego, sample_idx=s_idx_diego, scaler=None,
                 test_frac=0.2, seed=42, logging=0, maxiter=-1,
                 **kwargs):
        """
        Parameters
        ----------
        func : function
            Lebesge function to be learning by surrogate model.
        x_dim : int
            Number of input dimensions for the function to be learned
            within the domain of [0,1] for each parameter.
        epsilon : float
            Desired accuracy level [0.0, 1.0)
        delta : float
            Desired confidence (1 - delta) level (0.0, 1.0].
        meta_model:
        sample_num : function, optional
            The sampling sequence in the form of a callable where n is
            the input domain dimension to be sampled from and index
            is the sampling level according to the scheme
            (Default is s_num_diego).
        sample_idx : function, optional
            The function that returns the index of sampling to be used
            of a sampling scheme given a required minimum number of
            samples.
        scaler : TransformerMixin
        test_frac : float
        seed : int
            (Default is 1).
        logging: {0, 1, 2}, optional
            Determines the level of logging after each iteration.
                - 1 : Minimum required for evaluation
                - 2 : Maximum logging.
                    - Sampled data indices are stored w.r.t. each
                      iteration.
                    - Predictive model is stored for each iteration.
            (Default is 0).
        verbose: bool
            (Default is False).
        tdmq : bool
            (Default is False).

        See Also
        --------
        s_num_diego :
            Sampling sequence used in Diego G. Loyola R et al. [1]_
        s_idx_diego :
            Index of sampling used in Diego G. Loyola R et al. [1]_

        References
        ----------
        ..  [1] Loyola R, D. G., Pedergnana, M., & Gimeno García, S.
            (2016). Smart sampling and incremental function learning
            for very large high dimensional data. Neural Networks, 78,
            75–87. https://doi.org/10.1016/j.neunet.2015.09.001
        """
        super().__init__(func, x_dim, meta_model, sample_num, sample_idx,
                         scaler, test_frac, seed=seed,
                         logging=logging)

        self._maxiter = maxiter
        self._algorithm_settings = dict(
            cumulative=kwargs.pop("cumulative", True),
            importance=kwargs.pop("importance", "error"),
            tdmq=kwargs.pop("tdmq", False),
            verbose=kwargs.pop("verbose", False),
            hopt=kwargs.pop("hopt", True),
            clip=kwargs.pop("clip", False),
            v=kwargs.pop("v", 1))

        tdmq = self._algorithm_settings["tdmq"]
        verbose = self._algorithm_settings["verbose"]

        self.delta = delta
        self.epsilon = epsilon

        # Determine initial design of experiments based of s_pacc.
        self._s_min = s_pacc(self.epsilon, self.delta)

        # Determine index of closest sample num after minimum.
        self._s_idx = self.sample_idx(self.x_dim, self._s_min)

        # Determine the sample number of that index.
        self._s_num = self.sample_num(self.x_dim, self._s_idx)

        # Sample initial design of experiments using CVT.
        x_idoe_train = self.sample(self._s_num,
                                   "cvt", seed=self._seed, tdmq=tdmq,
                                   verbose=verbose)

        x_idoe_val = self.sample(self.sample_num(self.x_dim, self._s_idx - 1),
                                 "cvt", seed=self._seed - 1, tdmq=tdmq,
                                 verbose=verbose)

        # Evaluate the experiments.
        f_idoe_train = self.func(*x_idoe_train.T)
        f_idoe_val = self.func(*x_idoe_val.T)

        # Scale if scaler is set.
        if self.scaler is not None:
            f_idoe_train = self.scaler.fit_transform(
                f_idoe_train.reshape(-1, 1)).flatten()
            f_idoe_val = self.scaler.transform(
                f_idoe_val.reshape(-1, 1)).flatten()

        # Split 80/20 train/validation.
        # (x_idoe_train,
        #  x_idoe_val,
        #  y_idoe_train,
        #  y_idoe_val) = train_test_split(
        #     x_idoe, f_idoe,
        #     train_size=self._s_num,
        #     random_state=seed)

        # Set training and validation data
        self._training_data = (x_idoe_train, f_idoe_train)
        self._validation_data = (x_idoe_val, f_idoe_val)

    # Define scoring function for hyperparameter optimisation.
    def model_score(self, model):
        return self.pacc_evaluate(self._validation_data[1],
                                  model.predict(self._validation_data[0]),
                                  self.epsilon,
                                  self.delta,
                                  score_return=True)

    @property
    def algorithm_settings(self):
        return self._algorithm_settings

    @algorithm_settings.setter
    def algorithm_settings(self, x):
        self._algorithm_settings = x

    def iterate(self, **kwargs):
        """
        Carries out next iteration of algorithm.

        Parameters
        ----------

        * kwargs : [optional]
            - cumulative : bool, optional
            - importance : {'none', 'error', 'max', 'min'}
            - tdmq : bool, optional
                Progress bar in jupyter lab environment (default = False).
            - verbose : int or bool, optional
                Sets verbosity of iterations of algorithm. True for each
                iteration to be printed, integer value for frequency of
                iterations to be printed.


        Returns
        -------

        """
        cumulative = self.algorithm_settings["cumulative"]
        importance = self.algorithm_settings["importance"]
        tdmq = self.algorithm_settings["tdmq"]
        verbose = self.algorithm_settings["verbose"]
        hopt = self.algorithm_settings["hopt"]
        clip = self.algorithm_settings["clip"]
        v = self.algorithm_settings["v"]

        if self.terminate:
            raise AssertionError(
                "Termination cond. met. Set force as True for continued iter.")

        if hopt:
            # Fit and optimise the tunable parameters of the model.
            self.meta_model.optimise_fit(*self._training_data,
                                         validation_data=self._validation_data,
                                         # score_function=self.model_score,
                                         tdmq=tdmq,
                                         reset=False,
                                         verbose=verbose)

        else:
            self.meta_model.fit(*self._training_data,
                                validation_data=self._validation_data,
                                reset=False,
                                verbose=verbose)

        # Evaluate the model according to the PACC framework.
        evaluation_log, rel_error = self.pacc_evaluate(
            f=self._validation_data[1],
            f_s=self.meta_model.predict(self._validation_data[0]),
            delta=self.delta,
            epsilon=self.epsilon,
            with_error_array=True)
        self._terminate = evaluation_log.terminate

        if self._iteration >= self._maxiter:
            if self._maxiter == -1:
                pass
            else:
                self._terminate = True

        if verbose:
            # Print headers if verbose.
            if self._iteration == 0:
                print_pacc_header()
            print_pacc_iteration(self._iteration,
                                 self._s_num,
                                 evaluation_log)

        if not self.terminate:
            # Increase iteration count and sample idx.
            self._iteration += 1
            self._s_idx += 1

            # Determine the sample number of that index.
            self._s_num = self.sample_num(self.x_dim, self._s_idx)

            if cumulative:
                s_new = ceil((1 + self._test_frac) *
                             (self._s_num - self.sample_num(self.x_dim,
                                                            self._s_idx - 1)))
            else:
                s_new = self._s_num

            if importance == 'error':
                all_data = self.concat_data(self._training_data,
                                            self._validation_data)
                _importance_log, _rel_error = self.pacc_evaluate(
                    f=all_data[1],
                    f_s=self.meta_model.predict(all_data[0]),
                    delta=self.delta,
                    epsilon=self.epsilon,
                    with_error_array=True)
                if clip is not False:
                    p = np.where(rel_error >= self.epsilon, rel_error ** v,
                                 clip)
                else:
                    p = rel_error ** v
                mapping = InterpolatedMarginalInverseECDF(
                    p=p,
                    x=self._validation_data[0],
                    kind='linear')

            elif importance == 'none':
                mapping = null_mapping

            else:
                raise NotImplementedError("Only error importance sampling" +
                                          "currently supported")

            # Sample initial design of experiments using CVT.
            x_new = self.sample(s_new, "cvt", seed=self._seed,
                                tdmq=tdmq,
                                verbose=verbose,
                                mapping=mapping)

            # Evaluate the experiments.
            f_new = self.func(*x_new.T)

            # Scale if scaler is set.
            if self.scaler is not None:
                f_new = self.scaler.transform(f_new.reshape(-1, 1)).flatten()

            if cumulative:
                # Split train/validation.
                (x_new_train,
                 x_new_val,
                 y_new_train,
                 y_new_val) = train_test_split(
                    x_new, f_new,
                    train_size=(self._s_num - self.sample_num(self.x_dim,
                                                              self._s_idx - 1)),
                    random_state=self._seed + self._iteration)

                # Set training and validation data
                new_training_data = (x_new_train, y_new_train)
                new_validation_data = (x_new_val, y_new_val)
                self._training_data = self.concat_data(
                    self._training_data,
                    new_training_data)
                self._validation_data = self.concat_data(
                    self._validation_data,
                    new_validation_data)

                # plt.scatter(*new_training_data[0].T)
                # plt.ylim((0, 1))
                # plt.xlim((0, 1))
                # plt.show()


            else:
                self._validation_data = self._training_data
                self._training_data = (x_new, f_new)

        else:
            x_new = None
        # Logging
        if self._logging == 0:
            # Minimum logging level.
            self._log(n_samples=evaluation_log.n_samples,
                      n_passing=evaluation_log.n_passing,
                      statistic=evaluation_log.statistic,
                      terminate=evaluation_log.terminate)

        elif self._logging == 1:
            self._log(n_samples=evaluation_log.n_samples,
                      n_passing=evaluation_log.n_passing,
                      statistic=evaluation_log.statistic,
                      terminate=evaluation_log.terminate,
                      rel_error=rel_error,
                      it_sample=x_new,
                      importance=importance,
                      hopt=hopt,
                      cumulative=cumulative,
                      delta=self.delta,
                      epsilon=self.epsilon,
                      hyperparams=self.meta_model.hyper_params)
            # self._log()
        elif self._logging == 2:
            raise NotImplementedError
            # self._log(n_samples=evaluation_log.n_samples,
            #           n_passing=evaluation_log.n_passing,
            #           statistic=evaluation_log.statistic,
            #           terminate=evaluation_log.terminate,
            #           rel_error=rel_error,
            #           it_sample=x_new))
            # self._log()
        else:
            raise RuntimeError("Logging argument not recognised.")

    def iterate_to_confidence(self):
        cumulative = self.algorithm_settings["cumulative"]
        importance = self.algorithm_settings["importance"]
        tdmq = self.algorithm_settings["tdmq"]
        verbose = self.algorithm_settings["verbose"]
        hopt = self.algorithm_settings["hopt"]
        clip = self.algorithm_settings["clip"]
        v = self.algorithm_settings["v"]

        while not self.terminate:
            self.iterate(cumulative=cumulative, importance=importance,
                         tdmq=tdmq, verbose=verbose, hopt=hopt, clip=clip, v=v)


if __name__ == "__main__":
    # t = SSIFL(lambda x: 1)
    #
    # for i in t:
    #     print(i)

    # d = DynamicLogger()
    # for i in range(10):
    #     d(t1=1 + i, t2=2 + i, t3=3 + i)
    #
    #     if i == 8:

    #         d(t1=1 + i, t2=2 + i, t3=3 + i)

    # print(len(d[-1]))

    # print(d[4])

    from metamodel import SupportVectorRegression as svr
    from mmgpy.surrogate.test import TestFunctionSet2DInputSpace as F2D
    from sklearn.preprocessing import MinMaxScaler

    scaler = MinMaxScaler()

    F2D = F2D()

    test = SSIFL(func=F2D[9],
                 x_dim=2,
                 meta_model=svr(),
                 delta=0.001,
                 epsilon=0.05,
                 verbose=True,
                 scaler=scaler)

    test.iterate_to_confidence(cumulative=True, verbose=10,
                               importance="error")

    # Sample initial design of experiments using CVT.
    x_test = test.sample(10000,
                         "halton", seed=1, tdmq=False,
                         verbose=False)

    # Evaluate the experiments.
    f_test = test.func(*x_test.T)

    print(test.pacc_evaluate(
        test.scaler.transform(f_test.reshape(-1, 1)).flatten(),
        test.meta_model.predict(x_test),
        test.epsilon,
        test.delta
    )
    )
