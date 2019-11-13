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


def ssifl(epsilon, delta, function, n, optimize_hp=None, scaler=None):
    s_val = s_val_diego(n, epsilon, delta)
    n_pass = 0
    n_test = 1
    iteration = 0
    idoe = cvt(n, int(s_diego(n, s_val) * 1.25), halton, random_uniform, 1000, 50, seed=None, form="sx")
    _fido = function(*idoe.T)
    if scaler:
        X_new, y_new = idoe, scaler.fit_transform(_fido.reshape(-1, 1)).flatten()
    else:
        X_new, y_new = idoe, _fido.flatten()
    X_train_, X_test_, y_train_, y_test_ = train_test_split(X_new, y_new, test_size=0.20, random_state=42)
    train_data = (X_train_, y_train_)
    test_data = (X_test_, y_test_)
    header_printed = False
    headers = ["iter", "s_train", "n_s_test < epsilon", "n_s_test", "Pr(|fsm(x)-f(x)| <= epsilon)"]
    list_len_h = list(map(lambda x: len(x) + 2, headers))
    headers = [("{:^" + str(len(h) + 2) + "}").format(h) for h in headers]
    previous_hp = None
    x_hp_tested = []

    while n_pass / n_test <= 1 - delta or iteration <= 4:
        iteration += 1
        #
        # Optimize model parameters, if set..
        #
        if optimize_hp is not None:
            SPACE = [skopt.space.Real(0.01, 1e3, name='gamma'),
                     skopt.space.Integer(1, 200, name='C')]

            kernels = ['rbf', 'linear']

            STATIC_PARAMS = {}

            @skopt.utils.use_named_args(SPACE)
            def objective(**params):
                all_params = {**params, **STATIC_PARAMS}
                clf = svm.SVR(C=all_params["C"], gamma=all_params["gamma"], kernel='rbf', max_iter=-1)
                clf.fit(*train_data)
                # return np.mean(np.abs(clf.predict(test_data[0]) - test_data[1]))
                return clf.score(*test_data)

            results = skopt.forest_minimize(objective, SPACE, verbose=False, n_calls=40, x0=x_hp_tested)
            gamma, C = results.x
            x_hp_tested.append(results.x)
            clf = svm.SVR(C=C, gamma=gamma, kernel=kernels[0])
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

        if n_pass / n_test <= 1 - delta or iteration <= 4:
            s_val += 1
            new_s = s_diego(2, s_val) - s_diego(2, s_val - 1)
            new_input_u = random_uniform([[0] * n, [1] * n], int(new_s * 1.25))
            #
            # Importance sampling.
            #
            #     # Generate error inverse CDF.
            #     #
            e_cdf = [F_inverse_function(error, test_data[0].T[i]) for i in range(n)]
            print(len(e_cdf))
            new_input = np.vstack([e_cdf[i](u) for i, u in enumerate(new_input_u.T)]).T
            _f = function(*new_input.T)

            if scaler:
                X_new, y_new = new_input, scaler.transform(_f.reshape(-1, 1)).flatten()
            else:
                X_new, y_new = new_input, _f.flatten()
            X_train_, X_test_, y_train_, y_test_ = train_test_split(X_new, y_new, test_size=0.20, random_state=42)
            train_data = (np.vstack((train_data[0], X_train_)), np.concatenate((train_data[1], y_train_)))
            test_data = (np.vstack((test_data[0], X_test_)), np.concatenate((test_data[1], y_test_)))

            print(len(train_data[0]))
            print(len(test_data[0]))


        else:
            print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))
            print('|'.join(
                [""] + [("{:^" + str(len_h) + "}").format(col) for len_h, col in zip(list_len_h, cols)] + [""]))
            print('+'.join([""] + ["-" * len_h for len_h in list_len_h] + [""]))

    return clf


if __name__ == "__main__":
    ssifl(0.1, 0.001, F2D[0], 2, optimize_hp=True)
