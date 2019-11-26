import skopt.plots
from skopt.plots import _format_scatter_plot_axes
from skopt.plots import MaxNLocator
import matplotlib.pyplot as plt
import numpy as np


def plot_evaluations(result, bins=20, dimensions=None,fig_scale=1, **kwargs):
    """Visualize the order in which points where sampled.

    The scatter plot matrix shows at which points in the search
    space and in which order samples were evaluated. Pairwise
    scatter plots are shown on the off-diagonal for each
    dimension of the search space. The order in which samples
    were evaluated is encoded in each point's color.
    The diagonal shows a histogram of sampled values for each
    dimension. A red point indicates the found minimum.

    Note: search spaces that contain `Categorical` dimensions are
          currently not supported by this function.

    Parameters
    ----------
    * `result` [`OptimizeResult`]
        The result for which to create the scatter plot matrix.

    * `bins` [int, bins=20]:
        Number of bins to use for histograms on the diagonal.

    * `dimensions` [list of str, default=None] Labels of the dimension
        variables. `None` defaults to `space.dimensions[i].name`, or
        if also `None` to `['X_0', 'X_1', ..]`.

    Returns
    -------
    * `ax`: [`Axes`]:
        The matplotlib axes.
    """
    space = result.space
    samples = np.asarray(result.x_iters)
    order = range(samples.shape[0])
    fig, ax = plt.subplots(space.n_dims, space.n_dims,
                           figsize=(2 * space.n_dims*fig_scale, 2 * space.n_dims*fig_scale), **kwargs)

    fig.subplots_adjust(left=0.05, right=0.95, bottom=0.05, top=0.95,
                        hspace=0.1, wspace=0.1)

    for i in range(space.n_dims):
        for j in range(space.n_dims):
            if i == j:
                if space.dimensions[j].prior == 'log-uniform':
                    low, high = space.bounds[j]
                    bins_ = np.logspace(np.log10(low), np.log10(high), bins)
                else:
                    bins_ = bins
                ax[i, i].hist(samples[:, j], bins=bins_,
                              range=space.dimensions[j].bounds)

            # lower triangle
            elif i > j:
                ax[i, j].scatter(samples[:, j], samples[:, i], c=order,
                                 s=40, lw=0., cmap='viridis')
                ax[i, j].scatter(result.x[j], result.x[i],
                                 c=['r'], s=20, lw=0.)

    return _format_scatter_plot_axes(ax, space, ylabel="Number of samples",
                                     dim_labels=dimensions)