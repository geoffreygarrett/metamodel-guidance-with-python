from ._base import SurrogateModelBaseRegression
from sklearn.gaussian_process import GaussianProcessRegressor as sklearnGPR
from sklearn.gaussian_process.kernels import Matern

DEFAULT_GPR_PARAMS = {
    "kernel": Matern()+Matern(),
    "alpha": 1e-10,
    "optimizer": "fmin_l_bfgs_b",
    "n_restarts_optimizer": 0,
    "normalize_y": False,
    "copy_X_train": True,
    "random_state": None
}

DEFAULT_GPR_ROUTINES = dict(
    intermediate=[
        {"real__alpha": (1e-10, 1e-3),
         "_optimiser__name": "gp_minimize"}
        # "_optimiser__kwargs": {"n_calls": 50}}
    ]
)


class GaussianProcessRegression(SurrogateModelBaseRegression):

    def __init__(self, static_params=None):
        """
        Gaussian process regression model from sci-kit learn.

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
        super().__init__(routines=DEFAULT_GPR_ROUTINES,
                         hyperparams_default=DEFAULT_GPR_PARAMS,
                         hyperparams_static=static_params)
        self._model_cls = sklearnGPR

    def __str__(self):
        return ("Gaussian Process Regression "
                "(sklearn.gaussian_process.GaussianProcessRegressor)")

    def copy_model(self, model):
        """

        Parameters
        ----------
        model

        Returns
        -------

        """
        return model
