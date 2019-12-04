import numpy as np


class BaseConstructor:
    """Base class from which all constructors are derived.

    """

    def __init__(self, parent=lambda *x: x):
        """

        Parameters
        ----------
        parent : callable, optional
            Parent constructor in earlier hierarchical construction.
        """
        self._parent = parent

    def __call__(self, *args):
        """

        Returns
        -------
        constructed : numpy.ndarray, shape=(self._n,0)
            Constructed time-series of physical independent variable.

        """
        return self.construct(args)

    @property
    def parent(self):
        """Parent constructor

        Returns
        -------

        """
        return self._parent

    def construct(self, *args):
        """

        Parameters
        ----------
        args : tuple, shape=(len(args),)
            Arguments with which construction occurs with.

        Returns
        -------
        constructed : numpy.ndarray, shape=(self._n,0)

        """
        return self._parent(args)


class FixedConstructor(BaseConstructor):

    def __init__(self, fixed_vector):
        """

        Parameters
        ----------
        fixed_vector
        """
        self._fixed_vector = fixed_vector
        super().__init__()

    def construct(self, *args):
        return self._fixed_vector


class IntegerDesignConstructor(BaseConstructor):
    """

    """

    def __init__(self, bound=()):
        raise NotImplementedError("Currently not implemented.")


class RealDesignConstructor(BaseConstructor):

    def __init__(self, bound=(-1.0, 1.0), n=1):
        """Real design variable type to be constructed.

        Parameters
        ----------
        bound : [tuple of float, default=(-1.0, 1.0)]
            The maximum and minimum values of this type of design
            variable.
        n : [int, default=1]
            The number of design variables of this type (default = 1).
        """
        super().__init__()
        self._bound = bound
        self._n = n

    def get_ncx(self):
        """Continuous dimension of the constructor.

        This method will return $𝑛_{cx}$, the continuous dimension
        of the problem.

        Returns
        -------
        ncx : [int]
            The continuous dimension of the constructor.
        """
        return self._n

    def get_bounds(self):
        """Box-bounds.

        Returns
        -------
        bounds : [tuple of numpy.ndarray]

        """
        return tuple(np.array(self._bound * self._n).reshape(self._n, -1).T)

# class TimeVector(BaseConstructor):
#
#     def __init__(self):
#         super().__init__()

#
# class MagnitudeVector:
