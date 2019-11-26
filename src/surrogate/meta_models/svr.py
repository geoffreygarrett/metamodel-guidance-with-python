from src.surrogate.meta_models._base import SurrogateModelBaseRegression
from sklearn.svm import SVR as sklearnSVR

DEFAULT_SVR_PARAMS = {
    "kernel": "rbf",
    "degree": 3,
    "gamma": "auto_deprecated",
    "coef0": 0.0,
    "tol": 1e-3,
    "C": 1.0,
    "epsilon": 0.01,
    "shrinking": True,
    "cache_size": 200,
    # "verbose": False,
    "max_iter": -1}

DEFAULT_SVR_ROUTINES = dict(
    intermediate=[
        {"real__gamma": (1e-3, 2e3),
         "real__epsilon": (5e-4, 2e-1),
         "_optimiser__name": "gp_minimize"}
         # "_optimiser__kwargs": {"n_calls": 50}}
    ]
)


class SupportVectorRegression(SurrogateModelBaseRegression):

    def __init__(self, static_params=None):
        """
        Support vector regression model from sci-kit learn.

        Parameters
        ----------
        static_params : dict, optional
            Static parameters which overwrite the coded default
            parameters of the SVR model.

        See Also
        --------
        sklearn.svm.SVR

        References
        ----------


        """
        super().__init__(routines=DEFAULT_SVR_ROUTINES,
                         hyperparams_default=DEFAULT_SVR_PARAMS,
                         hyperparams_static=static_params)
        self._model_cls = sklearnSVR

    def __str__(self):
        return "Support Vector Regression (sklearn.svm.SVR)"

    def copy_model(self, model, *kwargs):
        """

        Parameters
        ----------
        model

        Returns
        -------

        """
        return model
