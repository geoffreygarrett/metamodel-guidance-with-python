from ._base import SurrogateModelBaseRegression
from sklearn.svm import SVR as sklearnSVR


def _model_cls_(all_params):
    return sklearnSVR(kernel=all_params["kernel"],
                      degree=all_params["degree"],
                      gamma=all_params["gamma"],
                      coef0=all_params["coef0"],
                      tol=all_params["tol"],
                      C=all_params["C"],
                      epsilon=all_params["epsilon"],
                      shrinking=all_params["shrinking"],
                      cache_size=all_params["cache_size"],
                      verbose=all_params["verbose"],
                      max_iter=all_params["max_iter"])


class SupportVectorRegression(SurrogateModelBaseRegression):
    def __str__(self):
        return "SVR"

    def __init__(self, static_params={}):
        super().__init__()
        self._default_params = {
            "kernel": "rbf",
            "degree": 3,

            "gamma": "auto_deprecated",
            "coef0": 0.0,
            "tol": 1e-3,
            "C": 1.0,
            "epsilon": 0.01,
            "shrinking": True,
            "cache_size": 200,
            "verbose": False,
            "max_iter": -1}

        self._hyper_param_space = {
            "categorical__kernel": (['rbf', 'linear'],),
            "real__gamma": (1e-3, 500),
            "real__epsilon": (0.001, 1e-1)
            # "real__epsilon": (0.001, 1e-1)
        }
        self._static_params = static_params
        self._hyper_params = {}
        self._model_cls = _model_cls_

    def fit(self, x_train, y_train, x_test=None, y_test=None, reset=False,
            verbose=False, tdmq=False, early_stopping=False):
        self.reset_model()
        self.model.fit(x_train, y_train)
