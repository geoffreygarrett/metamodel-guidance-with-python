import numpy as np
from ._halton import *


def grid_sample_domain(bounds, n_sample_dim, flatten=True, endpoint=True):
    assert len(bounds[0]) == len(bounds[1])
    if type(n_sample_dim) is int:
        linspace = [np.linspace(bounds[0][i], bounds[1][i], n_sample_dim, endpoint=endpoint) for i in
                    range(len(bounds[0]))]
    elif hasattr(n_sample_dim, '__iter__'):
        try:
            assert len(n_sample_dim) == len(bounds[0])
        except AssertionError:
            raise AssertionError(f"Length of n_sample_dim not correct {len(n_sample_dim)}!={len(bounds[1])}")
        linspace = [np.linspace(bounds[0][i], bounds[1][i], n_sample_dim[i], endpoint=endpoint) for i in
                    range(len(bounds[0]))]
    _return = np.array(np.meshgrid(*linspace, indexing='ij'))
    _return = np.array(
        [_return_i.flatten() for _return_i in _return.reshape(len(bounds[0]), -1)]).T if flatten else _return
    return _return


def random_uniform_sample_domain(bounds, n_samples, seed=101):
    np.random.seed(seed)
    return np.random.uniform(bounds[0], bounds[1], (n_samples, len(bounds[0])))


def halton_sample_domain(bounds, n_samples):
    dim = len(bounds[0])
    bounds = np.array(bounds)
    halton_sample = halton(dim, n_samples)
    return halton_sample * (bounds[1, :] - bounds[0, :]) + bounds[0, :]


def multivariate_normal_sample_point(point, covariance, size, seed=101):
    np.random.seed(seed)
    return np.random.multivariate_normal(point, cov=covariance, size=size)


if __name__ == "__main__":
    pass
