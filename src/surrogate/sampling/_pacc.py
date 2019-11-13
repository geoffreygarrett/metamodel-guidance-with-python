import numpy as np


def s_pacc(epsilon, delta):
    return 1 / (2 * epsilon ** 2) * np.log(2. / delta)


def s_diego(n, i):
    # TODO: Case where i=1, 1 is returned, which does not play well with Torch batch_size.
    return i ** n if n <= 9 else 10 ** i


def s_val_diego(n, epsilon, delta):
    _s_pacc = s_pacc(epsilon, delta)
    _s_val = None
    if n <= 9:
        _s_val = np.int(_s_pacc ** (1 / n)) + 1

    elif n >= 10:
        _s_val = np.int(np.log10(_s_pacc)) + 1
    return _s_val
