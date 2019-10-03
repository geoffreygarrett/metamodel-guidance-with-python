from ._functions import *
import numpy as np
from scipy import integrate, interpolate


class DesignSpaceBase:

    def __init__(self, n_samples):
        """

        """
        self._n_samples = n_samples
        self._sampled_time_array = None
        self._reference_time = None
        self._init = {}

    def __call__(self, *args, **kwargs):
        raise NotImplementedError("Not callable as base class.")

    @property
    def init(self):
        return self._init

    @property
    def n_samples(self):
        return self._n_samples

    @property
    def sampled_time_array(self):
        if self._sampled_time_array is None:
            self._sampled_time_array = np.arange(self.n_samples) / self.n_samples * self.reference_time
        return self._sampled_time_array

    @property
    def reference_time(self):
        if self._reference_time is None:
            raise ValueError("Reference time must be set for design space")
        return self._reference_time

    @reference_time.setter
    def reference_time(self, x):
        self._reference_time = x

    def get_bounds(self):
        raise NotImplementedError("Not implemented in base class.")


class OmegaBasedDesign(DesignSpaceBase):
    """
    Parent class for design vectors based on setting omega profile.
    """

    def __init__(self,
                 n_samples,
                 init_theta=None):
        super().__init__(n_samples)
        self._init_theta = init_theta

    @property
    def init_theta(self):
        return self._init["theta"]

    @property
    def design_theta(self):
        return True if self.init_theta is None else False

    @init_theta.setter
    def init_theta(self, x):
        self._init["theta"] = x

    def get_bounds(self):
        raise NotImplementedError("Not implemented in base class.")


# class NOmegaPointsFixedTime(OmegaBasedDesign):
#
#     def __init__(self,
#                  n_samples,
#                  n_design_points,
#                  max_abs_omega=np.deg2rad(1.5),
#                  init_theta=None,
#                  ):
#         super().__init__(n_samples)
#         self._max_abs_omega = max_abs_omega
#         self._n_design_points = n_design_points
#         self._init_theta = init_theta
#
#     def __call__(self, design_vector):
#         theta0 = design_vector[-1] if self.design_theta else self.init_theta
#         time_sc = design_vector[self.n_design_omega:][:-1] if self.design_theta else design_vector[self.n_design_omega:]
#         omega_p = design_vector[:self.n_design_omega]
#
#         # https://en.wikipedia.org/wiki/N-sphere#CITEREFMarsaglia1972
#         scale_time_vector = np.concatenate(([0], np.cumsum(time_sc)))
#         scale_time_vector = scale_time_vector / np.max(scale_time_vector)
#
#         time_vector_end = (scale_time_vector * self.reference_time)
#         time_vector_no_end = time_vector_end[:-1]  # Remove tf, as tf=t0
#         sum_interior = integrate.cumtrapz(omega_p, time_vector_no_end[1:])[-1]
#
#         dt_i = time_vector_no_end[1]
#         dt_f = self.reference_time - time_vector_no_end[-1]
#
#         delta_theta = (
#                 - 2 * sum_interior
#                 - omega_p[-1] * dt_f
#                 - omega_p[0] * dt_i
#                 + 4 * np.pi  # TODO: n.
#         )
#
#         omega_i_f = 1 / (dt_i + dt_f) * delta_theta
#         omega_p = np.concatenate(([omega_i_f], omega_p, [omega_i_f]))
#
#         omega_sampled = interpolate.interp1d(time_vector_end, omega_p)(self.sampled_time_array)
#         theta_sampled = integrate.cumtrapz(omega_sampled, self.sampled_time_array, initial=0) + theta0
#         alpha_sampled = np.diff(omega_sampled)
#         alpha_sampled = np.concatenate((alpha_sampled, [alpha_sampled[-1]])) / (self.reference_time / self.n_samples)
#         return alpha_sampled, omega_sampled, theta_sampled
#
#     @property
#     def max_abs_omega(self):
#         return self._max_abs_omega
#
#     @max_abs_omega.setter
#     def max_abs_omega(self, x):
#         self._max_abs_omega = x
#
#     @property
#     def n_design_omega(self):
#         return self._n_design_points


# class NOmegaPointsFixedTimePeriodic(OmegaBasedDesign):
#
#     def __init__(self,
#                  n_samples,
#                  n_design_points,
#                  max_abs_omega=np.deg2rad(1.5),
#                  init_theta=None,
#                  ):
#         super().__init__(n_samples)
#         self._max_abs_omega = max_abs_omega
#         self._n_design_points = n_design_points
#         self._init_theta = init_theta
#
#     def __call__(self, design_vector):
#         theta0 = design_vector[-1] if self.design_theta else self.init_theta
#         omega_p = design_vector[:self.n_design_omega]
#         time_sc = design_vector[self.n_design_omega:][:-1] if self.design_theta else design_vector[self.n_design_omega:]
#
#         # https://en.wikipedia.org/wiki/N-sphere#CITEREFMarsaglia1972
#         scale_time_vector = np.concatenate(([0], np.cumsum(time_sc)))
#         scale_time_vector = scale_time_vector / np.max(scale_time_vector)
#
#         time_vector_end = (scale_time_vector * self.reference_time)
#         time_vector_no_end = time_vector_end[:-1]  # Remove tf, as tf=t0
#         sum_interior = integrate.cumtrapz(omega_p, time_vector_no_end[1:])[-1]
#
#         dt_i = time_vector_no_end[1]
#         dt_f = self.reference_time - time_vector_no_end[-1]
#
#         delta_theta = (
#                 - 2 * sum_interior
#                 - omega_p[-1] * dt_f
#                 - omega_p[0] * dt_i
#                 + 4 * np.pi  # TODO: n.
#         )
#
#         omega_i_f = 1 / (dt_i + dt_f) * delta_theta
#         omega_p = np.concatenate(([omega_i_f], omega_p, [omega_i_f]))
#
#         omega_sampled = interpolate.interp1d(time_vector_end, omega_p)(self.sampled_time_array)
#         theta_sampled = integrate.cumtrapz(omega_sampled, self.sampled_time_array, initial=0) + theta0
#         alpha_sampled = np.diff(omega_sampled)
#         alpha_sampled = np.concatenate((alpha_sampled, [alpha_sampled[-1]])) / (self.reference_time / self.n_samples)
#         return alpha_sampled, omega_sampled, theta_sampled


class NOmegaPointsScaleBasedPeriodic(OmegaBasedDesign):
    """

    """

    def __init__(self,
                 n_samples,
                 n_design_points,
                 max_abs_omega=np.deg2rad(1.5),
                 init_theta=None,
                 ):
        super().__init__(n_samples)
        self._max_abs_omega = max_abs_omega
        self._n_design_points = n_design_points
        self.init_theta = init_theta
        self._min_t_scale = 0.001

    def __call__(self, design_vector):
        theta0 = design_vector[-1] if self.design_theta else self.init_theta
        omega_p = design_vector[:self.n_design_omega]
        time_sc = design_vector[self.n_design_omega:][:-1] if self.design_theta else design_vector[self.n_design_omega:]

        # https://en.wikipedia.org/wiki/N-sphere#CITEREFMarsaglia1972
        scale_time_vector = np.concatenate(([0], np.cumsum(time_sc)))
        scale_time_vector = scale_time_vector / np.max(scale_time_vector)

        time_vector_end = (scale_time_vector * self.reference_time)
        time_vector_no_end = time_vector_end[:-1]  # Remove tf, as tf=t0
        sum_interior = integrate.cumtrapz(omega_p, time_vector_no_end[1:])[-1]

        dt_i = time_vector_no_end[1]
        dt_f = self.reference_time - time_vector_no_end[-1]

        delta_theta = (
                - 2 * sum_interior
                - omega_p[-1] * dt_f
                - omega_p[0] * dt_i
                + 4 * np.pi  # TODO: n.
        )

        omega_i_f = 1 / (dt_i + dt_f) * delta_theta
        omega_p = np.concatenate(([omega_i_f], omega_p, [omega_i_f]))

        omega_sampled = interpolate.interp1d(time_vector_end, omega_p)(self.sampled_time_array)
        theta_sampled = integrate.cumtrapz(omega_sampled, self.sampled_time_array, initial=0) + theta0
        alpha_sampled = np.diff(omega_sampled)
        alpha_sampled = np.concatenate((alpha_sampled, [alpha_sampled[-1]])) / (self.reference_time / self.n_samples)
        return alpha_sampled, omega_sampled, theta_sampled

    @property
    def max_abs_omega(self):
        return self._max_abs_omega

    @max_abs_omega.setter
    def max_abs_omega(self, x):
        self._max_abs_omega = x

    @property
    def min_t_scale(self):
        return self._min_t_scale

    @min_t_scale.setter
    def min_t_scale(self, x):
        self._min_t_scale = x

    @property
    def n_design_omega(self):
        return self._n_design_points

    @property
    def n_design_scale(self):
        return self._n_design_points + 1

    # @property
    def get_bounds(self):
        _base = [
            [-self._max_abs_omega] * self.n_design_omega + [0.0 + self.min_t_scale] * self.n_design_scale,
            [+self._max_abs_omega] * self.n_design_omega + [1.0 - self.min_t_scale] * self.n_design_scale,
        ]
        _base[0] += [0] if self.design_theta else []
        _base[1] += [2 * np.pi] if self.design_theta else []
        return tuple(_base)


# class NOmegaPointsDomainBased(OmegaBasedDesign):
#     """
#
#     """
#
#     def __init__(self):
#         super().__init__()
#


if __name__ == "__main__":
    import matplotlib.pyplot as plt

    test = NOmegaPointsScaleBasedPeriodic(100, 3, init_theta=0)

    test.reference_time = 1000

    a, o, t = test([0.002, -0.002, 0.002, 0.1, 0.1, 0.1, 0.1])

    # print(o[0])
    # print(o[-1] + a[-1]*10)

    plt.subplot(3, 1, 1)
    plt.plot(test.sampled_time_array, a)

    plt.subplot(3, 1, 2)
    plt.plot(test.sampled_time_array, o)

    plt.subplot(3, 1, 3)
    plt.plot(test.sampled_time_array, t)

    plt.show()
