ROUTINE_NAMES = ["initial", "intermediate", "closing"]
DEFAULT_ROUTINE_KWARGS = {
    # "subroutine__n_reevaluate_forward": 3,
    "subroutine__n_best_historical": 1,
    "subroutine__reevaluate_n_best": True,
    # "subroutine__intermediate_recycle": False
}
STATIC_ARGS_TYPES = ["function", "optimiser", "subroutine"]
STATIC_OPTIMIZER_KEYS = ["name", "kwargs"]
STATIC_ROUTINE_KEYS = [
    # "n_reevaluate_forward",
    "n_best_historical",
    "reevaluate_n_best",
    # "intermediate_recycle"
]
DECISION_SPACE_KEYS = ["categorical", "integer", "real"]
