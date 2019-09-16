from dataset import DataSetFX, TransformDataFrame
from sklearn import preprocessing
from collections import OrderedDict
import numpy as np

import pandas as pd

# transform = TransformDataFrame.from_ordered_dict(OrderedDict([
#     ("tx1", (preprocessing.MinMaxScaler(feature_range=(-1, 1)), ["x1", "x2", "x3"])),
#     ("tx2", (preprocessing.Normalizer(norm='l2'), ["x1", "x2", "x3"])),
#     ("tx3", (preprocessing.Normalizer(norm='l2'), ["x4", "x5", "x6", "x7"])),
#     ("fx1", (preprocessing.MinMaxScaler(feature_range=(0, 1)), ["f1", "f2", "f3", "f4"]))
# ]
# ))
#
# # transform.add_feature(which="tx1",
# #                       operation=[(np.square, {"axis": 1}), (np.sum, {"axis": 1}), np.sqrt],
# #                       target=["x1", "x2", "x3"])
#
# transform.add_filter(step="pre",
#                      condition=lambda x: x <= 0.05,
#                      target=["x4", "x5", "x6", "x7"])
#
# print(transform._steps)
#
# ds1 = DataSetFX.from_parquet(
#     file_name="dataSet_gridSampled_3.parquet",
#     root_dir="data",
#     # transform=transform
# )
#
# print(transform(ds1.get_df()))

# ds1_train, ds1_test = ds1.train_test_split()

# ds2 = DataSetFX.from_parquet(
#     file_name="dataSet_gridSampled_3.parquet",
#     root_dir="data",
#     transform=TransformFX
# )

# print(ds1.output.size)
#
# # print(ds1[1])
#
# print("train len -l: ", len(ds1_train))
# print("train len -o: ", ds1_train.output.shape)
# print("\n")
# print("test len: -l", len(ds1_test))
# print("test len: -o", ds1_test.input.shape)

# print(ds1_train.output.size)


# df = ds1.get_df()
# print(df.name)
# print(train.get_df().name)
# print(test.get_df().name)


from representation import NOmegaPointsScaleBasedPeriodic
from problems.two_dimensional import *
from optimisation import *

test_geometry = MissionGeometry()  # Environment.
test_spacecraft = Spacecraft()  #
test_design = NOmegaPointsScaleBasedPeriodic(int(test_geometry.P_s / 10), 3)
test_problem = AttitudeTrajectoryProblem2D(test_geometry, test_spacecraft, test_design)

test_fitness_tuples = [
    ("obj", "f_thrust_inefficiency"),
    ("ci1", "f_power_from_available", ">", 0.7),
    ("ci2", "f_star_sensor_exclusion", ">", np.deg2rad(3)),
    ("ci3", "f_max_angular_rate", "<", np.deg2rad(0.12)),
    ("ci4", "f_max_angular_acceleration", "<", 0.001),
]


class Fitness:

    def __init__(self, f_names):
        self._attributes = f_names

    def __call__(self, problem):
        return [getattr(problem, att)(problem) for att in self._attributes]

    @classmethod
    def from_tuples(cls, problem, list):
        _names = []
        _funcs = []

        assert len(list[0]) == 2
        for tup in list[1:]:

            _names.append(tup[0])
            _func = getattr(problem, tup[1])

            def _attribute(function):
                if len(tup) == 2:
                    def call(*args, **kwargs):
                        return function(problem)[1]
                elif len(tup) == 4:
                    sign = tup[2]
                    g = tup[3]

                    def call(*args, **kwargs):
                        if sign == ">":
                            print(function(problem)[1])
                            return g - function(problem)[1]
                        elif sign == "<":
                            return function(problem)[1] - g

                    return call
                else:
                    raise AttributeError("""
                    <name, method_name>  <- obj
                    <name, method_name, sign, g_value>  <- ci
                    4 or 2 arguments in from_tuples constructor only.""")

            _funcs.append( _attribute(_func))

        _cls = cls(_names)
        for name in _names:
            _cls.

        return _cls


class Wrapper:

    def __init__(self, problem):
        self._problem = problem

    def get_bounds(self):
        bounds = self._problem.get_bounds()
        # n_omega = self._problem.design_space.n_design_omega
        # for i in range(self._problem.design_space.n_design_scale):
        #     bounds[0][n_omega + i] = 1
        #     bounds[1][n_omega + i] = 1
        return bounds

    def fitness(self, x):
        f = self._problem.fitness(x)
        f_thrust_inefficiency = f[0]
        f_power_from_available = f[1]
        f_star_sensor_exclusion = f[2]
        f_max_angular_acceleration = f[3]
        f_max_angular_rate = f[4]
        # print(f_star_sensor_exclusion)
        return [
            f_thrust_inefficiency,
            0.7 - f_power_from_available,
            np.deg2rad(3) - f_star_sensor_exclusion,
            f_max_angular_acceleration - 0.01,
            f_max_angular_rate - np.deg2rad(0.12)
        ]

    @property
    def fitness_dim(self):
        return self._problem.fitness_dim

    def get_nic(self):
        return self._problem.fitness_dim - 1


print("1\n")
# test_fitness = Fitness.from_tuples(test_problem, test_fitness_tuples)
# print(test_fitness())

x = [0.002, -0.002, 0.002, 0.1, 0.1, 0.1, 0.1]
test_problem.design_space_evaluate(x)

print(test_problem.fitness(x))
print("2\n")
test_fitness = Fitness.from_tuples(test_problem, test_fitness_tuples)
print(test_fitness())

pop = PopulationManager.standard(Wrapper(test_problem))
algos = [GlobalOptimisation.gaco(gen=5000),
         LocalOptimisation.compass(max_fevals=10000),
         LocalOptimisation.cobyla(maxeval=10000)
         ]
# sol = OptimisationRoutine.from_list_algos(pop, algos, verbosity=100)

from problems.two_dimensional._plotting import *

# x = np.array([0, 0, 0, 1, 1, 1, 1])

x = [0.00192016,
     -0.00135844,
     0.00226742,
     0.4064695,
     0.28561942,
     0.96828936,
     0.50069615]

print(Wrapper(test_problem).fitness(x))

# x = sol.champion_x

fig1, ax1 = plt.subplots(3, 1, figsize=(10, 6), dpi=400)
test_problem.design_space_evaluate(x)
# print(np.rad2deg(test_problem.design_space.init["theta"]))
# print(test_problem.mission_geometry.X_s)
plot_dynamics(problem=test_problem, x=x, ax1=ax1)

plt.show()

# print()

plot_solution(test_problem, x)
# print(x)
