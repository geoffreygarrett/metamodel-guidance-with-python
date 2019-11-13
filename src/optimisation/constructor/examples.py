import numpy as np


def rs_bicycle_constructor(x, v0=0, t0=0, velocity_limit=10, duration=200):
    _x = x.T
    # _x = x
    if len(_x) % 2 == 0:
        if len(_x) != 2:
            _v = np.concatenate(([v0], _x[:len(_x) // 2])) * velocity_limit
            _t = np.cumsum((np.concatenate(([t0], _x[len(_x) // 2:] + 0.01))))
            _t = (_t / np.max(_t)) * duration
        else:
            _v = _x * velocity_limit
            _t = np.array([0, 1]) * duration
    elif len(_x) == 3:
        _v = np.concatenate(([v0], _x[:2])) * velocity_limit
        _t = np.array([t0, 0.01 + _x[-1], 1.01]) * duration
    else:
        raise AssertionError("Nx not recognised.")
    return np.vstack((_t, _v)).T
