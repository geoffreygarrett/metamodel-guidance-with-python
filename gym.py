from poliastro.bodies import Mars, Sun, Earth
from astropy import units as u
import poliastro
from poliastro.twobody import orbit
from astropy import time
import numpy as np
from math import *


def rounding_precision(expected):
    return eval('10E-{}'.format(len(str(expected).split('.')[1]) + 1))


class OrbitalExpressions:
    @staticmethod
    def orbit_type(e):
        if e < 1.0:
            return "Elliptical"
        elif e == 1:
            return "Parabolic"
        elif e > 1.0:
            return "Hyperbolic"

    @staticmethod
    def a(r, v, mu):
        return 1 / ((2.0 / r) - (v ** 2 / mu))

    @staticmethod
    def r(p, e, theta):
        return p / (1.0 + e * cos(theta))

    @staticmethod
    def H(mu, a, e):
        return sqrt(mu * a * (1 - e ** 2))

    def n(self, mu, a, e):
        """
        :param mu:
        :param a:
        :param e:
        :return: Mean anomaly (n)
        """
        _orbit_type = self.orbit_type(e)
        if _orbit_type is "Elliptical":
            return sqrt(mu / (a ** 3))
        elif _orbit_type is "Hyperbolic":
            return sqrt(mu / (- a ** 3))
        elif _orbit_type is "Parabolic":
            return sqrt(mu / ((a * (1 - e ** 2)) ** 3))

    def theta(self, e, _M):
        E = self.E(e, M=_M)
        theta = 2 * atan(sqrt((1 + e) / (1 - e)) * tan(E / 2))
        return 2 * pi + theta if theta <= 0 else theta

    def r_p(self, a, e):
        """
        :param a:
        :param e:
        :return: Radius of periapsis (r_p)
        """
        _orbit_type = self.orbit_type(e)
        if _orbit_type is "Elliptical":
            return a * (1 - e)
        elif _orbit_type is "Hyperbolic":
            return (a * (1 - e ** 2)) / 2
        elif _orbit_type is "Parabolic":
            return a * (1 - e)

    def r_a(self, a, e):
        if e < 1.0:
            return a * (1 + e)
        else:
            raise AttributeError(
                "Radius of apoapsis (r_a) cannot be computed for {} trajectory.".format(self.orbit_type(e))
            )

    def theta_max(self, e):
        if e > 1.0:
            return acos(- 1.0 / e)
        else:
            raise AttributeError(
                "θ_max can only be computed for Hyperbolic trajectories. Not applicable to {} trajectory.".format(
                    self.orbit_type(e))
            )

    @staticmethod
    def E(e, theta=None, M=None):
        """
        :param e:
        :param theta:
        :return: Eccentric anomaly (E)
        """
        if theta:
            E = 2 * atan(sqrt((1 - e) / (1 + e)) * tan(theta / 2))
        elif M:
            dE = 1
            E = M
            while abs(dE) >= max([10E-5 * rounding_precision(M), 10E-12]):
                E_old = E
                E = E - (E - e * sin(E) - M) / (1 - e * cos(E))
                dE = E - E_old

        else:
            raise SystemError("Theta or M must be given.")
        return E

    def F(self, e, theta):
        """
        :param e:
        :param theta:
        :return: Hyperbolic anomaly (F)
        """
        F = 2 * atanh(sqrt((e - 1) / (e + 1)) * tan(theta / 2))
        return F + 2 * pi if F <= 0 else F

    def M(self, e, theta):
        """
        :param mu:
        :param a:
        :param t:
        :param tau:
        :return: Mean anomaly (M)
        """
        if e < 1.0:
            M = self.E(e, theta) - e * sin(self.E(e, theta))
            return M + 2 * pi if M <= 0 else M
        elif e > 1.0:
            M = e * sinh(self.F(e, theta)) - self.F(e, theta)
            return M + 2 * pi if M <= 0 else M
        elif e == 1:
            return 0.5 * (tan(theta / 2) + 1.0 / 3 * tan(theta / 2) ** 3)

    def dt(self, e, theta, mu, a):
        return self.M(e, theta) / self.n(mu, a, e)

    # TODO: Complete and add test for dt calculation.

    def tau(self, time, e, theta, mu, a):
        """
        :param time:
        :param e:
        :param theta:
        :param mu:
        :param a:
        :return:
        """
        return time + self.dt(e, theta, mu, a)
    # TODO: Complete and add test for tau calculation.


def classical2vector(a, e, inc, raan, argp, theta, mu):
    _cos_raan = np.cos(raan)
    _sin_raan = np.sin(raan)
    _cos_argp = np.cos(argp)
    _sin_argp = np.sin(argp)
    _cos_inc = np.cos(inc)
    _sin_inc = np.sin(inc)
    _theta = theta
    _r = OrbitalExpressions().r(a * (1 - e ** 2), e, theta)  # TODO: Check
    _e = e

    _l1 = (_cos_raan * _cos_argp - _sin_raan * _sin_argp * _cos_inc)
    _l2 = (-_cos_raan * _sin_argp - _sin_raan * _cos_argp * _cos_inc)
    _m1 = (_sin_raan * _cos_argp + _cos_raan * _sin_argp * _cos_inc)
    _m2 = (-_sin_raan * _sin_argp + _cos_raan * _cos_argp * _cos_inc)
    _n1 = _sin_argp * _sin_inc
    _n2 = _cos_argp * _sin_inc

    _aux = np.array([_r * np.cos(_theta), _r * np.sin(_theta)]).T
    _transformation = np.array([[_l1, _l2],
                                [_m1, _m2],
                                [_n1, _n2]])

    # Position
    _xyz = np.matmul(_transformation, _aux)
    _x = _xyz[0]
    _y = _xyz[1]
    _z = _xyz[2]

    # Velocity
    _H = OrbitalExpressions().H(mu, a, e)
    _v_x = mu / _H * (-_l1 * np.sin(_theta) + _l2 * (_e + np.cos(_theta)))
    _v_y = mu / _H * (-_m1 * np.sin(_theta) + _m2 * (_e + np.cos(_theta)))
    _v_z = mu / _H * (-_n1 * np.sin(_theta) + _n2 * (_e + np.cos(_theta)))
    return np.array([_x, _y, _z]), np.array([_v_x, _v_y, _v_z])


def vector2classical(r, v, mu):
    _r = np.linalg.norm(r)
    _v = np.linalg.norm(v)
    _h = np.cross(r, v)
    _N = np.cross(np.array([0, 0, 1]).T, _h)
    _N_xy = np.sqrt(_N[0] ** 2 + _N[1] ** 2)
    _a = OrbitalExpressions().a(_r, _v, mu)
    _e_vec = (np.cross(v, _h) / mu) - (r / _r)
    _e = np.linalg.norm(_e_vec)
    _inc = np.arccos(_h[-1] / np.linalg.norm(_h))
    _raan = np.arctan2(_N[1] / _N_xy, _N[0] / _N_xy)

    _s1 = 1 if np.dot(np.cross(_N / np.linalg.norm(_N), _e_vec), _h) > 0 else -1
    _argp = _s1 * np.arccos(
        np.dot(_e_vec / np.linalg.norm(_e_vec),
               _N / np.linalg.norm(_N))
    )

    _s2 = 1 if np.dot(np.cross(_e_vec, r), _h) > 0 else -1
    _theta = _s2 * np.arccos(
        np.dot(
            r / np.linalg.norm(r),
            _e_vec / np.linalg.norm(_e_vec))
    )

    _theta = 2 * np.pi + _theta if _theta <= 0 else _theta
    _raan = 2 * np.pi + _raan if _raan <= 0 else _raan
    _argp = 2 * np.pi + _argp if _argp <= 0 else _argp

    return _a, _e, _inc, _raan, _argp, _theta


constraints = {
    "power_budget": 0 * u.W * u.hr,
    "max_angular_rate": 0 * (u.rad / u.s),
    "max_torque": 0 * (u.N / u.m),
    "star_tracker_fov_clearance": 0 * u.rad,
    "horizon_thrust_cost": 0 * u.dimensionless_unscaled
}

cost = {
    "power_budget": 1,
    "max_angular_rate": 0 * (u.rad / u.s),
    "max_torque": 0 * (u.N / u.m),
    "star_tracker_fov_clearance": 0 * u.rad,
    "horizon_thrust_cost": 0 * u.dimensionless_unscaled
}


# class Spacecraft(object):
#     def __init__(self):
#
#     @property
#     def state_history(self):
#         """
#         [x, y, theta]
#         :return:
#         """

class SpacecraftConfiguration(object):
    def __init__(self):
        self.star_sensors = [45, 360 - 45, 180]
        self.solar_panels = 90
        self.antenna = 0


class DemonstrationGym1(object):
    """
    The demonstration environment initiates at t0 epoch and concerns only N * p_i attitude state points for one orbital
    period of the planetary body.
    """
    def __init__(self, t0, planetary_body, N, horizon=1.0, h=200 * u.km):
        planetary_orbit = orbit.Orbit.from_body_ephem(planetary_body, t0)
        earth_orbit = orbit.Orbit.from_body_ephem(Earth, t0)
        spacecraft_orbit = orbit.Orbit.from_classical(planetary_body,
                                                      Mars.R + h,
                                                      0 * u.dimensionless_unscaled,
                                                      0 * u.rad,
                                                      0 * u.rad,
                                                      0 * u.rad,
                                                      0 * u.rad)
        planetary_orbit = orbit.Orbit.from_classical(Sun, planetary_orbit.a,
                                                     planetary_orbit.ecc,
                                                     0 * u.rad,
                                                     planetary_orbit.raan,
                                                     planetary_orbit.argp,
                                                     planetary_orbit.nu)
        # spacecraft_orbit =

        # @classmethod
        # @u.quantity_input(a=u.m, ecc=u.one, inc=u.rad, raan=u.rad, argp=u.rad, nu=u.rad)
        # def from_classical(
        #         cls,
        #         attractor,
        #         a,
        #         ecc,
        #         inc,
        #         raan,
        #         argp,
        #         nu,
        #         epoch=J2000,
        #         plane=Planes.EARTH_EQUATOR,
        # ):


class AttitudeGuidanceGym2D(object):

    def __init__(self, central_body=Sun, planetary_body=Mars, epoch=time.Time("2010-01-01T00:00:00", scale="tdb")):
        central_body_orbit = orbit.Orbit.from_body_ephem(central_body, epoch)
        planetary_body_orbit = orbit.Orbit.from_body_ephem(planetary_body, epoch)
        print(central_body_orbit)


class AttitudeGuidanceGym3D(object):

    def __init__(self, central_body=Sun, planetary_body=Mars, epoch=time.Time("2010-01-01T00:00:00", scale="tdb")):
        central_body_orbit = orbit.Orbit.from_body_ephem(central_body, epoch)
        planetary_body_orbit = orbit.Orbit.from_body_ephem(planetary_body, epoch)
        print(central_body_orbit)

        # if "power_budget" in kwargs.keys():
        #
        # if "max_angular_rate" in kwargs.keys():
        #
        # if "max_torque" in kwargs.keys():
        #
        # if "star_tracker_fov_clearance" in kwargs.keys():

    # def cost(self, p):
    #
    # def constraint(self, p):
    #
    #
    # def


if __name__ == "__main__":
    PLANETARY_BODY = Mars
    INITIAL_STATE_CLASSICAL = [

        Mars,  # attractor
        Mars.R + 300 * u.km,  # a
        0.02 * u.dimensionless_unscaled,  # e
        30 * u.deg,  # inc
        0 * u.deg,  # raan
        0 * u.deg,  # argp
        0 * u.deg,  # nu
        # Reference epoch
        # Reference plane

    ]

    test = SimpleAttitudeGuidanceGym()
