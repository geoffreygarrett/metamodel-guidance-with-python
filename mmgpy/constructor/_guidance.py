from ._base import BaseConstructor
from ._base import RealDesignConstructor


class RelativeTimeSeriesConstructor:

    def __init__(self, n):

        self._time_series_design = RealDesignConstructor(n=n-1)


