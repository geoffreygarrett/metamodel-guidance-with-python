import numpy as np
from numpy.core.umath_tests import inner1d
from numba import jit
from scipy import integrate


def f_thrust_inefficiency(planned, actual, weight=1):
    _dot_product = inner1d(planned, actual)
    _aux = (1 - _dot_product) * weight
    _val = (1 / _aux.size) * np.trapz(_aux)
    return _aux, _val


def f_power_from_available(panel_pointing_u, sun_pointing_u, solar_eclipse_bool):
    _dot_product = np.where(solar_eclipse_bool, 0, inner1d(panel_pointing_u, sun_pointing_u))  # Remove for eclipse.
    _aux1 = np.where(_dot_product > 0, _dot_product, 0)  # Filter out pointing from wrong side.
    _aux2 = (1 / float(solar_eclipse_bool.size - solar_eclipse_bool.nonzero()[0].size)) * integrate.cumtrapz(_aux1)
    _val = _aux2[-1]
    return [_aux1, _aux2], _val


def f_max_angular_rate(omega):
    _aux = np.maximum.accumulate(np.abs(omega))
    _val = _aux[-1]
    return _aux, _val


def f_max_angular_acceleration(alpha):
    _aux = np.maximum.accumulate(np.abs(alpha))
    _val = _aux[-1]
    return _aux, _val


def f_star_sensor_exclusion(sensor1_pointing_u, sensor2_pointing_u, sun_pointing_u, solar_eclipse_bool, body_u, R, h):
    _star_aux_1 = np.arccos(inner1d(sensor1_pointing_u, sun_pointing_u))
    _planet_aux_1 = np.arccos(inner1d(sensor1_pointing_u, body_u)) - np.arcsin(R / (R + h))
    _aux1 = - np.amin(np.array([
        [_star_aux_1],
        [_planet_aux_1]
    ]),
        axis=0)[0]

    _star_aux_2 = np.arccos(inner1d(sensor2_pointing_u, sun_pointing_u))
    _planet_aux_2 = np.arccos(inner1d(sensor2_pointing_u, body_u)) - np.arcsin(R / (R + h))
    _aux2 = - np.amin(np.array([
        [_star_aux_2],
        [_planet_aux_2]
    ]), axis=0)[0]

    _aux_sum = np.amin(np.array([[_aux1], [_aux2]]), axis=0)[0]
    _aux_max = np.maximum.accumulate(_aux_sum)
    _val = _aux_max[-1]
    return (_aux1, _aux2, _aux_max), _val


if __name__ == "__main__":
    def T(theta):
        return np.array([
            [np.cos(theta), -np.sin(theta)],
            [np.sin(theta), np.cos(theta)]
        ])


    ns = 1000

    theta_test = np.linspace(0, 4 * np.pi, ns)
    theta_test_orbit = np.linspace(0, 2 * np.pi, ns)

    ts1u = np.array([np.matmul(T(t), np.array([0, 1])) for t in theta_test])
    ts2u = np.array([np.matmul(T(t), np.array([1 / np.sqrt(2), 1 / np.sqrt(2)])) for t in theta_test])
    body_u = -np.array([np.matmul(T(t), np.array([0, 1])) for t in theta_test_orbit])
    sola = np.array([np.array([0, -1]) for t in theta_test])
    eclispe = np.concatenate((np.zeros((int(0.5 * len(theta_test)))), np.ones((int(0.5 * len(theta_test))))))

    import matplotlib.pyplot as plt

    print(ts1u)
    aux_l, val = f_star_sensor_exclusion(sensor1_pointing_u=ts1u, sensor2_pointing_u=ts2u, solar_eclipse_bool=eclispe,
                                         body_u=body_u, h=200e3, R=3600e3,
                                         sun_pointing_u=sola)
    # plt.plot(np.linspace(0, 100, 100), aux_l[0], label="0")
    # plt.plot(np.linspace(0, 100, 100), aux_l[1], label="1")
    # # plt.plot(np.linspace(0, 100, 100), np.ones((100)) * np.arccos(np.deg2rad(10)), label="lim")
    # # plt.plot(np.linspace(0, 100, 100), aux_l[2], label="2")
    # # plt.plot(np.linspace(0, 100, 100), aux_l[3], label="3")
    # plt.legend()
    # plt.show()

    # plt.plot(np.linspace(0, 100, 100), np.rad2deg(theta_test), label="theta")
    # plt.plot(np.linspace(0, 100, 100), np.rad2deg(aux_l[4]), label="dtheta_ss1_sun")
    # plt.plot(np.linspace(0, 100, 100), np.rad2deg(aux_l[5]), label="dtheta_ss1_m")
    plt.plot(np.linspace(0, 100, ns), np.zeros(ns), label="zero")
    plt.plot(np.linspace(0, 100, ns), np.ones(ns) * 20, label="10 deg")
    plt.plot(np.linspace(0, 100, ns), np.rad2deg(aux_l[1]), label="dtheta_ss2")
    plt.plot(np.linspace(0, 100, ns), np.rad2deg(aux_l[0]), label="dtheta_ss1")
    plt.plot(np.linspace(0, 100, ns), np.rad2deg(aux_l[2]), label="dtheta_ss1")
    # plt.plot(np.linspace(0, 100, 100), np.rad2deg(aux_l[7]), label="dtheta_ss2_m")
    # plt.plot(np.linspace(0, 100, 100), np.ones((100)) * 10, label="")
    plt.legend()
    plt.show()

    # print(ts1u)
    # print(ts1u)
