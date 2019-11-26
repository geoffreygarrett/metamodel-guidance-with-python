import copy
import warnings

import numpy as np

from src.utils import TQDMSkoptCallable
from ._parse import parse_routines
from ._parse import parse_static
from ._parse import parse_subroutine


class BaseOptimiserRoutine:
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
    (`optimiser__optimiser_name` : `optimiser_kwargs`).

    * `param_type` [str in {"categorical", "real", "integer"}]:
        Parameter type to optimise.

    * `param_domain` [list, tuple of float, tuple of int]:
        Domain of parameter to optimise where:

        - categorical params are given as a `list`,

            >>> domain_categorical = ["option1", "option2", "option3"]

        - real params are given as a `tuple` of inclusive bounds,

            >>> domain_real = (0.0, 1.0)

        - and integer params are given as a `tuple` of inclusive
          bounds.

            >>> domain_integer = (0, 100)

    * `optimiser__optimiser_name`
        Only one is allowed per sub-routine. If the user
        provides more than one, an AssertionError is raised. The
        accepted `optimiser_name` arguments correspond to the supported
        optimiser functions from the `skopt` module (See [1]).

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
            default optimiser (`gp_minimize`) and default optimiser
            parameters.

            >>> sub_routine_1 = {
            ...     "categorical__param_1": domain_categorical,
            ...     "real__param_2": domain_real,
            ...     "integer__param_3": domain_integer
            ... }

        * Example 2:
            Three parameters, categorical, real and integer, with
            non-default optimiser settings.

            >>> sub_routine_2 = {
            ...     "categorical__param_1": domain_categorical,
            ...     "real__param_2": domain_real,
            ...     "integer__param_3": domain_integer,
            ...     "optimiser__gp_minimize": {
            ...         "n_calls": 12,
            ...         "n_random_starts": 6
            ...         }
            ... }

        * Example 3:
            Three parameters, categorical, real and integer, with
            non-default optimiser and non-default settings, defined
            in dict form.

            >>> sub_routine_3 = dict(
            ...     categorical__param_1=domain_categorical,
            ...     real__param_2=domain_real,
            ...     integer__param_3=domain_integer,
            ...     optimiser__forest_minimize=dict(n_calls=12,
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
    ..  [1] Scikit-optimise module https://scikit-optimise.github.io/

    """

    def __init__(self, routines=None, default_kwargs=None, **kwargs):
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
        # optimiser specific.
        self._optimiser_map = None
        self._space_map = None

        # optimiser and optimiser arguments.
        default_kwargs = default_kwargs if default_kwargs is not None else {}
        fn = kwargs.setdefault("function_default", {})
        op = self.parse_static(default_kwargs, "optimiser")
        sb = self.parse_static(default_kwargs, "subroutine")

        self._default_static = dict(function=fn, optimiser=op, subroutine=sb)
        self._global_static = dict(function={}, optimiser={}, subroutine={})

        # Routines, results and state.
        self._routines = parse_routines(routines)
        self._state = dict(initial=True, closing=False, idx=0)
        self._locals_history = [dict(initial=[], intermediate=[], closing=[])]
        self._global_history = dict(static=[], results=[], score=[])

    @property
    def optimiser_map(self):
        return self._optimiser_map

    @property
    def space_map(self):
        return self._space_map

    # VIRTUAL METHOD.
    def subroutine_optimise(self, function, current_static, decision_space,
                            initial, callback):
        raise NotImplementedError("Not implemented in base class.")

    def record_to_global(self, results, static, space):
        score = results.fun
        decided = self.results_mapping(space, results)
        static["function"] = {**static["function"], **decided}
        self._global_static["function"] = static["function"]
        self._global_history["score"].append(score)
        self._global_history["static"].append(static)
        self._global_history["results"].append(results)

    def record_to_local(self, results):
        self._locals_history[-1][self._get_routine_key(self._state)].append(
            results)

    def current_best_global(self):
        _score = np.array(self._global_history["score"])
        _static = np.array(self._global_history["static"])
        return np.array(_static)[_score == np.min(_score)][0]

    @staticmethod
    def parse_static(static, name):
        return parse_static(static, name)

    def optimise(self, function, tdmq=False, callback=None):
        """

        Parameters
        ----------
        function
        tdmq
        callback

        Returns
        -------

        """

        # Retrieve global static parameters.
        gbl_static = self._get_global_static_params()
        gbl_function_static = gbl_static["function"]
        gbl_optimiser_static = gbl_static["optimiser"]
        gbl_subroutine_static = gbl_static["subroutine"]

        # Parse for local static parameters.
        subroutine = self._get_subroutine(self._state)
        lcl_static, space = parse_subroutine(subroutine, self.space_map)
        lcl_function_static = parse_static(lcl_static, "function")
        lcl_optimiser_static = parse_static(lcl_static, "optimiser")
        lcl_subroutine_static = parse_static(lcl_static, "subroutine")

        # Combine global and local static parameters.
        function_kwargs = {**gbl_function_static, **lcl_function_static}
        optimiser_kwargs = {**gbl_optimiser_static, **lcl_optimiser_static}
        subroutine_kwargs = {**gbl_subroutine_static, **lcl_subroutine_static}

        # Store current static parameters in effect.
        current_static = dict(function=function_kwargs,
                              optimiser=optimiser_kwargs,
                              subroutine=subroutine_kwargs)

        # Determine what to give to optimiser to start.
        subroutine_n_best_historical = subroutine_kwargs["n_best_historical"]
        subroutine_reevaluate_n_best = subroutine_kwargs["reevaluate_n_best"]
        x0, y0 = self._get_n_best(subroutine_n_best_historical, space)
        y0 = None if subroutine_reevaluate_n_best is True else y0

        # Callback and progress bar.
        _callback = []
        if tdmq:
            len_x0 = len(x0) if x0 is not None else 0
            progress = TQDMSkoptCallable(
                total=optimiser_kwargs["kwargs"]["n_calls"] - len_x0,
                desc="Model HpOpt",
                leave=False)
            _callback += [progress]

        if callback:
            _callback += callback

        # Run optimisation.
        results = self.subroutine_optimise(function, current_static, space,
                                           (x0, y0), _callback)

        # Append results to history dict.
        self.record_to_local(results)

        # Save to globals history.
        self.record_to_global(results, gbl_static, space)

        # Increment state.
        self._increment_state()
        return results

    def optimise_routine(self, function, tdmq=False, callback=None):
        for idx in range(len(self._get_routine(self._state))):
            self.optimise(function, tdmq, callback)
        return self.get_best_result()

    def get_best_result(self):
        try:
            score_arr = np.array(self._global_history["score"])
            sort_idx = np.argsort(score_arr)
            sort_results = np.array(self._global_history["results"])[sort_idx]
            return sort_results[0]
        except ValueError:
            raise AssertionError("Optimisation hasn't been run yet.")

    def get_best_function_params(self):
        try:
            score_arr = np.array(self._global_history["score"])
            sort_idx = np.argsort(score_arr)
            sort_results = np.array(self._global_history["static"])[sort_idx]
            return sort_results[0]["function"]
        except ValueError:
            raise AssertionError("Optimisation hasn't been run yet.")

    def _get_n_best(self, n, space):
        try:
            score_arr = np.array(self._global_history["score"])
            sort_idx = np.argsort(score_arr)
            sorted_static = np.array(self._global_history["static"])[sort_idx]
            n_best_static = sorted_static[:n]
            n_best_scores = score_arr[:n]
            x0 = []
            y0 = []
            for idx, best in enumerate(n_best_static):
                _x0 = []
                _y0 = []
                for s in space:
                    _x0.append(best["function"][s.name])
                    _y0.append(n_best_scores[idx])
                x0.append(_x0)
                y0.append(_y0)
            if len(x0) == 0:
                raise ValueError
            return x0, y0
        except ValueError:
            return None, None
        except KeyError:
            return None, None

    def reset(self, to_initial=True,
              routines=None,
              reset_history=False,
              reset_static=False):
        """

        Parameters
        ----------

        to_initial
        routines
        reset_history
        reset_static

        Returns
        -------

        """
        # Set state according to reset.
        if to_initial:
            self._state["idx"] = 0
            self._state["initial"] = True
            self._state["closing"] = False

        # Create new history dict for next history.
        _new_history = dict(initial=[], intermediate=[], closing=[])

        # Reset history completely (clear all)
        if reset_history:
            self._locals_history = [_new_history]
        else:
            self._locals_history.append(_new_history)

        # Reset static params if desired.
        if reset_static:
            _static_params = {}
        else:
            _static_params = copy.deepcopy(self._global_static)

        # Re initialize the class
        _default_params = copy.deepcopy(self._default_static)
        self.__init__(self._routines if routines is None else routines)
        self._global_static = _static_params
        self._default_static = _default_params

    def close(self):
        self._state["closing"] = True
        self._state["idx"] = 0

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

        results : [`optimiseResult`, scipy object]:
            The optimization result returned as a optimiseResult object.
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

            For more details related to the optimiseResult object, refer
            http://docs.scipy.org/doc/scipy/reference/generated/scipy.optimise.optimiseResult.html
            Returns
            -------


        """
        param_names = []
        for arg_space in sub_routine_space:
            param_names.append(arg_space.name)
        return dict(zip(param_names, results.x))

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
        return dict(function={**self._default_static["function"],
                              **self._global_static["function"]},
                    optimiser={**self._default_static["optimiser"],
                               **self._global_static["optimiser"]},
                    subroutine={**self._default_static["subroutine"],
                                **self._global_static["subroutine"]})

    def _increment_state(self):
        if self._get_routine_key(self._state) is "initial":
            n_initial = len(self._get_routine(self._state))
            if (self._state["idx"] + 1) == n_initial:
                self._state["idx"] = 0
                self._state["initial"] = False
            elif (self._state["idx"] + 1) < n_initial:
                self._state["idx"] += 1

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
