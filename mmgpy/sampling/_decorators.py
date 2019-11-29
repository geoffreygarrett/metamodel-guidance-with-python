import numpy as np


def check_bounds(function):
    def wrapper(*args, **kwargs):
        try:
            assert hasattr(args[0], '__iter__')
        except AssertionError:
            raise AssertionError("<bounds> argument format not recognised.")
        try:
            assert len(args[0][0]) == len(args[0][1])
        except AssertionError:
            raise AssertionError(f"Lower and upper bound dimensions must match. {args[0][0]}!={args[0][1]}")
        _args = list(args)
        _args[0] = np.array(_args[0])
        return function(*_args, **kwargs)

    return wrapper
