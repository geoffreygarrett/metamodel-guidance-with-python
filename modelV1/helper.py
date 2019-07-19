import numpy as np
import poliastro.bodies
import poliastro.twobody.orbit
import astropy.time
import astropy.units
from collections import namedtuple

########################################################################################################################
#
#    ██████╗  █████╗ ████████╗ █████╗     ███████╗████████╗██████╗ ██╗   ██╗ ██████╗████████╗██╗   ██╗██████╗ ███████╗
#    ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔════╝╚══██╔══╝██║   ██║██╔══██╗██╔════╝
#    ██║  ██║███████║   ██║   ███████║    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║   ██║██████╔╝█████╗
#    ██║  ██║██╔══██║   ██║   ██╔══██║    ╚════██║   ██║   ██╔══██╗██║   ██║██║        ██║   ██║   ██║██╔══██╗██╔══╝
#    ██████╔╝██║  ██║   ██║   ██║  ██║    ███████║   ██║   ██║  ██║╚██████╔╝╚██████╗   ██║   ╚██████╔╝██║  ██║███████╗
#    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝
#
########################################################################################################################
SolutionLog = namedtuple("SolutionLog", "")


########################################################################################################################
#
#        ██████╗ ███████╗███╗   ██╗███████╗██████╗  █████╗ ██╗
#       ██╔════╝ ██╔════╝████╗  ██║██╔════╝██╔══██╗██╔══██╗██║
#       ██║  ███╗█████╗  ██╔██╗ ██║█████╗  ██████╔╝███████║██║
#       ██║   ██║██╔══╝  ██║╚██╗██║██╔══╝  ██╔══██╗██╔══██║██║
#       ╚██████╔╝███████╗██║ ╚████║███████╗██║  ██║██║  ██║███████╗
#        ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝
#
########################################################################################################################
def shadow_function(source_vector: np.array, observer: np.array, radius_planet: float) -> np.array:
    """
    Function to determine whether a spherical body is occulting a given position (satellite) vector.
    :param source_vector:
    :param sat_vector:
    :param radius_planet:
    :return: (int) 0 if in Eclipse, 1 if not in Eclipse.
    """
    cos_phi = np.dot(source_vector, observer) / (np.linalg.norm(source_vector) * np.linalg.norm(observer))
    if (cos_phi < 0) and (np.linalg.norm(observer) * np.sin(np.arccos(cos_phi)) < radius_planet):
        return 0
    else:
        return 1


def orbital_period(sma, mu):
    """

    :param sma: Semi-major axis.
    :param mu: Gravitational parameter of body.
    :return:
    """
    return 2 * np.pi * np.sqrt(sma ** 3 / mu)


def initial_orbit_from_ephemeris(body: poliastro.bodies.Body,
                                 epoch: astropy.time.Time) -> poliastro.twobody.orbit.Orbit:
    """
    Function for convenient return of orbit from body and epoch.
    :param body:
    :param epoch:
    :return:
    """
    return poliastro.twobody.orbit.Orbit.from_body_ephem(body, epoch)


def initial_si_state_from_ephemeris(body: poliastro.bodies.Body,
                                    epoch: astropy.time.Time) -> np.ndarray:
    """
    Function for convenient return of state from body and epoch.
    :param body:
    :param epoch:
    :return:
    """
    _initial_orbit = initial_orbit_from_ephemeris(body, epoch)
    return np.concatenate((_initial_orbit.r.si.value, _initial_orbit.v.si.value))


def initial_si_state_from_orbit(orbit: poliastro.twobody.orbit.Orbit):
    """

    :param orbit:
    :return:
    """
    return np.concatenate((orbit.r.si.value, orbit.v.si.value))


def counter(n0=0):
    """
    Simple counter.
    :param n0:
    :return:
    """
    while True:
        yield n0
        n0 += 1


def normalize_vector(vector: np.array):
    return vector / np.linalg.norm(vector)


def rotation_matrix(theta: float):
    return np.array([[np.cos(theta), np.sin(theta)],
                     [-np.sin(theta), np.cos(theta)]])


########################################################################################################################
#
#       ███╗   ███╗ ██████╗ ██████╗ ███████╗██╗         ██╗   ██╗ ██╗
#       ████╗ ████║██╔═══██╗██╔══██╗██╔════╝██║         ██║   ██║███║
#       ██╔████╔██║██║   ██║██║  ██║█████╗  ██║         ██║   ██║╚██║
#       ██║╚██╔╝██║██║   ██║██║  ██║██╔══╝  ██║         ╚██╗ ██╔╝ ██║
#       ██║ ╚═╝ ██║╚██████╔╝██████╔╝███████╗███████╗  ██╗╚████╔╝  ██║
#       ╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝  ╚═╝ ╚═══╝   ╚═╝
#
########################################################################################################################
def make2d(func):
    """
    Wrapper to remove third dimension on returned state vector.
    :param func:
    :return:
    """

    def wrapper(*args, **kwargs):
        result = func(*args, **kwargs)
        assert len(result) == 6
        result = np.concatenate((result[:2], result[3:5]))
        return result

    return wrapper


@make2d
def initial_2d_si_state_from_ephemeris(*args, **kwargs):
    """
    Wrapped version of initial_orbit_from_ephemeris to return 2d state vector for known body.
    :param args:
    :param kwargs:
    :return:
    """
    return initial_si_state_from_ephemeris(*args, **kwargs)


if __name__ == "__main__":
    def test():
        return np.array([1, 2, 3, 4, 5, 6])


    print(test())

    print(make2d(test)())
