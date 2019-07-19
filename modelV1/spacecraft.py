import numpy as np
from astropy import units as u
import astropy.units.quantity


class Spacecraft(object):

    def __init__(self, spacecraft_configuration=False):
        # Available components and component attributes.
        self._available_components = {
            "solar_panels":
                {
                    "r",  # type: astropy.units.Quantity
                    "area",  # type: astropy.units.Quantity
                },
            "star_sensors":
                {
                    "r",  # type: astropy.units.Quantity
                    "solar_exclusion_angle"  # type: astropy.units.Quantity
                },
            "antennas":
                {
                    "r",  # type: astropy.units.Quantity
                    "communication_inclusion_angle",  # type: astropy.units.Quantity
                },
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
    "solar_panels": [

        {  # Solar panel.
            "area": 3.0 * u.m,
            "r": np.array([0, 1]) * u.dimensionless_unscaled
        }

    ],
    "star_sensors": [

        {  # Star sensor 1.
            "r": np.array([1 / np.sqrt(2), 1 / np.sqrt(2)]),
            "solar_exclusion_angle": 5 * u.deg
        },
        {  # Star sensor 2.
            "r": np.array([1 / np.sqrt(2), 1 / np.sqrt(2)]),
            "solar_exclusion_angle": 5 * u.deg
        }

    ],
    "antennas": [

        {  # High gain antenna.
            "r": np.array([0, 1]) * u.dimensionless_unscaled,
            "communication_inclusion_angle": 1.5e-3 * u.rad
        },
    ],
    "thruster":
        {
            "r": np.array([0, -1]),
            "thrust_force": 0 * u.N  # type: astropy.units.Quantity
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
