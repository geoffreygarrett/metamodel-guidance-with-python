
from ._plotly import *
from ._matplotlib import *


plotly_kwargs = {
    "interactive" : True,
    "renderer": ["svg", "png"],
    "save_path": str,
    "title": str,
    "ylabel": str,
    "xlabel": str,

}

mpl_kwargs = {


}

def plot_2D_scatter(using="plotly"):

def plot_2D_contour(using="plotly"):

def plot_3D_scatter(using="plotly"):

def plot_3D_surface(using="plotly"):
    """

    Parameters
    ----------
    using : str
        - "matplotlib"
        - "plotly"

    options :


    Returns
    -------

    """

def plot_3D_trisurf(using="plotly"):

def plot_ND_surface(using="plotly"):