import numpy as np
from numpy.core.umath_tests import inner1d


# Geometry.
def orbital_period(sma, mu):
    """
    :param sma: Semi-major axis.
    :param mu: Gravitational parameter of body.
    :return:
    """
    return 2 * np.pi * np.sqrt(sma ** 3 / mu)


def state_spacecraft(R, h, nu_s0, mu_m, t, period=None):
    _T = orbital_period(R + h, mu_m) if not period else period
    return (R + h) * np.concatenate(([np.cos(nu_s0 + 2 * np.pi * t / _T)],
                                     [np.sin(nu_s0 + 2 * np.pi * t / _T)])).T


def state_celestial_body(a, nu_0, t):
    return a * np.tile(np.array([np.cos(nu_0), np.sin(nu_0)]), (len(t), 1))


# def shadow_function(source_vector: np.array, observer: np.array, radius_planet: float) -> np.array:
#     """
#     Function to determine whether a spherical body is occulting a given position (satellite) vector.
#     :param source_vector:
#     :param sat_vector:
#     :param radius_planet:
#     :return: (int) 0 if in Eclipse, 1 if not in Eclipse.
#     """
#     cos_phi = np.dot(source_vector, observer) / (np.linalg.norm(source_vector) * np.linalg.norm(observer))
#     if (cos_phi < 0) and (np.linalg.norm(observer) * np.sin(np.arccos(cos_phi)) < radius_planet):
#         return 0
#     else:
#         return 1


def shadow_function(source_vector_u_vec: np.array, observer_vector_u_vec: np.array, radius_planet: float,
                    spacecraft_h: float) -> np.array:
    """
    Function to determine whether a spherical body is occulting a given position (satellite) vector.
    :param source_vector:
    :param sat_vector:
    :param radius_planet:
    :return: (int) 0 if in Eclipse, 1 if not in Eclipse.
    """
    cos_phi = inner1d(source_vector_u_vec, observer_vector_u_vec)
    a_sin_phi = (radius_planet + spacecraft_h) * np.sin(np.arccos(cos_phi))
    shadow_bool = np.where(
        (cos_phi < 0) & (a_sin_phi < radius_planet),
        1,  # <- return IF
        0)  # <- else.
    return shadow_bool, cos_phi, a_sin_phi


def a_tilde(R, h, nu_s0, nu_m0, mu_m, t):
    _T = orbital_period(R + h, mu_m)
    np.sqrt(1 - np.cos(-nu_m0 + nu_s0 + 2 * np.pi * t / _T) ** 2) * np.sqrt((R + h) ** 2)


def da_tilde_dt(R, h, nu_s0, nu_m0, mu_m, t):
    _T = orbital_period(R + h, mu_m)
    np.sqrt(2) * np.pi * np.sqrt((R + h) ** 2) * np.sin(-2 * nu_m0 + 2 * nu_s0 + 4 * np.pi * t / _T) / (
            _T * np.sqrt(1 - np.cos(-2 * nu_m0 + 2 * nu_s0 + 4 * np.pi * t / _T)))


def phi(R, h, a_m, nu_s0, nu_m0, mu_m, t):
    _T = orbital_period(R + h, mu_m)
    np.arccos(
        -a_m * (R + h) * np.cos(-nu_m0 + nu_s0 + 2 * np.pi * t / _T) / (np.sqrt(a_m ** 2) * np.sqrt((R + h) ** 2)))


def t_aux(R, h, nu_s0, nu_m0, mu_m):
    _T = orbital_period(R + h, mu_m)
    _delta_nu = nu_m0 - nu_s0
    _k_e = h * (2 * R + h) / (R ** 2 + 2 * R * h + h ** 2)
    _result = np.array([
        _T * (_delta_nu + np.arccos(-np.sqrt(_k_e))) / (2 * np.pi),
        _T * (_delta_nu + np.arccos(+np.sqrt(_k_e))) / (2 * np.pi),
        _T * (_delta_nu - np.arccos(-np.sqrt(_k_e)) + 2 * np.pi) / (2 * np.pi),
        _T * (_delta_nu - np.arccos(+np.sqrt(_k_e)) + 2 * np.pi) / (2 * np.pi)])
    return _result


def phi_condition(nu_s0, nu_m0, T, t):
    _delta_nu = nu_m0 - nu_s0
    _result = np.cos(-_delta_nu + np.pi * 2 / T * t) >= 0
    return _result


def t_solar_eclipse_solutions(R, h, nu_s0, nu_m0, mu_m):
    _T = orbital_period(R + h, mu_m)
    _t_aux1 = t_aux(R, h, nu_s0, nu_m0, mu_m)
    _t_aux2 = np.mod(_t_aux1, _T)
    return _t_aux2[phi_condition(nu_s0, nu_m0, _T, _t_aux1)]
