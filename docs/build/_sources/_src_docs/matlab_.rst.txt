
**mmgpy.matlab**
================

This module consists of functions and classes which aim towards linking the environment of MATLAB to the metamodelling
environment in Python. The two versions which are used and demonstrated for are R2015b and R2019b. There are two main
functions provided, namely; the execution of MATLAB scripts and Simulink models in Python and the porting of trained
models back into the MATLAB environment.

Running MATLAB & Simulink in Python
###################################

There are a few ways to get this done. Two methods are detailed here with some commonalities.

1. Compiling and running a standalone executable using Simulink Coder :cite:`simulink_coder`.
2. Running MATLAB in Python using the distributed Python :cite:`python_matlab_engine`.


Importing trained models into MATLAB
####################################

.. bibliography:: matlab_.bib
    :style: unsrt

.. automodule:: matlab
   :members:
   :private-members:
   :special-members: