import numpy as np
cimport numpy as np
from stage.util import np_cache
from _formatting import *
from mathematics.signal cimport discrete_impulse_sum
# from mathematics.signal import discrete_impulse_sum
from mathematics.signal cimport discrete_ramp_sum
# from mathematics.signal import discrete_ramp_sum

# from util import

import matplotlib.pyplot as plt


class ImpulseDynamics:

    @staticmethod
    def discrete_domain_conversion(quantity_samples_1, quantity_samples_2, hat_k_array):
        return ((hat_k_array / quantity_samples_1) * quantity_samples_2).astype(int)

    def __init__(self, sample_quantity):
        """
        :param sample_quantity:
        """
        self._sample_quantity = sample_quantity
        self._a_array = np.array([])
        self._hat_k_array = np.array([])

    def update_quantity_samples(self, new_qty_samples):
        self._hat_k_array = self.discrete_domain_conversion(self.sample_quantity, new_qty_samples, self.hat_k_array)

    # Discrete Impulses.
    @property
    def sample_quantity(self):
        """
        :return: Integer number of samples across domain.
        """
        return self._sample_quantity

    @property
    def n_array(self):
        """
        :return: Array of integer values which define the domain.
        """
        return np.arange(0, self.sample_quantity)

    @property
    def a_array(self):
        """
        :return: The magnitude of the impulses defined as ∈ [-1,1] * ΔΩ_max.
        """
        return self._a_array

    @property
    def hat_k_array(self):
        """
        :return: Array of integer values which define the integer locations of impulses.
        """
        return self._hat_k_array

    # Continuous Impulse approximation.
    def k_array(self, time_bounds, delta_t):
        """
        :return: Array of time values which define the discrete locations of impulses.
        """
        return time_bounds[0] + self.hat_k_array * delta_t

    @staticmethod
    def time_array(time_bounds, sample_quantity):
        """
        :param time_bounds: Initial and final time values of domain [t0,tf].
        :param delta_t: Discrete Δt slice size.
        :return: Array of time values which represent the discretised integer locations of the domain.
        """
        return np.linspace(*time_bounds, sample_quantity, endpoint=False)

    def alpha_array(self, delta_t):
        """
        :param delta_t: Discrete Δt slice size.
        :return: Array of alpha impulse values across discretised time domain.
        """
        return discrete_impulse_sum(self.n_array, self.hat_k_array, self.a_array / delta_t)

    def omega_array(self, omega_0):
        """
        :param omega_0: Initial omega value at t0.
        :return: Array of omega values across discretised time domain.
        """
        return omega_0 + discrete_heaviside_sum(self.n_array, self.hat_k_array, self.a_array)

    def theta_array(self, omega_0, theta_0, delta_t):
        """
        :param omega_0: Initial omega value at t0.
        :param theta_0: Initial theta value at t0.
        :param delta_t: Discrete Δt slice size.
        :return: Array of theta values across discretised time domain.
        """
        return (+ theta_0
                + omega_0 * self.n_array * delta_t
                + discrete_ramp_sum(self.n_array, self.hat_k_array, 0.5 * self.a_array * delta_t))


class _RepresentationBase:

    def __init__(self, t0, tf, sample_quantity=650):
        # Impulse dynamics manager.
        self._sample_quantity = sample_quantity
        self._impulse_dynamics = ImpulseDynamics(sample_quantity)

        # Physical representation values.
        self._time_bounds = [t0, tf]
        self._theta_bounds = [None, None]
        self._omega_bounds = [None, None]

        # Values that define the non-dimensional to dimensional transposition.
        self._omega_max = None
        self._alpha_max = None

        # Configuration / display settings.
        self._rounding_repr = 3

    def __repr__(self):
        return representation_base_repr(self)

    def to_latex(self):
        return representation_base_latex(self)

    @property
    def delta_omega_max(self):
        """
        ΔΩ_max defines the range of magnitude changes of Ω as ∈ [-1,1] * ΔΩ_max.
        :return:
        """
        return min(self._omega_max, self._alpha_max * self.delta_t)

    @property
    def sample_quantity(self):
        """
        N_s
        :return:
        """
        return self._impulse_dynamics.sample_quantity

    @property
    def impulse_dynamics(self):
        """
        Object for handing impulse dynamics calculations.
        :return:
        """
        return self._impulse_dynamics

    # Boundary values.
    @property
    def time_bounds(self):
        """
        [t0, tf]
        :return:
        """
        return self._time_bounds

    @property
    def theta_bounds(self):
        """
        [theta_0, theta_f]
        :return:
        """
        return self._theta_bounds

    @property
    def omega_bounds(self):
        """
        [omega_0, omega_f]
        :return:
        """
        return self._omega_bounds

    @property
    def delta_t(self):
        """
        Discrete Δt slice size.
        :return:
        """
        return (self.time_bounds[-1] - self.time_bounds[0]) / self.sample_quantity

    # Both forms.
    @property
    def a_array(self):
        return self.impulse_dynamics.a_array

    # Discretised numerical impulse form.
    @property
    def hat_k_array(self):
        return self.impulse_dynamics.hat_k_array

    # Continuous analytical impulse form.
    @property
    def k_array(self):
        return self.impulse_dynamics.k_array(self.time_bounds, self.delta_t)

    # Dynamics derived from discretised numerical impulse form (sampled with Ns).
    @property
    def time_array(self):
        """
        # TODO: n1 = t1 = dt ?
        :return:
        """
        return self.impulse_dynamics.time_array(self.time_bounds, self.sample_quantity) + self.delta_t

    @property
    def alpha_array(self):
        return self.impulse_dynamics.alpha_array(self.delta_t)

    @property
    def omega_array(self):
        return self.impulse_dynamics.omega_array(self.omega_bounds[0])

    @property
    def theta_array(self):
        return self.impulse_dynamics.theta_array(self.omega_bounds[0], self.theta_bounds[0], self.delta_t)

    def separate_parts(self, time_points, circular_domain=False):
        assert np.all((time_points >= self.time_bounds[0]) & (time_points <= self.time_bounds[-1]))
        # TODO: This


# class X0Design(_RepresentationBase):
#     def __init__(self, t0, tf, sample_quantity):
#         super().__init__(t0, tf, sample_quantity)
#
#
# class XFDesign(_RepresentationBase):


class NImpulseDesign(_RepresentationBase):
    def __init__(self, t0, tf, sample_quantity, n_impulse=1):
        super().__init__(t0, tf, sample_quantity)
        self._n_impulse = n_impulse
        self._time__bounds = [t0, tf]

    def get_name(self):
        """
        Problem’s name.
        https://esa.github.io/pagmo2/docs/python/py_problem.html
        :return:
        """
        return f"N-Impulse N*{{k, tilde_alpha}}, (N={self._n_impulse})"

    def get_nx(self):
        """
        Dimension of the problem.
        https://esa.github.io/pagmo2/docs/python/py_problem.html
        :return:
        """
        return 2 * self._n_impulse

    def get_nix(self):
        """
        Integer dimension of the problem.
        https://esa.github.io/pagmo2/docs/python/py_problem.html
        :return:
        """
        return self._n_impulse

    def get_ncx(self):
        """
        Continuous dimension of the problem.
        https://esa.github.io/pagmo2/docs/python/py_problem.html
        :return:
        """
        return self._n_impulse

    def get_bounds(self):
        """
        Box-bounds.
        https://esa.github.io/pagmo2/docs/python/py_problem.html
        :return:
        """
        a_bounds = np.array([-1, 1]) * self.delta_omega_max
        k_bounds = [0, self.sample_quantity]
        return (
            a_bounds[+0] * self._n_impulse + k_bounds[+0] * self._n_impulse,
            a_bounds[-1] * self._n_impulse + k_bounds[-1] * self._n_impulse,
        )


class BaseMapping:
    def __init__(self, time_array):
        self._t_horizon = time_array[-1] - time_array[0]
        self._t_segment = time_array[1] - time_array[0]
        self._n_segments = len(time_array)
        self._time_disc = (1 / self._n_segments)
        self._n_discretisation = self._n_segments

        self._theta_0 = 0
        self._omega_0 = 0
        self._theta_f = 0
        self._omega_f = 0
        self._alpha_max = 0

    @property
    def alpha_max(self):
        return self._alpha_max

    @property
    def theta_0(self):
        return self._theta_0

    @property
    def omega_0(self):
        return self._omega_0

    @theta_0.setter
    def theta_0(self, x):
        self._theta_0 = x

    @omega_0.setter
    def omega_0(self, x):
        self._omega_0 = x

    @property
    def theta_f(self):
        return self._theta_f

    @property
    def omega_f(self):
        return self._omega_f

    @theta_f.setter
    def theta_f(self, x):
        self._theta_f = x

    @omega_f.setter
    def omega_f(self, x):
        self._omega_f = x

    def return_dynamics(self, _impulse_array):
        @np_cache
        def _alpha(t):
            return _impulse_array

        @np_cache
        def _omega(t):
            return self.omega_0 + np.concatenate(([0], self._t_segment * np.cumsum(_alpha(t))[:-1]))

        @np_cache
        def _theta(t):
            return self.theta_0 + np.concatenate(([0], self._t_segment * np.cumsum(_omega(t))[:-1]))

        return rotational_eom(alpha=_alpha, omega=_omega, theta=_theta)


class AlphaImpulseMapping(BaseMapping):
    def __init__(self, time_array):
        super().__init__(time_array)
        self._n = 1

    @property
    def n(self):
        return self._n

    @n.setter
    def n(self, x):
        self._n = x

    @property
    def dof(self):
        return 2 * self.n

    def get_bounds(self):
        return (
            [0, -1] * self.n,
            [1, +1] * self.n
        )

    def _mapping_to_impulse_array(self, args):
        _n = int(len(args[0]) / 2)
        _T = args[0][0::2] if _n != 1 else [args[0][0]]
        _H = args[0][1::2] if _n != 1 else [args[0][1]]
        _impulse_array = np.zeros(self._n_discretisation)
        _alpha_max_mag = 1e-2

        for idx in range(len(_T)):
            _impulse_array[int(_T[idx] / self._time_disc) - 1] += _H[idx]

        return _impulse_array * _alpha_max_mag

    def __call__(self, *args, **kwargs):
        return self.return_dynamics(self._mapping_to_impulse_array)


class ThreeImpulseMapping(BaseMapping):
    def __init__(self, time_array):
        super().__init__(time_array)
        self._n_design = False
        self._n = 0

    @property
    def n(self):
        return self._n

    @n.setter
    def n(self, x):
        if x is False:
            self._n_design = False
            self._n = 0
        else:
            self._n = x

    def get_bounds(self):
        return (
            [0] * self._n_design + [0] + [0] + [-1],
            [3 - 1e-10] * self._n_design + [1] + [1] + [+1]
        )

    @property
    def dof(self):
        return self._n_design + 3

    def _mapping_to_impulse_array(self, x):
        assert self._n_design + 3

        n = (int(x[0]) - 1) if self._n_design else self.n

        tilde_tau = x[0 + self._n_design]
        tilde_width = x[1 + self._n_design]
        tilde_alpha_2 = x[2 + self._n_design]

        _impulse_array = np.zeros(self._n_discretisation)
        _alpha_max_mag = 1e-2
        _alpha_2 = tilde_alpha_2 * _alpha_max_mag
        _tilde_width = 2 * tilde_width * np.min([tilde_tau, 1 - tilde_tau])
        _width_real = _tilde_width * self._t_horizon

        _alpha_1 = (
                           - self._t_horizon * self.omega_f
                           + self.omega_f * (tilde_tau * self._t_horizon)
                           - self.omega_0 * (tilde_tau * self._t_horizon)
                           + self.theta_f - self.theta_0 + 2 * np.pi * n
                           + _width_real * (self.omega_f - self.omega_0 - _alpha_2 * self._t_segment) / 2) / (
                           self._t_segment * _width_real
                   )
        _alpha_3 = (
                           + self._t_horizon * self.omega_f
                           - self.omega_f * (tilde_tau * self._t_horizon)
                           + self.omega_0 * (tilde_tau * self._t_horizon)
                           - self.theta_f + self.theta_0 - 2 * np.pi * n
                           + _width_real * (self.omega_f - self.omega_0 - _alpha_2 * self._t_segment) / 2) / (
                           self._t_segment * _width_real
                   )

        _impulse_array[int((tilde_tau - 0.5 * _tilde_width) / self._time_disc) - 1] += _alpha_1
        _impulse_array[int(tilde_tau / self._time_disc) - 1] += _alpha_2
        _impulse_array[int((tilde_tau + 0.5 * _tilde_width) / self._time_disc) - 1] += _alpha_3

        return _impulse_array

    def __call__(self, *args, **kwargs):
        _impulse_array = self._mapping_to_impulse_array(args[0])
        return self.return_dynamics(_impulse_array)


# (newer-style) super(DerivedClass, self).__init__()
class ThreeImpulseMappingWithInitial(ThreeImpulseMapping):

    def __init__(self, time_array):
        super().__init__(time_array)

    def initial_condition_bounds(self):
        return (
            [-1, 0],
            [+1, 1]
        )

    def get_bounds(self):
        return (
            self.initial_condition_bounds()[0] + [0] * self._n_design + [0] + [0] + [-1],
            self.initial_condition_bounds()[1] + [3 - 1e-10] * self._n_design + [1] + [1] + [+1]
        )

    @property
    def dof(self):
        return 2 + self._n_design + 3

    def __call__(self, *args, **kwargs):
        _initial_x = args[0][:2]
        self.theta_0 = _initial_x[1] * 2.0 * np.pi  #
        self.omega_0 = _initial_x[0] * (2 * np.pi) / 60  # Max initial RPM = 1
        _impulse_array = self._mapping_to_impulse_array(args[0][2:])
        return self.return_dynamics(_impulse_array)


class ThreeImpulseMappingWithFinal(ThreeImpulseMapping):
    def __init__(self, time_array):
        super().__init__(time_array)

    def initial_condition_bounds(self):
        return (
            [-1, 0],
            [+1, 1]
        )

    def get_bounds(self):
        return (
            self.initial_condition_bounds()[0] + [0] * self._n_design + [0] + [0] + [-1],
            self.initial_condition_bounds()[1] + [3 - 1e-10] * self._n_design + [1] + [1] + [+1]
        )

    @property
    def dof(self):
        return 2 + self._n_design + 3

    def __call__(self, *args, **kwargs):
        _initial_x = args[0][:2]
        self.theta_f = _initial_x[1] * 2.0 * np.pi  #
        self.omega_f = _initial_x[0] * (2 * np.pi) / 60  # Max initial RPM = 1
        _impulse_array = self._mapping_to_impulse_array(args[0][2:])
        return self.return_dynamics(_impulse_array)


class ThreeImpulseMappingWithInitialAndFinal(ThreeImpulseMapping):
    def __init__(self, time_array):
        super().__init__(time_array)

    def condition_bounds(self):
        return (
            [-1, 0] * 2,
            [+1, 1] * 2
        )

    def get_bounds(self):
        return (
            self.condition_bounds()[0] + [0] * self._n_design + [0] + [0] + [-1],
            self.condition_bounds()[1] + [3 - 1e-10] * self._n_design + [1] + [1] + [+1]
        )

    @property
    def dof(self):
        return 4 + self._n_design + 3

    def __call__(self, *args, **kwargs):
        _x = args[0][:4]
        self.omega_0 = _x[0] * (2 * np.pi) / 60  # Max initial RPM = 1
        self.theta_0 = _x[1] * 2.0 * np.pi
        self.omega_f = _x[2] * (2 * np.pi) / 60  # Max initial RPM = 1
        self.theta_f = _x[3] * 2.0 * np.pi
        _impulse_array = self._mapping_to_impulse_array(args[0][4:])
        return self.return_dynamics(_impulse_array)


class DesignSpace:
    def __init__(self, mapping):
        """
        :param dof: Degrees of freedom.
        :param mapping:
        """
        self._mapping = mapping
        self._dof = mapping.dof

    @property
    def mapping(self):
        """
        :return: Mapping function(s) for x_vector.
        """
        return self._mapping

    # @property
    # def subspace(self):
    #     """
    #     :return: Subspace, if provided for bi-level optimisation.
    #     """
    #     return self._subspace

    @property
    def dof(self) -> int:
        """
        :return: Degrees of freedom.
        """
        return self._dof

    @property
    def bounds(self) -> tuple:
        return self._mapping.bounds

    def evaluate_vector(self, x):
        """
        :param x: Design vector.
        :return:
        """
        return self._mapping(x)


if __name__ == "__main__":
    test = _RepresentationBase(0, 1000, )

    test._omega_bounds = [0, 0]
    test._theta_bounds = [0, 0]
    test._alpha_max = 0.07
    test._omega_max = 0.01

    test.impulse_dynamics._hat_k_array = np.array([0, 300, 600])
    test.impulse_dynamics._a_array = np.array([-0.001, 0.001, 0.0005])

    print(test.to_latex())
    print(test)

    # plt.stem(test.time_array, test.theta_array)

    # plt.show()
    breakpoint()

    n_sampled = np.arange(0, 10)

    a_array = np.random.random_sample(3) - 0.5

    k_array = np.random.randint(0, 10, 3)

    from stage.mathematics import discrete_heaviside_sum

    y = 1 + discrete_heaviside_sum(n_sampled, k_array, a_array)
    y2 = discrete_ramp_sum(n_sampled, k_array, a_array * 0.1)

    plt.stem(n_sampled, y)
    # plt.stem(n_sampled, y2)
    plt.show()

    breakpoint()
    test = _Base()
    print(test.to_latex())
    breakpoint()
    print(test)
    # print(test.to_latex())
    breakpoint()

    t_array = np.linspace(0, 6500, 650)

    # three_impulse_mapping = ThreeImpulseMappingWithInitialAndFinal(t_array)
    three_impulse_mapping = AlphaImpulseMapping(t_array)

    # alpha_impulse

    three_impulse_mapping.omega_0 = 1e-4
    three_impulse_mapping.omega_f = 5e-4

    three_impulse_mapping.theta_0 = 1.00
    three_impulse_mapping.theta_f = 1.00

    three_impulse_mapping.n = 0

    # Define upper and lower level domain.
    design_space = DesignSpace(mapping=three_impulse_mapping)  # Follower

    # x = [
    #     1e-4 / ((2 * np.pi) / 60),
    #     1.00 / (2.0 * np.pi),
    #     5e-4 / ((2 * np.pi) / 60),
    #     1.00 / (2.0 * np.pi),
    #     0.5, 0.2, 0.1]

    x = [0.5, 0.5]
    # *2.0 * np.pi  #
    # *(2 * np.pi) / 60  # Max initial RPM = 1

    alpha = design_space.evaluate_vector(x).alpha(np.linspace(0, 100, 600))
    omega = design_space.evaluate_vector(x).omega(np.linspace(0, 100, 600))
    theta = design_space.evaluate_vector(x).theta(np.linspace(0, 100, 600))

    plt.plot(t_array, [three_impulse_mapping.omega_0] * len(t_array), color="red")
    plt.plot(t_array, [three_impulse_mapping.omega_f] * len(t_array), color="red")

    # plt.plot(t_array, alpha)
    plt.plot(t_array, alpha / np.max(np.abs(alpha)), label="$\\alpha_{max}$=" + str(np.round(np.max(np.abs(alpha)), 8)))
    plt.plot(t_array, omega / np.max(np.abs(omega)), label="$\\omega_{max}$=" + str(np.round(np.max(np.abs(omega)), 8)))
    plt.plot(t_array, theta / np.max(np.abs(theta)), label="$\\theta_{max}$=" + str(np.round(np.max(np.abs(theta)), 8)))
    # plt.plot(t_array, theta)
    plt.minorticks_on()
    plt.grid(which="major", linewidth=0.9)
    plt.grid(which="minor", linewidth=0.2)
    plt.legend()
    plt.show()
    # times = []
    #
    # n_dof = []
    #
    # import time
    #
    # for n in range(1, 50):
    #
    #     now = time.time()
    #     vec = [0.1 * n, 0.1] * n
    #     for i in range(10000):
    #         design_space.evaluate_vector(vec)
    #
    #     n_dof.append(n)
    #     times.append(time.time() - now)
    #
    # import matplotlib.pyplot as plt
    #
    # plt.semilogy(n_dof, times)
    #
    # plt.show()
