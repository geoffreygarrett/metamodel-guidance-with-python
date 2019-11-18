import numpy as np
from src.surrogate.sampling._pacc import *
from src.surrogate.sampling import random_uniform, cvt, halton

from sklearn import svm
import skopt
from src.surrogate.sampling._pacc import s_diego, s_pacc, s_val_diego
from scipy.interpolate import interp1d
from sklearn.preprocessing import MinMaxScaler, StandardScaler
from src.surrogate.test import TestFunctionSet2DInputSpace

F2D = TestFunctionSet2DInputSpace()

# scaler = StandardScaler()

import numpy as np
from sklearn.model_selection import train_test_split
from scipy.stats import norm
import inspect

from src.utils import TQDMSkoptCallable


def marginal_cdf2(f, x):
    _x_sorted = x[np.argsort(x)]
    _f_sorted = f[np.argsort(x)]
    aux = np.cumsum(_f_sorted)
    _X = np.concatenate(([0], _x_sorted))
    aux = np.concatenate(([0], aux))
    _CDF = aux / np.max(aux)
    return _X, _CDF


def F_inverse_function(f, x):
    _X, _CDF = marginal_cdf2(f, x)
    return interp1d(_CDF, _X)


from copy import deepcopy


def ssifl2(epsilon, delta, function, n, model_handle_cls,
           hpopt=None,
           scaler=None,
           s_series=s_diego,
           s_idx=s_val_diego,
           path=None,
           train_size=None,
           val_size=None,
           verbose=True,
           save=True,
           hpopt_calls=15):
    model_handle = model_handle_cls()
    #
    # Catch for only one argument set for either train_size or val_size.
    #
    try:
        assert train_size is None or val_size is None
    except AssertionError:
        raise AssertionError(
            """
            Only one of (train_size,val_size) can be set as either integer or float:
            - Float implies fraction of total data.
            - Integer implies integer value of samples.
            """)
    #
    # Initial S_val based on PACC framework evaluation lower limit.
    #
    s_val = s_idx(n, epsilon, delta)
    #
    # Initialised values for algorithm.
    #
    n_pass = 0
    n_test = 1
    iteration = 1
    #
    # Initial design of experiments.
    #
    idoe = cvt(n, int(s_series(n, s_val) * 1.25) + 1, halton, random_uniform, 1000, 50, seed=None, form="sx")
    #
    # Evaluation of IDOE.
    #
    fido = function(*idoe.T)
    #
    # Create scaler if scaler is defined and evaluate on IDOE.
    #
    if scaler:
        X_idoe, y_idoe = idoe, scaler.fit_transform(fido.reshape(-1, 1)).flatten()
    else:
        X_idoe, y_idoe = idoe, fido.flatten()
    #
    # Split for training and validation data.
    #
    X_idoe_train, X_idoe_val, y_idoe_train, y_idoe_val = train_test_split(X_idoe, y_idoe,
                                                                          train_size=s_series(n, s_val),
                                                                          random_state=42)
    #
    # Prepare tupled training and validation data sets.
    #
    training_data = (X_idoe_train, y_idoe_train)
    validation_data = (X_idoe_val, y_idoe_val)
    #
    # Prepare verbosity table headers.
    #
    header_printed = False
    list_len_h = None
    headers = None
    if verbose is not None:
        header_printed = False
        headers = ["iter", "s_train", "n_s_test < epsilon", "n_s_test", "Pr(|fsm(x)-f(x)| <= epsilon)"]
        list_len_h = list(map(lambda x: len(x) + 2, headers))
        headers = [("{:^" + str(len(h) + 2) + "}").format(h) for h in headers]
    #
    # If hyperparameter optimisation is required.
    #
    x_hp_tested = []
    f_hp_tested = []
    hpopt_space = model_handle.space

    @skopt.utils.use_named_args(hpopt_space)
    def objective(**params):
        model_handle.reset_model()
        static_params = {"training_data": training_data, "validation_data": validation_data,
                         "Xdim": len(training_data[0][0]), "fdim": 1}
        model_handle.static_params = static_params
        model_handle.hyper_params = params
        model_handle.fit(*training_data)
        return -model_handle.score(*validation_data)

    #
    # Begin algorithm while loop until condition of accuracy with confidence is acquired.
    #
    # below_minimum = lambda: (iteration < int(16 ** (1 / n)))
    below_minimum = lambda: False
    not_confident = lambda: (n_pass / n_test <= 1 - delta)
    while not_confident() or below_minimum():
        #
        # If hyperparameter optimisation is required.
        #
        if hpopt is not None:
            x0 = x_hp_tested if len(x_hp_tested) > 0 else None
            y0 = f_hp_tested if len(f_hp_tested) > 0 else None
            x0_ = None
            if x0 is not None and y0 is not None:
                y0 = np.array(y0)
                ybest = np.argsort(y0)[:5]
                x0_ = [x0[int(yb)] for yb in ybest]
                y0 = None
            n_calls = hpopt_calls
            total = n_calls if x0_ is None else n_calls - len(x0_) + 1
            progress = TQDMSkoptCallable(total=total, desc="Model HpOpt", leave=False)
            results = skopt.forest_minimize(objective, hpopt_space, verbose=False, n_calls=n_calls, x0=x0_, y0=y0,
                                            callback=[progress])
            progress.close()
            x_hp_tested.append(results.x)
            f_hp_tested.append(results.fun)
            model_handle.reset_model()
            static_params = {"training_data": training_data, "validation_data": validation_data,
                             "Xdim": len(training_data[0][0]), "fdim": 1}
            model_handle.static_params = static_params
            model_handle.hyper_params = model_handle.hyper_params_x(results.x)
            current_model = model_handle
        else:
            model_handle.reset_model()
            static_params = {"training_data": training_data, "validation_data": validation_data,
                             "Xdim": len(training_data[0][0]), "fdim": 1}
            model_handle.static_params = static_params
            current_model = model_handle
        #
        # Statistical model evaluation.
        #
        current_model.fit(*training_data)
        f_validation = current_model.predict(validation_data[0])
        square_error = np.square(f_validation - validation_data[1])
        absolute_error = np.abs(f_validation - validation_data[1])
        x_test = epsilon * (np.max(validation_data[1]) - np.min(validation_data[1]))
        n_pass = absolute_error[absolute_error <= x_test].size
        n_test = absolute_error.size

        if iteration % verbose == 0:
            # TODO: Make print string imported.
            cols = [iteration, s_series(n, s_val), n_pass, n_test, np.round(n_pass / n_test, 3)]
            if header_printed is False:
                print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))
                print('|'.join([""] + headers + [""]))
                print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))
                header_printed = True

            print('|'.join(
                [""] + [("{:^" + str(len_h) + "}").format(col) for len_h, col in zip(list_len_h, cols)] + [""]))

        if not_confident() or below_minimum():
            iteration += 1
            s_val += 1
            new_s = s_series(n, s_val) - s_series(n, s_val - 1)
            new_t = int(0.25 * new_s) + 1
            new_input_u = random_uniform([[0] * n, [1] * n], new_s + new_t)

            e_cdf = [F_inverse_function(absolute_error, validation_data[0].T[i]) for i in range(n)]
            new_input = np.vstack([e_cdf[i](u) for i, u in enumerate(new_input_u.T)]).T
            _f = function(*new_input.T)

            if scaler:
                X_new, y_new = new_input, scaler.transform(_f.reshape(-1, 1)).flatten()
            else:
                X_new, y_new = new_input, _f.flatten()
            X_train_, X_test_, y_train_, y_test_ = train_test_split(X_new, y_new, train_size=new_s, random_state=42)
            training_data = (np.vstack((training_data[0], X_train_)), np.concatenate((training_data[1], y_train_)))
            validation_data = (np.vstack((validation_data[0], X_test_)), np.concatenate((validation_data[1], y_test_)))

        else:
            print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))
            print('|'.join(
                [""] + [("{:^" + str(len_h) + "}").format(col) for len_h, col in zip(list_len_h, cols)] + [""]))
            print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))

    if save:
        current_model.save(path)

    return current_model  # , training_log,


def ssifl(epsilon, delta, function, n, hpopt=None, scaler=None):
    s_val = s_val_diego(n, epsilon, delta)
    n_pass = 0
    n_test = 1
    iteration = 0
    idoe = cvt(n, int(s_diego(n, s_val) * 1.25) + 1, halton, random_uniform, 1000, 50, seed=None, form="sx")
    _fido = function(*idoe.T)
    if scaler:
        X_new, y_new = idoe, scaler.fit_transform(_fido.reshape(-1, 1)).flatten()
    else:
        X_new, y_new = idoe, _fido.flatten()
    X_train_, X_test_, y_train_, y_test_ = train_test_split(X_new, y_new, train_size=s_diego(n, s_val), random_state=42)
    train_data = (X_train_, y_train_)
    test_data = (X_test_, y_test_)
    header_printed = False
    headers = ["iter", "s_train", "n_s_test < epsilon", "n_s_test", "Pr(|fsm(x)-f(x)| <= epsilon)"]
    list_len_h = list(map(lambda x: len(x) + 2, headers))
    headers = [("{:^" + str(len(h) + 2) + "}").format(h) for h in headers]
    x_hp_tested = []
    f_hp_tested = []

    while (n_pass / n_test <= 1 - delta) or (iteration < int(16 ** (1 / n))):
        iteration += 1
        #
        # Optimize model parameters, if set.
        #
        if hpopt is not None:
            SPACE = [skopt.space.Real(0.01, 1e3, name='gamma'),
                     skopt.space.Real(1, 200, name='C'),
                     skopt.space.Integer(0, 1, name='k_idx')
                     ]

            kernels = ['rbf', 'linear']

            STATIC_PARAMS = {}

            @skopt.utils.use_named_args(SPACE)
            def objective(**params):
                all_params = {**params, **STATIC_PARAMS}
                clf = svm.SVR(C=all_params["C"], gamma=all_params["gamma"], kernel=kernels[all_params['k_idx']],
                              max_iter=-1)
                clf.fit(*train_data)
                # return np.mean(np.abs(clf.predict(test_data[0]) - test_data[1]))
                return -clf.score(*test_data)

            x0 = x_hp_tested if len(x_hp_tested) > 0 else None
            y0 = f_hp_tested if len(f_hp_tested) > 0 else None
            x0_ = None
            if x0 is not None and y0 is not None:
                y0 = np.array(y0)
                ybest = np.argsort(y0)[:5]
                x0_ = [x0[int(yb)] for yb in ybest]
                y0 = None
            results = skopt.forest_minimize(objective, SPACE, verbose=False, n_calls=15, x0=x0_, y0=y0)
            gamma, C, k_idx = results.x
            x_hp_tested.append(results.x)
            f_hp_tested.append(results.fun)
            clf = svm.SVR(C=C, gamma=gamma, kernel=kernels[k_idx])
        else:
            clf = svm.SVR(gamma="scale")

        clf.fit(*train_data)
        #
        #
        f_test = clf.predict(test_data[0])
        #
        #
        error = np.abs(f_test - test_data[1])

        x_test = epsilon * (np.max(test_data[1]) - np.min(test_data[1]))
        n_pass = error[error <= x_test].size
        n_test = error.size

        if iteration % 1 == 0:
            # TODO: Make print string imported.
            cols = [iteration, s_diego(n, s_val), n_pass, n_test, np.round(n_pass / n_test, 3)]
            # str_cols = [("{:" + str(max_len) + "}").format(str(item)) for item in cols]
            if header_printed is False:
                print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))
                print('|'.join([""] + headers + [""]))
                print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))
                header_printed = True

            print('|'.join(
                [""] + [("{:^" + str(len_h) + "}").format(col) for len_h, col in zip(list_len_h, cols)] + [""]))

            # print(
            #     f"""
            # iteration  : {iteration};
            # ===============================
            # n_samples  : {s_diego(n, s_val)};
            # n_pass     : {n_pass};
            # n_test     : {n_test};
            # Pr e <= ep : {np.round(n_pass / n_test, 4)}
            # """)

        if n_pass / n_test <= 1 - delta or iteration < int(16 ** (1 / n)):
            s_val += 1
            new_s = s_diego(n, s_val) - s_diego(n, s_val - 1)
            new_t = int(0.25 * new_s) + 1
            new_input_u = random_uniform([[0] * n, [1] * n], new_s + new_t)
            #
            # Importance sampling.
            #
            #     # Generate error inverse CDF.
            #     #
            e_cdf = [F_inverse_function(error, test_data[0].T[i]) for i in range(n)]
            new_input = np.vstack([e_cdf[i](u) for i, u in enumerate(new_input_u.T)]).T
            _f = function(*new_input.T)

            if scaler:
                X_new, y_new = new_input, scaler.transform(_f.reshape(-1, 1)).flatten()
            else:
                X_new, y_new = new_input, _f.flatten()
            X_train_, X_test_, y_train_, y_test_ = train_test_split(X_new, y_new, train_size=new_s, random_state=42)
            train_data = (np.vstack((train_data[0], X_train_)), np.concatenate((train_data[1], y_train_)))
            test_data = (np.vstack((test_data[0], X_test_)), np.concatenate((test_data[1], y_test_)))

        else:
            print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))
            print('|'.join(
                [""] + [("{:^" + str(len_h) + "}").format(col) for len_h, col in zip(list_len_h, cols)] + [""]))
            print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))

    return clf


if __name__ == "__main__":
    ssifl(0.1, 0.001, F2D[0], 2, optimize_hp=True)
