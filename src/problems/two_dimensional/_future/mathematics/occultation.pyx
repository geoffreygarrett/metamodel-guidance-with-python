import numpy as np
cimport numpy as np
cimport cython

# ███████╗ ██████╗ ██╗      █████╗ ██████╗     ███████╗ ██████╗██╗     ██╗██████╗ ███████╗███████╗
# ██╔════╝██╔═══██╗██║     ██╔══██╗██╔══██╗    ██╔════╝██╔════╝██║     ██║██╔══██╗██╔════╝██╔════╝
# ███████╗██║   ██║██║     ███████║██████╔╝    █████╗  ██║     ██║     ██║██████╔╝███████╗█████╗
# ╚════██║██║   ██║██║     ██╔══██║██╔══██╗    ██╔══╝  ██║     ██║     ██║██╔═══╝ ╚════██║██╔══╝
# ███████║╚██████╔╝███████╗██║  ██║██║  ██║    ███████╗╚██████╗███████╗██║██║     ███████║███████╗
# ╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚══════╝ ╚═════╝╚══════╝╚═╝╚═╝     ╚══════╝╚══════╝

#####################
# VECTOR CALCULATION.
#####################
cpdef double orbital_period(double sma, double mu):
    """
    :param sma: Semi-major axis.
    :param mu: Gravitational parameter of body.
    :return:
    """
    return 2 * np.pi * np.sqrt(sma ** 3 / mu)

cdef np.ndarray[double] a_tilde(double R, double h, double nu_s0, double nu_m0, double mu_m, np.ndarray[double] t):
    """
    :param R: Mean equatorial radius of target body.
    :param h: Altitude of spacecraft above the surface of target body.
    :param nu_s0: Initial true anomaly of spacecraft.
    :param nu_m0: Initial true anomaly of target body.
    :param mu_m: Gravitational parameters of target body.
    :param t: Time array.
    :return: 
    """
    cdef double T;
    T = orbital_period(R + h, mu_m)
    return np.sqrt(1 - np.cos(-nu_m0 + nu_s0 + 2 * np.pi * t / T) ** 2) * np.sqrt((R + h) ** 2)

cpdef np.ndarray[double] tilde_da_dt(double R, double h, double nu_s0, double nu_m0, double mu_m, np.ndarray[double] t):
    """
    :param R: Mean equatorial radius of target body.
    :param h: Altitude of spacecraft above the surface of target body.
    :param nu_s0: Initial true anomaly of spacecraft.
    :param nu_m0: Initial true anomaly of target body.
    :param mu_m: Gravitational parameters of target body.
    :param t: Time array.
    :return: 
    """
    cdef double T;
    T = orbital_period(R + h, mu_m)
    return np.sqrt(2) * np.pi * np.sqrt((R + h) ** 2) * np.sin(-2 * nu_m0 + 2 * nu_s0 + 4 * np.pi * t / T) / (
            T * np.sqrt(1 - np.cos(-2 * nu_m0 + 2 * nu_s0 + 4 * np.pi * t / T)))

cpdef phi(double R, double h, double a_m, double nu_s0, double nu_m0, double mu_m, np.ndarray[double] t):
    """
    :param R: Mean equatorial radius of target body.
    :param h: Altitude of spacecraft above the surface of target body.
    :param a_m: Semi-major axis of target body.
    :param nu_s0: Initial true anomaly of spacecraft.
    :param nu_m0: Initial true anomaly of target body.
    :param mu_m: Gravitational parameters of target body.
    :param t: Time array.
    :return: 
    """
    cdef double T;
    T = orbital_period(R + h, mu_m)
    return np.arccos(
        -a_m * (R + h) * np.cos(-nu_m0 + nu_s0 + 2 * np.pi * t / T) / (np.sqrt(a_m ** 2) * np.sqrt((R + h) ** 2)))

#########################
# ANALYTICAL CALCULATION.
#########################
cpdef t_aux(double R, double h, double nu_s0, double nu_m0, double mu_m):
    """
    :param R: Mean equatorial radius of target body.
    :param h: Altitude of spacecraft above the surface of target body.
    :param nu_s0: Initial true anomaly of spacecraft.
    :param nu_m0: Initial true anomaly of target body.
    :param mu_m: Gravitational parameters of target body.
    :return: 
    """
    cdef double _T, _delta_nu, _k_e;
    _T = orbital_period(R + h, mu_m)
    _delta_nu = nu_m0 - nu_s0
    _k_e = h * (2 * R + h) / (R ** 2 + 2 * R * h + h ** 2)
    cdef np.ndarray[double, ndim=1] _result = np.array([
        _T * (_delta_nu + np.arccos(-np.sqrt(_k_e))) / (2 * np.pi),
        _T * (_delta_nu + np.arccos(+np.sqrt(_k_e))) / (2 * np.pi),
        _T * (_delta_nu - np.arccos(-np.sqrt(_k_e)) + 2 * np.pi) / (2 * np.pi),
        _T * (_delta_nu - np.arccos(+np.sqrt(_k_e)) + 2 * np.pi) / (2 * np.pi)
    ])
    return _result

cpdef phi_condition(double nu_s0, double nu_m0, double T, np.ndarray[double] t):
    """
    :param nu_s0: Initial true anomaly of spacecraft.
    :param nu_m0: Initial true anomaly of target body.
    :param T: Orbital period of spacecraft.
    :param t: Time array.
    :return: 
    """
    cdef double _delta_nu;
    _delta_nu = nu_m0 - nu_s0
    return np.cos(-_delta_nu + np.pi * 2 / T * t) >= 0

@cython.boundscheck(False)  # Deactivate bounds checking
@cython.wraparound(False)  # Deactivate negative indexing.
cpdef t_solar_eclipse_solutions(double R, double h, double nu_s0, double nu_m0, double mu_m):
    """
    :param R: Mean equatorial radius of target body.
    :param h: Altitude of spacecraft above the surface of target body.
    :param nu_s0: Initial true anomaly of spacecraft.
    :param nu_m0: Initial true anomaly of target body.
    :param mu_m: Gravitational parameters of target body.
    :return: 
    """
    cdef double _T;
    cdef np.ndarray[double] _t_aux1, _t_aux2;
    _T = orbital_period(R + h, mu_m)
    _t_aux1 = t_aux(R, h, nu_s0, nu_m0, mu_m)
    _t_aux2 = np.mod(_t_aux1, _T)

    return _t_aux2[phi_condition(nu_s0, nu_m0, _T, _t_aux1)]
