import numpy as np


def check_bounds(function):
    def wrapper(*args, **kwargs):
        try:
            assert hasattr(args[0], '__iter__')
            _args = list(args)
            _args[0] = np.array(_args[0])
            try:
                assert len(_args[0][0]) == len(_args[0][1])
            except AssertionError:
                raise AssertionError("Lower and upper bound dimensions must"
                                     f" match. {_args[0][0]}!={_args[0][1]}")
        except AssertionError:
            try:
                assert type(args[0]) == int
                args = list(args)
                args[0] = [[0] * args[0], [1] * args[0]]
            except AssertionError:
                raise AssertionError("<bounds> argument "
                                     "format not recognised.")
        _args = list(args)
        _args[0] = np.array(_args[0])
        return function(*_args, **kwargs)

    return wrapper
