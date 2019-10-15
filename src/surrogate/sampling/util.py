import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import rc, cm
import plotly.figure_factory as FF
import numpy as np
from scipy.spatial import Delaunay

rc('font', **{'family': 'sans-serif', 'sans-serif': ['Helvetica']})
## for Palatino and other serif fonts use:
# rc('font',**{'family':'serif','serif':['Palatino']})
rc('text', usetex=True)


def plot2Ddemo(x, y, name=None, demo_lim=True):
    fig = plt.figure(figsize=(5, 5), dpi=300)
    ax = fig.add_subplot(111)
    plt.gcf().patch.set_facecolor('0.95')
    if demo_lim:
        plt.gca().set_aspect('equal')
        plt.ylim((-0.05, 1.05))
        plt.xlim((-0.05, 1.05))
    plt.grid(which='major', linewidth=0.5)
    plt.minorticks_on()
    plt.grid(which='minor', linewidth=0.1)
    # plt.axis('off')
    ax.set_xlabel('$x_1$')
    ax.set_ylabel('$x_2$')
    plt.scatter(x, y)
    if name is not None:
        plt.savefig(f'notebooks/graphics/{name}.pdf')
    plt.show()


def plot2Dline(x, y, name=None, demo_lim=True):
    fig = plt.figure(figsize=(5, 5), dpi=300)
    ax = fig.add_subplot(111)
    plt.gcf().patch.set_facecolor('0.95')
    if demo_lim:
        plt.gca().set_aspect('equal')
        plt.ylim((-0.05, 1.05))
        plt.xlim((-0.05, 1.05))
    plt.grid(which='major', linewidth=0.5)
    plt.minorticks_on()
    plt.grid(which='minor', linewidth=0.1)
    # plt.axis('off')
    ax.set_xlabel('$x_1$')
    ax.set_ylabel('$f_1(x_1)$')
    plt.plot(x, y)
    if name is not None:
        plt.savefig(f'notebooks/graphics/{name}.pdf')
    plt.show()


def plotFFTPeak(xf, yf, name=None):
    fig = plt.figure(figsize=(5, 2), dpi=300)
    ax = fig.add_subplot(111)
    plt.gcf().patch.set_facecolor('0.95')
    plt.grid(which='major', linewidth=0.5)
    plt.minorticks_on()
    plt.grid(which='minor', linewidth=0.1)
    # plt.axis('off')
    ax.set_xlabel('$f\;\;[1/T]$')
    ax.set_ylabel('$Amplitude\;\;(A)\;\;[-]$')
    ax.stem(xf, yf, use_line_collection=True)
    if name is not None:
        plt.savefig(f'notebooks/graphics/{name}.pdf')
    plt.show()


def mpl3Ddemo(x, y, z, name=None):
    fig = plt.figure(figsize=(5, 5), dpi=300)
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(x, y, z, marker='o')
    plt.gcf().patch.set_facecolor('0.95')

    plt.ylim((-0.05, 1.05))
    plt.xlim((-0.05, 1.05))
    ax.set_zlim(-0.05, 1.05)
    # plt.zlim((-0.05, 1.05))
    # plt.axis('off')
    ax.set_xlabel('$x_1$')
    ax.set_ylabel('$x_2$')
    ax.set_zlabel('$x_3$')

    # ax.set_yticklabels([])
    # ax.set_xticklabels([])
    # ax.set_zticklabels([])
    if name is not None:
        plt.savefig(f'notebooks/graphics/{name}.pdf')
    plt.show()


import plotly.graph_objects as go

import plotly.io as pio
from IPython.display import Image


def plotly3Dsurf(x, y, z, name=None, show_scatter=False, static=False):
    data = []
    data.append(go.Surface(x=x, y=y, z=z, colorscale='inferno'))
    if show_scatter:
        data.append(go.Scatter3d(x=x.flatten(),
                                 y=y.flatten(),
                                 z=z.flatten(),
                                 mode='markers',
                                 marker=dict(
                                     size=4.0,
                                     opacity=0.7,
                                     line=dict(width=1.5,
                                               color='black'),
                                     color='rgba(255,255,153,0.8)'
                                 )))
    fig = go.Figure(data=data)

    camera = dict(
        # up=dict(x=0, y=0, z=-10),
        center=dict(x=0, y=0, z=-0.20),
        # eye=dict(x=1.25, y=1.25, z=1.25)
    )

    fig.update_layout(title=name, autosize=False,
                      width=620, height=580,
                      margin=dict(l=65, r=50, b=65, t=90),
                      scene_camera=camera)

    fig.update_layout(scene_aspectmode='cube')

    if static:
        # Image(pio.to_image(fig, format='png'))
        fig.show(renderer="png")

    else:
        fig.show()
    # if name is not None:
    #     plt.savefig(f'notebooks/graphics/{name}.pdf')
    # plt.show()


def tri_indices(simplices):
    # simplices is a numpy array defining the simplices of the triangularization
    # returns the lists of indices i, j, k

    return ([triplet[c] for triplet in simplices] for c in range(3))


from functools import reduce


def map_z2color(zval, colormap, vmin, vmax):
    # map the normalized value zval to a corresponding color in the colormap

    if vmin > vmax:
        raise ValueError('incorrect relation between vmin and vmax')
    t = (zval - vmin) / float((vmax - vmin))  # normalize val
    R, G, B, alpha = colormap(t)
    return 'rgb(' + '{:d}'.format(int(R * 255 + 0.5)) + ',' + '{:d}'.format(int(G * 255 + 0.5)) + \
           ',' + '{:d}'.format(int(B * 255 + 0.5)) + ')'


def plotly_trisurf(x, y, z, simplices, colormap=cm.RdBu, plot_edges=None):
    # x, y, z are lists of coordinates of the triangle vertices
    # simplices are the simplices that define the triangularization;
    # simplices  is a numpy array of shape (no_triangles, 3)
    # insert here the  type check for input data

    points3D = np.vstack((x, y, z)).T
    tri_vertices = map(lambda index: points3D[index], simplices)  # vertices of the surface triangles
    zmean = [np.mean(tri[:, 2]) for tri in tri_vertices]  # mean values of z-coordinates of
    # triangle vertices
    min_zmean = np.min(zmean)
    max_zmean = np.max(zmean)
    facecolor = [map_z2color(zz, colormap, min_zmean, max_zmean) for zz in zmean]
    I, J, K = tri_indices(simplices)

    triangles = go.Mesh3d(x=x,
                          y=y,
                          z=z,
                          facecolor=facecolor,
                          i=I,
                          j=J,
                          k=K,
                          name=''
                          )

    if plot_edges is None:  # the triangle sides are not plotted
        return [triangles]
    else:
        # define the lists Xe, Ye, Ze, of x, y, resp z coordinates of edge end points for each triangle
        # None separates data corresponding to two consecutive triangles
        lists_coord = [[[T[k % 3][c] for k in range(4)] + [None] for T in tri_vertices] for c in range(3)]
        Xe, Ye, Ze = [reduce(lambda x, y: x + y, lists_coord[k]) for k in range(3)]

        # define the lines to be plotted
        lines = go.Scatter3d(x=Xe,
                             y=Ye,
                             z=Ze,
                             mode='lines',
                             line=dict(color='rgb(50,50,50)', width=1.5)
                             )
        return [triangles, lines]


def plotly3Dtrisurf(x, y, z, name=None, show_scatter=False, static=False):
    x = x.flatten()
    y = y.flatten()
    z = z.flatten()

    data = []

    camera = dict(
        # up=dict(x=0, y=0, z=-10),
        center=dict(x=0, y=0, z=-0.20),
        # eye=dict(x=1.25, y=1.25, z=1.25)
    )
    if show_scatter:
        data.append(go.Scatter3d(x=x.flatten(),
                                 y=y.flatten(),
                                 z=z.flatten(),
                                 mode='markers',
                                 marker=dict(
                                     size=4.0,
                                     opacity=0.7,
                                     line=dict(width=1.5,
                                               color='black'),
                                     color='rgba(255,255,153,0.8)'
                                 )))

    points2D = np.vstack([x, y]).T
    tri = Delaunay(points2D)
    simplices = tri.simplices

    data += plotly_trisurf(x, y, z, simplices, colormap=cm.inferno, plot_edges=None)

    fig = go.Figure(data=data)

    fig.update_layout(title=name, autosize=False,
                      width=620, height=580,
                      margin=dict(l=65, r=50, b=65, t=90),
                      scene_camera=camera)

    fig.update_layout(scene_aspectmode='cube')

    if static:
        # Image(pio.to_image(fig, format='png'))
        fig.show(renderer="png")

    else:
        fig.show()
    # if name is not None:
    #     plt.savefig(f'notebooks/graphics/{name}.pdf')
    # plt.show()


def plotly3Dscatter(x, y, z, name=None, lim=None):
    fig = go.Figure(data=[go.Scatter3d(x=x,
                                       y=y,
                                       z=z,
                                       mode='markers',
                                       marker=dict(
                                           size=4.5,
                                           opacity=0.7,
                                           line=dict(width=0.5,
                                                     color='blue'),
                                           color='rgba(0,0,130,0.5)'
                                       )
                                       )])

    camera = dict(
        # up=dict(x=0, y=0, z=-10),
        center=dict(x=0, y=0, z=-0.20),
        # eye=dict(x=1.25, y=1.25, z=1.25)
    )
    fig.update_layout(scene_aspectmode='cube')

    # if lim:
    #     if lim[0] is not None:
    #         fig.update_layout(scene=dict(xaxis=dict(range=lim[0])))
    #     if lim[1] is not None:
    #         fig.update_layout(scene=dict(yaxis=dict(range=lim[1])))
    #     if lim[2] is not None:
    #         fig.update_layout(scene=dict(zaxis=dict(range=lim[2])))

    fig.update_layout(title=None, autosize=False,
                      width=620, height=580,
                      margin=dict(l=65, r=50, b=65, t=90),
                      scene_camera=camera)

    fig.show()
    # if name is not None:
    #     plt.savefig(f'notebooks/graphics/{name}.pdf')
    # plt.show()


def plot3Dsurf2(x, y, f, name=None):
    fig = plt.figure(figsize=(5, 5), dpi=300)
    ax = fig.add_subplot(111, projection='3d')
    plt.gcf().patch.set_facecolor('0.95')

    plt.ylim((-0.05, 1.05))
    plt.xlim((-0.05, 1.05))
    ax.set_zlim(-0.05, 1.05)

    ax.set_xlabel('$x_1$')
    ax.set_ylabel('$x_2$')
    ax.set_zlabel('$x_3$')

    # X, Y = np.meshgrid(x, y)
    Z = f(x, y)

    # Plot the surface.
    surf = ax.plot_surface(x, y, Z, cmap=cm.coolwarm,
                           linewidth=0, antialiased=False)

    # Add a color bar which maps values to colors.
    fig.colorbar(surf)

    if name is not None:
        plt.savefig(f'notebooks/graphics/{name}.pdf')
    plt.show()


def process_samples(samples, problem, verbose=True):
    """
    Concatenates [F: outputs, X: inputs] on 0'th axis.
    :param samples:
    :param problem:
    :param verbose:
    :return:
    """
    column_dim = len(problem.get_bounds()[0]) + problem.fitness_dim
    res = np.zeros((samples.shape[0], column_dim))
    count = 0
    perc_val = int(0.1 * samples.shape[0])
    for idx, _x in enumerate(samples):
        count += 1
        f = problem.fitness(_x)
        res[idx] = np.concatenate((f, _x))
        if (count % perc_val) == 0 and verbose:
            print(round(count / len(samples) * 100, 1), r"%")
    return res
