import numpy as np
from scipy.interpolate import interp1d
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import StandardScaler


def null_mapping(x):
    """

    Parameters
    ----------
    x : ndarray
        Design of experiments.

    Returns
    -------
    x : ndarray
        Unchanged design of experiments.

    """
    return x


def marginal_inverse_ecdf(p, x, kind='linear', single_x=False, h=1.0):
    """
    Parameters
    ----------
    p : ndarray, shape (samples,)
        Determines the (un)normalized probability distribution to be
        sampled. Will be normalized for integral value of 1 for the
        empirical distribution function.
    x : ndarray, shape (samples, input_dimension)
    kind : str or int, optional
        Specifies the kind of interpolation as a string
        ('linear', 'nearest', 'zero', 'slinear', 'quadratic', 'cubic',
        'previous', 'next', where 'zero', 'slinear', 'quadratic' and
        'cubic' refer to a spline interpolation of zeroth, first,
        second or third order; 'previous' and 'next' simply return
        the previous or next value of the point) or as an integer
        specifying the order of the spline interpolator to use.
        (Default is 'linear').
    single_x : True or False, optional
        Specifies the possibility to return a single callable if the
        input dimension of len(x) == 1 (Default is False).
    Returns
    -------
    marginal_inverse_ecdf : tuple of function
        shape, x.shape[-1]
        Returns the list of callable inverse empirical distribution
        functions.
        https://en.wikipedia.org/wiki/Empirical_distribution_function
    """
    x_sorted = []
    p_sorted = []
    m_i_ecdf = []
    # scaler = StandardScaler(feature_range=(1e-3, h))
    # scaler = StandardScaler()
    # p = scaler.fit_transform(p.reshape(-1, 1)).flatten()

    try:
        assert np.all(p >= 0)
    except AssertionError:
        AssertionError("Negative probability from given p")

    if len(x.shape) == 1:
        x_sorted = [x[np.argsort(x)]]
        p_sorted = [p[np.argsort(x)]]
    else:
        for x_i in x.T:
            x_sorted.append(x_i[np.argsort(x_i)])
            p_sorted.append(p[np.argsort(x_i)])

    for x_i, p_i in zip(x_sorted, p_sorted):

        p_pdf = np.abs(p_i)
        x_cdf = x_i
        # if x_i[0] > 0.0:
        x_cdf = np.concatenate(([0.0], x_cdf))
        p_pdf = np.concatenate(([0.0], p_pdf))

        # if x_i[-1] < 1.0:
        x_cdf = np.concatenate((x_cdf, [1.0]))
        p_pdf = np.concatenate((p_pdf, [0.0]))

        p_cdf = np.cumsum(p_pdf)
        p_cdf /= np.max(p_cdf)

        if p_cdf[0] == p_cdf[1]:
            p_cdf[1] += 1e-8
        if p_cdf[-1] == p_cdf[-2]:
            p_cdf[-2] -= 1e-8

        # print(p_cdf)
        #
        # # p_cdf = p_cdf[np.argsort(p_cdf)]
        # # print("-" * 40)
        # # print(x_cdf)
        # # print(p_cdf)
        # print(np.max(p_cdf))
        # print(np.min(p_cdf))
        # print(np.diff(p_cdf)[np.diff(p_cdf) < 0].shape)
        # print(np.diff(x_cdf)[np.diff(p_cdf) < 0].shape)
        # # print(np.unique(x_cdf).shape)
        m_i_ecdf.append(interp1d(x=p_cdf, y=x_cdf, kind=kind))
    m_i_ecdf = tuple(m_i_ecdf)
    return m_i_ecdf[0] if (len(m_i_ecdf) is 1 and single_x) else m_i_ecdf


class InterpolatedMarginalInverseECDF:

    def __init__(self, p, x, kind='linear'):
        """
        Interpolated Marginal Inverse of the empirical cumulative
        distribution function of p.

        Parameters
        ----------
        p : ndarray, shape (samples,)
            Determines the (un)normalized probability distribution
            to be sampled. Will be normalized for integral value of 1
            for the empirical distribution function.
        x : ndarray, shape (samples, input_dimension)
        kind : str or int, optional
            Specifies the kind of interpolation as a string
            ('linear', 'nearest', 'zero', 'slinear', 'quadratic',
            'cubic', 'previous', 'next', where 'zero', 'slinear',
            'quadratic' and 'cubic' refer to a spline interpolation of
            zeroth, first, second or third order; 'previous' and 'next'
            simply return the previous or next value of the point) or
            as an integer specifying the order of the spline
            interpolator to use.
            (Default is 'linear').
        """
        self._interpolations = marginal_inverse_ecdf(p, x, kind,
                                                     single_x=False)
        self.__x_dim = x.shape[-1]

    def __call__(self, u):
        # Catch mismatch in dimensions for sampling input.
        try:
            assert u.shape[-1] == len(self._interpolations)
        except AssertionError:
            raise AssertionError(
                f"""
            Dimension mismatch: 
            u.shape[-1] ({u.shape[-1]}) != x.shape[-1]({self.__x_dim})
            """)
        result = u
        # print(result)
        # Sample from each input marginal distribution.
        # try:
        # print("-" * 40)
        # print(np.max(u))
        # print(np.min(u))
        # print("-" * 40)
        for x_idx in range(u.shape[-1]):
            # print(self._interpolations[x_idx](np.linspace(0, 1, 100)))
            result[:, x_idx] = np.apply_along_axis(self._interpolations[x_idx],
                                                   axis=0,
                                                   arr=result.T[x_idx])
            # print(result)
        # except ValueError:

        return result


if __name__ == "__main__":
    import matplotlib.pyplot as plt
    from mmgpy.surrogate.sampling import uniform_grid
    from mmgpy.surrogate.sampling import halton
    from mmgpy.surrogate.sampling import cvt

    # x = cvt(2, 200, iterations=30, sample_num=2000)
    x = halton([[0] * 2, [1] * 2], 100)
    p = 100 - 100 * np.sqrt(
        (x.T[0] - 0.5) ** 2 + (x.T[1] - 0.5) ** 2).flatten()

    from sklearn.preprocessing import MinMaxScaler

    # scl = MinMaxScaler(feature_range=(0.01, 90))
    #
    # p_scl = scl.fit_transform(p.reshape(-1, 1)).flatten()

    # print(p_scl)
    # p = (p + 1) ** 5
    # print(p.shape)
    # print(p)
    # print(p)

    test = InterpolatedMarginalInverseECDF(p**4, x,
                                           kind='linear')

    # print(x)
    # print(test(x))
    # print(test(x))
    plt.scatter(*test(x).T)

    plt.plot(np.linspace(0, 1, 100),
             test._interpolations[0](np.linspace(0.0, 1.0, 100)))

    # plt.scatter(*x.T)
    plt.show()
