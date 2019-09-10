import numpy as np
from numpy.core.umath_tests import inner1d
from numba import jit


def f_thrust_inefficiency(planned, actual, weight=1):
    _dot_product = inner1d(planned, actual)
    _aux = (1 - _dot_product) * weight
    _val = (1 / _aux.size) * np.trapz(_aux)
    return _aux, _val


def f_power_from_available(panel_pointing_u, sun_pointing_u, solar_eclipse_bool):
    _dot_product = np.where(solar_eclipse_bool, 0, inner1d(panel_pointing_u, sun_pointing_u))  # Remove for eclipse.
    _aux = np.where(_dot_product > 0, _dot_product, 0)  # Filter out pointing from wrong side.
    _val = (1 / float(solar_eclipse_bool.size - solar_eclipse_bool.nonzero()[0].size)) * np.trapz(_aux)
    return _aux, _val


def f_max_angular_rate(omega):
    _aux = np.maximum.accumulate(np.abs(omega))
    _val = _aux[-1]
    return _aux, _val


def f_max_angular_acceleration(alpha):
    _aux = np.maximum.accumulate(np.abs(alpha))
    _val = _aux[-1]
    return _aux, _val


def f_star_sensor_exclusion(sensor1_pointing_u, sensor2_pointing_u, sun_pointing_u, solar_eclipse_bool, body_u, R, h):
    _aux1 = inner1d(sensor1_pointing_u, sun_pointing_u) * (1 - solar_eclipse_bool) + (
            np.arcsin(R / (R + h)) + inner1d(sensor1_pointing_u, body_u)) - 2
    # + inner1d(sensor1_pointing_u, body_u)
    _aux2 = inner1d(sensor2_pointing_u, sun_pointing_u) * (1 - solar_eclipse_bool) + (
            np.arcsin(R / (R + h)) + inner1d(sensor2_pointing_u, body_u)) - 2
    # _aux2 = inner1d(sensor2_pointing_u, body_u)
    _aux_sum = _aux1 + _aux2
    _aux_max = np.maximum.accumulate(_aux_sum)
    _val = _aux_max[-1]
    return (_aux1, _aux2, _aux_sum, _aux_max), _val
