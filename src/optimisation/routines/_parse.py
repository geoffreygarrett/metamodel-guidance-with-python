from ._error import catch_empty_list
from ._error import catch_more_than_three_routines
from ._error import catch_bad_keys
from ._error import catch_bad_routine_logic
from ._error import catch_bad_type
from ._error import catch_bad_space_value
from ._error import catch_bad_static_value

from ._config import ROUTINE_NAMES
from ._config import STATIC_ARGS_TYPES
from ._config import STATIC_OPTIMIZER_KEYS
from ._config import STATIC_ROUTINE_KEYS
from ._config import DECISION_SPACE_KEYS


def parse_routine_list_to_dict(list_of_list_of_dict):
    """

    Parameters
    ----------
    list_of_list_of_dict

    Returns
    -------

    """
    length_of_list = len(list_of_list_of_dict)
    if length_of_list == 1:
        return dict(initial=list_of_list_of_dict[0],
                    intermediate=list_of_list_of_dict[0],
                    closing=None)

    elif length_of_list == 2:
        return dict(initial=list_of_list_of_dict[0],
                    intermediate=list_of_list_of_dict[1],
                    closing=None)

    elif length_of_list == 3:
        return dict(initial=list_of_list_of_dict[0],
                    intermediate=list_of_list_of_dict[1],
                    closing=list_of_list_of_dict[2])
    else:
        raise AssertionError(
            "Conversion from list of list of dicts to dict routines form"
            f"failed due to the length of list being: {length_of_list}")


def is_list_of_dict(lst):
    return all(type(item) == dict for item in lst)


def is_list_of_list_of_dict(lst):
    return all(is_list_of_dict(item) for item in lst)


def parse_routines_list(routines_list):
    try:
        assert is_list_of_dict(routines_list)
        list_of_list_of_dict = [routines_list]
    except AssertionError:
        try:
            assert is_list_of_list_of_dict(routines_list)
            list_of_list_of_dict = routines_list
        except AssertionError:
            raise AssertionError(
                "Routines argument is a list, but is neither of the"
                "accepted following forms:"
                " - list of dicts (1 routine)"
                " - list of list of dicts (>=1 routine)")

    length_of_list = len(list_of_list_of_dict)
    if length_of_list == 1:
        return dict(initial=list_of_list_of_dict[0],
                    intermediate=list_of_list_of_dict[0],
                    closing=None)

    elif length_of_list == 2:
        return dict(initial=list_of_list_of_dict[0],
                    intermediate=list_of_list_of_dict[1],
                    closing=None)

    elif length_of_list == 3:
        return dict(initial=list_of_list_of_dict[0],
                    intermediate=list_of_list_of_dict[1],
                    closing=list_of_list_of_dict[2])
    else:
        raise AssertionError(
            "Conversion from list of list of dicts to dict routines form"
            f"failed due to the length of list being: {length_of_list}")


def parse_routines(routines):
    """

    Parameters
    ----------
    routines

    Returns
    -------

    """
    if type(routines) == list:
        catch_empty_list(routines, "Routine list should not be empty.")
        catch_more_than_three_routines(routines)
        routine_dict = parse_routines_list(routines)
    elif type(routines) == dict:
        routine_dict = routines
    else:
        raise AssertionError(
            f"`routines` argument not recognized. (type={type(routines)})"
            f"If this type is iterable, and should be accepted, then"
            f"contact the developer.")
    catch_bad_keys(routine_dict, ROUTINE_NAMES, "routine")
    catch_bad_routine_logic(routine_dict)
    # self._catch_bad_subroutines(routine_dict)
    # TODO: parse subroutines.
    parsed_routine_dict = routine_dict
    return parsed_routine_dict


def is_local_static_parameter(key):
    return key[0] == "_"


def is_local_space_parameter(key):
    return key in DECISION_SPACE_KEYS


def parse_subroutine(subroutine, space_mapping):
    """

    Parameters
    ----------
    subroutine
    space_mapping

    Returns
    -------

    """
    decision_space = []
    local_static_params = {}
    for key, value in subroutine.items():
        if is_local_space_parameter(key.split("__")[0]):
            param_type, param_name = key.split("__")
            catch_bad_type(param_type, DECISION_SPACE_KEYS, desc="space")
            catch_bad_space_value(param_type, value)
            space_obj = space_mapping[param_type]
            if param_type == "categorical":
                param_space = space_obj(value, name=param_name)
            else:
                param_space = space_obj(*value, name=param_name)
            decision_space.append(param_space)

        elif is_local_static_parameter(key):
            static_key = key[1:]
            static_type, _ = static_key.split("__")
            catch_bad_type(static_type, STATIC_ARGS_TYPES, desc="static")
            catch_bad_static_value(static_key, value,
                                   STATIC_OPTIMIZER_KEYS,
                                   STATIC_ROUTINE_KEYS)
            local_static_params[static_key] = value

        else:
            raise KeyError(
                f"{key} is not a recognized subroutine key. Accepted types:"
                f"- local static parameter: _<type_static>__<sub_type>"
                f"- local decision parameter space:"
                f"  > integer__param_name"
                f"  > real__param_name"
                f"  > category__param_name")
    return local_static_params, decision_space,


def parse_static(static_params, parse_for):
    """

    Parameters
    ----------
    static_params
    parse_for

    Returns
    -------

    """
    static_keys = list(filter(lambda x: parse_for in x,
                              static_params.keys()))
    kwargs_keys = list(map(lambda x: x.split("__")[1],
                           static_keys))
    static = dict(zip(kwargs_keys,
                      [static_params[key] for key in
                       static_keys]))
    return static
