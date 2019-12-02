import numpy as np

from scipy import fftpack
import matplotlib.pyplot as plt
from .uninformed import grid_sample_domain
from plotting.util import plotFFTPeak


def dft_peaks(func, bounds, n_sample_dim, target=None, plot=False,
              rel_threshold=None,
              abs_threshold=None):
    N = np.array(n_sample_dim)
    f = func(*grid_sample_domain(bounds, N, flatten=False, endpoint=False))
    target = target if target is not None else np.arange(len(f.shape))
    X = fftpack.fftn(f, axes=target)

    freqs = []
    for n in N:
        freqs.append(fftpack.fftfreq(int(n)) * n)

    X_abs = np.abs(X)

    if len(X_abs.shape) > 1:
        X_abs = np.swapaxes(X_abs, 0, 1)

    aux = np.arange(len(X_abs.shape))
    _return_f = []
    _return_a = []

    for i in target:

        axes_to_rid = tuple(aux[aux != i])
        axes_avg = np.mean(X_abs, axis=tuple(aux[aux != i]))
        axes_avg[0] = 0  # Get rid of 0 Hz peak
        pos_bool = freqs[i] > 0
        neg_bool = freqs[i] < 0

        a = 2 / (N[i]) * axes_avg[pos_bool]

        if abs_threshold:
            a_cum_reversed = np.maximum.accumulate(a[::-1])[::-1]
            try:
                _a_val = a[a_cum_reversed <= abs_threshold][0]
            except IndexError:
                _a_val = a[-1]
            _f_val = freqs[i][pos_bool][a == _a_val][0]

        elif rel_threshold:
            a_cum_reversed = np.maximum.accumulate(a[::-1])[::-1]
            try:
                _a_val = a[a_cum_reversed <= rel_threshold * np.max(a)][0]
            except IndexError:
                _a_val = a[-1]
            _f_val = freqs[i][pos_bool][a == _a_val][0]


        elif abs_threshold and rel_threshold:
            a_cum_reversed = np.maximum.accumulate(a[::-1])[::-1]
            try:
                a1 = a[a_cum_reversed <= rel_threshold * np.max(a)][0]
            except IndexError:
                a1 = a[-1]
            try:
                a2 = a[a_cum_reversed <= abs_threshold][0]
            except IndexError:
                a2 = a[-1]
            _a_val = np.min([a1, a2])
            _f_val = freqs[i][pos_bool][a == _a_val][0]

        else:
            _a_val = np.max(a)
            _f_val = freqs[i][pos_bool][a == _a_val][0]

        _return_f.append(_f_val)
        _return_a.append(_a_val)

        if plot:
            plotFFTPeak(freqs[i][pos_bool], a)

    return tuple([np.array(_return_f), np.array(_return_a)])


def dft_peaks_1(func, bounds, n_sample_dim, target=None, plot=False,
                rel_threshold=None,
                abs_threshold=None):

    N = np.array(n_sample_dim)
    f = func(*grid_sample_domain(bounds, N, flatten=False, endpoint=False))
    target = target if target is not None else np.arange(len(f.shape))
    X = fftpack.fftn(f, axes=target)

    freqs = []
    for n in N:
        freqs.append(fftpack.fftfreq(int(n)) * n)

    X_abs = np.abs(X)

    if len(X_abs.shape) > 1:
        X_abs = np.swapaxes(X_abs, 0, 1)

    aux = np.arange(len(X_abs.shape))
    _return_f = []
    _return_a = []

    H_a = None
    H_f = None

    for i in target:

        axes_to_rid = tuple(aux[aux != i])
        axes_avg = np.mean(X_abs, axis=axes_to_rid)
        axes_avg[0] = 0  # Get rid of 0 Hz peak
        pos_bool = freqs[i] > 0
        neg_bool = freqs[i] < 0

        a = 2 / (N[i]) * axes_avg[pos_bool]

        H_a = np.concatenate((H_a, [a]), axis=0) if H_a is not None else np.array([a])
        H_f = np.concatenate((H_f, [freqs[i][pos_bool]]), axis=0) if H_f is not None else np.array([freqs[i][pos_bool]])

        if abs_threshold:
            a_cum_reversed = np.maximum.accumulate(a[::-1])[::-1]
            try:
                _a_val = a[a_cum_reversed <= abs_threshold][0]
            except IndexError:
                _a_val = a[-1]
            _f_val = freqs[i][pos_bool][a == _a_val][0]

        elif rel_threshold:
            a_cum_reversed = np.maximum.accumulate(a[::-1])[::-1]
            try:
                _a_val = a[a_cum_reversed <= rel_threshold * np.max(a)][0]
            except IndexError:
                _a_val = a[-1]
            _f_val = freqs[i][pos_bool][a == _a_val][0]

        elif abs_threshold and rel_threshold:
            a_cum_reversed = np.maximum.accumulate(a[::-1])[::-1]
            try:
                a1 = a[a_cum_reversed <= rel_threshold * np.max(a)][0]
            except IndexError:
                a1 = a[-1]
            try:
                a2 = a[a_cum_reversed <= abs_threshold][0]
            except IndexError:
                a2 = a[-1]
            _a_val = np.min([a1, a2])
            _f_val = freqs[i][pos_bool][a == _a_val][0]

        else:
            _a_val = np.max(a)
            _f_val = freqs[i][pos_bool][a == _a_val][0]

        _return_f.append(_f_val)
        _return_a.append(_a_val)

        if plot:
            plotFFTPeak(freqs[i][pos_bool], a)

    #     print(H_f)
    #     print(H_f.shape)
    #     print(freqs[0][pos_bool].shape)
    #     print(np.array(_return_f).shape)
    #     print(freqs[0][pos_bool][freqs[0][pos_bool]==np.array(_return_f)])
    H = H_a[:, np.isin(freqs[0][pos_bool], np.array(_return_f))]
    print(H)
    u, s, vh = np.linalg.svd(H, full_matrices=True, compute_uv=True, hermitian=False)
    print(H_a.shape)
    print(u)
    print(s)
    print(vh)
    print(vh.shape)
    return tuple([np.array(_return_f), np.array(_return_a)])


import itertools


def bounds2vertices(bounds):
    return np.array(list(itertools.product(*np.array(bounds).T)))


def matmul_grid2D(e_v, e_grid):
    e_x_grid = np.zeros(e_grid.shape)
    e_x_grid[0] = e_v[0, 0] * e_grid[0] + e_v[0, 1] * e_grid[1]
    e_x_grid[1] = e_v[1, 0] * e_grid[0] + e_v[1, 1] * e_grid[1]
    return e_x_grid


def e_grid(bounds, N, e_v, flatten=False, endpoint=False):
    # Generate eigen space vertices from original bounds.
    e_vertices = np.matmul(np.linalg.inv(e_v), bounds2vertices(bounds).T).T
    e_bounds = np.array([np.min(e_vertices, axis=0), np.max(e_vertices, axis=0)])
    e_grid = grid_sample_domain(e_bounds,  # Generate meshgrid if init
                                N,
                                flatten=flatten,
                                endpoint=endpoint)
    return e_grid


def dft_peaks2(function, bounds,
               n_sample_dim,
               rel_threshold=None,
               abs_threshold=None,
               dft_basis=None,
               plot=False):
    # Pre-preparative coding tid bits.
    N = np.array(n_sample_dim)  # Ensure N is a numpy array.
    if dft_basis is not None:
        meshgrid = e_grid(bounds,  # Generate meshgrid if init
                          N,
                          dft_basis,
                          flatten=False,
                          endpoint=False)
        meshgrid = matmul_grid2D(np.linalg.inv(dft_basis), meshgrid)

    else:
        meshgrid = grid_sample_domain(bounds,  # Generate meshgrid if init
                                      N,
                                      flatten=False,
                                      endpoint=False)

    f = function(*meshgrid)
    f_range = np.max(f) - np.min(f)
    target = np.arange(len(f.shape))

    # Perform n dimensional DFT on target axes
    X = fftpack.fftn(f, axes=target)
    X_abs = np.abs(X)

    # X_1 = np.abs(fftpack.fftn(f, axes=(0)))
    # X_2 = np.abs(fftpack.fftn(f, axes=(1)))

    # Generate frequency spectrum for sample rate of each dimension.
    freqs = [fftpack.fftfreq(int(n)) * n for n in N]

    # Post preparative coding tid bits.
    a_pos_per_x = []  # Amplitude history per input dimension.
    f_pos_per_x = []  # Frequency history per input dimension.
    a_pos_exceeded_per_x = []  # Amplitude history per input dimension.
    f_pos_exceeded_per_x = []  # Frequency history per input dimension.
    aux = np.arange(len(X_abs.shape))  # Index set {0, 1, ..., n_dim}

    #     X_abs = np.swapaxes(X_abs, 0, 1) if len(X_abs.shape) > 1 else X_abs
    # Swaps axes 0 and 1 (for numpy convention of dealing with arrays)
    # test_lam = lambda x: 0 if x is 1 else 1 if x is 0 else x

    #     print(X_abs)
    # def f__(freqs, N, X_abs):
    #     mg = np.meshgrid(*freqs)
    #     X_abs[mg[0] == 0] == 0
    #     X_abs[mg[1] == 0] == 0
    #     _x = mg[0][(mg[0] > 0) & (mg[1] > 0)]
    #     _y = mg[1][(mg[0] > 0) & (mg[1] > 0)]
    #     _z = X_abs[(mg[0] > 0) & (mg[1] > 0)] / N
    #     print(_x.shape)
    #     print(_y.shape)
    #     print(_z.shape)
    #     sq = int(np.sqrt(_z.shape[0]))
    #     plot_z_grids(_x.reshape(sq, sq), _y.reshape(sq, sq), _z.reshape(sq, sq))
    #
    # f__(freqs, np.product(N), X_abs)
    # f__(freqs, 1, X_1)
    # f__(freqs, 1, X_2)

    for i in target:

        # Determine the one dimensional spectral analysis.
        axes_to_rid = tuple(aux[aux != i])
        axes_avg = np.mean(X_abs, axis=axes_to_rid)
        axes_avg[0] = 0  # Get rid of 0 Hz peak

        pos_bool = freqs[i] > 0
        neg_bool = freqs[i] < 0

        a_pos = 2 / (N[i]) * axes_avg[pos_bool]
        f_pos = freqs[i][pos_bool]
        a_pos_per_x.append(a_pos)
        f_pos_per_x.append(f_pos)

        # Threshold present.
        if abs_threshold or rel_threshold:
            if abs_threshold and not rel_threshold:
                threshold = abs_threshold
            elif rel_threshold and not abs_threshold:
                threshold = f_range * rel_threshold
            elif abs_threshold and rel_threshold:
                threshold = np.min([abs_threshold, f_range * rel_threshold])
            a_pos_exceeded_x_i = a_pos[a_pos >= threshold]
            f_pos_exceeded_x_i = f_pos[a_pos >= threshold]

        # Max amplitude convergence.
        else:
            raise Warning(
                f"""
            dft_peaks functionally required either:
                - relative threshold (rel_threshold)
                - absolute threshold (abs_threshold)

            But these arguments were found to be:
                - rel_threshold = {rel_threshold}
                - abs_threshold = {abs_threshold}

            The algorithm will converge to the maximum 
            deteced amplitude per x, by default.""")
            a_pos_exceeded_x_i = a_pos[a_pos == np.max(a_pos)]
            f_pos_exceeded_x_i = f_pos[a_pos == np.max(a_pos)]

        f_pos_exceeded_per_x.append(f_pos_exceeded_x_i)
        a_pos_exceeded_per_x.append(a_pos_exceeded_x_i)

        if plot:
            plotFFTPeak(f_pos, a_pos)

    available_f_throughout = np.intersect1d(*f_pos_per_x)
    intersection_violated_f = np.intersect1d(*f_pos_exceeded_per_x)
    all_violated_f = np.union1d(*f_pos_exceeded_per_x)

    if set(all_violated_f).issubset(set(available_f_throughout)):
        # Construct H matrix for SVD.
        H = np.vstack([a_i[np.isin(f_i, all_violated_f)] for a_i, f_i in zip(a_pos_per_x, f_pos_per_x)])
        A = H[:, np.argsort(np.max(H, axis=0))[::-1][:len(bounds[0])]]

    else:
        #         raise Warning(
        #         f"""
        #         All violated signal components are not available for all x.

        #         The following frequencies are not common throughout:
        #         {np.setdiff1d(all_violated_f, available_f_throughout)}
        #         """)
        H = np.vstack([a_i[np.isin(f_i, intersection_violated_f)] for a_i, f_i in zip(a_pos_per_x, f_pos_per_x)])
        A = H[:, np.argsort(np.max(H, axis=0))[::-1][:len(bounds[0])]]

    return H, A, f_pos_exceeded_per_x


def svd(H):
    U = []
    S = []
    VH = []
    for h in H.T:
        u, s, vh = np.linalg.svd(h.reshape(-1, 1), full_matrices=True, compute_uv=True, hermitian=False)
        U.append(u)
        S.append(s)
        VH.append(vh)
    U, S, VH = [np.array(i) for i in [U, S, VH]]
    return (np.concatenate(U.reshape(-1, *U.shape), axis=0),
            np.concatenate(S.reshape(-1, *S.shape), axis=0),
            np.concatenate(VH.reshape(-1, *VH.shape), axis=0))


def base_analysis(function, bounds, N_init_mag=3, maxiter=70, verbose=False,
                  rel_threshold=None,
                  abs_threshold=None):
    try:
        assert N_init_mag >= 3
    except AssertionError:
        raise AssertionError("N_init_mag must be greater or equal to 3.")
    ret = None
    n_inc = maxiter
    N_init = np.ones(len(bounds[0])) * N_init_mag
    previous_mag = np.ones(len(N_init))
    mag_hist = []

    for i in range(n_inc):

        print(i) if i % 10 == 0 and verbose else None

        N_ = N_init + i

        freqs, mag = dft_peaks(function, bounds, N_,
                               abs_threshold=abs_threshold,
                               rel_threshold=rel_threshold)

        mag_hist.append(mag)

        previous_mag = mag

        if ret is None:
            ret = np.array(freqs).reshape(1, -1)

        else:
            ret = np.concatenate((ret, np.array(freqs).reshape(1, -1)), axis=0)

    plt.figure(figsize=(5, 3), dpi=300)
    plt.gcf().patch.set_facecolor('0.95')
    plt.minorticks_on()
    plt.grid(which='major', linewidth=0.5)
    plt.grid(which='minor', linewidth=0.1)
    plt.title("Frequency ($f$) Reproduction Required")
    plt.ylabel("$f\;\;[1/T]$")
    plt.xlabel("$N_s\;\;[-]$")
    plt.plot(np.array(list(range(n_inc))) + 5, ret)
    plt.show()

    plt.figure(figsize=(5, 3), dpi=300)
    plt.gcf().patch.set_facecolor('0.95')
    plt.minorticks_on()
    plt.grid(which='major', linewidth=0.5)
    plt.grid(which='minor', linewidth=0.1)
    plt.title("Corresponding Magnitude ($A$)")
    plt.ylabel("$A\;\;[-]$")
    plt.xlabel("$N_s\;\;[-]$")
    plt.plot(np.array(list(range(n_inc))) + 5, mag_hist)
    plt.show()

    # plt.figure(figsize=(5, 3), dpi=300)
    # plt.gcf().patch.set_facecolor('0.95')
    # plt.minorticks_on()
    # plt.grid(which='major', linewidth=0.5)
    # plt.grid(which='minor', linewidth=0.1)
    # plt.plot(np.array(list(range(1, n_inc))) + 5, np.diff(ret, axis=0))
    # plt.show()
