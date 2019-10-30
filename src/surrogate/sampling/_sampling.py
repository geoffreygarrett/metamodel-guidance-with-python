import numpy as np
from ._decorators import check_bounds
from ._halton import halton as __halton


def _grid_auxiliary(grids_1d, flatten, components_across):
    _return = np.array(np.meshgrid(*grids_1d, indexing='ij'))
    _dim = len(_return)
    if flatten:
        _return = np.array([_return_i.flatten() for _return_i in _return.reshape(_dim, -1)])
        if components_across is "row":
            _return = _return.T
        elif components_across is "col":
            _return = _return
        else:
            raise ValueError("<components_across> argument not recognised.")
    return _return


@check_bounds
def _uniform_grid(bounds, n_sample, flatten=True, edges=False, components_across="col"):
    if edges:
        start = bounds[0]
        end = bounds[1]
    else:
        width = (bounds[1] - bounds[0]) / n_sample
        start = bounds[0] + 0.5 * width
        end = bounds[1] - 0.5 * width
    grids_1d = [np.linspace(start[i], end[i], n_sample, endpoint=True) for i in range(len(bounds[0]))]
    return _grid_auxiliary(grids_1d, flatten, components_across)


@check_bounds
def _full_factorial(bounds, n_sample_tuple, flatten=True, edges=False, components_across="col"):
    if edges:
        start = bounds[0]
        end = bounds[1]
    else:
        width = (bounds[1] - bounds[0]) / np.array(n_sample_tuple)
        print(np.array(n_sample_tuple))
        print(width)
        start = bounds[0] + 0.5 * width
        end = bounds[1] - 0.5 * width
    grids_1d = [np.linspace(start[i], end[i], n_sample_tuple[i], endpoint=True) for i in
                range(len(bounds[0]))]
    return _grid_auxiliary(grids_1d, flatten, components_across)


@check_bounds
def _halton(bounds, n_sample, components_across="row"):
    bounds = np.array(bounds)
    halton_sample = __halton(len(bounds[0]), n_sample)
    _return = (halton_sample * (bounds[1, :] - bounds[0, :]) + bounds[0, :])
    if components_across is "col":
        _return = _return.T
    elif components_across is "row":
        _return = _return
    else:
        raise ValueError("<components_across> argument not recognised.")
    return _return


@check_bounds
def _random_uniform(bounds, n_sample, seed=None, components_across="row"):
    np.random.seed(seed)
    _return = np.random.uniform(bounds[0], bounds[1], (n_sample, len(bounds[0])))
    if components_across is "col":
        _return = _return.T
    elif components_across is "row":
        _return = _return
    else:
        raise ValueError("<components_across> argument not recognised.")
    return _return


def _multivariate_normal(mean, covariance, n_sample, seed=None, components_across="row"):
    np.random.seed(seed)
    _return = (np.random.multivariate_normal(mean, cov=covariance, size=n_sample))
    if components_across is "col":
        _return = _return.T
    elif components_across is "row":
        _return = _return
    else:
        raise ValueError("<components_across> argument not recognised.")
    return _return


if __name__ == "__main__":
    print(_full_factorial([[0, 0], [1, 1]], (20, 3), flatten=True, components_across="row"))
    print(_halton([[0, 0], [1, 1]], 5, components_across="row"))
    print(_random_uniform([[0, 0], [1, 1]], 5, components_across="row"))
    print(_multivariate_normal(np.array([0.5, 0.5]), np.array([[1, 0], [0, 1]]), 5, components_across="row"))
