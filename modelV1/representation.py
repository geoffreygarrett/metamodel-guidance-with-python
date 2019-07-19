import sympy
import numpy as np

N_max = 20

# Problem symbol setup.
t = sympy.Symbol("t")
T = sympy.Symbol("T")
a = [sympy.Symbol(f"a_{i}") for i in range(N_max)]


# N degree polynomial representation.
def n_polynomial(n):
    assert n <= N_max
    expression = 0
    for i in range(n + 1):
        expression += a[i] * (t / T) ** i
    return expression


def n_polynomial_representation(n, _T=1):
    system = []

    # Definition of the three governing physical equations.
    omega = n_polynomial(n)
    alpha = sympy.diff(omega, t)
    theta = sympy.integrate(omega, t)

    # Acceleration boundary conditions. a(0) = a(T) = 0
    system.append(sympy.Eq(alpha.subs(t, 0), 0))
    system.append(sympy.Eq(alpha.subs(t, T), 0))

    # Omega boundary conditions. v(0) = v(T) = 0
    system.append(sympy.Eq(omega.subs(t, 0), 0))
    system.append(sympy.Eq(omega.subs(t, T), 0))

    # Theta boundary conditions. theta(0) = theta(T) = theta_0
    system.append(sympy.Eq(theta.subs(t, 0), theta.subs(t, T)))
    sol = sympy.solve(system, *a)

    design_variables = [sympy.Symbol(f"x_{k}") for k in range(n - 4)]
    design_variables_conv = {}
    for j in range(n - 4):
        design_variables_conv.update({a[5 + j]: design_variables[j]})

    # Solve
    return ({'alpha': alpha.subs(sol).subs({T: _T}).subs(design_variables_conv),
             'omega': omega.subs(sol).subs({T: _T}).subs(design_variables_conv),
             'theta': theta.subs(sol).subs({T: _T}).subs(design_variables_conv)}, design_variables)


class Representation(object):
    def __init__(self):
        pass


class PolynomialRepresentation(Representation):

    def __init__(self, n_degree, t_horizon):
        super().__init__()
        self._t_horizon = t_horizon
        self._n_degree = n_degree
        self._analytical_solution = n_polynomial_representation(n_degree, t_horizon)

    @property
    def design_variables(self):
        return self._analytical_solution[1]

    @property
    def analytical_equations(self):
        return self._analytical_solution[0]

    def analytical_solution_functions(self, design_parameters, vectorised=False):
        result = {}
        for key in self.analytical_equations.keys():
            eq = self.analytical_equations[key]

            def function(eq):
                def inner(t_value):
                    replace = {}
                    for idx, parameter in enumerate(design_parameters):
                        replace.update({self.design_variables[idx]: parameter})
                    eq2 = eq.subs(replace)
                    return float(eq2.subs(t, t_value))

                return inner

            # TODO: Make less messy.

            if vectorised:
                result.update({key: np.vectorize(function(eq))})
            else:
                result.update({key: function(eq)})
        return result


if __name__ == "__main__":
    import matplotlib.pyplot as plt

    test = PolynomialRepresentation(5, 1)

    for k in np.linspace(0, 1, 10):
        funcs = test.analytical_solution_functions([k], True)
        t_array = np.linspace(0, 1, 100)
        o = funcs["omega"](t_array)
        a = funcs["alpha"](t_array)
        th = funcs["theta"](t_array)

        plt.plot(t_array, a)
        plt.plot(t_array, o)
        plt.plot(t_array, th)

    plt.show()

    pass
    # t = n_polynomial_representation_modelV1(5, 1)

    # t[0]["alpha"] = t[0]["alpha"].subs({t[1][0]: 1})
    # t[0]["omega"] = t[0]["omega"].subs({t[1][0]: 1})
    # t[0]["theta"] = t[0]["theta"].subs({t[1][0]: 1})
    #
    # p1 = sympy.plotting.plot(t[0]["alpha"], xlim=(0, 1), ylim=(-0.02, 0.02), show=False, line_color="r", legend=True)
    # p2 = sympy.plotting.plot(t[0]["omega"], xlim=(0, 1), ylim=(-0.02, 0.02), show=False, line_color="g")
    # p3 = sympy.plotting.plot(t[0]["theta"], xlim=(0, 1), ylim=(-0.02, 0.02), show=False, line_color="b")
    #
    # p1.extend(p2)
    # p1.extend(p3)
    # p1.show()
