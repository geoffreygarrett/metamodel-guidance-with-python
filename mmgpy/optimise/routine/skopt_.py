# Support for skopt.
import skopt
from ._base import BaseOptimiserRoutine
from ._config import DEFAULT_ROUTINE_KWARGS

SKOPT_SPACE_MAPPING = {"integer": skopt.space.Integer,
                       "real": skopt.space.Real,
                       "categorical": skopt.space.Categorical}

SKOPT_MINIMIZER_MAPPING = {"gp_minimize": skopt.gp_minimize,
                           "forest_minimize": skopt.forest_minimize,
                           "gbrt_minimize": skopt.gbrt_minimize,
                           "dummy_minimize": skopt.dummy_minimize}

SKOPT_DEFAULT_KWARGS = {**DEFAULT_ROUTINE_KWARGS,
                        "optimiser__name": "gp_minimize",
                        "optimiser__kwargs": {"n_calls": 15,
                                              "n_random_starts": 5}}


class SciKitOptOptimiserRoutine(BaseOptimiserRoutine):

    def __init__(self, routines=None, function_default=None, **kwargs):
        function_default = function_default if function_default is not None else {}
        super().__init__(routines, default_kwargs=SKOPT_DEFAULT_KWARGS,
                         function_default=function_default, **kwargs)
        self._optimiser_map = SKOPT_MINIMIZER_MAPPING
        self._space_map = SKOPT_SPACE_MAPPING

    def subroutine_optimise(self, function,
                            current_static,
                            decision_space,
                            initial,
                            callback):

        # Extract function and optimiser static.
        function_static = current_static["function"]
        optimiser_static = current_static["optimiser"]

        # Extract optimiser name and kwargs.
        optimiser_kwargs = optimiser_static["kwargs"]
        optimiser_name = optimiser_static["name"]

        # Make skopt function to minimize.
        @skopt.utils.use_named_args(decision_space)
        def objective(**decision_params):
            all_params = {**function_static, **decision_params}
            return function(**all_params)

        # Retrieve optimiser to be used.
        optimiser = self._optimiser_map[optimiser_name]
        if initial[0] is not None:
            return optimiser(objective, decision_space, callback=callback,
                             x0=initial[0], y0=initial[1], **optimiser_kwargs)
        else:
            return optimiser(objective, decision_space, callback=callback,
                             **optimiser_kwargs)


if __name__ == "__main__":
    from sklearn.svm import SVR as sklearnSVR
    from mmgpy.surrogate.sampling import halton
    from mmgpy.surrogate.sampling import random_uniform
    from mmgpy.surrogate.test import TestFunctionSet2DInputSpace as F2D
    from mmgpy.surrogate.test import TestFunctionSetNDInputSpace as FND
    from sklearn.preprocessing import MinMaxScaler

    STATIC_PARAMS = {

    }

    scaler = MinMaxScaler()
    F2D = F2D()
    F_ = F2D[6]
    x_train = halton([[0, 0], [1, 1]], 3000)
    x_test_ = random_uniform([[0, 0], [1, 1]], 1000)
    f_train = F_(*x_train.T)
    f_test_ = F_(*x_test_.T)

    ds_train = (
        x_train, scaler.fit_transform(f_train.reshape(-1, 1)).flatten())
    ds_test_ = (x_test_, scaler.transform(f_test_.reshape(-1, 1)).flatten())

    routine = {
        "intermediate": [
            # Subroutine 1.
            {
                # Subroutine decision hyperparameters.
                "real__gamma": (1e-3, 1e3),
                "real__epsilon": (1e-2, 1e-1),

                # optimiser arguments.
                "_optimiser__name": "gp_minimize",
                "_optimiser__kwargs": {"n_calls": 100},

                # Subroutine hyperparameters.
                "_subroutine__n_reevaluate_forward": 5,
                "_subroutine__intermediate_recycle": True,
                "_subroutine__n_best_so_far": True,
            },
            {
                # Subroutine decision hyperparameters.
                # "real__gamma": (1e-3, 1e3),
                "real__gamma": (1e-3, 1e3),
                "real__epsilon": (1e-2, 1e-1),

                # optimiser arguments.
                "_optimiser__name": "forest_minimize",
                "_optimiser__kwargs": {"n_calls": 100},

                # Subroutine hyperparameters.
                # "_subroutine__n_reevaluate_forward": 5,
                # "_subroutine__intermediate_recycle": True
            }
        ],
        # "intermediate": [
        #     {
        #
        #     },
        #     {
        #
        #     }
        # ]
    }


    def function_to_minimize(**params):
        svr = sklearnSVR(**params)
        svr.fit(*ds_train)
        return - svr.score(*ds_test_)


    test = SciKitOptOptimiserRoutine(routine)

    result1 = test.optimise(function_to_minimize)
    # print(test.current_best_global())
    # print(result1.space, result1.x)

    result2 = test.optimise(function_to_minimize)
    # print(test.current_best_global())
    # print(result2.space, result2.x)

    import matplotlib.pyplot as plt
    import skopt.plots


    def plot_for_result(result):
        plt.figure(dpi=400, figsize=(6, 5))
        skopt.plots.plot_convergence(result)
        plt.show()

        plt.figure(dpi=400, figsize=(6, 5))
        skopt.plots.plot_evaluations(result)
        plt.show()

        plt.figure(dpi=400, figsize=(6, 5))
        skopt.plots.plot_objective(result)
        plt.show()


    plot_for_result(result1)
    plot_for_result(result2)
