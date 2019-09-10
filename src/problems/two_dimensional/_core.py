from .geometry import MissionGeometry
from .spacecraft import Spacecraft
from .representation import DesignSpaceBase
from ._performance import *


class AttitudeTrajectoryProblem2D:

    def __init__(self, mission_geometry: MissionGeometry, spacecraft: Spacecraft, design_space: DesignSpaceBase,
                 thrust_profile="tangential+",
                 thrust_profile_w_f=lambda x: 1,
                 case="default"):

        self._mg = mission_geometry
        self._sc = spacecraft
        self._ds = design_space
        self._alpha = None
        self._omega = None
        self._theta = None

        self._name = None
        self._case_name = None

        self._thrust_profile_w_f = thrust_profile_w_f

        # Case handling.
        if case in ("default", "solar_eclipse_exit_sun_pointing"):

            self._case_name = "Case1"

            # Design space init with time domain of satellite period.
            self.design_space.reference_time = self.mission_geometry.P_s

            # Spacecraft position initiated at exit of eclipse.
            self.mission_geometry.spacecraft_nu0 = self.mission_geometry.nu_eclipse["exit"]

            # Give spacecraft sampled time array.
            self.mission_geometry.sample_time = self.design_space.sampled_time_array

            # Set spacecraft initial theta as pointing towards Sun.
            self.design_space.init["theta"] = np.arctan2(self.mission_geometry.R_solar_u[0][1],
                                                         self.mission_geometry.R_solar_u[0][0])

        else:
            raise EnvironmentError("Input case not recognised.")

    def get_name(self):
        return

    @property
    def case_name(self):
        """
        Case1: Solar Eclipse Exit, Sun Pointing.
            - t0: Exit of solar eclipse.
            - Initial angular rate default: Mean motion of orbit.
            - Initial pointing direction: Sun pointing.
        :return:
        """
        return self._case_name

    # Core properties of the problem.
    @property
    def mission_geometry(self):
        return self._mg

    @property
    def spacecraft(self):
        return self._sc

    @property
    def design_space(self):
        return self._ds

    @property
    def thrust_profile(self):
        return self._thrust_profile_f(self.mission_geometry.time_to_nu_s(self.design_space.sampled_time_array))

    @property
    def thrust_profile_weight(self):
        return self._thrust_profile_w_f(self.mission_geometry.time_to_nu_s(self.design_space.sampled_time_array))

    # Parameters of importance.
    # @property
    def f_thrust_inefficiency(self):
        x = np.cos(self.thrust_profile)
        y = np.sin(self.thrust_profile)
        _planned = np.concatenate(([x], [y]), axis=0).T
        return f_thrust_inefficiency(planned=_planned,
                                     actual=self.spacecraft.thr_u_vec(),
                                     weight=self.thrust_profile_weight)

    # @property
    def f_power_from_available(self):
        return f_power_from_available(panel_pointing_u=self.spacecraft.arr_u_vec(),
                                      sun_pointing_u=self.mission_geometry.R_solar_u,
                                      solar_eclipse_bool=self.mission_geometry.E_solar)

    # @property
    def f_max_angular_rate(self):
        return f_max_angular_rate(omega=self.omega)

    # @property
    def f_max_angular_acceleration(self):
        return f_max_angular_acceleration(alpha=self.alpha)

    # @property
    def f_star_sensor_exclusion(self):
        return f_star_sensor_exclusion(sensor1_pointing_u=self.spacecraft.ss1_u_vec(),
                                       sensor2_pointing_u=self.spacecraft.ss2_u_vec(),
                                       sun_pointing_u=self.mission_geometry.R_solar_u,
                                       solar_eclipse_bool=self.mission_geometry.E_solar,
                                       body_u=-self.mission_geometry.X_s_u,
                                       R=self.mission_geometry.m_target_R,
                                       h=self.mission_geometry.spacecraft_h)

    def design_space_evaluate(self, x):
        alpha, omega, theta = self.design_space(x)
        self.spacecraft.attitude_trajectory = theta
        self._alpha = alpha
        self._omega = omega
        self._theta = theta

    def fitness(self, x):
        self.design_space_evaluate(x)
        return [
            self.f_thrust_inefficiency()[1],
            self.f_power_from_available()[1],
            self.f_max_angular_acceleration()[1],
            self.f_max_angular_rate()[1],
        ]

    @property
    def alpha(self):
        return self._alpha

    @alpha.setter
    def alpha(self, x):
        self._alpha = x

    @property
    def omega(self):
        return self._omega

    @omega.setter
    def omega(self, x):
        self._omega = x

    @property
    def theta(self):
        return self._theta

    @theta.setter
    def theta(self, x):
        self._theta = x


if __name__ == "__main__":
    from representation import NOmegaPointsScaleBasedPeriodic

    test_geometry = MissionGeometry()
    test_spacecraft = Spacecraft()
    test_design = NOmegaPointsScaleBasedPeriodic(int(test_geometry.P_s / 10), 3)
    test_problem = AttitudeTrajectoryProblem2D(test_geometry, test_spacecraft, test_design)

    x = [0.002, -0.002, 0.002, 0.1, 0.1, 0.1, 0.1]
    test_problem.design_space_evaluate(x)


    def test():
        test_problem.fitness(x)


    import timeit

    print(timeit.timeit(test, number=100))

    import time
    #
    # a, o, t = test_problem.alpha, test_problem.omega, test_problem.theta
    #
    # import matplotlib.pyplot as plt
    #
    # plt.figure(figsize=(7, 10), dpi=300)
    #
    # plt.subplot(7, 1, 1)
    # plt.plot(test_problem.design_space.sampled_time_array, a)
    #
    # plt.subplot(7, 1, 2)
    # plt.plot(test_problem.design_space.sampled_time_array, o)
    #
    # plt.subplot(7, 1, 3)
    # plt.plot(test_problem.design_space.sampled_time_array, t)
    #
    # plt.subplot(7, 1, 4)
    # # print(test_problem.f_max_angular_rate()[0])
    # plt.plot(test_problem.design_space.sampled_time_array, test_problem.f_max_angular_rate()[0])
    #
    # plt.subplot(7, 1, 5)
    # # print(test_problem.f_max_angular_rate()[0])
    # plt.plot(test_problem.design_space.sampled_time_array, test_problem.f_thrust_inefficiency()[0])
    #
    # plt.subplot(7, 1, 6)
    # # print(test_problem.f_max_angular_rate()[0])
    # plt.plot(test_problem.design_space.sampled_time_array, test_problem.f_star_sensor_exclusion()[0][0])
    #
    # plt.subplot(7, 1, 7)
    # # print(test_problem.f_max_angular_rate()[0])
    # plt.plot(test_problem.design_space.sampled_time_array, test_problem.f_star_sensor_exclusion()[0][2])
    # plt.plot(test_problem.design_space.sampled_time_array,
    #          (np.arcsin(test_problem.mission_geometry.m_target_R / (
    #                  test_problem.mission_geometry.m_target_R + test_problem.mission_geometry.spacecraft_h)) - 2 * np.sin(
    #              np.deg2rad(5))) * np.ones(test_problem.design_space.sampled_time_array.size))
    #
    # plt.show()
