import numpy as np
import poliastro
import matplotlib.pyplot as plt
from poliastro.twobody import Orbit
from astropy import time
from poliastro.util import circular_velocity_fast
from poliastro.bodies import Mars
from poliastro.bodies import Earth
from poliastro.bodies import Sun
from poliastro.bodies import _Body as poliastro_body
from poliastro.twobody._states import ClassicalState, RVState
from poliastro.frames import Planes

# Custom software.
from astrotk.simulator.integrators import RK4
from astrotk.simulator.eom.test import point_mass_acceleration_2D
from astrotk.tests.test_state_values import *
from helper import *

plt.rcParams["font.family"] = "serif"
plt.rcParams["mathtext.fontset"] = "dejavuserif"


class Spacecraft(object):

    def __init__(self, h: float, parent: poliastro_body):
        """
        :param epoch: time.Time
        :param h: Altitude [km]
        """
        self.h = h
        self.parent = parent

    def orbit(self, epoch, theta=0):
        return Orbit(ClassicalState(
            self.parent,
            (self.parent.R.si.value + self.h * 1E3) * u.m,  # a
            0 * u.dimensionless_unscaled,  # e
            0 * u.rad,  # inc
            0 * u.rad,  # raan
            0 * u.rad,  # argp
            theta * u.rad,  # theta
        ), epoch, Planes.EARTH_ECLIPTIC)

    def state2D(self, epoch, theta=0):
        orbit = self.orbit(epoch, theta)
        return np.concatenate((orbit.r[:2].si.value, orbit.v[:2].si.value))


class GuidanceGeometry(object):

    @staticmethod
    def _discrete_horizon(t_spacecraft: float, s_horizon: float, n: int) -> np.array:
        """
        :param t_spacecraft: Spacecraft orbital period.
        :param s_horizon: Horizon scaling factor on spacecraft orbital period (s_horizon * T = Horizon).
        :param n: Quantity of equidistant discrete points for horizon window.
        :return: Discretised time array for horizon window.
        """
        return np.linspace(0, s_horizon * t_spacecraft, n)

    @staticmethod
    def _orbital_period(*args, **kwargs):
        if args:
            if len(args) == 1:
                assert type(args[0]) == Orbit
                return 2 * np.pi * np.sqrt(args[0].a ** 3 / args[0].parent.k)
            # elif len(args) == 2:
            #
            #     assert type(args[0]) == float
            #     assert type(args[1]) == float

        elif kwargs:
            if "orbit" in kwargs.keys():
                assert type(kwargs["orbit"]) == Orbit
                return 2 * np.pi * np.sqrt(kwargs["orbit"].a ** 3 / kwargs["orbit"].parent.k)

    def __init__(self, spacecraft_orbit_altitude, mission_target=Mars, communication_target=Earth, s_horizon=1, n=100):
        self._communication_target = communication_target  # type: poliastro_body
        self._mission_target = mission_target  # type: poliastro_body
        self._horizon_factor = s_horizon  # type: float
        self._number_of_points = n
        self._spacecraft = Spacecraft(spacecraft_orbit_altitude, self._mission_target)

    @property
    def T_spacecraft(self):
        return 2 * np.pi * np.sqrt(
            (self._mission_target.R.si.value + self._spacecraft.h * 1e3) ** 3 / self._mission_target.k.si.value)

    @property
    def horizon_array(self):
        return self._discrete_horizon(self.T_spacecraft, self._horizon_factor, self._number_of_points)

    def get_body_initial_state(self, body, epoch):
        body_orbit = Orbit.from_body_ephem(body, epoch)
        return np.concatenate((body_orbit.r[:2].si.value, body_orbit.v[:2].si.value))

    def get_system_initial_states(self, epoch):
        """

        :param epoch:
        :return:
        """
        # Body to communicate with.
        initial_communcation_body_state = self.get_body_initial_state(self._communication_target, epoch)

        # Body around which the spacecraft is orbiting.
        mission_target_body_state = self.get_body_initial_state(self._mission_target, epoch)

        # Spacecraft initial planetocentric state.
        spacecraft_initial_state = self._spacecraft.state2D(epoch, 0)

        return {
            "Spacecraft": spacecraft_initial_state,
            "Target": mission_target_body_state,
            "Communication": initial_communcation_body_state}  # type: dict

    def get_body_state_solution(self, body: poliastro_body, epoch: time.Time) -> np.array:
        return RK4.odeint(point_mass_acceleration_2D, self.get_body_initial_state(body, epoch), body.parent.k.si.value)

    def get_system_solution(self, epoch):
        initial_states = self.get_system_initial_states(epoch)
        t = self.horizon_array

        # Integrate for state history solutions of all relevant bodies.
        spacecraft_state_hist = \
            RK4.odeint(point_mass_acceleration_2D, initial_states["Spacecraft"], t, Mars.k.si.value)
        mission_target_body_state_hist = \
            RK4.odeint(point_mass_acceleration_2D, initial_states["Target"], t, Sun.k.si.value)
        communication_body_state_hist = \
            RK4.odeint(point_mass_acceleration_2D, initial_states["Communication"], t, Sun.k.si.value)

        return {
            "Spacecraft": spacecraft_state_hist,
            "Target": mission_target_body_state_hist,
            "Communication": communication_body_state_hist}  # type: dict


# guidance_mapping = {
#     "t0": time.Time('2010-01-01T00:01:06.184'),
#     "Target": Mars,
#     "Communication": Earth,
#     "Altitude": 200 * u.km,
#     "Spacecraft":
# }

# class AttitudeEvaluation(object):
#     def __init__(self, **kwargs):
#         for key in kwargs.keys():
#             setattr(self, key, kwargs[key])
#
#     def


if __name__ == "__main__":
    case = GuidanceGeometry(2000, s_horizon=0.8, n=400)
    import matplotlib.patches as patches

    EPOCH = time.Time('2010-01-01T00:01:06.184')

    sol = case.get_system_solution(EPOCH)


    def plot_one(sol, name, ax):
        ax.plot(sol[:, 0], sol[:, 1], label=name)


    # shadow_function_vectorised = np.vectorize(shadow_function)





    # fig, ax = plt.subplots(2, 1)

    # ax = []
    # ax.append(plt.subplot2grid((2, 2), (0, 0)))
    # ax.append(plt.subplot2grid((2, 2), (1, 0), colspan=2))
    # ax.append(plt.subplot2grid((2, 2), (0, 1)))

    def plot_target(sol, ax, shadows):
        # Plot 2D Geometry.
        c1 = plt.Circle((0, 0), Mars.R.si.value, color='r')
        ax.add_artist(c1)
        ax.set_aspect("equal")
        ax.arrow(0, 0, *(
                np.linalg.norm(sol["Spacecraft"][0, :2]) * sol["Target"][0, :2] / np.linalg.norm(sol["Target"][0, :2])),
                 head_width=0.5, head_length=0.7, fc='lightblue', ec='black')
        plot_one(sol["Spacecraft"], "Spacecraft", ax)


        for shadow in shadows:
            result = []
            for idx, s in enumerate(shadow):
                result.append(abs(1 - s) * sol["Spacecraft"][idx, :])
            result = np.array(result)
            plot_one(result, f"Eclipse Sector {idx}", ax)

        ax.set_ylabel("$y - coordinate$ [m]")
        ax.set_xlabel("$x - coordinate$ [m]")
        ax.scatter(*sol["Spacecraft"][0, :2], marker="x", label="Initial Position")
        ax.set_title("Mars Planetocentric Frame (J2000)")
        ax.grid(linewidth=0.2)
        ax.legend()


    def plot_geometry(sol, ax):
        theta_sample = np.linspace(0, 2 * np.pi, 200)

        ax.plot(
            np.linalg.norm(sol["Target"][0, :2]) * np.cos(theta_sample),
            np.linalg.norm(sol["Target"][0, :2]) * np.sin(theta_sample),
            label="Mars Orbit",
            color="0.75",
            linestyle="-."
        )

        ax.plot(
            np.linalg.norm(sol["Communication"][0, :2]) * np.cos(theta_sample),
            np.linalg.norm(sol["Communication"][0, :2]) * np.sin(theta_sample),
            label="Earth Orbit",
            color="0.75",
            linestyle="-."
        )

        # Plot Heliocentric Geometry.
        plot_one(sol["Target"], "Mars", ax)
        plot_one(sol["Communication"], "Earth", ax)
        ax.set_aspect("equal")
        ax.set_title(EPOCH)
        sun = plt.Circle((0, 0), 0.07 * np.linalg.norm(sol["Target"][0, :2]), color='y')
        mars = plt.Circle((sol["Target"][0, :2]), 0.07 * np.linalg.norm(sol["Target"][0, :2]), color='r')
        earth = plt.Circle((sol["Communication"][0, :2]), 0.07 * np.linalg.norm(sol["Target"][0, :2]), color='b')
        ax.set_ylim(-np.max(sol["Target"][:, 1]) * 1.2, 1.2 * np.max(sol["Target"][:, 1]))
        ax.set_xlim(-np.max(sol["Target"][:, 1]) * 1.2, 1.2 * np.max(sol["Target"][:, 1]))
        ax.add_artist(sun)
        ax.add_artist(earth)
        ax.add_artist(mars)
        ax.set_ylabel("$y - coordinate$ [m]")
        ax.set_xlabel("$x - coordinate$ [m]")
        ax.grid(linewidth=0.2)

    S = [shadow_function(-sol["Target"][i, :2], sol["Spacecraft"][i, :2], Mars.R.si.value) for i in
         range(case._number_of_points)]

    C = [shadow_function(sol["Communication"][i, :2] - sol["Target"][i, :2], sol["Spacecraft"][i, :2], Mars.R.si.value) for i in
         range(case._number_of_points)]


    fig, ax = plt.subplots(1, figsize=(6,5), dpi=300)
    # fig, ax = plt.subplots(1, figsize=(6, 2.2), dpi=300)
    # plot_geometry(sol, ax[2])
    plot_target(sol, ax, [S,C])
    # plot_geometry(sol, ax)
    # plot_one(sol["Spacecraft"], "Spacecraft", ax)

    # # Plot shadow function.
    # ax.plot(case.horizon_array, S)
    # ax.plot(case.horizon_array, C)

    # ax.set_title("Eclipse Array")
    # ax.set_xlabel("$t$ [s]")
    # ax.set_ylabel("$Eclipse\;(boolean)$")
    # ax.grid(linewidth=0.2)
    #
    # plt.legend()
    plt.show()
