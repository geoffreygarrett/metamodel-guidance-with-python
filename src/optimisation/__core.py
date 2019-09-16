import pygmo as pg


class LocalOptimisation:

    @classmethod
    def cobyla(cls, maxeval=300):
        _cobyla = pg.nlopt("cobyla")
        _cobyla.maxeval = maxeval
        return pg.algorithm(_cobyla)

    @classmethod
    def compass(cls, max_fevals=200, stop_range=1e-10, start_range=0.8, reduction_coeff=0.8):
        _compass = pg.compass_search(max_fevals=max_fevals,
                                     stop_range=stop_range,
                                     start_range=start_range,
                                     reduction_coeff=reduction_coeff)
        return pg.algorithm(_compass)


class GlobalOptimisation:

    @classmethod
    def gaco(cls, gen=50, seed=1):
        return pg.algorithm(pg.gaco(gen=gen, seed=seed))

    @classmethod
    def sade(cls, gen=50, seed=1):
        return pg.algorithm(pg.sade(gen=gen, seed=seed))

    @classmethod
    def ihs(cls, gen=100, phmcr=0.85, ppar_min=0.35, ppar_max=0.99, bw_min=1E-5, bw_max=1., seed=1):
        return pg.algorithm(gen=gen, phmcr=phmcr, ppar_min=ppar_min, ppar_max=ppar_max, bw_min=bw_min, bw_max=bw_max,
                            seed=seed)


class OptimisationRoutine:

    @classmethod
    def from_list_algos(cls, pop, algos, verbosity=1):
        _pop = pop
        for algo in algos:
            algo.set_verbosity(verbosity)
            _pop = algo.evolve(_pop)
        return _pop


class PopulationManager:

    @classmethod
    def unconstrained_weighted(cls, problem, size=100, method="weighted"):
        return pg.population(pg.unconstrain(problem, method=method, weights=[1.] * (problem.fitness_dim - 1)),
                             size=size, seed=1)

    @classmethod
    def standard(cls, problem, size=100, seed=1):
        return pg.population(problem, size=size, seed=seed)
