import skopt

from sklearn.externals import joblib
from copy import deepcopy
from src.utils import TQDMSkoptCallable
import numpy as np
import torch
from collections import namedtuple
from src.optimisation.hyperparameter import HyperParamRoutineOptimizer


# hyperopt_routine =


class SurrogateModelBaseRegression:

    def __init__(self):
        self._skopt_space_mapping = {
            "integer": skopt.space.Integer,
            "real": skopt.space.Real,
            "categorical": skopt.space.Categorical}

        self._default_params = {}
        self._static_params = {}
        self._hyper_parameters_level_1 = {}  # requires model reset.
        self._hyper_parameters_level_2 = {}

        self._hyper_parameter_level_1_space = None
        self._hyper_parameter_level_2_space = None

        self._trainer = None
        self._model_cls = None
        self._model = None

        self._x_hp_evaluated = {"level1": [], "level2": []}
        self._f_hp_evaluated = {"level1": [], "level2": []}

    @classmethod
    def new(cls):
        new_cls = cls()
        return new_cls

    def hp_dict(self, space, x):
        new_keys = []
        for key in space.keys():
            new_keys.append(key.split("__")[-1])
        return dict(zip(new_keys, x))

    def reset_model(self):
        self._model = None

    @property
    def model(self):
        if self._model is None:
            self._model = self._model_cls(self.all_params)
        else:
            pass
        return self._model

    @property
    def hyper_params(self):
        if self._model is None:
            return {**self._hyper_parameters_level_1,
                    **self._hyper_parameters_level_2}
        else:
            return self._hyper_parameters_level_2

    @property
    def default_params(self):
        return self._default_params

    @property
    def static_params(self):
        return self._static_params

    @static_params.setter
    def static_params(self, x):
        self._static_params = x

    @property
    def all_params(self):
        return {**self.default_params,
                **self.structure_params,
                **self.hyper_params,
                **self.static_params}

    @property
    def hp_structure_keys(self):
        new_keys = []
        for key in self._structure_hyper_param_space.keys():
            new_keys.append(key.split("__")[-1])
        return new_keys

    @property
    def hp_tunable(self):
        new_keys = []
        for key in self._hyper_param_space.keys():
            new_keys.append(key.split("__")[-1])
        return new_keys

    def hyper_params_x(self, x):
        new_keys = []
        for key in self._hyper_param_space.keys():
            new_keys.append(key.split("__")[-1])
        if len(x) > len(self._hyper_param_space.keys()):
            for key in self._structure_hyper_param_space.keys():
                new_keys.append(key.split("__")[-1])
        return dict(zip(new_keys, x))

    def set_hyper_params_from_results(self, results):
        self._hyper_params

    def space(self, params):
        _space = []
        for key, value in params.items():
            _type, _name = key.split("__")
            _space.append(self._skopt_space_mapping[_type](*value, name=_name))
        return _space

    def fit(self, x_train, y_train, x_test=None, y_test=None, reset=False,
            verbose=False, tdmq=False, early_stopping=None, **kwargs):
        """

        Parameters
        ----------
        x_train
        y_train
        x_test
        y_test
        reset
        verbose

        Returns
        -------

        """
        try:
            self.model.fit(x_train, y_train)
        except AttributeError:
            raise NotImplementedError(
                "Either base used, which has no model attribute, or default .fit method doesn't exist for model."
            )

    def best_hyper_params(self, type_opt, n=3):
        x0_ = None
        ybest = None
        x0 = self._x_hp_evaluated[type_opt] if len(
            self._x_hp_evaluated[type_opt]) > 0 else None
        y0 = self._f_hp_evaluated[type_opt] if len(
            self._f_hp_evaluated[type_opt]) > 0 else None
        if x0 is not None and y0 is not None:
            y0 = np.array(y0)
            ybest = np.argsort(y0)[:n]
            x0_ = [x0[int(yb)] for yb in ybest]
        return x0_, ybest

    def fit_optimise(self, x_train, y_train, x_test, y_test,
                     score_function, reset=False, n_calls=30,
                     n_random_starts=5, verbose=False, tdmq=False,
                     early_stopping=None):

        self.static_params["x_dim"] = len(x_train.T)
        self.static_params["f_dim"] = 1

        if not self._model or reset:  # Then level 1 hyper parameter optimisation.
            type_opt = "reset"
            self.reset_model()
            space = self.space({**self._hyper_parameters_level_1,
                                **self._hyper_parameters_level_2})

        else:
            type_opt = "tuning"
            space = self.space(self._hyper_param_space)
        checkpoint = None
        try:
            checkpoint = self.model.state_dict()
        except AttributeError:
            print(self._model)
            print("no checkpoint")
            pass

        @skopt.utils.use_named_args(space)
        def objective(**params):
            model_handle = self.new()
            model_handle.static_params = self.static_params
            try:
                model_handle.model.load_state_dict(checkpoint)
            except AttributeError:
                print("yo mamam!")
                pass
            model_handle.hyper_params = params
            model_handle.fit(x_train, y_train, x_test, y_test,
                             early_stopping=True)
            # return score_function(model_handle)
            return -model_handle.score(x_test, y_test)

        if self.best_hyper_params(type_opt)[0] is not None:
            total = n_calls - len(self.best_hyper_params(type_opt)[0])
        else:
            total = n_calls
        progress = TQDMSkoptCallable(total=total, desc="Model HpOpt",
                                     leave=False)
        results = skopt.gp_minimize(objective, space, verbose=False,
                                    n_calls=n_calls,
                                    callback=[progress],
                                    n_random_starts=n_random_starts,
                                    x0=self.best_hyper_params(type_opt)[0])

        self._x_hp_evaluated[type_opt].append(results.x)
        self._f_hp_evaluated[type_opt].append(results.fun)
        self.set_hyper_params_from_results(results.x)
        self.fit(x_train, y_train, x_test, y_test,
                 reset=reset, verbose=verbose, tdmq=tdmq, early_stopping=False)

    def score(self, X, y, sample_weight=None):
        """

        :param X:
        :param y:
        :param sample_weight:
        :return:
        """
        try:
            return self.model.score(X, y, sample_weight=sample_weight)
        except AttributeError:
            raise NotImplementedError(
                "Either base used, which has no model attribute, or default .score method doesn't exist for model."
            )

    def predict(self, X):
        """
        Method to return prediction based on input.
        :param X:
        :return:
        """
        try:
            return self.model.predict(X)

        except AttributeError:
            raise NotImplementedError(
                "Either base used, which has no model attribute, or default .predict method doesn't exist for model."
            )

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
