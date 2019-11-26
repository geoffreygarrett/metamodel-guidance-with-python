"""
A simple example of an animated plot
"""
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import mpl_toolkits.mplot3d.axes3d as p3
from matplotlib import cm

from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure(dpi=100, figsize=(10, 5))
# ax = p3.Axes3D(fig)
ax_surr = fig.add_subplot(2, 2, 1, projection="3d")  # surrogate
ax_targ = fig.add_subplot(2, 2, 2, projection="3d")  # target
# ax_samp = fig.add_subplot(2, 2, 3)  # sample contour
# ax_rerr = fig.add_subplot(2, 2, 4)  # relative error

x = np.linspace(-1, 1, 100)
y = np.linspace(-1, 1, 100)
XX, YY = np.meshgrid(x, y)
Z = np.sin(XX) + np.cos(YY)

surf_surr = ax_surr.plot(XX.flatten(), YY.flatten(), Z.flatten(),
                                                    linewidth=0)
plt.show()


def animate(i):
    ax_surr.remove()
    ax_surr
    surf_surr = ax_surr.plot(X=XX, Y=YY, Z=Z, linewidth=0)
    surf_surr.set_data(XX, YY)  # update the data
    print(i)
    surf_surr.set_3d_properties(
        np.sin(XX + i / 10) + np.cos(YY + i / 10))  # update the data
    return surf_surr,


ani = animation.FuncAnimation(fig, animate, np.arange(1, 200),
                              interval=25, blit=True)
plt.show()
