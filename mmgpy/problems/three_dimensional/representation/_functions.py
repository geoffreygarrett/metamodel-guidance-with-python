import numpy as np


# Design representation.
def discrete_heaviside_sum(sampled_n,
                           k_array,
                           a_array):
    # assert k_array.size == a_array.size
    result = np.zeros(len(sampled_n))
    for a, k in zip(a_array, k_array):
        result += a * np.heaviside(np.subtract(sampled_n, k), 1)
    return result


def discrete_ramp_sum(sampled_n,
                      k_array,
                      a_array):
    # assert k_array.size == a_array.size
    result = np.zeros(len(sampled_n))
    for a, k in zip(a_array, k_array):
        result += a * np.subtract(sampled_n, k).clip(0)
    return result
