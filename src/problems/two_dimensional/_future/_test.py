from stage.mathematics import thrust_inefficiency_vector_input
from numpy.core.umath_tests import inner1d

import timeit

import numpy as np


def orbital_period(sma, mu):
    """
    :param sma: Semi-major axis.
    :param mu: Gravitational parameter of body.
    :return:
    """
    return 2 * np.pi * np.sqrt(sma ** 3 / mu)


def state_spacecraft(R, h, nu_s0, mu_m, t):
    _T = orbital_period(R + h, mu_m)
    return (R + h) * np.concatenate(([np.cos(nu_s0 + 2 * np.pi * t / _T)],
                                     [np.sin(nu_s0 + 2 * np.pi * t / _T)])).T


def state_celestial_body(a, nu_0, t):
    return a * np.tile(np.array([np.cos(nu_0), np.sin(nu_0)]), (len(t), 1))


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


u_act = np.ones((100, 3)) * 0.2
u_planned = np.ones((100, 3)) * 0.4
n_array = np.arange(0, 100)


def occultation():
    mu = 4.2828372 * 10 ** 13

    def cython():
        stage.mathematics.occultation.t_solar_eclipse_solutions(3100000, 200000, 0, 0, mu)

    def not_cython():
        t_solar_eclipse_solutions(3100000, 200000, 0, 0, mu)


    print("Cython: ", timeit.timeit(cython, number=10000))

    print("Not Cython: ", timeit.timeit(not_cython, number=10000))


occultation()


def array_stuff():
    def custom():
        return thrust_inefficiency_vector_input(u_act, u_planned, n_array, integrated=True, custom=True)

    def not_custom():
        return thrust_inefficiency_vector_input(u_act, u_planned, n_array, integrated=True, custom=False)

    def not_cython():
        j = u_act.shape[0]
        i = u_act.shape[1]
        integrated = True
        w = 1
        custom = False

        if custom:

            _y = np.zeros((j,), dtype=np.double)
            for y in range(j):
                tmp = 0
                for x in range(i):
                    tmp += u_planned[y, x] * u_act[y, x]
                _y[y] = 1 - tmp
            _y = _y * w
            _integrated = (1 / n_array.size) * np.trapz(_y, n_array)

        else:
            # Scipy + numpy
            _y = (1 - inner1d(u_planned, u_act, axis=1)) * w
            _integrated = (1 / n_array.size) * np.trapz(_y, n_array)

        if integrated:
            return _integrated
        else:
            return _y

    # assert(custom()==not_custom())

    print("Custom: ", timeit.timeit(custom, number=100000))

    print("Not Custom: ", timeit.timeit(not_custom, number=100000))

    print("Not Cython: ", timeit.timeit(not_cython, number=100000))
