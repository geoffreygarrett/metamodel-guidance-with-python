import numpy as np
from ._sampling import _uniform_grid
from ._sampling import _full_factorial
from ._sampling import _halton
from ._sampling import _random_uniform
from ._sampling import _multivariate_normal
from ._sampling import _cvt


def uniform_grid(bounds, n_sample, flatten=True, edges=False, form="sx"):
    """Uniform Grid (UG).
    Uniform grid (UG) is the simplest sampling method in which the samples are created using node points at fixed
    intervals uniformly distributed for every dimension.

    Notes:
    The coverage of the input space using UG is very poor for low number of sampling points and high dimensions.
    :param bounds:
    :param n_sample:
    :param flatten:
    :param edges:
    :param components_across: Ignored if flatten=True.
    :return:
    """
    return _uniform_grid(bounds, n_sample, flatten, edges, form)


def full_factorial(bounds, n_sample_tuple, flatten=True, edges=True, form="sx"):
    """ Custom Grid (CG).
    This Grid method is the sample as the UG method, but allows for non-uniform grid sampling.

    Notes:
    The coverage of the input space using CG is very poor for low number of sampling points and high dimensions.
    :param bounds:
    :param n_sample_tuple:
    :param flatten:
    :param edges:
    :param components_across: Ignored if flatten=True.
    :return:
    """
    return _full_factorial(bounds, n_sample_tuple, flatten, edges, form)


def halton(bounds, n_sample, form="sx"):
    """

    :param bounds:
    :param n_sample:
    :param components_across:
    :return:
    """
    return _halton(bounds, n_sample, form)


def multivariate_normal(mean, covariance, n_sample, seed=None, form="sx"):
    """

    :param mean:
    :param covariance:
    :param n_sample:
    :param seed:
    :param components_across:
    :return:
    """
    return _multivariate_normal(mean, covariance, n_sample, seed, form)


def random_uniform(bounds, n_sample, seed=None, form="sx"):
    """

    :param bounds:
    :param n_sample:
    :param seed:
    :param form:
    :return:
    """
    return _random_uniform(bounds, n_sample, seed, form)


def cvt(xdim, gdim, initialize, sample, sample_num, iterations, seed=None, form="sx"):
    """

    :param xdim:
    :param gdim:
    :param initialize:
    :param sample:
    :param sample_num:
    :param iterations:
    :param seed:
    :param form:
    :return:
    """
    return _cvt(xdim, gdim, initialize, sample, sample_num, iterations, seed, form)


if __name__ == "__main__":
    pass
