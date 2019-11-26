import warnings
import inspect


def catch_bad_keys(dictionary, keys_accepted, name):
    """

    Parameters
    ----------
    dictionary : [dict]
    keys_accepted : [list]
    name : [str, optional]

    Returns
    -------


    """
    # Catch wrongly named key(s).
    bad_keys = []
    for key in dictionary.keys():
        if key not in keys_accepted:
            bad_keys.append(key)

    # Error response for one key incorrect.
    if len(bad_keys) == 1:
        raise KeyError(f"{bad_keys[0]} is not a valid {name} key.")

    # Error response for multiple incorrect keys.
    elif len(bad_keys) > 1:
        raise KeyError(
            f"The Following keys are not valid {name} keys: \n{bad_keys}")


def catch_empty_list(list_to_check, desc=None):
    try:
        assert len(list_to_check) > 0
    except AssertionError:

        if desc is not None:
            raise AssertionError(desc)
        else:
            raise AssertionError("List should not be empty.")


# Routine specific.
def catch_more_than_three_routines(routines):
    try:
        assert len(routines) <= 3
    except AssertionError:
        raise AssertionError("Routines list contains more than three"
                             "items (initial, intermediate, closing).")


def catch_bad_routine_logic(routines):
    take_instead = None
    # Check if intermediate routine present (minimum requirement).
    try:
        assert "intermediate" in routines.keys()
    except AssertionError:
        # Try take initial as intermediate (if defined).
        # Raises warning about initial being taken as intermediate if
        # try succeeds.
        try:
            assert "initial" in routines.keys()
            take_instead = "initial"

        # Try take closing as intermediate AND initial (raises Warning
        # as the closing routine is the only optional).
        except AssertionError:
            try:
                assert "closing" in routines.keys()
                take_instead = "closing"

            # If no intermediate, closing, or initial is found, then
            # raise an assertion error. Note: This should never happen
            # when _catch_bad_routine_logic is preceded by
            # _catch_bad_keys.
            except AssertionError:
                raise AssertionError(
                    "intermediate routine was not defined. "
                    "Tried initial or closing but they weren't found.")
            finally:
                routines["initial"] = routines["closing"]
                warnings.warn(
                    "The only routine found was closing, the initial"
                    "routine is being taken as the closing routine.")
        finally:
            routines["intermediate"] = routines[take_instead]
            warnings.warn(
                "intermediate routine not explicitly defined."
                f" The {take_instead} routine was used in its place.")

    # Finally, if intermediate is defined, check if initial is defined.
    # if it is not, initial is taken as intermediate for maintaining
    # the framework consistency of the class (normal operation).
    finally:
        try:
            assert "initial" in routines.keys()
        except AssertionError:
            routines["initial"] = routines["intermediate"]


def catch_bad_type(name, available_types, desc="space"):
    try:
        assert name in available_types
    except AssertionError:
        raise KeyError(
            f"{name} is not in one of the accepted {desc} types:"
            f"\n{available_types}")


def catch_bad_space_value(space_type, space_value):
    try:
        if space_type is "real":
            assert type(space_value) is tuple and len(space_value) == 2
        elif space_type is "integer":
            assert type(space_value) is tuple and len(space_value) == 2
        elif space_type is "categorical":
            assert type(space_value) is list
    except AssertionError:
        raise AssertionError(
            f"{space_value} is not valid value type for {space_type}."
            f"- real : tuple of floats, size(2)"
            f"- integer : tuple of ints, size(2)"
            f"- categorical : list of any")


def catch_bad_static_value(static_key, static_value,
                           available_minimizer_keys,
                           available_subroutine_keys):
    static_type, static_arg = static_key.split("__")

    try:
        if static_type is "function":
            # TODO: Make non-staticmethod and retrieve function sig.
            pass
        elif static_type is "minimizer":
            assert static_arg in available_minimizer_keys
        elif static_type is "subroutine":
            assert static_arg in available_subroutine_keys
    except AssertionError:
        raise AssertionError(
            f"{static_value} is not valid value type for {static_type}."
            f"- minimizer : {available_minimizer_keys}"
            f"- subroutine : {available_subroutine_keys}"
            f"- function : TODO")
