from dataset import DataSetFX
from sklearn.externals import joblib
from sklearn.model_selection import KFold
from sklearn.model_selection import train_test_split
import numpy as np
from optimise.routine import SciKitOptOptimiserRoutine


class SurrogateModelBaseRegression(SciKitOptOptimiserRoutine):
    """
    Test
    """

    def __init__(self, routines=None, hyperparams_default=None,
                 hyperparams_static=None):
        """

        Parameters
        ----------
        routines : dict
        hyperparams_default :
        hyperparams_static :
        """
        self._routines = routines
        super().__init__(routines=routines,
                         function_default=hyperparams_default)
        hp_stat = hyperparams_static if hyperparams_static is not None else {}
        self._global_static["function"] = hp_stat
        self._trainer_cls = None
        self._trainer = None
        self._model_cls = None
        self._model = None

    @property
    def routines(self):
        return self._routines

    @property
    def hyperparameters(self):
        return self._get_global_static_params()["function"]

    def trainer_hyperparameters(self, hyperparameters):
        return {}

    def architecture_hyperparameters(self, hyperparameters):
        return {}

    def _fit(self, x, y, model=None, **all_params):
        """
        Fits the data given the current default -> global static
        hyperparameters.

        Parameters
        ----------
        x
        y
        options

        Returns
        -------

        """
        # Extract options.
        vb = all_params.pop('verbose', False)
        reset = all_params.pop('reset', False)
        validation_data = all_params.pop('validation_data', None)
        hyperparameters = all_params

        # Reset model if required (i.e. fresh neural network training)
        if reset:
            model = None

        if self._trainer_cls is None:
            """Model does not require training, or inbuilt (Simple models)"""
            if model is None:
                model = self._model_cls(**hyperparameters)
            model.fit(x, y)
            trainer = None

        else:
            architecture_hyperparameters = self.architecture_hyperparameters(
                hyperparameters)
            trainer_hyperparameters = self.trainer_hyperparameters(
                hyperparameters)
            if model is None:
                """Create model with architecture and train (e.g. FFNN)"""
                model = self._model_cls(
                    {'x_dim': len(x.T), 'f_dim': 1,
                     **architecture_hyperparameters})
            train_dataset = self.prepare_dataset(x, y)
            if validation_data is not None:
                x_val, y_val = validation_data
                validation_dataset = self.prepare_dataset(x_val, y_val)
            else:
                validation_dataset = self.prepare_dataset(x, y)

            trainer = self._trainer_cls(
                **trainer_hyperparameters,
                training_dataset=train_dataset,
                validation_dataset=validation_dataset,
                model=model,
                PATH="models/")
            trainer.train(verbose=vb)
        return model, trainer

    def fit(self, x, y, **options):
        """
        Fits the data given the current default -> global static
        hyperparameters.

        Parameters
        ----------
        x
        y
        options

        Returns
        -------

        """
        self._model, self._trainer = self._fit(x, y,
                                               model=self._model,
                                               **self.hyperparameters,
                                               **options)

    def make_objective(self, x, y, **options):
        """

        Parameters
        ----------
        x : ndarray
        y : ndarray

        options
            - validation_data : tuple of ndarray, optional
            - method : str, optional
            - verbose : bool, optional
            - reset : bool, optional

            * Cross-validation
                - test_size :
                - random_state :
                - stratify :
                - shuffle :
                - n_splits :

        Returns
        -------

        """
        # Extract relevant options in the scope of make_objective.
        method = options.pop('method', 'LOOCV')
        validation_data = options.pop('validation_data', None)

        # Cross-validation optional parameters.
        test_size = options.pop('test_size', 0.2)
        random_state = options.pop('random_state', None)
        stratify = options.pop('stratify', None)
        shuffle = options.pop('shuffle', True)
        n_splits = options.pop('n_splits', 5)

        # Create options pertaining to to ._fit method.
        fit_options = dict(
            reset=options.pop('reset', False),
            verbose=options.pop('verbose', False),
            validation_data=validation_data)

        # Use leave one out cross-validation with provided validation.
        if validation_data:
            def _objective(**decision_params):
                if self._model:
                    pre_model = self.copy_model(self._model, x=x, y=y)
                else:
                    pre_model = None
                # Use validation data provided directly.
                post_model, trainer = self._fit(
                    x, y, pre_model,
                    **decision_params,
                    **fit_options)
                x_test, y_test = fit_options["validation_data"]
                return -self._score(post_model, x_test, y_test,
                                    trainer=trainer)

        # Leave out one cross-validation.
        elif method == "LOOCV":
            def _objective(**decision_params):
                if self._model:
                    pre_model = self.copy_model(self._model, x=x, y=y)
                else:
                    pre_model = None
                # Split given x, y into training and validation data.
                (x_train, x_test,
                 y_train, y_test) = train_test_split(x, y,
                                                     test_size=test_size,
                                                     random_state=random_state,
                                                     stratify=stratify,
                                                     shuffle=shuffle)

                fit_options["validation_data"] = (x_test, y_test)
                post_model, trainer = self._fit(
                    x_train, y_train, pre_model,
                    **decision_params,
                    **fit_options)
                return -self._score(post_model, x_test, y_test,
                                    trainer=trainer)

        # K-Fold cross-validation.
        elif method is "KFCV":
            # Split given x, y into training and validation for KFold
            # cross validation (Computationally expensive, although
            # more robust).
            def _objective(**decision_params):
                if self._model:
                    pre_model = self.copy_model(self._model, x=x, y=y)
                else:
                    pre_model = None
                kf = KFold(n_splits=n_splits, shuffle=shuffle,
                           random_state=random_state)
                scores = []
                for train_index, test_index in kf.split(x):
                    x_train, x_test = x[train_index], x[test_index]
                    y_train, y_test = y[train_index], y[test_index]
                    fit_options["validation_data"] = (x_test, y_test)
                    post_model, trainer = self._fit(
                        x_train, y_train, pre_model,
                        **decision_params,
                        **fit_options)
                    scores.append(-self._score(post_model, x_test, y_test,
                                               trainer=trainer))
                return np.mean(scores)

        else:
            raise ValueError("Score method not recognised.")

        return _objective

    def optimise_hyperparameters(self, x, y, **options):
        """
        Optimizes the hyperparameters by splitting the provided x and y
        arrays according to the validation score method chosen for the
        optimisation.

        Parameters
        ----------
        x :
        y :
        options
            - validation_data : tuple of ndarray, optional
            - method : str, optional
            - verbose : bool, optional
            - reset : bool, optional
            - tdmq : bool, optional
            - callback : list of callable, optional

            * Cross-validation
                - test_size :
                - random_state :
                - stratify :
                - shuffle :
                - n_splits :

        Returns
        -------

        """
        # Extract options pertaining to .optimise_routine() method.
        optimise_routine_options = dict(
            tdmq=options.pop('tdmq', False),
            callback=options.pop('callback', False))

        # Make objective function.
        objective = self.make_objective(x, y, **options)

        # Optimise hyperparameters.
        self.optimise_routine(objective, **optimise_routine_options)

    def optimise_fit(self, x, y, **options):
        """

        Parameters
        ----------
        x
        y
        options
            - validation_data : tuple of ndarray, optional
            - method : str, optional
            - verbose : bool, optional
            - reset : bool, optional
            - tdmq : bool, optional
            - callback : list of callable, optional

            * Cross-validation
                - test_size :
                - random_state :
                - stratify :
                - shuffle :
                - n_splits :
        Returns
        -------

        """
        # Cross-validation optional parameters.
        cross_validation_options = dict(
            test_size=options.pop('test_size', 0.2),
            random_state=options.pop('random_state', None),
            stratify=options.pop('stratify', None),
            shuffle=options.pop('shuffle', True),
            n_splits=options.pop('n_splits', 5))

        # Extract options pertaining to .optimise_hyperparameters() method.
        o = optimise_hyperparameters_options = dict(
            validation_data=options.pop('validation_data', None),
            method=options.pop('method', 'LOOCV'),
            verbose=options.pop('verbose', False),
            reset=options.pop('reset', False),
            tdmq=options.pop('tdmq', False),
            callback=options.pop('callback', False),
            **cross_validation_options)

        # Extract options pertaining to .fit() method.
        fit_options = dict(
            reset=options.pop('reset', False),
            verbose=o["verbose"],
            validation_data=o["validation_data"])

        # Optimise hyperparameters.
        self.optimise_hyperparameters(x, y, **optimise_hyperparameters_options)

        # Fit the final optimised parameters.
        self.fit(x, y, **fit_options)

    def copy_model(self, model, **kwargs):
        """

        Parameters
        ----------
        model

        Returns
        -------

        """
        raise NotImplementedError("Not implemented in base class.")

    def score(self, x, y, sample_weight=None, trainer=None):
        """

        Parameters
        ----------
        x
        y
        sample_weight

        Returns
        -------

        """
        return self._score(self._model, x, y, sample_weight, trainer)

    def predict(self, x):
        """

        Parameters
        ----------
        x

        Returns
        -------

        """

        return self._predict(self._model, x)

    def save(self, path):
        """

        :param path:
        :return:
        """
        joblib.dump(self._model, path)

    def load(self, path):
        """

        :param path:
        :return:
        """
        self._model = joblib.load(path)

    @staticmethod
    def prepare_dataset(x, y):
        """

        Parameters
        ----------
        x
        y

        Returns
        -------

        """
        return DataSetFX(
            output=y.reshape(-1, 1),
            input=x.reshape(-1, len(x.T)))

    @staticmethod
    def _score(model, x, y, sample_weight=None, trainer=None):
        """

        Parameters
        ----------
        model
        x
        y
        sample_weight

        Returns
        -------

        """
        try:
            return model.score(x, y, sample_weight=sample_weight)
        except AttributeError:
            raise NotImplementedError(
                "Either base used, which has no model attribute, or "
                "default .score method doesn't exist for model.")

    @staticmethod
    def _predict(model, x):
        """

        Parameters
        ----------
        model
        x

        Returns
        -------

        """
        # try:
        return model.predict(x)
        #
        # except AttributeError:
        #     raise NotImplementedError(
        #         "Either base used, which has no model attribute, or "
        #         "default .predict method doesn't exist for model.")
