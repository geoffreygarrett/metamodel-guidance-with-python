import skopt

HyperOptSpaceMapping = {"integer": skopt.space.Integer,
                        "real": skopt.space.Real,
                        "categorical": skopt.space.Categorical}

HyperOptOptimizerMapping = {"gp_minimize": skopt.gp_minimize,
                            "forest_minimize": skopt.forest_minimize,
                            "gbrt_minimize": skopt.gbrt_minimize}
