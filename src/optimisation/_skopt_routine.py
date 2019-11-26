from sklearn.externals import joblib
import warnings

import skopt
from src.utils import HyperOptSpaceMapping
from src.utils import HyperOptOptimizerMapping
from src.utils import plot_evaluations

import numpy as np

__static_param_types__ = ["function",
                          "minimizer",
                          "subroutine"]

__space_param_types__ = HyperOptSpaceMapping.keys()

__routine_types__ = ["initial",
                     "intermediate",
                     "closing"]

__available_minimizer_args__ = ["name", "kwargs"]
__available_subroutine_args__ = ["n_best_forward"]


class HyperParamRoutineOptimizer:
    """
    Notes
    -----
    Definition of parameters.

    * `default`
        Default parameter of the target function.

    * `static`
        A parameter which has either:

        - been explicitly defined by the user or
        - has been optimised in a previous subroutine.

    * `decision`
        The parameter which is to be optimised for in the current
        optimisation subroutine.

    Three routine types are defined in the framework :

    * `initial`
        The initial routine is the first optimisation routine
        following the initialisation of the class which,

        - is only done once following .__init__() unless the
          `reset` method is called,

        - taken as the `intermediate` routine if it is not
          explicitly defined.

    * `intermediate`
        The intermediate routine is called following the
        `initial` routine and prior to the `closing` routine.

    * `closing`
        The closing routine is the final optimisation routine
        following the `intermediate` routine,

        - which is called only once the `close` method has been
          called.

        - whose result will be the last saved `intermediate`
          routine if a `closing` routine is not defined.

        - which will be called in any consecutive optimisation
          calls without calling the `reset` (raises Warning).

            TODO: Make warning for consecutive closing call.

    Strictly speaking, given the above definition of routines only an
     `intermediate` routine is required.

    A routine is in the form of a list, which hold optimisation
    subroutines, whose results are passed onto the next subroutine in
    the order of definition. Parameters are cumulatively redefined
    throughout subroutines. The following two cases are presented:

    * If `param_1` is defined in `sub_routine_1`, but not in
      `sub_routine_2`,
            - `param_1` will become a `static_param` of
              `sub_routine_2`.

    * If `param_1` has been optimised in `sub_routine_final` of the
      `intermediate` optimisation routine and is not a `decision`
      parameter of `sub_routine_1`,
            - a subsequent call of `sub_routine_1` will take the
              optimised result of `param_1` as a `static_param` of
              `sub_routine_1`.

    Subroutines are lists of dictionaries which hold a
    key-value pair in either of the forms;
    (`param_type__param_name` : `param_domain`) or
    (`optimizer__optimizer_name` : `optimizer_kwargs`).

    * `param_type` [str in {"categorical", "real", "integer"}]:
        Parameter type to optimize.

    * `param_domain` [list, tuple of float, tuple of int]:
        Domain of parameter to optimize where:

        - categorical params are given as a `list`,

            >>> domain_categorical = ["option1", "option2", "option3"]

        - real params are given as a `tuple` of inclusive bounds,

            >>> domain_real = (0.0, 1.0)

        - and integer params are given as a `tuple` of inclusive
          bounds.

            >>> domain_integer = (0, 100)

    * `optimizer__optimizer_name`
        Only one is allowed per sub-routine. If the user
        provides more than one, an AssertionError is raised. The
        accepted `optimizer_name` arguments correspond to the supported
        optimizer functions from the `skopt` module (See [1]).

        - `gp_minimize`
            Bayesian optimization using Gaussian Processes (Default).

        - 'forest_minimize`
            Sequential optimisation using decision trees.

        - `gbrt_minimize`
            Sequential optimization using gradient boosted trees.

    Examples
    --------
        The specific function used for optimisation in the skopt module
        can be defined optionally as follows:

        * Example 1:
            Three parameters, categorical, real and integer with
            default optimizer (`gp_minimize`) and default optimizer
            parameters.

            >>> sub_routine_1 = {
            ...     "categorical__param_1": domain_categorical,
            ...     "real__param_2": domain_real,
            ...     "integer__param_3": domain_integer
            ... }

        * Example 2:
            Three parameters, categorical, real and integer, with
            non-default optimizer settings.

            >>> sub_routine_2 = {
            ...     "categorical__param_1": domain_categorical,
            ...     "real__param_2": domain_real,
            ...     "integer__param_3": domain_integer,
            ...     "optimizer__gp_minimize": {
            ...         "n_calls": 12,
            ...         "n_random_starts": 6
            ...         }
            ... }

        * Example 3:
            Three parameters, categorical, real and integer, with
            non-default optimizer and non-default settings, defined
            in dict form.

            >>> sub_routine_3 = dict(
            ...     categorical__param_1=domain_categorical,
            ...     real__param_2=domain_real,
            ...     integer__param_3=domain_integer,
            ...     optimizer__forest_minimize=dict(n_calls=12,
            ...                                     n_random_starts=6)
            ... )

        * Example 4:
            A definition of a routine.

            >>> example_routine = [
            ...     sub_routine_1,
            ...     sub_routine_2,
            ...     sub_routine_3
            ... ]

    References
    ----------
    ..  [1] Scikit-Optimize module https://scikit-optimize.github.io/

    """

    @staticmethod
    def _catch_bad_keys(routines):
        """

        Parameters
        ----------
        routines

        Returns
        -------

        """
        # Catch wrongly named key.
        bad_keys = []
        for key in routines.keys():
            if key not in __routine_types__:
                bad_keys.append(key)
        if len(bad_keys) == 1:
            raise AssertionError(
                f"{bad_keys[0]} is not a valid routine name.")
        elif len(bad_keys) > 1:
            raise AssertionError(
                f"Following keys are note valid routine names: {bad_keys}")

    @staticmethod
    def _catch_bad_routine_logic(routines):
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

    @staticmethod
    def _catch_more_than_three(routines):
        try:
            assert len(routines) <= 3
        except AssertionError:
            raise AssertionError("Routines list contains more than three"
                                 "items (initial, intermediate, closing).")

    @staticmethod
    def _catch_empty_list(routines):
        try:
            assert len(routines) > 0
        except AssertionError:
            raise AssertionError("Routines list argument is empty.")

    @staticmethod
    def _ensure_routine_list_logic(routines):
        is_list_of_dict = lambda x: all(
            type(item) == dict for item in x)
        try:
            assert is_list_of_dict(routines)
            list_of_list_of_dict = [routines]
        except AssertionError:
            is_list_of_list_of_dict = lambda x: all(
                is_list_of_dict(item) for item in x)
            try:
                assert is_list_of_list_of_dict(routines)
                list_of_list_of_dict = routines
            except AssertionError:
                raise AssertionError(
                    "Routines argument is a list, but is neither of the"
                    "accepted following forms:"
                    " - list of dicts (1 routine)"
                    " - list of list of dicts (>=1 routine)")
        return list_of_list_of_dict

    @staticmethod
    def _list_form_to_dict(list_of_list_of_dict):
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

    @staticmethod
    def _catch_bad_default(default_params, static_params):
        """

        Parameters
        ----------
        default_params
        static_params

        Returns
        -------

        """
        try:
            assert "_optimizer__name" in default_params.keys()
        except AssertionError:
            raise KeyError(
                "_optimizer__name is not found in default_params dict."
                "It is required, and its value must one of:"
                f"{__space_param_types__}")
        try:
            assert "_optimizer_kwargs" in default_params.keys()

        except AssertionError:
            try:
                ignore_error_key = "_ignore_default_param_kwargs_error"
                assert ignore_error_key in static_params.keys()
                default_params["_optimizer_kwargs"] = {}

            except AssertionError:
                raise KeyError(
                    "_optimizer__kwargs is not found in default_params dict."
                    "When the `save` method is called, it contains it,"
                    "if the dictionary was user_defined, either add the key"
                    "or add `_ignore_default_param_kwargs_error=True` to the"
                    "class when instantiated.")

    @staticmethod
    def optimizer_mapping(optimizer_name):
        """

        Parameters
        ----------
        optimizer_name

        Returns
        -------

        """
        return HyperOptOptimizerMapping[optimizer_name]

    @staticmethod
    def space_mapping(param_type):
        """

        Parameters
        ----------
        param_type : {"integer", "real", "categorical"}
            String argument determining the type of space parameter to
            be returned.

        Returns
        -------
        space : skopt.space.Space

        """
        return HyperOptSpaceMapping[param_type]

    @staticmethod
    def results_mapping(sub_routine_space, results):
        """

        Parameters
        ----------
        sub_routine_space : dict
            Dictionary of key-value pairs

            >>> sub_routine_space = {
                 ... {
                 ... "categorical__param_1": ["option1", "option2", "option3"],
                 ... "real__param_2": (0.0, 1.0),
                 ... "integer__param_3": (0, 100)
                 ... }

        results : [`OptimizeResult`, scipy object]:
            The optimization result returned as a OptimizeResult object.
            Important attributes are:

            - `x` [list]: location of the minimum.
            - `fun` [float]: function value at the minimum.
            - `models`: surrogate models used for each iteration.
            - `x_iters` [list of lists]: location of function evaluation
               for each iteration.
            - `func_vals` [array]: function value for each iteration.
            - `space` [Space]: the optimization space.
            - `specs` [dict]`: the call specifications.
            - `rng` [RandomState instance]: State of the random state
               at the end of minimization.

            For more details related to the OptimizeResult object, refer
            http://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.OptimizeResult.html
            Returns
            -------


        """
        param_names = []
        for key in sub_routine_space.keys():
            param_names.append(key.split("__")[-1])
        return dict(zip(param_names, results.x))

    def optimise(self):
        """
        >>> routines = dict(
        ...     initial = [{
        ...         "categorical__param_1": domain_categorical,
        ...         "real__param_2": domain_real,
        ...         "integer__param_3": domain_integer,
        ...         "_param_4": 10.0,
        ...         "_optimizer__kwargs" : {
        ...             "n_calls": 12,
        ...             "n_random_starts": 6
        ...             },
        ...         "_routine__n_best_forward": 5
        ...         }],
        ...     intermediate = [{
        ...         "categorical__param_1": domain_categorical,
        ...         "real__param_2": domain_real,
        ...         "integer__param_3": domain_integer,
        ...         "_function__param_4": 1.0,
        ...         "_routine__n_best_forward":5,
        ...         "_optimizer__name": "forest_minimize",
        ...         "_optimizer__kwargs" : {
        ...             "n_calls": 12,
        ...             "n_random_starts": 6
        ...             },
        ...
        ...         },
        ...         {
        ...         "categorical__param_1": domain_categorical,
        ...         "real__param_2": domain_real,
        ...         "integer__param_3": domain_integer,
        ...         "_optimizer__name": "forest_minimize",
        ...         "_optimizer_kwargs" : {
        ...             "n_calls": 12,
        ...             "n_random_starts": 6
        ...             },
        ...
        ...         }],
        ...     closing = [{
        ...         "categorical__param_1": domain_categorical,
        ...         "real__param_2": domain_real,
        ...         "integer__param_3": domain_integer,
        ...         "optimizer__gp_minimize": {
        ...             "n_calls": 12,
        ...             "n_random_starts": 6
        ...             },
        ...         "static": {"early_stopping":False}
        ...         }],


        Returns
        -------

        """

    @staticmethod
    def _get_coded_default_params():
        return {"minimizer__name": "gp_minimize",
                "minimizer__kwargs": {"n_calls": 15,
                                      "n_random_starts": 5},
                "subroutine__n_reevaluate_forward": 5,
                "subroutine__intermediate_recycle": True}

    def __init__(self, routines=None, **kwargs):
        """
        # TODO: Add optional load to kwargs for loading.

        Notes
        -----


        Parameters
        ----------
        routines [dict, list of dict or list of list of dict]:
            The routine parameter can be interpreted three ways for
            hyperparameter optimisation. It should be noted that the
            instantiated class will behave consistently according to
            the logic behind the supplied routine, defined below. There
            are three routine types defined as:

            * `dict`
                A dictionary can be provided with three keys which
                determine the optimisation logic.

            * `list`
                A single list
        """
        # Optimizer and optimizer arguments.
        self._default_params = self._get_coded_default_params()
        self._static_params = kwargs

        # Routines, results and state.
        self._routines = self._parse_routines(routines)
        self._state = dict(initial=True, closing=False, idx=0)
        self._results_history = [dict(initial=[], intermediate=[], closing=[])]
        self._globals_history = [dict(static=[], )]

    def _parse_routines(self, routines):
        """

        Parameters
        ----------
        routines

        Returns
        -------

        """
        if type(routines) == list:
            self._catch_empty_list(routines)
            self._catch_more_than_three(routines)
            list_of_list_of_dict = self._ensure_routine_list_logic(routines)
            routine_dict = self._list_form_to_dict(list_of_list_of_dict)
        elif type(routines) == dict:
            routine_dict = routines
        else:
            raise AssertionError(
                f"`routines` argument not recognized. (type={type(routines)})"
                f"If this type is iterable, and should be accepted, then"
                f"contact the developer.")
        self._catch_bad_keys(routine_dict)
        self._catch_bad_routine_logic(routine_dict)
        # self._catch_bad_subroutines(routine_dict)
        # TODO: parse subroutines.
        parsed_routine_dict = routine_dict
        return parsed_routine_dict

    @staticmethod
    def _catch_bad_static_type(static_type):
        try:
            assert static_type in __static_param_types__
        except AssertionError:
            raise KeyError(
                f"{static_type} is not in one of the accepted static types:"
                f"{__static_param_types__}")

    @staticmethod
    def _catch_bad_space_type(space_type):
        try:
            assert space_type in __space_param_types__
        except AssertionError:
            raise KeyError(
                f"{space_type} is not in one of the accepted static types:"
                f"{__space_param_types__}")

    @staticmethod
    def _catch_bad_space_value(space_type, space_value):
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

    @staticmethod
    def _catch_bad_static_value(static_key, static_value):
        static_type, static_arg = static_key.split("__")

        try:
            if static_type is "function":
                # TODO: Make non-staticmethod and retrieve function sig.
                pass
            elif static_type is "minimizer":
                assert static_arg in __available_minimizer_args__
            elif static_type is "subroutine":
                assert static_arg in __available_subroutine_args__
        except AssertionError:
            raise AssertionError(
                f"{static_value} is not valid value type for {static_type}."
                f"- minimizer : {__available_minimizer_args__}"
                f"- subroutine : {__available_subroutine_args__}"
                f"- function : TODO")

    def _parse_subroutine(self, subroutine):
        decision_space = []
        local_static_params = {}
        is_local_static_parameter = lambda x: x[0] == "_"
        is_local_space_parameter = lambda x: x in __space_param_types__
        for key, value in subroutine.items():
            if is_local_space_parameter(key.split("__")[0]):
                param_type, param_name = key.split("__")
                self._catch_bad_space_type(param_type)
                self._catch_bad_space_value(param_type, value)
                space_obj = self.space_mapping(param_type)
                if param_type == "categorical":
                    param_space = space_obj(value, name=param_name)
                else:
                    param_space = space_obj(*value, name=param_name)
                decision_space.append(param_space)

            elif is_local_static_parameter(key):
                static_key = key[1:]
                static_type, _ = static_key.split("__")
                self._catch_bad_static_type(static_type)
                self._catch_bad_static_value(static_key, value)
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

    @property
    def default_params(self):
        return self._default_params

    def load_default_params(self, path):
        """

        Parameters
        ----------
        path

        Returns
        -------

        """
        default_params_loaded = joblib.load(path)
        self._catch_bad_default(default_params_loaded, self._static_params)
        self._default_params = default_params_loaded

    @staticmethod
    def _get_routine_key(state):
        if state["initial"] is True and state["closing"] is False:
            return "initial"

        elif state["initial"] is False and state["closing"] is False:
            return "intermediate"

        elif state["initial"] is False and state["closing"] is True:
            return "closing"

        else:
            raise AssertionError(
                "_get_subroutine received a state that has been managed"
                "incorrectly. state['initial']={}; state['closing']={}".format(
                    state["initial"], state["closing"]))

    def _get_routine(self, state):
        return self._routines[self._get_routine_key(state)]

    def _get_subroutine(self, state):
        routine = self._get_routine(state)
        try:
            return routine[state["idx"]]
        except TypeError:
            try:
                assert state["closing"] == True
                return None
            except AssertionError:
                raise AssertionError(
                    f"The current routine is not defined. It is {routine}."
                    f"Only the closing routine can be NoneType.")

    def _get_global_static_params(self):
        return {**self._default_params, **self._static_params}

    @staticmethod
    def hp_dict(space, x):
        new_keys = []
        for key in space.keys():
            new_keys.append(key.split("__")[-1])
        return dict(zip(new_keys, x))

    @staticmethod
    def _parse_function_static_params(static_params):
        function_static_keys = filter(lambda x: "function" in x,
                                      static_params.keys())
        function_kwargs_keys = map(lambda x: x.split("__")[1],
                                   function_static_keys)
        function_static = dict(zip(function_kwargs_keys,
                                   [static_params[key] for key in
                                    function_static_keys]))
        return function_static

    def _increment_state(self):
        if self._get_routine_key(self._state) is "initial":
            self._state["initial"] = False
            self._state["idx"] = 0

        elif self._get_routine_key(self._state) is "intermediate":
            n_intermediate = len(self._get_routine(self._state))
            if (self._state["idx"] + 1) == n_intermediate:
                self._state["idx"] = 0
            elif (self._state["idx"] + 1) < n_intermediate:
                self._state["idx"] += 1

        elif self._get_routine_key(self._state) is "closing":
            n_closing = len(self._get_routine(self._state))
            self._state["idx"] += 1
            if (self._state["idx"] + 1) == n_closing:
                self._state["idx"] = 0
                warnings.warn("Closing has been evaluated already.")
            elif (self._state["idx"] + 1) < n_closing:
                self._state["idx"] += 1

    def minimize(self, function, tdmq=False):
        """
        Create function to minimize.

        Parameters
        ----------
        function
        callback

        Returns
        -------

        """
        if tdmq:
            progress = TQDMSkoptCallable(total=total, desc="Model HpOpt",
                                         leave=False)
            callback = [progress]

        else:
            callback = None

        # Retrieve global and local static.
        subroutine = self._get_subroutine(self._state)
        global_static = self._get_global_static_params()

        (local_static,
         decision_space) = self._parse_subroutine(subroutine)
        current_static = {**global_static, **local_static}
        function_static = self._parse_function_static_params(current_static)

        # Make skopt function to minimize.
        @skopt.utils.use_named_args(decision_space)
        def objective(**decision_params):
            all_params = {**function_static, **decision_params}
            return function(**all_params)

        # Determine what to give to minimizer to start.
        n_forward = current_static["subroutine__n_reevaluate_forward"]

        b_recycle = current_static["subroutine__intermediate_recycle"]
        if b_recycle and self._get_routine_key(self._state) is "intermediate":
            try:
                x0 = self._results_history[-1]["intermediate"][-1].x_iters
                y0 = self._results_history[-1]["intermediate"][-1].func_vals
            except IndexError:
                x0, y0 = [None, None]
        else:
            x0, y0 = [None, None]

        # Retrieve minimizer kwargs, name and evaluate.
        minimizer__kwargs = current_static["minimizer__kwargs"]
        minimizer__name = current_static["minimizer__name"]
        minimizer = HyperOptOptimizerMapping[minimizer__name]
        results = minimizer(objective, decision_space, callback=callback,
                            **{**{"x0": x0, "y0": y0}, **minimizer__kwargs})

        # Append results to history dict.
        self._results_history[-1][
            self._get_routine_key(self._state)].append(results)

        # Increment state.
        self._increment_state()

        best_local_parameters = {**current_static}

        return results

    def reset(self, routines=None,
              reset_history=False,
              reset_default=False,
              reset_static=False):
        """

        Parameters
        ----------
        routines
        reset_history
        reset_default
        reset_static

        Returns
        -------

        """
        self._state["idx"] = 0
        self._state["initial"] = True
        self._state["closing"] = False
        _new_history = dict(initial=[], intermediate=[], closing=[])
        if reset_history:
            self._results_history = [_new_history]
        else:
            self._results_history.append(_new_history)
        if reset_default:
            default_params = self._get_coded_default_params()
        else:
            default_params = self._default_params
        if reset_static:
            static_params = {}
        else:
            static_params = self._static_params
        self.__init__(self._routines if routines is None else routines)
        self._default_params = default_params
        self._static_params = static_params

    def close(self):

        self._state["closing"] = True


if __name__ == "__main__":
    from sklearn.svm import SVR as sklearnSVR
    from src.surrogate.sampling import halton
    from src.surrogate.sampling import random_uniform
    from src.surrogate.test import TestFunctionSet2DInputSpace as F2D
    from src.surrogate.test import TestFunctionSetNDInputSpace as FND
    from sklearn.preprocessing import MinMaxScaler

    STATIC_PARAMS = {

    }

    scaler = MinMaxScaler()
    # F2D = F2D()
    F_ = FND(2)
    x_train = halton([[0, 0], [1, 1]], 2000)
    x_test_ = random_uniform([[0, 0], [1, 1]], 1000)
    f_train = F_[0](*x_train.T)
    f_test_ = F_[0](*x_test_.T)

    ds_train = (
        x_train, scaler.fit_transform(f_train.reshape(-1, 1)).flatten())
    ds_test_ = (x_test_, scaler.transform(f_test_.reshape(-1, 1)).flatten())

    routine = {
        "intermediate": [
            {
                "real__gamma": (1e-3, 1e3),
                "real__epsilon": (1e-2, 1e-1),
                "_minimizer__kwargs": {"n_calls": 20},
                "_subroutine__n_reevaluate_forward": 5,
                "_subroutine__intermediate_recycle": True
            },
            {
                "real__gamma": (1e-3, 1e3),
                "real__epsilon": (1e-2, 1e-1)
            },
            {

            }
        ],
        # "intermediate": [
        #     {
        #
        #     },
        #     {
        #
        #     }
        # ]
    }


    def function_to_minimize(**params):
        svr = sklearnSVR(**params)
        svr.fit(*ds_train)
        return - svr.score(*ds_test_)


    test = HyperParamRoutineOptimizer(routine)

    result1 = test.minimize(function_to_minimize)
    result2 = test.minimize(function_to_minimize)

    import matplotlib.pyplot as plt
    import skopt.plots


    def plot_for_result(result):
        plt.figure(dpi=400, figsize=(6, 5))
        skopt.plots.plot_convergence(result)
        plt.show()

        plt.figure(dpi=400, figsize=(6, 5))
        plot_evaluations(result, fig_scale=2)
        plt.show()


    plot_for_result(result1)
    plot_for_result(result2)

    # class BaseMetaModelRegressionHandler(HyperParamRoutineOptimizer):
    #     """
    #     Base class for handling meta modelling and hyperparameter optimisation.
    #
    #     Attributes
    #     ----------
    #     model : object
    #
    #     References
    #     ----------
    #     skopt module https://scikit-optimize.github.io/
    #
    #
    #     """
    #
    #     @classmethod
    #     def new(cls):
    #         new_cls = cls()
    #         return new_cls
    #
    #     @classmethod
    #     def from_path(cls, path):
    #         return cls.
    #
    #     def __init__(self):
    #         """
    #         Other Parameters
    #         ----------------
    #         model : object
    #             Model that is in current memory that has been instantiated
    #             from the `model_cls parameter
    #         """
    #         self._model = None
    #         self._model_cls = None
    #         self._model_trainer = None
    #         super(HyperParamRoutineOptimizer).__init__(routine=None)
    #
    #     @property
    #     def model(self):
    #         return self._model
    #
    #     def save(self, path):
    #         """
    #
    #         Parameters
    #         ----------
    #         path
    #
    #         Returns
    #         -------
    #
    #         """
    #         joblib.dump(self._model, path)
    #
    #     def load(self, path):
    #         """
    #
    #         Parameters
    #         ----------
    #         path
    #
    #         Returns
    #         -------
    #
    #         """
    #         self._model = joblib.load(path)
