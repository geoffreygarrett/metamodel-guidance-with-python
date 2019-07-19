from poliastro.twobody.orbit import Orbit
from poliastro.bodies import Body
from astropy import time
from helper import initial_orbit_from_ephemeris
from helper import initial_si_state_from_orbit
from helper import counter


class MissionGeometry(object):
    """
    Class to define a general mission geometry which is defined according to a reference epoch.
    """

    def __init__(self, epoch: time.Time = False, entity_configuration=False):
        self._entities = {} if not entity_configuration else entity_configuration
        self._epoch = epoch
        # self._counter = counter()

    @property
    def entities(self):
        return self._entities

    def add_body(self, body: Body, entity_id=False):
        """
        Method to add a body which is known within the ephemerides.
        :param body:
        :param entity_id:
        :return:
        """
        entity_id = entity_id #if not entity_id #else self._counter
        self._entities.update({str(entity_id): initial_orbit_from_ephemeris(body, self._epoch)})

    def add_orbit(self, orbit: Orbit, entity_id=False):
        """
        Method to add an arbitrarily defined orbit, usually for custom body (i.e. Spacecraft).
        :param orbit:
        :param entity_id:
        :return:
        """
        entity_id = entity_id #if not entity_id #else self._counter
        self._entities.update({str(entity_id): orbit})

    def get_initial_state(self, body_id):
        """
        Method to return all initial cartesian states of all bodies in the mission geometry.
        :return:
        """
        return initial_si_state_from_orbit(self._entities[body_id])
