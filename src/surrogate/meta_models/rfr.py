from ._base import SurrogateModelBaseRegression
from sklearn.ensemble.forest import RandomForestRegressor as sklearnRFR


def _model_cls_(all_params):
    return sklearnRFR(n_estimators=all_params["n_estimators"],
                      criterion=all_params["criterion"],
                      max_depth=all_params["max_depth"],
                      min_samples_split=all_params["min_samples_split"],
                      min_samples_leaf=all_params["min_samples_leaf"],
                      min_weight_fraction_leaf=all_params["min_weight_fraction_leaf"],
                      max_features=all_params["max_features"],
                      max_leaf_nodes=all_params["max_leaf_nodes"],
                      min_impurity_decrease=all_params["min_impurity_decrease"],
                      min_impurity_split=all_params["min_impurity_split"],
                      bootstrap=all_params["bootstrap"],
                      oob_score=all_params["oob_score"],
                      n_jobs=all_params["n_jobs"],
                      random_state=all_params["random_state"],
                      verbose=all_params["verbose"],
                      warm_start=all_params["warm_start"])


class RandomForestRegression(SurrogateModelBaseRegression):

    def __init__(self, static_params=None):
        super().__init__()
        self._default_params = {
            "n_estimators": 'warn',
            "criterion": "mse",
            "max_depth": None,
            "min_samples_split": 2,
            "min_samples_leaf": 1,
            "min_weight_fraction_leaf": 0.,
            "max_features": "auto",
            "max_leaf_nodes": None,
            "min_impurity_decrease": 0.,
            "min_impurity_split": None,
            "bootstrap": True,
            "oob_score": False,
            "n_jobs": None,
            "random_state": None,
            "verbose": 0,
            "warm_start": False}
        self._hyper_param_space = {
            "integer__n_estimators": (10, 5000)
        }
        self._structure_hyper_param_space = {}
        self._static_params = static_params
        self._model_cls = _model_cls_
