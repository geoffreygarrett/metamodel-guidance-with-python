import numpy as np
from ._sampling import _uniform_grid
from ._sampling import _custom_grid
from ._sampling import _halton
from ._sampling import _random_uniform
from ._sampling import _multivariate_normal


def uniform_grid(bounds, n_sample, flatten=True, endpoint=True, components_across="row"):
    """Uniform Grid (UG).
    Uniform grid (UG) is the simplest sampling method in which the samples are created using node points at fixed
    intervals uniformly distributed for every dimension.

    Notes:
    The coverage of the input space using UG is very poor for low number of sampling points and high dimensions.
    :param bounds:
    :param n_sample:
    :param flatten:
    :param endpoint:
    :param components_across: Ignored if flatten=True.
    :return:
    """
    return _uniform_grid(bounds, n_sample, flatten, endpoint, components_across)


def custom_grid(bounds, n_sample_tuple, flatten=True, endpoint=True, components_across="row"):
    """ Custom Grid (CG).
    This Grid method is the sample as the UG method, but allows for non-uniform grid sampling.

    Notes:
    The coverage of the input space using CG is very poor for low number of sampling points and high dimensions.
    :param bounds:
    :param n_sample_tuple:
    :param flatten:
    :param endpoint:
    :param components_across: Ignored if flatten=True.
    :return:
    """
    return _custom_grid(bounds, n_sample_tuple, flatten=True, endpoint=True, components_across="row")


def halton(bounds, n_sample, components_across="row"):
    """

    :param bounds:
    :param n_sample:
    :param components_across:
    :return:
    """
    return _halton(bounds, n_sample, components_across)


def multivariate_normal(mean, covariance, n_sample, seed=None, components_across="row"):
    """

    :param mean:
    :param covariance:
    :param n_sample:
    :param seed:
    :param components_across:
    :return:
    """
    return _multivariate_normal(mean, covariance, n_sample, seed, components_across)


def random_uniform(bounds, n_sample, seed=None, components_across="row"):
    """

    :param bounds:
    :param n_sample:
    :param seed:
    :param components_across:
    :return:
    """
    return _random_uniform(bounds, n_sample, seed, components_across)

def cvt(bounds, n_sample, seed=None, components_across="row"):
    pass
