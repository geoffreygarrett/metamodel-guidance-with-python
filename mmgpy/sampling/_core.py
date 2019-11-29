import numpy as np
from ._sampling import _uniform_grid
from ._sampling import _full_factorial
from ._sampling import _halton
from ._sampling import _random_uniform
from ._sampling import _multivariate_normal
from ._sampling import _cvt

"""
**GEOMETRIC**
"""


def uniform_grid(bounds, n_sample, flatten=True, edges=False, form="sx",
                 **kwargs):

    """**Uniform Grid (UG)**:
    Uniform grid (UG) is the simplest sampling method in which the
    samples are created using node points at fixed intervals uniformly
    distributed for every dimension.

    Parameters
    ----------
    bounds
    n_sample
    flatten
    edges
    form
    kwargs

    Notes
    -----
    * The coverage of the input space using UG is very poor for low
      number of sampling points and high dimensions.

    Returns
    -------

    """
    """


    :param bounds:
    :param n_sample:
    :param flatten:
    :param edges:
    :param components_across: Ignored if flatten=True.
    :return:
    """
    return _uniform_grid(bounds, n_sample, flatten, edges, form)


def full_factorial(bounds, n_sample_tuple, flatten=True, edges=True,
                   form="sx", **kwargs):
    """**Custom Grid (CG)**:
    This Grid method is the sample as the UG method, but allows for
    non-uniform grid sampling.

    Parameters
    ----------
    bounds
    n_sample_tuple
    flatten
    edges
    form
    kwargs

    Notes
    -----
    * The coverage of the input space using CG is very poor for low
      number of sampling points and high dimensions.

    Returns
    -------

    """
    return _full_factorial(bounds, n_sample_tuple, flatten, edges, form)


def halton(bounds, n_sample, form="sx", **kwargs):
    """**Halton**:

    Parameters
    ----------
    bounds
    n_sample
    form
    kwargs

    Returns
    -------

    """
    return _halton(bounds, n_sample, form)


def multivariate_normal(mean, covariance, n_sample, seed=None, form="sx"):
    """**Multivariate Normal**:

    Parameters
    ----------
    mean
    covariance
    n_sample
    seed
    form

    Returns
    -------

    """
    return _multivariate_normal(mean, covariance, n_sample, seed, form)


def random_uniform(bounds, n_sample, seed=None, form="sx", **kwargs):
    """**Random Uniform**:

    Parameters
    ----------
    bounds
    n_sample
    seed
    form
    kwargs

    Returns
    -------

    """
    return _random_uniform(bounds, n_sample, seed, form)


def cvt(xdim, gdim, initialize=halton, sample=random_uniform, sample_num=1000,
        iterations=5, seed=None,
        form="sx", **kwargs):
    """**Centroidal Voronoi Tessellation**:

    Parameters
    ----------
    xdim
    gdim
    initialize
    sample
    sample_num
    iterations
    seed
    form
    kwargs

    Returns
    -------

    """
    return _cvt(xdim, gdim, initialize, sample, sample_num, iterations, seed,
                form)
