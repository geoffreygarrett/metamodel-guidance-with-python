from ._functions import *

# https://en.wikipedia.org/wiki/Standard_gravitational_parameter#targetText=G%20M%20%E2%98%89%2C%20the%20gravitational,20%20m3%20s%E2%88%922.
MU_SUN = 1.32712440018 * 10 ** 20  # [m^3 s^-2]
AU = 150e9  # [m]
MEAN_MARS_RADIUS = 3389.5e3  # [m]
MU_MARS = 4.282837 * 10 ** 13  # [m^3 s^-2]


class MissionGeometry:

    def __init__(self,
                 mission_target_nu0=np.pi / 2,
                 mission_target_a=1.524 * AU,
                 mission_target_R=MEAN_MARS_RADIUS,
                 mission_target_mu=MU_MARS,
                 spacecraft_nu0=0,
                 spacecraft_h=200e3,
                 communication_target_nu0=None,
                 communication_target_a=None):

        # Mission target attributes.
        self._m_target_nu0 = mission_target_nu0
        self._m_target_a = mission_target_a
        self._m_target_R = mission_target_R
        self._m_target_mu = mission_target_mu

        # Communication target attributes.
        self._c_target_nu0 = communication_target_nu0
        self._c_target_a = communication_target_a
        if (self._c_target_nu0 is None) and (self._c_target_a is None):
            self._c_target = False
        elif (self._c_target_nu0 is not None) and (self._c_target_a is not None):
            self._c_target = True
        else:
            raise AssertionError("Both nu0 and a must either be defined or None for communications.")

        # Spacecraft attributes.
        self._spacecraft_nu0 = spacecraft_nu0
        self._spacecraft_h = spacecraft_h

        # Update states.
        self._m_update = True
        self._c_update = True
        self._s_update = True

        # Previously computed array for time array.
        self._sample_time = None
        self._X_m = None
        self._X_c = None
        self._X_s = None
        self._X_s_u = None
        self._E_comm = None
        self._E_solar = None
        self._E_comm_aux = None
        self._E_solar_aux = None
        self._R_comm = None
        self._R_solar = None

        # Other
        self._nu_eclipse = None
        # self._X_m_u = None

    # Alternative constructor.
    @classmethod
    def from_dict(cls, init_dict):
        """
        Alternative constructor for Geometry class.
        :param init_dict: Example:
        example = {
            "mission_target": {
                "nu0": 0,
                "a": 0,
                "R": 0,
                "mu": 0
            },
            "communication_target": {
                "nu0": 0,
                "a": 0
            },
            "spacecraft": {
                "nu0": 0,
                "h": 0,
            }
        }
        :return: Instantiated MissionGeometry(args).
        """
        _kwargs = {}
        for key, sub_dict in init_dict.items():
            for sub_key, value in sub_dict.items():
                _kwargs[key + "_" + sub_key] = value
        return cls(**_kwargs)

    # Update handler.
    @property
    def m_update(self) -> bool:
        return self._m_update

    @m_update.setter
    def m_update(self, x: bool):
        self._m_update = x

    @property
    def c_update(self) -> bool:
        return self._c_update

    @c_update.setter
    def c_update(self, x: bool):
        self._c_update = x

    @property
    def s_update(self) -> bool:
        return self._s_update

    @s_update.setter
    def s_update(self, x: bool):
        self._s_update = x

    # Geometry configuration.
    @property
    def m_target_mu(self) -> float:
        """
        :return: Mission target gravitational parameter.
        """
        return self._m_target_mu

    @property
    def m_target_a(self) -> float:
        """
        :return: Mission target semi-major axis.
        """
        return self._m_target_a

    @property
    def m_target_nu0(self) -> float:
        """
        :return: Mission target initial true anomaly.
        """
        return self._m_target_nu0

    @property
    def m_target_R(self) -> float:
        """
        :return: Mission target mean equatorial radius.
        """
        return self._m_target_R

    @property
    def c_target_a(self) -> float:
        """
        :return: Mission target semi-major axis.
        """
        return self._c_target_a

    @property
    def c_target_nu0(self) -> float:
        """
        :return: Communication target initial true anomaly.
        """
        return self._c_target_nu0

    @property
    def spacecraft_nu0(self) -> float:
        """
        :return: Spacecraft initial true anomaly.
        """
        return self._spacecraft_nu0

    @property
    def spacecraft_h(self) -> float:
        """
        :return: Spacecraft altitude.
        """
        return self._spacecraft_h

    @m_target_mu.setter
    def m_target_mu(self, x: float):
        self._s_update = True
        self._m_target_mu = x

    @m_target_a.setter
    def m_target_a(self, x: float):
        self._m_update = True
        self._m_target_a = x

    @m_target_nu0.setter
    def m_target_nu0(self, x: float):
        self.m_update = True
        self._m_target_nu0 = x

    @m_target_R.setter
    def m_target_R(self, x: float):
        self.s_update = True
        self._m_target_R = x

    @c_target_a.setter
    def c_target_a(self, x: float):
        self.c_update = True
        self._c_target_a = x

    @c_target_nu0.setter
    def c_target_nu0(self, x: float):
        self.c_update = True
        self._c_target_nu0 = x

    @spacecraft_nu0.setter
    def spacecraft_nu0(self, x: float):
        self.s_update = True
        self._spacecraft_nu0 = x

    @spacecraft_h.setter
    def spacecraft_h(self, x: float):
        self.s_update = True
        self._spacecraft_h = x

    # Geometry attributes
    @property
    def sample_time(self) -> np.ndarray:
        if self._sample_time is None:
            raise LookupError("Sample time array has not been provided.")
        return self._sample_time

    @sample_time.setter
    def sample_time(self, t: np.ndarray):
        self.m_update = True
        self.c_update = True
        self.s_update = True
        self._sample_time = t

    @property
    def thrust_radial_positive_func_nu(self):
        return lambda x: x,

    @property
    def thrust_radial_negative_func_nu(self):
        return lambda x: -x,

    @property
    def thrust_tangential_positive_func_nu(self):
        return lambda x: x + np.pi / 2,

    @property
    def thrust_tangential_negative_func_nu(self):
        return lambda x: x - np.pi / 2,

    @property
    def P_m(self) -> float:
        if self.m_update:
            self._P_m = orbital_period(self.m_target_a, MU_SUN)
        return self._P_m

    @property
    def P_c(self) -> float:
        if self.c_update:
            self._P_c = orbital_period(self.c_target_a, MU_SUN)
        return self._P_c

    @property
    def P_s(self) -> float:
        if self.s_update:
            self._P_s = orbital_period((self.m_target_R + self.spacecraft_h), self.m_target_mu)
        return self._P_s

    @property
    def R_solar(self) -> np.ndarray:
        if self.m_update or (self._R_solar is None):
            self._R_solar = self.__R_solar()
            self._R_solar_u = self._R_solar / np.tile(np.linalg.norm(self._R_solar, axis=1),
                                                      (self._R_solar.shape[1], 1)).T
        return self._R_solar

    @property
    def R_solar_u(self) -> np.ndarray:
        if self.m_update or (self._R_solar is None):
            self._R_solar = self.__R_solar()
            self._R_solar_u = self._R_solar / np.tile(np.linalg.norm(self._R_solar, axis=1),
                                                      (self._R_solar.shape[1], 1)).T
        return self._R_solar_u

    @property
    def R_comm(self) -> np.ndarray:
        if self.m_update or self.c_update or self.s_update or (self._R_comm is None):
            self._R_comm = self.__R_comm()
            self._R_comm_u = self._R_comm / np.tile(np.linalg.norm(self._R_comm, axis=1), (self._R_comm.shape[1], 1)).T
        return self._R_comm

    @property
    def R_comm_u(self) -> np.ndarray:
        if self.m_update or self.c_update or self.s_update or (self._R_comm is None):
            self._R_comm = self.__R_comm()
            self._R_comm_u = self._R_comm / np.tile(np.linalg.norm(self._R_comm, axis=1), (self._R_comm.shape[1], 1)).T
        return self._R_comm_u

    @property
    def E_solar(self) -> np.ndarray:
        if self.m_update or self.s_update or (self._E_solar is None):
            self._E_solar = self.__E_solar()
        return self._E_solar

    @property
    def E_comm(self) -> np.ndarray:
        if self.m_update or self.c_update or self.s_update or (self._E_comm is None):
            self._E_comm = self.__E_comm()
        return self._E_comm

    @property
    def X_m(self) -> np.ndarray:
        if self.m_update or (self._X_m is None):
            self._X_m = self.__X_m()
            self.m_update = False
        return self._X_m

    @property
    def X_c(self) -> np.ndarray:
        if self.c_update or (self._X_c is None):
            self._X_c = self.__X_c()
            self.c_update = False
        return self._X_c

    @property
    def X_s(self) -> np.ndarray:
        if self.s_update or (self._X_s is None):
            self._X_s = self.__X_s()
            self._X_s_u = self._X_s / np.tile(np.linalg.norm(self._X_s, axis=1), (self._X_s.shape[1], 1)).T
            self.s_update = False
        return self._X_s

    @property
    def X_s_u(self) -> np.ndarray:
        if self.s_update or (self._X_s is None):
            self._X_s = self.__X_s()
            self._X_s_u = self._X_s / np.tile(np.linalg.norm(self._X_s, axis=1), (self._X_s.shape[1], 1)).T
            self.s_update = False
        return self._X_s_u

    @property
    def E_solar_aux(self) -> tuple:
        if self.m_update or self.s_update or (self._E_solar is None):
            self._E_solar = self.__E_solar()
        return self._E_solar_aux

    @property
    def E_comm_aux(self) -> tuple:
        if self.m_update or self.c_update or self.s_update or (self._E_comm is None):
            self._E_comm = self.__E_comm()
        return self._E_comm_aux

    def time_to_nu_s(self, t):
        return 2 * np.pi / self.P_s * t + self.spacecraft_nu0

    @property
    def nu_eclipse(self):
        if self.s_update or self.m_update or (self._nu_eclipse is None):
            eclipse_sol = t_solar_eclipse_solutions(R=self.m_target_R,
                                                    h=self.spacecraft_h,
                                                    nu_s0=self.spacecraft_nu0,
                                                    nu_m0=self.m_target_nu0,
                                                    mu_m=self.m_target_mu)
            eclipse_nu = self.time_to_nu_s(eclipse_sol)
            self._nu_eclipse = {"exit": eclipse_nu[0], "entry": eclipse_nu[1]}
        return self._nu_eclipse

    # Private geometry attributes
    def __R_solar(self) -> np.ndarray:
        return - self.X_m

    def __R_comm(self) -> np.ndarray:
        return self.X_c - self.X_m

    def __E_solar(self) -> np.ndarray:
        _bool, _cos_phi, _a_sin_phi = shadow_function(self.R_solar_u, self.X_s_u, self.m_target_R, self.spacecraft_h)
        self._E_solar_aux = (_cos_phi, _a_sin_phi)
        return _bool

    def __E_comm(self) -> np.ndarray:
        _bool, _cos_phi, _a_sin_phi = shadow_function(self.R_comm_u, self.X_s_u, self.m_target_R, self.spacecraft_h)
        self._E_comm_aux = (_cos_phi, _a_sin_phi)
        return _bool

    def __X_m(self) -> np.ndarray:
        return state_celestial_body(self.m_target_a, self.m_target_nu0, self.sample_time)

    def __X_c(self) -> np.ndarray:
        return state_celestial_body(self.c_target_a, self.c_target_nu0, self.sample_time)

    def __X_s(self) -> np.ndarray:
        return state_spacecraft(self.m_target_R, self.spacecraft_h, self.spacecraft_nu0, self.m_target_mu,
                                self.sample_time, self.P_s)
