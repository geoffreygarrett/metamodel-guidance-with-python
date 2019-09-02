import numpy as np

n=1
np.set_printoptions(precision=4)
def omega0_jacobian(x, n=1):
    Omega1, Omega2, t_w0, t_w1, t_w2 = x
    j0 = (-t_w0 - t_w1)/(t_w0 + t_w2)
    j1 = (-t_w1 - t_w2)/(t_w0 + t_w2)
    j2 = -Omega1/(t_w0 + t_w2) - (-Omega1*t_w0 - Omega2*t_w2 + 4*np.pi*n - 2*t_w1*(Omega1/2 + Omega2/2))/(t_w0 + t_w2)**2
    j3 = (-Omega1 - Omega2)/(t_w0 + t_w2)
    j4 = -Omega2/(t_w0 + t_w2) - (-Omega1*t_w0 - Omega2*t_w2 + 4*np.pi*n - 2*t_w1*(Omega1/2 + Omega2/2))/(t_w0 + t_w2)**2
    return np.array([[j0, j1, j2, j3, j4]])

def omega0(x, n=1):
    Omega1, Omega2, t_w0, t_w1, t_w2 = x
    return (-Omega1*t_w0 - Omega2*t_w2 + 4*np.pi*n - 2*t_w1*(Omega1/2 + Omega2/2))/(t_w0 + t_w2)

def y_obs_pos_omega0(Omega0, Omega_max):
    return Omega_max - Omega0

def y_obs_neg_omega0(Omega0, Omega_max):
    """
    """
    return - Omega_max - Omega0

def delta_x_update(y, x, n=1):
    Omega1, Omega2, t_w0, t_w1, t_w2 = x
    j = omega0_jacobian(x, n=n)
    pin = np.linalg.pinv(np.matmul(j.T , j))
    return np.matmul(pin, j.T * y)

def uniform_sample(bounds, n_dim_sample=50):
    sample=0
    vec = np.zeros((n_dim_sample ** (len(bounds[0])), len(bounds[0])))
    for omega1 in np.linspace(bounds[0][0], bounds[1][0], n_dim_sample):
        for omega2 in np.linspace(bounds[0][1], bounds[1][1], n_dim_sample):
            for tw1 in np.linspace(bounds[0][2], bounds[1][2], n_dim_sample):
                for tw2 in np.linspace(bounds[0][3], bounds[1][3], n_dim_sample):
                    for tw3 in np.linspace(bounds[0][4], bounds[1][4], n_dim_sample):
                        vec[sample] = np.array([omega1, omega2, tw1, tw2, tw3])
                        sample+=1
    return vec


# def force_bounds_correction(x_proposed, bounds):
#     closest_bound = np.where(x_proposed - np.array(bounds[0]) < x_proposed - np.array(bounds[1]), 
#                              np.array(bounds[0]), 
#                              np.array(bounds[1]))
#     in_bounds = (x_proposed >= np.array(bounds[0])) & (x_proposed <= np.array(bounds[1]))
#     return np.where(in_bounds, x_proposed, closest_bound)

def force_bounds_correction(x_proposed, bounds):
    for idx, (x, lb, ub) in enumerate(zip(x_proposed, bounds[0], bounds[1])):
        closest_bound = np.where(x - lb < ub - x, lb, ub)
        in_bounds = (x_proposed >= lb) & (x_proposed <= ub)
        x_proposed[idx] = np.where(in_bounds, x_proposed, closest_bound)
    return x_proposed

def return_in_bounds(x, bounds):
    return x[
    (x[:,0]>=bounds[0][0]) & (x[:,0]<=bounds[1][0]) & 
    (x[:,1]>=bounds[0][1]) & (x[:,1]<=bounds[1][1]) &
    (x[:,2]>=bounds[0][2]) & (x[:,2]<=bounds[1][2]) & 
    (x[:,3]>=bounds[0][3]) & (x[:,3]<=bounds[1][3]) & 
    (x[:,4]>=bounds[0][4]) & (x[:,4]<=bounds[1][4]) ]


def iterate_to_omega_manifold(bounds, x_sample, omega_neg=False, maxiter=100, force_bounds=False, tolerance=1e-6, verbose=False):
    str1_head = f"Iterating to omega_max constraint manifold | omega_neg: {omega_neg} | tolerance: {tolerance}"
    print("-"*len(str1_head)) if verbose else None
    print(str1_head) if verbose else None
    print("-"*len(str1_head)) if verbose else None
    count = 0
    Omega0 = np.apply_along_axis(omega0, 1, x_sample)
    y_init = np.ones(len(Omega0))
    y = y_init
    x = x_sample
    while (np.any(np.abs(y)>tolerance)) and (count < maxiter):
        count+=1
        y = y_obs_neg_omega0(Omega0, 0.002) if omega_neg else  y_obs_pos_omega0(Omega0, 0.002)
        x_update = np.array([delta_x_update(y[i], x[i]) for i in range(len(y))]).reshape(-1,5)
        x = force_bounds_correction(x + x_update, bounds) if force_bounds else x + x_update
        Omega0 = np.apply_along_axis(omega0, 1, x)
        print(  f"Iteration: {count}/{maxiter}".ljust(1 + len("Iteration: ") + 2*len(str(maxiter)))
              + f" | Error: {np.round(np.sum(np.abs(y)),2)}".ljust(3*len(str(np.sum(np.abs(y_init))))) 
              ) if verbose else None
    x_return = return_in_bounds(x, bounds)
    print("-"*len(str1_head)) if verbose else None
    print(f"{len(x_return)}/{len(x_sample)} samples converged within bounds (force_bounds = {force_bounds})") if verbose else None
    print("-"*len(str1_head)) if verbose else None
    print("\n") if verbose else None
    return x_return

    
P = 6547.53783455185

bounds=[
        [-0.002] * (2) + [0.0001 * P] * (3),
        [+0.002] * (2) + [1.0000 * P] * (3)
]

x_sample = uniform_sample(bounds, 2)
x_orig = x_sample
tolerance = 1e-6
    
x_omega_pos = iterate_to_omega_manifold(bounds, x_sample, omega_neg=False, force_bounds=True, verbose=True)
x_omega_neg = iterate_to_omega_manifold(bounds, x_sample, omega_neg=True, force_bounds=True, verbose=True)

print(f"{len(x_omega_neg)}/{len(x_sample)}")
print(f"{len(x_omega_pos)}/{len(x_sample)}")

