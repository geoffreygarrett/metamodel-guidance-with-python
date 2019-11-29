import numpy as np
from ._decorators import check_bounds
from ._halton import halton as __halton
from ._cvt import CVT
from tqdm import tqdm_notebook as tqdm


def _grid_auxiliary(grids_1d, flatten, form, *args):
    _return = np.array(np.meshgrid(*grids_1d, indexing='ij'))
    _dim = len(_return)
    if flatten:
        _return = np.array([_return_i.flatten() for _return_i in _return.reshape(_dim, -1)])
        if form is "sx":
            _return = _return.T
        elif form is "xs":
            _return = _return
        else:
            raise ValueError("<form> argument not recognised.")
    return _return


@check_bounds
def _uniform_grid(bounds, n_sample, flatten=True, edges=False, form="sx", *args):
    if edges:
        start = bounds[0]
        end = bounds[1]
    else:
        width = (bounds[1] - bounds[0]) / n_sample
        start = bounds[0] + 0.5 * width
        end = bounds[1] - 0.5 * width
    grids_1d = [np.linspace(start[i], end[i], n_sample, endpoint=True) for i in range(len(bounds[0]))]
    return _grid_auxiliary(grids_1d, flatten, form)


@check_bounds
def _full_factorial(bounds, n_sample_tuple, flatten=True, edges=False, form="sx", *args):
    if edges:
        start = bounds[0]
        end = bounds[1]
    else:
        width = (bounds[1] - bounds[0]) / np.array(n_sample_tuple)
        start = bounds[0] + 0.5 * width
        end = bounds[1] - 0.5 * width
    grids_1d = [np.linspace(start[i], end[i], n_sample_tuple[i], endpoint=True) for i in
                range(len(bounds[0]))]
    return _grid_auxiliary(grids_1d, flatten, form)


@check_bounds
def _halton(bounds, n_sample, form="sx", *args):
    bounds = np.array(bounds)
    halton_sample = __halton(len(bounds[0]), n_sample)
    _return = (halton_sample * (bounds[1, :] - bounds[0, :]) + bounds[0, :])
    if form is "sx":
        _return = _return
    elif form is "xs":
        _return = _return.T
    else:
        raise ValueError("<form> argument not recognised.")
    return _return


@check_bounds
def _random_uniform(bounds, n_sample, seed=None, form="sx", *args):
    np.random.seed(seed)
    _return = np.random.uniform(bounds[0], bounds[1], (n_sample, len(bounds[0])))
    if form is "sx":
        _return = _return
    elif form is "xs":
        _return = _return.T
    else:
        raise ValueError("<form> argument not recognised.")
    return _return


def _multivariate_normal(mean, covariance, n_sample, seed=None, form="sx"):
    np.random.seed(seed)
    _return = (np.random.multivariate_normal(mean, cov=covariance, size=n_sample))
    if form is "sx":
        _return = _return
    elif form is "xs":
        _return = _return.T
    else:
        raise ValueError("<form> argument not recognised.")
    return _return


def _cvt(xdim, gdim, initialize, sample, sample_num, iterations, seed, form="sx"):
    """

    :param xdim:
    :param gdim:
    :param seed:
    :param initialize:
    :param sample:
    :param sample_num:
    :param iterations:
    :param form:
    :return:
    """
    bounds = [[0] * xdim, [1] * xdim]
    cvt = CVT(bounds, k=gdim, z_sample_method=initialize)
    iterations = tqdm(range(iterations), desc="Iterating CVT", leave=False)
    for _ in iterations:
        y = sample(bounds, sample_num, seed=seed, form="sx")
        cvt._iterate(y)
    _return = cvt._z
    iterations.close()
    iterations.clear()
    if form is "sx":
        _return = _return
    elif form is "xs":
        _return = _return.T
    else:
        raise ValueError("<form> argument not recognised.")
    return _return


if __name__ == "__main__":
    form_test = 'sx'
    print(_full_factorial([[0, 0], [1, 1]], (20, 3), flatten=True, form=form_test))
    print(_halton([[0, 0], [1, 1]], 5, form=form_test))
    print(_random_uniform([[0, 0], [1, 1]], 5, form=form_test))
    print(_multivariate_normal(np.array([0.5, 0.5]), np.array([[1, 0], [0, 1]]), 5, form=form_test))
    print(_cvt(xdim=3, gdim=20, initialize=_halton, sample=_random_uniform, sample_num=1000, iterations=5, seed=123,
               form=form_test))
