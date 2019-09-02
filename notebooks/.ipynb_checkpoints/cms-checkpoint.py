import numpy as np
import sympy as sp


def sampled_grid(bounds, n_sample_dim, flatten=True):
    linspace = [np.linspace(bounds[0][i], bounds[1][i], n_sample_dim) for i in range(len(bounds[0]))]
    _return = np.array(np.meshgrid(*linspace))
    return np.array([_return_i.flatten() for _return_i in _return.reshape(len(bounds[0]), -1)]) if flatten else _return


def f_delta_x(x0, delta_y, Jx_func):    
    J_list = [Jx_func(x0_i) for x0_i in x0.T]
    return np.array([
        np.matmul(np.linalg.pinv(np.matmul(J.T, J)), 
                  np.matmul(J.T, np.array([delta_y_i]))) for delta_y_i, J in zip(delta_y, J_list)])

def force_bounds_correction(x_proposed, bounds):
    for idx, (x, lb, ub) in enumerate(zip(x_proposed, bounds[0], bounds[1])):
        closest_bound = np.where(x - lb < ub - x, lb, ub)
        in_bounds = (x_proposed[idx] >= lb) & (x_proposed[idx] <= ub)
        rep = np.where(in_bounds, x_proposed[idx], closest_bound)
        x_proposed[idx] = rep
    return x_proposed

def iterate2manifold(bounds, x_sample, y_func, Jx_func, y_ref=0, maxiter=5, force_bounds=False, tol=1e-8, verbose=False):
    """
    :param bounds: Tuple of bounds [lb, ub], where lb = [x1_lb, x2_lb...], vice versa.
    :param x_sample: ndarray of x samples in shape (n_samples, x_dimension).
    :param f:
    :param Jx:
    :param y_ref: Reference value to which convergence is desired. Default is 0 for constraint manifold.
    :param maxiter: Maximum number of iterations accross all x_samples. Default is 5, as convergence usually occurs within 3 without force_bounds=True.
    :param force_bounds: Force the bounds across specific x components, so that they reside within the domain. Convergence to tol is not guranteed.
    :param tol: Tolerance for y_ref - y(x) which must be met by all x samples.
    :param verbose:
    """
    if verbose:
        str1_head = f"Iterating to omega_max constraint manifold | tolerance: {tol}"
        print("-"*len(str1_head))
        print(str1_head)
        print("-"*len(str1_head))
    
    # Counter for maxiter condition.
    count = 0
    
    # Initiate initial values.
    y0 = y_func(x_sample)
    delta_y =y_ref-y0
    d_y_init = delta_y
    x = x_sample
    
    while (np.any(np.abs(delta_y)>tol)) and (count < maxiter):
        count+=1
        
        # Determine delta x for observed difference from reference value (y*).
        delta_x = np.nan_to_num(f_delta_x(x, delta_y, Jx_func).T)
                        
        # Determine new updated x vectors.
        x = force_bounds_correction(x + delta_x, bounds) if force_bounds else x + delta_x        
        
        # Calculate new y values for updated x.
        y0 = y_func(x)
        
        # Calculated new observed difference from reference value.
        delta_y = y_ref - y0
                
        if verbose:
            print(  f"Iteration: {count}/{maxiter}".ljust(1 + len("Iteration: ") + 2*len(str(maxiter)))
                  + f" | Error: {np.round(np.sum(np.abs(delta_y)),4)}".ljust(3*len(str(np.sum(np.abs(d_y_init))))))
                         
    if verbose:
        print("-"*len(str1_head))
        print(f"{len(x)}/{len(x_sample)} samples converged within bounds (force_bounds = {force_bounds})")
        print("-"*len(str1_head))
        print("\n")
        
    return x


class System:
    def __init__(self, y_func, Jx_func, args):
        self._y_func = y_func
        self._Jx_func = Jx_func
        self._args = args
        
    def y(self, X):
        return self._y_func(*X, *self._args)
    
    def Jx(self, X):
        return self._Jx_func(*X, *self._args)
    
# Define symbols.
x1     = sp.Symbol("x1")
x2     = sp.Symbol("x2")
R      = sp.Symbol("R")
x1_0   = sp.Symbol("x_1_0")
x2_0   = sp.Symbol("x_2_0")
c_circ = sp.Symbol("\mathcal{C}_{circ}(\overline{X})")
k      = sp.Symbol("k")
x_vec  = sp.Matrix([x1, x2])

# r.h.s. of constraint equation.
c_circ_rhs = sp.sqrt(R ** (2 * k)) - sp.sqrt((x1-x1_0) ** 2 + (x2 - x2_0) ** 2) ** k

# Define equation.
c_circ_eq = sp.Eq(c_circ, c_circ_rhs)

# Jacobian of constraint observation.
Jx = sp.Matrix([c_circ_eq.rhs]).jacobian(x_vec)

# Define auxilliary function form of Jacobian.
Jx_func = sp.lambdify([x1,x2,x1_0,x2_0, R, k], Jx, "numpy")

# Define auxilliary function form of y_observation.
c_circ_func = sp.lambdify([x1,x2,x1_0,x2_0, R, k], c_circ_rhs, "numpy")




def simple_2d_case_study(ax, maxiter, k, y_ref=None, manifold=False, force_bounds=True):

    bounds = [[0.05,0.05],[0.95,0.95]]

    c1 = System(c_circ_func, Jx_func, [1, 0, 0.5, k])
    c2 = System(c_circ_func, Jx_func, [0, 1, 0.5, k])
    
    fine_x_meshgrid = sampled_grid(bounds, 30, flatten=False)
    Z = np.max([c1.y(fine_x_meshgrid), c2.y(fine_x_meshgrid)], axis=0)
    cs = ax.contourf(*fine_x_meshgrid, Z, alpha=1,cmap="Greys", levels=[-1, 0, 1])
    ax.contour(cs, colors='k', levels=[0], linewidths=0.5)
    
    sample_x_grid = sampled_grid(bounds, 10)
    ax.scatter(*sample_x_grid,s=40, color="black", marker="+", linewidth=0.25)

    
    if manifold:
        c1_bound = iterate2manifold(bounds, sample_x_grid, c1.y, c1.Jx, 
                                    maxiter=maxiter, force_bounds=force_bounds, tol=1e-6, verbose=False)
        c2_bound = iterate2manifold(bounds, sample_x_grid, c2.y, c2.Jx,
                                    maxiter=maxiter, force_bounds=force_bounds, tol=1e-6, verbose=False)
        
        ax.scatter(*c1_bound, s=30, color="black", marker="*", linewidth=0.1)
        ax.scatter(*c2_bound, s=30, color="black", marker="*", linewidth=0.1)

    x_refs = []
    
    if y_ref is not False:
        try:
            for _y_ref in y_ref:
                x_refs.append(iterate2manifold(bounds, sample_x_grid, c1.y, c1.Jx, y_ref=_y_ref, maxiter=maxiter, force_bounds=force_bounds, tol=1e-6, verbose=False))
                x_refs.append(iterate2manifold(bounds, sample_x_grid, c2.y, c2.Jx, y_ref=_y_ref, maxiter=maxiter, force_bounds=force_bounds, tol=1e-6, verbose=False))

        except TypeError:
            x_refs.append(iterate2manifold(bounds, sample_x_grid, c1.y, c1.Jx, y_ref=y_ref, maxiter=maxiter, force_bounds=force_bounds, tol=1e-6, verbose=False))
            x_refs.append(iterate2manifold(bounds, sample_x_grid, c2.y, c2.Jx, y_ref=y_ref, maxiter=maxiter, force_bounds=force_bounds, tol=1e-6, verbose=False))
        
        for x in x_refs:
            ax.scatter(*x, s=10, color="black", marker=".", linewidth=0.2, alpha=0.3)
    ax.set_ylabel("$x_2$")
    ax.set_xlabel("$x_1$")
    ax.set_aspect('equal', 'datalim')
#     ax.scatter(np.NaN, np.NaN, s=10, color="black", marker=".", linewidth=0.2, alpha=0.3, label="$y^*$")
#     ax.scatter(np.NaN, np.NaN, s=30, color="black", marker="*", linewidth=0.1, label="Manifold")
#     ax.scatter(np.NaN, np.NaN, s=40, color="black", marker="+", linewidth=0.25, label="Sample")
#     ax.legend()