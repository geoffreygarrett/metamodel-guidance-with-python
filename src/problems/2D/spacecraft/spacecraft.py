import numpy as np
from astropy import units as u
import astropy.units.quantity


class Spacecraft:

    def __init__(self, spacecraft_configuration=False):
        # Available components and component attributes.
        self._template_configuration = {
            "solar_panels":
                [
                    {
                        "r",  # type: astropy.units.Quantity
                        "area",  # type: astropy.units.Quantity
                    }
                ],
            "star_sensors":
                [
                    {
                        "r",  # type: astropy.units.Quantity
                        "solar_exclusion_angle"  # type: astropy.units.Quantity
                    }
                ],
            "antennas":
                [
                    {
                        "r",  # type: astropy.units.Quantity
                        "communication_inclusion_angle",  # type: astropy.units.Quantity
                    }
                ],
            "thruster":
                {
                    "r",  # type: astropy.units.Quantity
                    "thrust_force"  # type: astropy.units.Quantity
                }
        }

        # Current stored configuration of spacecraft.
        self._configuration = spacecraft_configuration if spacecraft_configuration else dict()

    def components(self, name):
        return self._configuration[name]

    def load_configuration(self, configuration):
        self._configuration = configuration

    @property
    def moi(self):
        try:
            return self._configuration["physical_characteristics"]["moi"](
                self._configuration["physical_characteristics"]["m"],
                self._configuration["physical_characteristics"]["w"],
                self._configuration["physical_characteristics"]["d"],
            )
        except KeyError("Configuration does not have the required physical characteristics."):
            return None

    def torque(self, alpha):
        return self.moi * alpha

    def alpha(self, torque):
        return torque / self.moi

    @property
    def alpha_max(self):
        return self._configuration["reaction_wheel"]["max_tau"] / self.moi

    @property
    def alpha_min(self):
        return self._configuration["reaction_wheel"]["min_tau"] / self.moi


########################################################################################################################
#
#       ███╗   ███╗ ██████╗ ██████╗ ███████╗██╗         ██╗   ██╗ ██╗
#       ████╗ ████║██╔═══██╗██╔══██╗██╔════╝██║         ██║   ██║███║
#       ██╔████╔██║██║   ██║██║  ██║█████╗  ██║         ██║   ██║╚██║
#       ██║╚██╔╝██║██║   ██║██║  ██║██╔══╝  ██║         ╚██╗ ██╔╝ ██║
#       ██║ ╚═╝ ██║╚██████╔╝██████╔╝███████╗███████╗  ██╗╚████╔╝  ██║
#       ╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝  ╚═╝ ╚═══╝   ╚═╝
#
########################################################################################################################
spacecraft_configuration_2d_example = {
    "solar_panels":
        [

            {  # Solar panel.
                "area": 3.0 * u.m,
                "r": np.array([0, 1]) * u.dimensionless_unscaled
            }

        ],
    "star_sensors":
        [

            {  # Star sensor 1.
                "r": np.array([1 / np.sqrt(2), 1 / np.sqrt(2)]),
                "solar_exclusion_angle": 5 * u.deg
            },
            {  # Star sensor 2.
                "r": np.array([-1 / np.sqrt(2), 1 / np.sqrt(2)]),
                "solar_exclusion_angle": 5 * u.deg
            }

        ],
    "antennas":
        [

            {  # High gain antenna.
                "r": np.array([0, 1]) * u.dimensionless_unscaled,
                "communication_inclusion_angle": 1.5e-3 * u.rad
            },
        ],
    "thruster":
        {
            "r": np.array([0, -1]),
            "thrust_force": 0 * u.N  # type: astropy.units.Quantity
        },
    "reaction_wheel":
        {
            "max_tau": 68 * u.N * u.m * u.s * 0.01,
            "min_tau": 0.04 * u.N * u.m * u.s,
        },
    "physical_characteristics":
        {
            # Inertia defined as rectangular.
            "moi": lambda m, w, d: 1 / 12 * m * (w ** 2 + d ** 2),

            # Physical characteristics.
            "w": 4 * u.m,
            "d": 5 * u.m,
            "m": 2000 * u.kg
        }
    ####################################################################################################################
    #
    #                                          Y
    #
    #                                          ^
    #                                          |
    #                                          |
    #                     star sensor 2        |         star sensor 1
    #                                         >>
    #                             X     +-+   ||   +-+     X
    #            solar panel       X    |------------|    X        solar panel
    #                ^              X   +-|antenna |-+   X             ^
    #                |               X   +-----+----+   X              |
    #                |                X        |       X               |
    #                |                 +--------------+                |
    #      +---------+------------+    |       |      |    +-----------+-----------+
    #      |                      |    |       |      |    |                       |
    #      |                      +----+       +----------------------------------------> X
    #      |                      |    |              |    |                       |
    #      +----------------------+    |              |    +-----------------------+
    #                                  +--------------+
    #
    ####################################################################################################################
}
