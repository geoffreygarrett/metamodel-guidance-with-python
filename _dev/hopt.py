import skopt
from src.surrogate.sampling import halton
from src.surrogate.sampling import random_uniform
from src.utils import TQDMSkoptCallable

from src.surrogate.test import TestFunctionSet2DInputSpace as F2D
from src.surrogate.test import TestFunctionSetNDInputSpace as FND
from sklearn.svm import SVR as sklearnSVR

SPACE = [skopt.space.Real(1e-4, 1e3, name='gamma'),
         skopt.space.Real(1e-2, 1e-1, name='epsilon'),
         ]

F2D = F2D()
F3D = FND(3)
F4D = FND(4)
F4D = FND(5)
from sklearn.preprocessing import MinMaxScaler

scaler = MinMaxScaler()

import joblib


if __name__=="__main__":

    def do_and_save(minimizer, N, dim):
        F = FND(dim)
        n_dim = dim
        Fset = F
        x = halton([[0] * n_dim, [1] * n_dim], N)
        x_v = random_uniform([[0] * n_dim, [1] * n_dim], int(N * 2), seed=1)
        f = Fset[0](*x.T)
        f = scaler.fit_transform(f.reshape(-1, 1)).flatten()
        f_v = scaler.transform(Fset[0](*x_v.T).reshape(-1, 1)).flatten()

        def get_objective_f(STATIC_PARAMS):
            @skopt.utils.use_named_args(SPACE)
            def objective(**params):
                all_params = {**params, **STATIC_PARAMS}
                # dataset_train = (x, f.flatten())
                # dataset_test = (x_v, f_v.flatten())
                #         all_params.pop("n_samples")
                all_params.pop("n_calls")
                model = sklearnSVR(**all_params)
                model.fit(x, f)
                return - model.score(x_v, f_v)

            return objective

        STATIC_PARAMS_2 = {}
        STATIC_PARAMS_2["n_calls"] = 50
        progress = TQDMSkoptCallable(total=STATIC_PARAMS_2["n_calls"],
                                     desc="Model HpOpt",
                                     leave=False)
        objective = get_objective_f(STATIC_PARAMS_2)
        result = minimizer(objective, SPACE, callback=[progress],
                           **STATIC_PARAMS_2)
        name = f"../models/hyperopt_res_{str(minimizer.__name__)}_N{N}_dim{dim}.sv"
        return result, name


    r1 = do_and_save(skopt.dummy_minimize, 10, 2)
    import skopt.plots
    import matplotlib.pyplot as plt

    print(r1[0])
    skopt.dump(*r1)

    result_bayesian = joblib.load("../models/hyperopt_res_gp_minimize_N100_dim2.sv")
    skopt.plots.plot_convergence(result_bayesian)
    skopt.plots.plot_evaluations(result_bayesian)

    plt.show()

