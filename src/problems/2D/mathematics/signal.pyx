cimport numpy as np
import numpy as np
from scipy import signal

# ██████╗ ██╗███████╗ ██████╗██████╗ ███████╗████████╗███████╗    ███████╗██╗ ██████╗ ███╗   ██╗ █████╗ ██╗
# ██╔══██╗██║██╔════╝██╔════╝██╔══██╗██╔════╝╚══██╔══╝██╔════╝    ██╔════╝██║██╔════╝ ████╗  ██║██╔══██╗██║
# ██║  ██║██║███████╗██║     ██████╔╝█████╗     ██║   █████╗      ███████╗██║██║  ███╗██╔██╗ ██║███████║██║
# ██║  ██║██║╚════██║██║     ██╔══██╗██╔══╝     ██║   ██╔══╝      ╚════██║██║██║   ██║██║╚██╗██║██╔══██║██║
# ██████╔╝██║███████║╚██████╗██║  ██║███████╗   ██║   ███████╗    ███████║██║╚██████╔╝██║ ╚████║██║  ██║███████╗
# ╚═════╝ ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝    ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝
cpdef discrete_impulse_sum(np.ndarray[long] sampled_n,
                           np.ndarray[long] k_array,
                           np.ndarray[double] a_array):
    """
    :param sampled_n: Sampled discrete parameter array.
    :param k_array: Discrete parameters on discrete domain of n.
    :param a_array: Scaling parameters of integrated impulse.
    :return: 
    """
    # assert k_array.size == a_array.size
    cdef np.ndarray result;
    result = np.zeros(sampled_n.size)
    cdef long k;
    cdef double a;
    for a, k in zip(a_array, k_array):
        result += a * signal.unit_impulse(sampled_n.size, k)
    return result

cpdef discrete_heaviside_sum(np.ndarray[long] sampled_n,
                             np.ndarray[long] k_array,
                             np.ndarray[double] a_array):
    """
    :param sampled_n: Sampled discrete parameter array.
    :param k_array: Discrete parameters on discrete domain of n.
    :param a_array: Scaling parameters of integrated impulse.
    :return: 
    """
    # assert k_array.size == a_array.size
    cdef np.ndarray[double, ndim=1] result;
    result = np.zeros(sampled_n.size)
    cdef long k;
    cdef double a;
    for a, k in zip(a_array, k_array):
        result += a * np.heaviside(np.subtract(sampled_n, k), 1)
    return result

cpdef discrete_ramp_sum(np.ndarray[long] sampled_n,
                        np.ndarray[long] k_array,
                        np.ndarray[double] a_array):
    """
    :param sampled_n: Sampled discrete parameter array.
    :param k_array: Discrete parameters on discrete domain of n.
    :param a_array: Scaling parameters of integrated impulse.
    :return: 
    """
    # assert k_array.size == a_array.size
    cdef np.ndarray[double, ndim=1] result;
    result = np.zeros(sampled_n.size)
    cdef long k;
    cdef double a;
    for a, k in zip(a_array, k_array):
        result += a * np.subtract(sampled_n, k).clip(0)
    return result

# Methods for conversion.
cpdef convert_to_continuous(self, x):
    raise NotImplementedError("Not implemented in base class.")

cpdef convert_to_discrete(self, x):
    raise NotImplementedError("Not implemented in base class.")
