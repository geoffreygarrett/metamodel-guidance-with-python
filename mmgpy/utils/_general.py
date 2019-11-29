class DynamicLogger:

    def __init__(self, equal_logging=True):
        """

        Parameters
        ----------
        equal_logging
        """
        self.equal_logging = equal_logging
        self.called = False
        self.lengths = None
        self.keys = []

    def __len__(self):
        """

        Returns
        -------

        """
        return self.lengths[0] if self.equal_logging else self.lengths

    def __getitem__(self, item):
        """

        Parameters
        ----------
        item

        Returns
        -------

        """
        ret = None
        if type(item) == int:
            ret = {}
            for k in self.keys:
                ret[k] = getattr(self, k)[item]
        elif type(item) == str:
            ret = getattr(self, item)
        return ret

    def __call__(self, **kwargs):
        """

        Parameters
        ----------
        kwargs

        Returns
        -------

        """
        self.called = True
        self.lengths = []
        self.keys = list(set(self.keys + list(kwargs.keys())))
        for k, v in kwargs.items():
            if hasattr(self, k):
                # Retrieve sub log for append.
                sub_log = getattr(self, k)
                sub_log.append(v)
                # Append length for __len__ inbuilt.
                self.lengths.append(len(sub_log))
            else:
                # Create sub log if it doesn't exist.
                setattr(self, k, [v])
                # Set sub_log length to 1 for init.
                self.lengths.append(1)

        # Equal length logging error catch.
        if self.equal_logging:
            self.equal_logging_catch()

    def equal_logging_catch(self):
        """

        Returns
        -------
        AssertionError

        """

        try:
            assert len(set(self.lengths)) == 1
        except AssertionError:
            raise AssertionError(
                "Unequal log length detected with equal_logging = True.")
