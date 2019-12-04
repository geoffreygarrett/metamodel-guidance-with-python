from .ffnn import FeedForwardNNRegression
from .rfr import RandomForestRegression
from .svr import SupportVectorRegression
from .gpr import GaussianProcessRegression
from ._base import SurrogateModelBaseRegression

__all__ = [
    "SurrogateModelBaseRegression",
    "FeedForwardNNRegression",
    "RandomForestRegression",
    "SupportVectorRegression",
    "GaussianProcessRegression"
]
