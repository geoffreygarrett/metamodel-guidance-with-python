import numpy as np
from itertools import combinations


def f0(x1, f=9.0):
    """
    F1: 3.0 Hz
    """
    return 0.25 * np.sin(f * 2 * np.pi * x1) + 0.5


def f1(x1, x2, f=[3, 5]):
    """
    F1: 3.0 Hz
    F2: 9.0 Hz
    """
    return 0.5 + 0.1 * (np.sin(f[0] * 2 * np.pi * x1)
                        + np.sin(f[1] * 2 * np.pi * x2))


def f1_1(x1, x2, f=[3, 5]):
    """
    F1: 3.0 Hz
    F2: 9.0 Hz
    """
    return 0.5 + 0.1 * (np.sin(f[0] * 2 * np.pi * x1)
                        + np.sin(f[1] * 2 * np.pi * x2)
                        + 2 * np.cos(5 * 2 * np.pi * x2 * x1))


def f2(x1, x2, x3, f=[3, 9, 27]):
    """
    F1: 3.0  Hz
    F2: 9.0  Hz
    F3: 27.0 Hz
    """
    return 0.5 + 0.1 * (1 * np.sin(f[0] * 2 * np.pi * x1) *
                        2 * np.sin(f[1] * 2 * np.pi * x2) *
                        3 * np.sin(f[2] * 2 * np.pi * x3) *
                        6 * np.sin(10 * 2 * np.pi * x3 * x2))


def f3(x1, x2, x3, x4, f=[3, 9, 27, 81]):
    """
    F1: 3.0  Hz
    F2: 9.0  Hz
    F3: 27.0 Hz
    F4: 81.0 Hz
    """
    return np.product([np.sin(f[0] * 2 * np.pi * x1),
                       np.sin(f[1] * 2 * np.pi * x2),
                       np.sin(f[2] * 2 * np.pi * x3),
                       np.sin(f[3] * 2 * np.pi * x4)])


class ClassPropertyDescriptor(object):

    def __init__(self, fget, fset=None):
        self.fget = fget
        self.fset = fset

    def __get__(self, obj, klass=None):
        if klass is None:
            klass = type(obj)
        return self.fget.__get__(obj, klass)()

    def __set__(self, obj, value):
        if not self.fset:
            raise AttributeError("can't set attribute")
        type_ = type(obj)
        return self.fset.__get__(obj, type_)(value)

    def setter(self, func):
        if not isinstance(func, (classmethod, staticmethod)):
            func = classmethod(func)
        self.fset = func
        return self


def classproperty(func):
    if not isinstance(func, (classmethod, staticmethod)):
        func = classmethod(func)

    return ClassPropertyDescriptor(func)


class TestFunction:

    @staticmethod
    def _catch_n(n, less_than=1):
        try:
            assert n >= less_than
        except AssertionError:
            raise AssertionError(f"n must be >= than 1, but is ={n}")

    @property
    def norm_domain(self):
        return self._norm_domain

    @norm_domain.setter
    def norm_domain(self, x):
        self._norm_domain = x

    def normed_call(self, *args):
        _args = [args[i] * (self._bounds[1][i] - self._bounds[0][i]) + self._bounds[0][i] for i in range(len(args))]
        return self._f(*_args)

    def __init__(self):
        self._norm_domain = True
        self._bounds = None
        self._optimum = None
        self._f = None
        self._n = None
        self._str = None

    def __call__(self, *args):
        return self._f(*args) if not self.norm_domain else self.normed_call(*args)

    def __str__(self):
        return self._str

    @property
    def bounds(self):
        return self._bounds

    @property
    def norm_bounds(self):
        return np.array([[0] * 2, [1] * 2]) if self._n is None else np.array([[0] * self._n, [1] * self._n])

    @property
    def optimums(self):
        return self._optimum


# https://en.wikipedia.org/wiki/Test_functions_for_optimization
class Rastrigin(TestFunction):
    """
    Rastrigin, L. A. "Systems of extremal control." Mir, Moscow (1974).
    """

    def __init__(self, n):
        self._catch_n(n)
        super().__init__()
        self._str = f"Rastrigin function [{n}D]"
        self._bounds = np.array([[-5.12] * n, [5.12] * n])
        self._optimum = [([0] * n, 0.0)]
        self._n = n
        self._f = lambda *x: 10 * len(x) + np.sum([x_i ** 2 - 10 * np.cos(2 * np.pi * x_i) for x_i in x], axis=0)


class Ackley(TestFunction):
    """
    Ackley, D. H. (1987) "A connectionist machine for genetic hillclimbing", Kluwer Academic Publishers, Boston MA.
    """

    def __init__(self):
        super().__init__()
        self._str = "Ackley function [2D]"
        self._bounds = np.array([
            [-5.0, -5.0],
            [+5.0, +5.0]])
        self._optimum = [([0.0, 0.0], 0.0)]
        self._f = lambda x, y: -20 * np.exp(-0.2 * np.sqrt(0.5 * (x ** 2 + y ** 2))) - np.exp(
            0.5 * (np.cos(2 * np.pi * x) + np.cos(2 * np.pi * y))) + np.e + 20


class Sphere(TestFunction):

    def __init__(self, n):
        self._catch_n(n)
        super().__init__()
        self._str = f"Sphere function [{n}D]"
        self._bounds = np.array([
            [-1e8] * n,
            [+1e8] * n])
        self._optimum = [([0.0] * n, 0.0)]
        self._n = n
        self._f = lambda *x: np.sum([x_i ** 2 for x_i in x], axis=0)


class Rosenbrock(TestFunction):

    def __init__(self, n):
        self._catch_n(n)
        super().__init__()
        self._str = f"Rosenbrock function [{n}D]"
        self._bounds = np.array([
            [-1.5] * n,
            [+1.5] * n])
        self._optimum = [([1.0] * n, 0.0)]
        self._a = lambda x_i_p_1, x_i: 100 * (x_i_p_1 - x_i ** 2) ** 2 + (1 - x_i) ** 2
        self._f = lambda *x: np.sum([self._a(x_i_p_1, x_i) for x_i_p_1, x_i in zip(x[1:], x[:-1])], axis=0)
        self._n = n


class Beale(TestFunction):

    def __init__(self):
        super().__init__()
        self._str = "Beale function [2D]"
        self._bounds = np.array([
            [-4.5] * 2,
            [+4.5] * 2])
        self._optimum = [([3, 0.5], 0.0)]
        self._f = lambda x, y: (1.5 - x + x * y) ** 2 + (2.25 - x + x * y ** 2) ** 2 + (2.625 - x + x * y ** 3) ** 2


class GoldsteinPrice(TestFunction):

    def __init__(self):
        super().__init__()
        self._str = "Goldstein–Price function [2D]"
        self._bounds = np.array([
            [-2] * 2,
            [+2] * 2])
        self._optimum = [([0.0, -1.0], 3.0)]
        self._a1 = lambda x, y: 1 + (x + y + 1) ** 2 * (19 - 14 * x + 3 * x ** 2 - 14 * y + 6 * x * y + 3 * y ** 2)
        self._a2 = lambda x, y: 30 + (2 * x - 3 * y) ** 2 * (
                18 - 32 * x + 12 * x ** 2 + 48 * y - 36 * x * y + 27 * y ** 2)
        self._f = lambda x, y: self._a1(x, y) * self._a2(x, y)


class Booth(TestFunction):
    def __init__(self):
        super().__init__()
        self._str = "Booth function [2D]"
        self._bounds = np.array([
            [-10.0] * 2,
            [+10.0] * 2])
        self._optimum = [([1.0, 3.0], 0.0)]
        self._f = lambda x, y: (x + 2 * y - 7) ** 2 + (2 * x + y - 5) ** 2


class BukinN6(TestFunction):
    def __init__(self):
        super().__init__()
        self._str = "Bukin function N.6 [2D]"
        self._bounds = np.array([
            [-15.0, -3],
            [-5.00, +3]])
        self._optimum = [([-10.0, 1.0], 0.0)]
        self._f = lambda x, y: 100 * np.sqrt(np.abs(y - 0.01 * x ** 2)) + 0.01 * np.abs(x + 10)


class Matyas(TestFunction):
    def __init__(self):
        super().__init__()
        self._str = "Matyas function [2D]"
        self._bounds = np.array([
            [-10.0] * 2,
            [+10.0] * 2])
        self._optimum = [([0.0, 0.0], 0.0)]
        self._f = lambda x, y: 0.26 * (x ** 2 + y ** 2) - 0.48 * x * y


class LeviN13(TestFunction):
    def __init__(self):
        super().__init__()
        self._bounds = np.array([
            [-10.0] * 2,
            [+10.0] * 2])
        self._optimum = [([1.0, 1.0], 0.0)]
        self._f = lambda x, y: (np.sin(3 * np.pi * x) ** 2 + (x - 1) ** 2 * (1 + np.sin(3 * np.pi * y) ** 2)
                                + (y - 1) ** 2 * (1 + np.sin(2 * np.pi * y)))

    def __str__(self):
        return "Lévi function N.13 2D"


class Himmelblau(TestFunction):
    """
    Himmelblau, D. (1972). Applied Nonlinear Programming. McGraw-Hill. ISBN 0-07-028921-2.
    """

    def __init__(self):
        super().__init__()
        self._str = "Himmelblau's function [2D]"
        self._bounds = np.array([
            [-5.0, -5.0],
            [+5.0, +5.0]])
        self._optimum = [
            ([+3.000000, +2.000000], 0.0),
            ([-2.805118, +3.131312], 0.0),
            ([-3.779310, -3.283186], 0.0),
            ([+3.584428, -1.848126], 0.0)
        ]
        self._f = lambda x, y: (x ** 2 + y - 11) ** 2 + (x + y ** 2 - 7) ** 2


class ThreeHumpCamel(TestFunction):
    def __init__(self):
        super().__init__()
        self._str = "Three-hump camel function [2D]"
        self._bounds = np.array([
            [-5.0] * 2,
            [+5.0] * 2])
        self._optimum = [([0.0, 0.0], 0.0)]
        self._f = lambda x, y: 2 * x ** 2 - 1.05 * x ** 4 + x ** 6 / 6 + x * y + y ** 2


class Easom(TestFunction):
    """
    """

    def __init__(self):
        super().__init__()
        self._str = "Easom function [2D]"
        self._bounds = np.array([
            [-100, -100],
            [+100, +100]])
        self._optimum = [((np.pi, np.pi), (-1.0))]
        self._f = lambda x, y: - np.cos(x) * np.cos(y) * np.exp(-((x - np.pi) ** 2 + (y - np.pi) ** 2))


class CrossInTray(TestFunction):
    def __init__(self):
        super().__init__()
        self._str = "Cross In Tray function [2D]"
        self._bounds = np.array([
            [-10.0] * 2,
            [+10.0] * 2])
        self._optimum = [
            ([+1.34941, -1.34941], -2.06261),
            ([+1.34941, +1.34941], -2.06261),
            ([-1.34941, -1.34941], -2.06261),
            ([-1.34941, -1.34941], -2.06261)]
        self._f = lambda x, y: -1e-4 * (
                np.abs(np.sin(x) * np.sin(y) * np.exp(np.abs(100 - np.sqrt(x ** 2 + y ** 2) / np.pi))) + 1) ** 1e-1


class Eggholder(TestFunction):
    """

    """

    def __init__(self):
        super().__init__()
        self._str = "Eggholder function [2D]"
        self._bounds = np.array([
            [-512, -512],
            [+512, +512]])
        self._optimum = [([512, 404.2319], -959.6407)]
        self._f = lambda x, y: - (y + 47) * np.sin(np.sqrt(np.abs(x / 2. + (y + 47)))) - x * np.sin(
            np.sqrt(np.abs(x - (y + 47))))


class HolderTable(TestFunction):
    """

    """

    def __init__(self):
        super().__init__()
        self._str = "Holder Table function [2D]"
        self._bounds = np.array([
            [-10] * 2,
            [+10] * 2])
        self._optimum = [([512, 404.2319], -959.6407)]
        self._f = lambda x, y: - np.abs(np.sin(x) * np.cos(y) * np.exp(np.abs(1 - np.sqrt(x ** 2 + y ** 2) / np.pi)))


class McCormick(TestFunction):
    """

    """

    def __init__(self):
        super().__init__()
        self._str = "McCormick function [2D]"
        self._bounds = np.array([
            [-1.5, -3.0],
            [+4.0, +4.0]])
        self._optimum = [([-0.54719, -1.54719], -1.9133)]
        self._f = lambda x, y: np.sin(x + y) + (x - y) ** 2 - 1.5 * x + 2.5 * y + 1


class SchafferN2(TestFunction):
    """

    """

    def __init__(self):
        super().__init__()
        self._str = "Schaffer function N. 2	[2D]"
        self._bounds = np.array([[-100, -100], [100, 100]])
        self._optimum = [([0.0, 0.0], 0.0)]
        self._f = lambda x, y: 0.5 + (np.sin(x ** 2 - y ** 2) ** 2 - 0.5) / (1 + 0.001 * (x ** 2 + y ** 2)) ** 2

    def __call__(self, x, y):
        return self._f(x, y)


class SchafferN4(TestFunction):
    """

    """

    def __init__(self):
        super().__init__()
        self._str = "Schaffer function N. 4 [2D]"
        self._bounds = np.array([
            [-100, -100],
            [+100, +100]])
        self._optimum = [
            ([0.0, +1.25313], 0.292579),
            ([0.0, -1.25313], 0.292579),

        ]
        self._f = lambda x, y: 0.5 + (np.cos(np.sin(np.abs(x ** 2 - y ** 2))) ** 2 - 0.5) / (
                1 + 0.001 * (x ** 2 + y ** 2)) ** 2


class StyblinskiTang(TestFunction):

    def __init__(self, n):
        self._catch_n(n)
        super().__init__()
        self._str = f"Styblinski–Tang function [{n}D]"
        self._bounds = np.array([
            [-5] * n,
            [+5] * n])
        # Optimum is not phrased as below. Check Wikipedia for actual test (This is only approx to 5th decimal place).
        self._optimum = [([-2.903535] * n, -39.166165 * n)]
        self._f = lambda x_vec: np.sum([(x_i ** 4 - 16 * x_i ** 2 + 5 * x_i) / 2.0 for x_i in x_vec], axis=0)

    def __call__(self, *x):
        return self._f(x)


class GarrettLagadec(TestFunction):

    def __init__(self, n, lam=0.5):
        self._catch_n(n)
        super().__init__()
        self._str = f"GarrettLagadec lam{lam} [{n}D]"

        def get_opt(n, lam):
            sol = np.array([[]])
            for i in range(1, n + 1):
                if i == 1:
                    sol = np.array([-lam, lam]).reshape(-1, 1)
                else:
                    sol = np.concatenate((
                        np.tile(sol, (2, 1)),
                        np.array([[-lam] * 2 ** (i - 1) + [lam] * 2 ** (i - 1)]).reshape(-1, 1)
                    ), axis=1)
            return sol

        self._bounds = np.array([
            [-1.0] * n,
            [+1.0] * n])
        # Optimum is not phrased as below. Check Wikipedia for actual test (This is only approx to 5th decimal place).
        self._optimum = [(x_val, 0.0) for x_val in get_opt(n, lam)]

        def f(x_vec):
            return np.max([np.min([np.abs(x_i - lam), np.abs(x_i + lam)], axis=0) for x_i in x_vec], axis=0)

        self._f = lambda *x_vec: f(x_vec)


class Test_x15_y21:
    def __init__(self):
        self._f = lambda x, y: np.cos((15 * 2 * np.pi * y)) + np.cos(
            (21 * 2 * np.pi * x))  # + 3*np.sin((30*2*np.pi*(y)))

    def __call__(self, x, y):
        return self._f(x, y)

    @property
    def bounds(self):
        return [[0, 0], [1, 1]]


class Test_x15_y21_xy30:
    def __init__(self):
        self._f = lambda x, y: np.cos((15 * 2 * np.pi * y)) + np.cos(
            (21 * 2 * np.pi * x)) + np.sin((30 * 2 * np.pi * (y + x)))

    def __call__(self, x, y):
        return self._f(x, y)

    @property
    def bounds(self):
        return [[0, 0], [1, 1]]


def props(cls):
    return [i for i in cls.__dict__.keys() if i[:1] != '_']


class TestFunctionSet2DInputSpace:

    def __init__(self):
        self.Rastrigin2D = Rastrigin(2)
        self.Ackley = Ackley()
        self.Sphere2D = Sphere(2)
        self.Rosenbrock2D = Rosenbrock(2)
        self.Beale = Beale()
        self.GoldsteinPrice = GoldsteinPrice()
        self.Booth = Booth()
        self.BukinN6 = BukinN6()
        self.Matyas = Matyas()
        self.LeviN13 = LeviN13()
        self.Himmelblau = Himmelblau()
        self.ThreeHumpCamel = ThreeHumpCamel()
        self.Easom = Easom()
        self.CrossInTray = CrossInTray()
        self.Eggholder = Eggholder()
        self.HolderTable = HolderTable()
        self.McCormick = McCormick()
        self.ScafferN2 = SchafferN2()
        self.ScafferN4 = SchafferN4()
        self.StyblinskiTang2D = StyblinskiTang(2)
        self.GarrettLagadec2D_pt6 = GarrettLagadec(2, lam=0.6)
        self._list = [
            self.Rastrigin2D,
            self.Ackley,
            self.Sphere2D,
            self.Rosenbrock2D,
            self.Beale,
            self.GoldsteinPrice,
            self.Booth,
            self.BukinN6,
            self.Matyas,
            self.LeviN13,
            self.Himmelblau,
            self.ThreeHumpCamel,
            self.Easom,
            self.CrossInTray,
            self.Eggholder,
            self.HolderTable,
            self.McCormick,
            self.ScafferN2,
            self.ScafferN4,
            self.StyblinskiTang2D,
            self.GarrettLagadec2D_pt6,
        ]

    def __getitem__(self, idx):
        return self._list[idx]

    def __len__(self):
        return len(self._list)

    def __str__(self):
        return ''.join(["Available test functions in set: \n"] + ["- {}\n".format(name) for name in props(self)])


class TestFunctionSetNDInputSpace:

    def __init__(self, N):
        setattr(self, "Rastrigin{}D".format(N), Rastrigin(N))
        setattr(self, "Sphere{}D".format(N), Sphere(N))
        setattr(self, "Rosenbrock{}D".format(N), Rosenbrock(N))
        setattr(self, "StyblinskiTang{}D".format(N), StyblinskiTang(N))
        setattr(self, "GarrettLagadec{}D".format(N), GarrettLagadec(N))
        self._list = [
            getattr(self, "Rastrigin{}D".format(N)),
            getattr(self, "Sphere{}D".format(N)),
            getattr(self, "Rosenbrock{}D".format(N)),
            getattr(self, "StyblinskiTang{}D".format(N)),
            getattr(self, "GarrettLagadec{}D".format(N)),

        ]

    def __str__(self):
        return ''.join(["Available test functions in set: \n"] + ["- {}\n".format(name) for name in props(self)])

    def __getitem__(self, idx):
        return self._list[idx]

    def __len__(self):
        return len(self._list)


if __name__ == "__main__":
    from sampling.uninformed import grid_sample_domain

    # GarrettLagadec = GarrettLagadec(2)
    #
    # f1_grid = grid_sample_domain(GarrettLagadec.bounds, [100, 100], flatten=False)
    # x, y = f1_grid[0], f1_grid[1]
    # print(GarrettLagadec(x, y))
    # # plotly3Dsurf(x, y, )
