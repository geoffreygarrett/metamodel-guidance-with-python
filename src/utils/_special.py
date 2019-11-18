from collections import namedtuple

PACCEvaluationLog = namedtuple("EvaluationLog", ["n_samples", "n_passing",
                                                 "statistic", "terminate"])
