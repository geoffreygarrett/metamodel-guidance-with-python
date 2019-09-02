from setuptools import find_packages
from distutils.core import setup
from distutils.extension import Extension
import numpy as np
from Cython.Build import cythonize

try:
    from Cython.Distutils import build_ext
except ImportError:
    use_cython = False
else:
    use_cython = True

cmdclass = {}
ext_modules = []

if use_cython:

    ext_modules = [
        Extension("stage.mathematics.occultation", ["stage/mathematics/occultation.pyx"]),
        Extension("stage.representation._core", ["stage/representation/_core.pyx"]),
        # Extension("mathematics.design", ["mathematics/design.pyx"]),
        # Extension("mathematics.constraints", ["mathematics/constraints.pyx"]),
        Extension("stage.mathematics.objectives", ["stage/mathematics/objectives.pyx"]),
        Extension("stage.mathematics.signal", ["stage/mathematics/signal.pyx"])
    ]
    cmdclass.update({'build_ext': build_ext})

else:
    ext_modules = [
        Extension("stage.mathematics.occultation", ["stage/mathematics/occultation.c"]),
        # Extension("mathematics.design", ["mathematics/design.c"]),
        # Extension("mathematics.constraints", ["mathematics/constraints.c"]),
        Extension("stage.mathematics.objectives", ["stage/mathematics/objectives.c"]),
        Extension("stage.mathematics.signal", ["stage/mathematics/signal.c"])
    ]

setup(
    name="stage",
    packages=["stage.mathematics", "stage.problem", "stage.representation"] + find_packages(),
    include_dirs=[np.get_include(),
                  "mathematics/*",
                  "representation/*"],
    cmdclass=cmdclass,
    ext_modules=cythonize(ext_modules),
)
