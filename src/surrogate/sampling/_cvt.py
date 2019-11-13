import numpy as np
import matplotlib.pyplot as plt
import platform
from scipy.spatial import Delaunay
from scipy.spatial import Voronoi
from scipy.spatial import voronoi_plot_2d
from scipy import argmin
from scipy import inner


# def _cvt(bounds, n_generators)


class CVT:

    def __init__(self,
                 bounds,
                 k,
                 z_sample_method,
                 alpha=(0, 1),
                 beta=(0, 1),
                 z_sample_kwargs=None,
                 logging=False
                 ):
        self._bounds = bounds
        self._k = k
        self._z = z_sample_method(bounds, k, form="sx",
                                  **z_sample_kwargs) if z_sample_kwargs else z_sample_method(bounds, k, form="sx")
        self._alpha = alpha
        self._beta = beta
        self._j = np.ones(k)

        self._e = 10e-10
        self._zm = 10e-10

        # Logging of algorithm iterations.
        self._logging = logging
        if logging:
            self._log_z = []
            self._log_y = []
            self._log_tri = []
            self._log_e = []
            self._log_zm = []
            self._log_u = []
            self._log_w = []
        else:
            self._log_z = None
            self._log_y = None
            self._log_tri = None
            self._log_e = None
            self._log_zm = None
            self._log_u = None
            self._log_w = None

    @staticmethod
    def _tile_j(j, dim):
        return np.tile(j, (dim, 1)).T

    def _iterate(self, y):
        #
        # For each sample point, find z_idx, the index of the nearest generator.
        #
        z_idx = np.array([argmin([inner(z_i - y_r, z_i - y_r) for z_i in self._z]) for y_r in y])
        #
        # Gather together each set W_i for all sampling points y_r closest to z_i.
        #
        w = [np.array(y[z_idx == i]) for i in range(self._k)]
        #
        # Get number of points in w_i closest to z_i to update.
        #
        n_w = np.bincount(z_idx, minlength=self._k)
        #
        # Get indices of z_i to update.
        #
        z_j = n_w > 0
        #
        #
        # Compute the average u_i of the set W_i.
        #
        u = [np.mean(w_i, axis=0) if w_i.size is not 0 else np.zeros(len(self._bounds[0])) for w_i in w]
        #
        # If the set W_i is empty, do nothing; otherwise, update z_i:
        #
        j_tile = self._tile_j(self._j, len(self._bounds[0]))
        z_j_tile = self._tile_j(z_j, len(self._bounds[0]))
        z_updated = np.where(
            z_j_tile,  # <- Where z must be updated, do the following:
            (
                    + (self._alpha[0] * j_tile + self._beta[0]) * self._z
                    + (self._alpha[1] * j_tile + self._beta[1]) * u) / (j_tile + 1),
            self._z)  # <- Else do nothing to z.
        #
        # Increment j_i for updated z.
        #
        self._j = np.where(z_j, self._j + 1, self._j)
        #
        # Compute the energy.
        #
        self._e = np.sum(np.linalg.norm(z_updated[z_idx] - y, axis=1) ** 2)
        #
        # Compute the generator motion.
        #
        self._zm = np.sum(np.linalg.norm(z_updated[z_j] - self._z[z_j], axis=1) ** 2)
        #
        # Log if set.
        #
        if self._logging:
            self._log_z.append(self._z)
            self._log_y.append(y)
            self._log_tri.append(Delaunay())
            self._log_e.append(self._e)
            self._log_zm.append(self._zm)
            self._log_u.append(u)
            self._log_w.append(w)
        #
        # Update the generators.
        #
        self._z = z_updated
