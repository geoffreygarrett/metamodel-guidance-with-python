# from ._functions import *
import numpy as np


class Spacecraft:

    def __init__(self,
                 body_solar_array_angle: float = 0.,  # [rad]
                 body_star_sensor1_angle: float = (1 / 4.) * np.pi,  # [rad]
                 body_star_sensor2_angle: float = (3 / 4.) * np.pi,  # [rad]
                 body_antenna_angle: float = (1 / 2.) * np.pi,  # [rad]
                 body_thrust_angle: float = (3 / 2.) * np.pi,  # [rad]
                 ):
        self._body_arr_angle = body_solar_array_angle  # [rad]
        self._body_ss1_angle = body_star_sensor1_angle  # [rad]
        self._body_ss2_angle = body_star_sensor2_angle  # [rad]
        self._body_ant_angle = body_antenna_angle  # [rad]
        self._body_thr_angle = body_thrust_angle  # [rad]
        self._attitude_theta = None
        self._cos_theta = None
        self._sin_theta = None

    @classmethod
    def from_dict(cls, init_dict):
        """
        Alternative constructor for Spacecraft class.
        :param init_dict: Example:
        :return:
        """
        raise NotImplementedError("from_dict not implemented yet.")

    @staticmethod
    def sin_a_plus_b(cos_a, sin_a, b):
        return sin_a * np.cos(b) + np.sin(b) * cos_a

    @staticmethod
    def cos_a_plus_b(cos_a, sin_a, b):
        return cos_a * np.cos(b) - sin_a * np.sin(b)

    def unit_vector_trajectory(self, angle):
        return np.array([
            self.cos_a_plus_b(self._cos_theta, self._sin_theta, angle),
            self.sin_a_plus_b(self._cos_theta, self._sin_theta, angle)]).T

    # def unit_vector_trajectory2(self, trajectory, angle):
    #     c_t = np.cos(trajectory)
    #     s_t = np.sin(trajectory)
    #     return np.array([
    #         self.cos_a_plus_b(c_t, s_t, angle),
    #         self.sin_a_plus_b(c_t, s_t, angle)]).T

    @property
    def attitude_trajectory(self):
        if self._attitude_theta is None:
            raise AttributeError("attitude_trajectory must be defined before retrieving component pointing history.")
        return self._attitude_theta

    @attitude_trajectory.setter
    def attitude_trajectory(self, x):
        self._attitude_theta = x
        self._cos_theta = np.cos(x)
        self._sin_theta = np.sin(x)

    # Solar array related.
    # @property
    def arr_u_vec(self):
        """
        Solar array unit vector array.
        :return:
        """
        return self.unit_vector_trajectory(self._body_arr_angle)

    # Star sensor related.
    # @property
    def ss1_u_vec(self):
        """
        Star sensor 1 unit vector array.
        :return:
        """
        return self.unit_vector_trajectory(self._body_ss1_angle)

    # @property
    def ss2_u_vec(self):
        """
        Star sensor 2 unit vector array.
        :return:
        """
        return self.unit_vector_trajectory(self._body_ss2_angle)

    # Telemetry related.
    # @property
    def ant_u_vec(self):
        """
        Antenna unit vector array.
        :return:
        """
        return self.unit_vector_trajectory(self._body_ant_angle)

    # Thrust profile related.
    # @property
    def thr_u_vec(self):
        """
        Thrust unit vector array.
        :return:
        """
        return self.unit_vector_trajectory(self._body_thr_angle)
