import numpy as np


def s_pacc(epsilon, delta):
    """
    Minimum number of samples for assessing Chebyshev inequality.

    Parameters
    ----------
    epsilon : float
        Accuracy desired [0.0, 1.0].
    delta : float
        Confidence level (1 - delta) desired [0.0, 1.0].

    Returns
    -------
    s_num_min : int
        Minimum number of samples for assessing Chebyshev inequality.

    References
    ----------

    """
    return 1 / (2 * epsilon ** 2) * np.log(2. / delta)


def s_num_diego(n, idx):
    """


    Parameters
    ----------
    n : int
        Input dimension for function.
    idx : int
        Sequence index to be sampled.

    Returns
    -------

    References
    ----------

    """
    return idx ** n if n <= 9 else 10 ** idx


def s_idx_diego(n, s_min):
    """

    Parameters
    ----------
    n
    s_min

    Returns
    -------

    """
    _s_val = None
    if n <= 9:
        _s_val = np.int(s_min ** (1 / n)) + 1

    elif n >= 10:
        _s_val = np.int(np.log10(s_min)) + 1
    return np.max([2, _s_val])


def s_diego(n, idx):
    # TODO: Deprecate s_diego
    """


    Parameters
    ----------
    n : int
        Input dimension for function.
    idx : int
        Sequence index to be sampled.

    Returns
    -------

    References
    ----------

    """
    return idx ** n if n <= 9 else 10 ** idx


def s_val_diego(n, epsilon, delta):
    # TODO: Deprecate s_val_diego
    """

    Parameters
    ----------
    n
    epsilon
    delta

    Returns
    -------

    """
    # raise DeprecationWarning("Will be removed.")

    _s_pacc = s_pacc(epsilon, delta)
    _s_val = None
    if n <= 9:
        _s_val = np.int(_s_pacc ** (1 / n)) + 1

    elif n >= 10:
        _s_val = np.int(np.log10(_s_pacc)) + 1
    return _s_val
