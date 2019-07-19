import poliastro.bodies
import poliastro.twobody
from geometry import *

# temp
import matplotlib.pyplot as plt
import astropy.units as u
from poliastro.bodies import Mars, Earth
from spacecraft import Spacecraft, spacecraft_configuration_2d_example
from representation import PolynomialRepresentation
from helper import *

# Custom software.
from astrotk.simulator.integrators import RK4
from astrotk.simulator.eom.test import point_mass_acceleration_2D

# Discrete integration.
from scipy.integrate import cumtrapz
from numpy.core.umath_tests import inner1d


class _BaseProblem2D(object):
    """
    Problem Description: Spacecraft orbiter mission performed around target body (mission_target), with telemetry link
    to communication body (communication_target).

    ~ spacecraft : Spacecraft body which orbits around the mission_target body.

    ~ mission_target : Target body around which the Spacecraft orbit is defined.
            - Occults Spacecraft orbit for solar radiation.

    ~ communication_target : Target for telemetry. Currently only compatible with heliocentric orbital body.
            - Acts as source for telemetry link occulted by target_body.

    """

    #  ██████╗ ██████╗      ██╗███████╗ ██████╗████████╗██╗██╗   ██╗███████╗███████╗
    # ██╔═══██╗██╔══██╗     ██║██╔════╝██╔════╝╚══██╔══╝██║██║   ██║██╔════╝██╔════╝
    # ██║   ██║██████╔╝     ██║█████╗  ██║        ██║   ██║██║   ██║█████a  ███████╗
    # ██║   ██║██╔══██╗██   ██║██╔══╝  ██║        ██║   ██║╚██╗ ██╔╝██╔══╝  ╚════██║
    # ╚██████╔╝██████╔╝╚█████╔╝███████╗╚██████╗   ██║   ██║ ╚████╔╝ ███████╗███████║
    #  ╚═════╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝   ╚═╝  ╚═══╝  ╚══════╝╚══════╝
    @staticmethod
    def _solar_power_log(sun_vector_array, solar_panel_vector_array, sun_occulted_array, area):
        """
        [Objective / Inequality constraint] # TODO: Check whether to implement as inequality.
        :param sun_vector_array:
        :param solar_panel_vector_array:
        :param sun_occulted_array:
        :return:
        """
        # Calculate solar radiation at location of target body at t0.
        solar_radiation = 1.3608e3 * (u.W / u.m / u.m) / (
                (np.linalg.norm(u.AU.to("m") / sun_vector_array[0])) ** 2) * u.m

        # Calculate Sun unit vectors.
        s_v = np.apply_along_axis(normalize_vector, axis=1, arr=sun_vector_array)

        # Calculate solar panel unit vectors.
        p_v = np.apply_along_axis(normalize_vector, axis=1, arr=solar_panel_vector_array)

        # Calculate dot product.
        dot_product = inner1d(s_v, p_v)

        # Remove negative (obtuse values) for incidence on back of solar panel.
        dot_product = np.where(dot_product >= 0, dot_product, 0)

        # Calculate the power incident on the solar array, neglecting efficiencies. # TODO: Include efficiencies.
        return sun_occulted_array * solar_radiation * area * dot_product

    @staticmethod
    def _thrust_inefficiency_log(planned_thrust_direction_array, weight_array, thruster_pointing_vector_array):
        """
        [Objective]
        :param planned_thrust_direction_array:
        :param weight_array:
        :param thruster_pointing_vector_array:
        :return:
        """
        # Calculate planned thrust direction unit vectors.
        planned_v = np.apply_along_axis(normalize_vector, axis=1, arr=planned_thrust_direction_array)

        # Calculate actual thruster direction unit vectors.
        actual_v = np.apply_along_axis(normalize_vector, axis=1, arr=thruster_pointing_vector_array)

        # Calculate dot product.
        dot_product = inner1d(planned_v, actual_v)

        # Weighted mismatch penalty.
        return 1 - (dot_product * weight_array)

    #  ██████╗ ██████╗ ███╗   ██╗███████╗████████╗██████╗  █████╗ ██╗███╗   ██╗████████╗███████╗
    # ██╔════╝██╔═══██╗████╗  ██║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
    # ██║     ██║   ██║██╔██╗ ██║███████╗   ██║   ██████╔╝███████║██║██╔██╗ ██║   ██║   ███████╗
    # ██║     ██║   ██║██║╚██╗██║╚════██║   ██║   ██╔══██╗██╔══██║██║██║╚██╗██║   ██║   ╚════██║
    # ╚██████╗╚██████╔╝██║ ╚████║███████║   ██║   ██║  ██║██║  ██║██║██║ ╚████║   ██║   ███████║
    # ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝
    @staticmethod
    def _constraint_max_omega(max_angular_rate, angular_rate_array):
        """
        [Inequality constraint]
        :param max_angular_rate:
        :param angular_rate_array:
        :return:
        """
        return - (np.abs(angular_rate_array) - max_angular_rate)

    @staticmethod
    def _constraint_max_alpha(max_angular_acceleration, angular_acceleration_array):
        """
        [Inequality constraint]
        :param max_torque:
        :param torque_array:
        :return:
        """
        return - (np.abs(angular_acceleration_array) - max_angular_acceleration)

    @staticmethod
    def _constraint_star_sensor_solar_exclusion(sun_vector_array, star_sensor_vector_array, sun_occulted_array,
                                                exclusion_angle):
        """
        [Inequality constraint]
        :param star_sensor_vector_array:
        :param sun_vector_array:
        :param exclusion_angle:
        :return:
        """
        # Calculate star sensor unit vectors.
        star_s_v = np.apply_along_axis(normalize_vector, axis=1, arr=star_sensor_vector_array)

        # Calculate Sun unit vectors.
        s_v = np.apply_along_axis(normalize_vector, axis=1, arr=sun_vector_array)

        # Calculate dot product.
        dot_product = inner1d(s_v, star_s_v)

        # Remove negative (obtuse values) for incidence on back of solar panel.
        dot_product = np.where(dot_product >= np.cos(exclusion_angle), dot_product, 0)

        # Calculate the power incident on the solar array, neglecting efficiencies. # TODO: Include efficiencies.
        return - (sun_occulted_array * dot_product)

    def __init__(self, geometry: MissionGeometry, spacecraft: Spacecraft, horizon_scale=1, N=50):
        self._mission_geometry = geometry
        self._spacecraft = spacecraft
        self._horizon = geometry.entities["spacecraft"].period.si.value * horizon_scale
        self._N = N
        self._time_array = np.linspace(0, self._horizon, N)
        self._decoupled_state_history = self._propagate_system_states()
        # Planned thrust direction (along-track).
        self._planned_thrust_vectors = self.component_pointing_history(self.spacecraft.components("thruster")["r"],
                                                                       np.linspace(0, 2 * np.pi, self.N))

    # Properties.

    @property
    def state(self):
        return self._decoupled_state_history

    @property
    def spacecraft(self):
        return self._spacecraft

    @property
    def geometry(self):
        return self._mission_geometry

    @property
    def horizon(self):
        return self._horizon

    @property
    def time_array(self):
        return self._time_array

    @property
    def N(self):
        return self._N

    # ██████╗ ██████╗  ██████╗ ██████╗  █████╗  ██████╗  █████╗ ████████╗██╗ ██████╗ ███╗   ██╗
    # ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██╔══██╗██╔════╝ ██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║
    # ██████╔╝██████╔╝██║   ██║██████╔╝███████║██║  ███╗███████║   ██║   ██║██║   ██║██╔██╗ ██║
    # ██╔═══╝ ██╔══██╗██║   ██║██╔═══╝ ██╔══██║██║   ██║██╔══██║   ██║   ██║██║   ██║██║╚██╗██║
    # ██║     ██║  ██║╚██████╔╝██║     ██║  ██║╚██████╔╝██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║
    # ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝
    def _propagate_body(self, body_id: str):
        return RK4.odeint(point_mass_acceleration_2D, make2d(self._mission_geometry.get_initial_state)(body_id),
                          self._time_array, self._mission_geometry.entities[body_id].attractor.k.si.value)

    def _propagate_system_states(self):
        result = {}
        for body_id in self._mission_geometry.entities.keys():
            result.update({body_id: self._propagate_body(body_id)})
        return result

    #  █████╗ ██╗   ██╗██╗  ██╗██╗██╗     ██╗ █████╗ ██████╗ ██╗   ██╗
    # ██╔══██╗██║   ██║╚██╗██╔╝██║██║     ██║██╔══██╗██╔══██╗╚██╗ ██╔╝
    # ███████║██║   ██║ ╚███╔╝ ██║██║     ██║███████║██████╔╝ ╚████╔╝
    # ██╔══██║██║   ██║ ██╔██╗ ██║██║     ██║██╔══██║██╔══██╗  ╚██╔╝
    # ██║  ██║╚██████╔╝██╔╝ ██╗██║███████╗██║██║  ██║██║  ██║   ██║
    # ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝
    def x_2_dynamics(self, x):
        raise NotImplementedError("Not implemented in base class representation.")

    def solar_occultation_history(self):
        """
        Returns an array of integers, interpreted as boolean (0/1); 0 - occulted, 1 - non-occulted.
        :return:
        """
        return np.array(
            [shadow_function(
                source_vector=- self.state["mission_target"][i, :2],
                observer=self.state["spacecraft"][i, :2],
                radius_planet=self._mission_geometry.entities["spacecraft"].attractor.R.si.value)
                for i in range(self.N)]
        )

    def communication_occultation_history(self):
        """
        Returns an array of integers, interpreted as boolean (0/1); 0 - occulted, 1 - non-occulted.
        :return:
        """
        return np.array(
            [shadow_function(
                source_vector=self.state["communication_target"][i, :2] - self.state["mission_target"][i, :2],
                observer=self.state["spacecraft"][i, :2],
                radius_planet=self._mission_geometry.entities["spacecraft"].attractor.R.si.value)
                for i in range(self.N)]
        )

    def solar_panel_power_history(self, spacecraft_attitude_history):
        """
        (Array of arrays for each solar panel)
        :return:
        """
        _return = np.array([])
        for solar_panel in self.spacecraft.components("solar_panels"):
            _pointing_hist = self.component_pointing_history(solar_panel["r"], spacecraft_attitude_history)
            _energy_horizon = self._solar_power_log(
                -self.state["mission_target"][:, :2],
                # w.r.t. target body, to reduce computation.
                # TODO: Check if computational gain is worth it.
                _pointing_hist,
                self.solar_occultation_history(),
                solar_panel["area"])
            _return = np.array([_energy_horizon]) if (
                    len(_return) == 0) else np.concatenate((_return, np.array([_energy_horizon])), axis=0)
        return _return

    def constraint_star_sensor_solar_exclusion_log(self, spacecraft_attitude_history):
        """
        
        :param spacecraft_attitude_history: 
        :return: Array of arrays of negative dot product values for violated exclusion angle points for star sensors.
        """
        _return = np.array([])
        for star_sensor in self.spacecraft.components("star_sensors"):
            _pointing_hist = self.component_pointing_history(star_sensor["r"], spacecraft_attitude_history)
            _sensor_horizon = self._constraint_star_sensor_solar_exclusion(
                -self.state["mission_target"][:, :2],
                # w.r.t. target body, to reduce computation.
                # TODO: Check if computational gain is worth it.
                _pointing_hist,
                self.solar_occultation_history(),
                star_sensor["solar_exclusion_angle"])
            _return = np.array([_sensor_horizon]) if (
                    len(_return) == 0) else np.concatenate((_return, np.array([_sensor_horizon])), axis=0)
        return _return

    @staticmethod
    def component_pointing_history(r_component_wrt_body, spacecraft_attitude_history):
        """
        # TODO: Add cache.
        :param r_component_wrt_body: 
        :param spacecraft_attitude_history: 
        :return: 
        """
        return np.array(
            [np.matmul(rotation_matrix(_theta), r_component_wrt_body) for _theta in spacecraft_attitude_history])

    # Temp
    def fitness_auxiliary_from_dynamics(self, spacecraft_alpha_hist, spacecraft_omega_hist, spacecraft_theta_hist):

        # Spacecraft thrust direction history.
        _thrust_vector_log = self.component_pointing_history(self.spacecraft.components("thruster")["r"],
                                                             spacecraft_theta_hist)

        # Power horizon
        _solar_power_log = self.solar_panel_power_history(spacecraft_theta_hist)

        # Cumulatively integrate the instantaneous power w.r.t. time for energy horizon.
        _solar_energy_log = np.apply_along_axis(cumtrapz, 1, _solar_power_log, self.time_array)

        # Thrust inefficiency.
        _thrust_inefficiency_log = self._thrust_inefficiency_log(self._planned_thrust_vectors,
                                                                 np.ones(self.N),  # Constant weight.
                                                                 _thrust_vector_log)

        # Max angular rate.
        _constraint_max_omega = self._constraint_max_omega(0.1, spacecraft_omega_hist)

        # Max angular acceleration.
        _constraint_max_alpha = self._constraint_max_alpha(0.01, spacecraft_alpha_hist)

        # Star sensor exclusion.
        _star_sensor_solar_exclusion_log = self.constraint_star_sensor_solar_exclusion_log(spacecraft_theta_hist)

        return [_thrust_vector_log,
                _solar_power_log,
                _solar_energy_log,
                _thrust_inefficiency_log,
                _constraint_max_omega,
                _constraint_max_alpha,
                _star_sensor_solar_exclusion_log]

    def fitness_from_dynamics(self, spacecraft_alpha_hist, spacecraft_omega_hist, spacecraft_theta_hist):

        (_actual_thrust_vectors,
         _power_over_horizon,
         _energy_over_horizon,
         _thrust_inefficiency_history,
         _constraint_max_angular_rate,
         _constraint_max_angular_acceleration,
         _star_sensor_exclusion_history) = self.fitness_auxiliary_from_dynamics(spacecraft_alpha_hist,
                                                                                spacecraft_omega_hist,
                                                                                spacecraft_theta_hist)

        return [
            cumtrapz(_thrust_inefficiency_history, self.time_array)[-1] / self.horizon - np.max(
                np.abs(spacecraft_theta_hist))
            # (_energy_over_horizon[0][-1] / 3600 - 700) + np.max(np.abs(spacecraft_theta_hist)),
            # np.min(_star_sensor_exclusion_history[0]),
            # np.min(_star_sensor_exclusion_history[1]),
            # np.min(_max_angular_rate),
            # np.min(_max_angular_acceleration),

            # Add communication.
        ]

    def fitness_function(self, x):
        return self.fitness_from_dynamics(*self.x_2_dynamics(x))

    @property
    def dof(self):
        raise NotImplementedError("Not implemented in base class.")

    # VISUALISATION
    def plot(self, x):

        # Independent history of spacecraft dynamics.
        (_spacecraft_alpha_log,
         _spacecraft_omega_log,
         _spacecraft_theta_log) = self.x_2_dynamics(x)

        # Dependent histories on the spacecraft dynamics.
        (_actual_thrust_log,
         _solar_power_log,
         _solar_energy_log,
         _thrust_inefficiency_log,
         _constraint_max_omega_log,
         _constraint_max_alpha_log,
         _constraint_star_sensor_solar_exclusion_log
         ) = self.fitness_auxiliary_from_dynamics(_spacecraft_alpha_log,
                                                  _spacecraft_omega_log,
                                                  _spacecraft_theta_log)

        fig1, ax1 = plt.subplots(3, 1, figsize=(10, 5), dpi=300)

        ax1[0].set_title(f"Spacecraft dynamics\n{self.dof + 4}$^{{th}}$ degree Polynomial")
        ax1[0].set_ylabel("$\\alpha$ [rad/s/s]")
        ax1[0].grid()
        ax1[0].plot(self.time_array / self.horizon, _spacecraft_alpha_log)

        ax1[1].set_ylabel("$\\omega$ [rad/s]")
        ax1[1].grid()
        ax1[1].plot(self.time_array / self.horizon, _spacecraft_omega_log)

        ax1[2].set_ylabel("$\\theta$ [rad]")
        ax1[2].grid()
        ax1[2].plot(self.time_array / self.horizon, _spacecraft_theta_log)
        ax1[2].set_xlabel("Time, $t$ [-]")

        # return
        plt.show()


class PolynomialFormulation2D(_BaseProblem2D):
    """
    Implementation of n_degree polynomial representation of solution space.
    """

    def __init__(self, geometry: MissionGeometry, spacecraft: Spacecraft, n_polynomial: int, horizon_scale=1, N=50):
        super().__init__(geometry, spacecraft, horizon_scale, N)
        self._polynomial_representation = PolynomialRepresentation(n_polynomial, self._horizon)
        self.n_polynomial = n_polynomial

    def x_2_dynamics(self, x):
        dynamic_equations = self._polynomial_representation.analytical_solution_functions(x, vectorised=True)

        # Dynamic history of spacecraft.
        spacecraft_alpha_hist = dynamic_equations["alpha"](self._time_array)
        spacecraft_omega_hist = dynamic_equations["omega"](self._time_array)
        spacecraft_theta_hist = dynamic_equations["theta"](self._time_array)

        return spacecraft_alpha_hist, spacecraft_omega_hist, spacecraft_theta_hist

    #
    # def plot(self, x):
    #     dynamic_equations = self._polynomial_representation.analytical_solution_functions(x, vectorised=True)
    #
    #     # Dynamic history of spacecraft.
    #     spacecraft_alpha_hist = dynamic_equations["alpha"](self._time_array)
    #     spacecraft_omega_hist = dynamic_equations["omega"](self._time_array)
    #     spacecraft_theta_hist = dynamic_equations["theta"](self._time_array)
    #
    #     # Planned thrust direction (along-track).
    #     _planned_thrust_vectors = self.component_pointing_history(self.spacecraft.components("thruster")["r"],
    #                                                               np.linspace(0, 2 * np.pi, self.N))
    #
    #     # Spacecraft thrust direction history.
    #     _actual_thrust_vectors = self.component_pointing_history(self.spacecraft.components("thruster")["r"],
    #                                                              spacecraft_theta_hist)
    #
    #     # Power horizon
    #     _power_horizon = self.solar_panel_power_history(spacecraft_theta_hist)
    #
    #     # Cumulatively integrate the instantaneous power w.r.t. time for energy horizon.
    #     _energy_horizon = np.apply_along_axis(cumtrapz, 1, _power_horizon, self.time_array)
    #
    #     # Thrust efficiency.
    #     _thrust_efficiency = self._thrust_efficiency(_planned_thrust_vectors, np.ones(self.N), _actual_thrust_vectors)
    #
    #     # Max angular rate.
    #     _max_angular_rate = self._max_angular_rate(0.1, spacecraft_omega_hist)
    #
    #     # Max angular acceleration.
    #     _max_angular_acceleration = self._max_angular_rate(0.01, spacecraft_alpha_hist)
    #
    #     # Star sensor exclusion.
    #     _star_sensor_exclusion_history = self.star_sensor_exclusion_history(spacecraft_theta_hist)
    #
    #     fig, ax = plt.subplots(4, 1, figsize=(10, 5))
    #     ax[0].plot(self.time_array, spacecraft_alpha_hist)
    #     ax[0].set_title("alpha")
    #
    #     ax[1].plot(self.time_array, spacecraft_omega_hist)
    #     ax[1].set_title("omega")
    #
    #     ax[2].plot(self.time_array, spacecraft_theta_hist)
    #     ax[2].set_title("theta")
    #     plt.show()
    #     # return [
    #     #     -cumtrapz(_thrust_efficiency, self.time_array)[-1] / self.horizon,
    #     #     # -(_energy_horizon[0][-1] / 3600 - 700),
    #     #     # np.min(_star_sensor_exclusion_history[0]),
    #     #     # np.min(_star_sensor_exclusion_history[1]),
    #     #     # np.min(_max_angular_rate),
    #     #     # np.min(_max_angular_acceleration),
    #     #
    #     #     # Add communication.
    #     # ]

    @property
    def dof(self):
        return int(self.n_polynomial - 4)

    # plt.plot(self._time_array[:-1],
    #          cumtrapz(_star_sensor_exclusion_history[0] + _star_sensor_exclusion_history[1], self.time_array))

    # plt.plot(self._time_array[:-1], cumtrapz(_thrust_efficiency, self.time_array)/self.horizon)
    # # plt.plot(self._time_array, _max_angular_acceleration)
    # # plt.plot(self._time_array, _thrust_efficiency)
    # # plt.plot(self._time_array[:-1], _energy_horizon[0] / np.max(_energy_horizon[0]))
    # # # plt.plot(self._time_array, _power_horizon[0] / np.max(_power_horizon[0]))
    # # plt.plot(self._time_array[:-1], _energy_horizon[1] / np.max(_energy_horizon[1]))
    # # plt.plot(self._time_array[:-1], _energy_horizon[1] / np.max(_energy_horizon[1]))
    # # # plt.plot(self._time_array, _power_horizon[1] / np.max(_power_horizon[1]))
    # # # plt.plot(self._time_array, spacecraft_theta_hist)
    # plt.show()
    # total_energy = _energy_horizon[0][-1]
    # print(total_energy / (3600))


# Define the geometrical configuration of the 2D problem.
epoch = time.Time('2010-01-01T00:01:06.184', scale="tdb")

spacecraft_h = 200e3  # [m]

geometry_configuration = {

    # Define Mars-centric starting orbit for spacecraft.
    "spacecraft": Orbit.from_classical(
        Mars,
        (Mars.R.si.value + spacecraft_h) * u.m,  # a
        0 * u.dimensionless_unscaled,  # e
        0 * u.rad,  # inc
        0 * u.rad,  # raan
        0 * u.rad,  # argp
        0 * u.rad,  # theta
    ),

    # Retrieve initial state of Mars as mission target.
    "mission_target": Orbit.from_body_ephem(Mars, epoch),

    # Retrieve initial state of Earth as communication target.
    "communication_target": Orbit.from_body_ephem(Earth, epoch)
}

# Retrieve the geometry of the planets involved in the defined problem.
mission_geometry = MissionGeometry(epoch, geometry_configuration)

# Retrieve the geometry of the 2D example spacecraft for component information.
spacecraft = Spacecraft(spacecraft_configuration_2d_example)

# Define representation of the decision space for the posed 2D problem.
test = PolynomialFormulation2D(mission_geometry, spacecraft, n_polynomial=8, N=50)


import pygmo as pg


class my_constrained_udp:

    def fitness(self, x):
        return test.fitness_function(x)

        # return [obj, ce1,ce2,ce3,ce4,ci1,ci2]

    def get_bounds(self):
        return ([-10] * test.dof, [10] * test.dof)

    def gradient(self, x):
        return pg.estimate_gradient_h(lambda x: self.fitness(x), x)


if __name__ == "__main__":
    def optimise_test():
        prob = pg.problem(my_constrained_udp())
        algo = pg.algorithm(pg.sea(gen=20))
        algo.set_verbosity(1)  # in this case this correspond to logs each 200 objevals
        pop = pg.population(prob=my_constrained_udp(), size=200)
        pop = algo.evolve(pop)
        print(pop.champion_x)


    optimise_test()

    # test.plot([-5.24821243, - 1.25757682, 9.62311827, 4.54969054, - 7.85524258, 7.9555992])
