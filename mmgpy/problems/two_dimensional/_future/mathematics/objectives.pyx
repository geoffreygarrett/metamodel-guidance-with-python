import numpy as np
cimport numpy as np
from numpy.core.umath_tests import inner1d
cimport cython
from libcpp cimport bool

@cython.boundscheck(False)  # Deactivate bounds checking
@cython.wraparound(False)  # Deactivate negative indexing.
cpdef thrust_inefficiency_vector_input(
        np.ndarray[double, ndim=2] hat_thruster_pointing_actual,
        np.ndarray[double, ndim=2] hat_thruster_pointing_planned,
        np.ndarray[long, ndim=1] n_array,
        w=1,
        integrated=True,
        custom=True):
    """
    :param hat_thruster_pointing_actual: Actual array of unit vectors of thruster pointing direction.
        - Shape: (sample_quantity, 3).
    :param hat_thruster_pointing_planned: Planned array of unit vectors of thruster pointing direction.
        - Shape: (sample_quantity, 3).
    :param n_array: Discretised array of integer values of sampled points across domain.
        - Shape: (sample_quantity, 3).
    :param w: Weight array with shape: (1, sample_quantity) 
        - Assumed constant if argument not provided.
        - If single (double) argument provided, this is used for every sample point.
    :param integrated: (bool) True: Single value integrated objective; False: Current integral slice per sample.
        - This is used in order to provided figure representation of current thrust_inefficiency at all samples.
    :param custom: (bool) Use numpy/scipy stuff. 
    :return: (np.ndarray) \ (float)
    """
    # Custom
    cdef int i = hat_thruster_pointing_actual.shape[1];
    cdef int j = hat_thruster_pointing_actual.shape[0];
    cdef int x, y;
    cdef double tmp;
    assert hat_thruster_pointing_actual.shape[0] == hat_thruster_pointing_planned.shape[0]


    if custom:

        _y = np.zeros((j,), dtype=np.double)
        for y in range(j):
            tmp = 0
            for x in range(i):
                tmp += hat_thruster_pointing_actual[y, x] * hat_thruster_pointing_planned[y, x]
            _y[y] = 1 - tmp
        _y = _y * w
        _integrated = (1 / n_array.size) * np.trapz(_y, n_array)

    else:
        # Scipy + numpy
        _y = (1 - inner1d(hat_thruster_pointing_planned, hat_thruster_pointing_actual, axis=1)) * w
        _integrated = (1 / n_array.size) * np.trapz(_y, n_array)

    if integrated:
        return _integrated
    else:
        return _y

# @cython.boundscheck(False)  # Deactivate bounds checking
# @cython.wraparound(False)  # Deactivate negative indexing.
# cpdef thrust_inefficiency_scalar_input(
#         np.ndarray[double, ndim=1] theta_spacecraft_actual,
#         np.ndarray[double, ndim=1] theta_spacecraft_planned,
#         np.ndarray[long, ndim=1] n_array,
#         w=1,
#         integrated=True,
#         custom=True):
#     """
#     :param theta_spacecraft_actual: Actual array of attitude for spacecraft.
#         - Shape: (1, sample_quantity).
#     :param theta_spacecraft_planned: Planned array of attitude for spacecraft.
#         - Shape: (1, sample_quantity).
#     :param n_array: Discretised array of integer values of sampled points across domain.
#         - Shape: (1, sample_quantity).
#     :param w: Weight array with shape: (1, sample_quantity)
#         - Assumed constant if argument not provided.
#         - If single (double) argument provided, this is used for every sample point.
#     :param time_period: Value used to normalise
#     :param integrated: (bool) True: Single value integrated objective; False: Current integral slice per sample.
#         - This is used in order to provided figure representation of current thrust_inefficiency at all samples.
#     :param custom: (bool) Use numpy/scipy stuff.
#     :return: (np.ndarray) \ (float)
#     """
#     pass
