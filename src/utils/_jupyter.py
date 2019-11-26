from tqdm import tqdm_notebook as tqdm


class TQDMSkoptCallable(object):

    def __init__(self, **kwargs):
        """

        Parameters
        ----------
        kwargs
        """
        self._bar = tqdm(**kwargs)

    def __call__(self, res):
        """

        Parameters
        ----------
        res

        Returns
        -------

        """
        self._bar.update()

    def close(self):
        """

        Returns
        -------

        """
        self._bar.close()
        self._bar.clear()

