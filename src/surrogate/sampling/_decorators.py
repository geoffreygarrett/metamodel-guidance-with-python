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
        return function(*args, **kwargs)

    return wrapper
