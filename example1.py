from mmgpy.benchmark import Rastrigin
from mmgpy.sampling import uniform_grid
from mmgpy.plotting import plot_3d_surface

# Define a callable target function.
rastrigin2D = Rastrigin(2)

# Sample the domain with uniform grid sampling.
x1, x2 = uniform_grid(2, 100, flatten=False)

# Plot the 3D surface response.
plot_3d_surface(x1, x2, rastrigin2D(x1, x2), showscale=False)
