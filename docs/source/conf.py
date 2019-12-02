# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# http://www.sphinx-doc.org/en/master/config

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys

sys.path.insert(0, os.path.abspath('../../mmgpy/'))
sys.path.insert(0, os.path.abspath('../../notebooks/'))

# -- Project information -----------------------------------------------------

project = 'mmgpy'
copyright = '2019, Geoffrey Garrett'
author = 'Geoffrey Garrett'

# The full version, including alpha/beta/rc tags
release = '0.8.0'

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'nbsphinx',
    'sphinx.ext.mathjax',
    'sphinx.ext.autodoc',
    'sphinx.ext.napoleon',
    'sphinx.ext.autosummary',
    'sphinx.ext.autosummary',
    'sphinx.ext.graphviz',
    'sphinxcontrib.bibtex'
]
source_suffix = '.rst'
master_doc = 'index'
pygments_style = 'sphinx'
autoclass_content = "both"

napoleon_google_docstring = False
napoleon_use_param = False
napoleon_use_ivar = True
latex_engine = 'xelatex'

autodoc_default_flags = ['members']
autosummary_generate = True

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', '**.ipynb_checkpoints']

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
# html_theme = 'sphinx_rtd_theme'
import rtcat_sphinx_theme

html_theme = "rtcat_sphinx_theme"

html_theme_path = [rtcat_sphinx_theme.get_html_theme_path()]

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

html_logo = "logos.png"
