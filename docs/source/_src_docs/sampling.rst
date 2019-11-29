
**mmgpy.sampling**
==================

The sampling module contains various methods for sampling

.. toctree::
   :maxdepth: 2

Data Sampling methods
#####################

Stochastic methods
******************
**Random uniform**\

- Function: :py:meth:`sampling.random_uniform`

**Multivariate normal**\

- Function: :py:meth:`sampling.multivariate_normal`

Deterministic methods
*********************
**Halton sequences**\

- Function: :py:meth:`sampling.halton`

Geometric methods
*****************
**Uniform grid**\

- Function: :py:meth:`sampling.uniform_grid`

**Full factorial**\

- Function: :py:meth:`sampling.full_factorial`

**Centroidal Voronoi Tessellation**\

- Function: :py:meth:`sampling.cvt`

Non-uniform sampling sampling
*****************************

Functions
#########
.. automodule:: sampling
   :members:
   :private-members:
   :special-members:

Classes
#######
.. autoclass:: sampling.InterpolatedMarginalInverseECDF
   :members:
   :private-members:
   :special-members: __call__, __init__,