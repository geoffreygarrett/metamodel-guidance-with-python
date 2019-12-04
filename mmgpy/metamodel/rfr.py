from ._base import SurrogateModelBaseRegression
from sklearn.ensemble.forest import RandomForestRegressor as sklearnRFR

DEFAULT_RFR_PARAMS = {
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
    "warm_start": False}

DEFAULT_RFR_ROUTINES = dict(
    intermediate=[
        {"integer__n_estimators": (200, 2000),
         "integer__max_depth": (10, 100),
         "integer__min_samples_leaf": (1, 4),
         "_optimiser__name": "gp_minimize",
         "_optimiser__kwargs": {"n_calls": 12, "n_random_starts": 4}
         }
    ]
)


def _model_cls_(all_params):
    return sklearnRFR(n_estimators=all_params["n_estimators"],
                      criterion=all_params["criterion"],
                      max_depth=all_params["max_depth"],
                      min_samples_split=all_params["min_samples_split"],
                      min_samples_leaf=all_params["min_samples_leaf"],
                      min_weight_fraction_leaf=all_params[
                          "min_weight_fraction_leaf"],
                      max_features=all_params["max_features"],
                      max_leaf_nodes=all_params["max_leaf_nodes"],
                      min_impurity_decrease=all_params[
                          "min_impurity_decrease"],
                      min_impurity_split=all_params["min_impurity_split"],
                      bootstrap=all_params["bootstrap"],
                      oob_score=all_params["oob_score"],
                      n_jobs=all_params["n_jobs"],
                      random_state=all_params["random_state"],
                      verbose=all_params["verbose"],
                      warm_start=all_params["warm_start"])


class RandomForestRegression(SurrogateModelBaseRegression):

    def __init__(self, static_params=None):
        super().__init__(routines=DEFAULT_RFR_ROUTINES,
                         hyperparams_default=DEFAULT_RFR_PARAMS,
                         hyperparams_static=static_params)
        self._model_cls = sklearnRFR

    def __str__(self):
        return "Random Forest Regression (sklearn.ensemble." \
               "RandomForestRegression)"

    def copy_model(self, model, **kwargs):
        """

        Parameters
        ----------
        model

        Returns
        -------

        """
        return model
