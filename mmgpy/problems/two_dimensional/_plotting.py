from matplotlib import pyplot as plt
import numpy as np

# plt.rc('text', usetex=True)
plt.rc('font', family='serif')


def _plot_mission_target(fig, ax, mission_geometry):
    # Planet graphics.
    ax.add_artist(plt.Circle((0, 0), mission_geometry.m_target_R, color='r', alpha=0.5))
    ax.fill(np.NaN, np.NaN, label="Body geometry", color="red", alpha=0.5)


def _spacecraft_state(mission_geometry):
    # Sample time over orbital period.
    # Plot trajectory.
    return mission_geometry.X_s


def _plot_spacecraft_trajectory(fig, ax, mission_geometry):
    __spacecraft_state = mission_geometry.X_s

    # Retrieve spacecraft state over orbital period.
    ax.plot(__spacecraft_state[:, 0], __spacecraft_state[:, 1])


def _plot_occultation(fig, ax, occultation_array, spacecraft_state, color="grey", name='', hatch=None):
    # Retrieve spacecraft state over orbital period.
    _geometry = (np.abs(occultation_array) * spacecraft_state.T).T
    # handles, labels = ax.get_legend_handles_labels()
    ax.fill(_geometry[:, 0], _geometry[:, 1], alpha=0.3, color=color, label=f"{name} eclipse", hatch=hatch)


def _plot_thrust_history(fig, ax, problem, actual_thrust_vectors):
    scale = 0.5 * np.linalg.norm(problem.mission_geometry.X_s[0, :])
    for idx, att in enumerate(actual_thrust_vectors):
        if idx % 3 == 0:
            att = scale * att
            ax.arrow(problem.mission_geometry.X_s[:, 0][idx],
                     problem.mission_geometry.X_s[:, 1][idx],
                     att[0], att[1], head_width=0.5 * 2, head_length=0.7 * 2, fc='lightblue', ec='black')


def plot_mission_environment(problem, fig, ax, thrust_history=None):
    # Initial state of spacecraft.
    state = problem.mission_geometry.X_s
    ax.scatter(state[0][0], state[0][1],
               marker="x", label="Initial Position", s=200,
               color="red", linewidth=3)

    _plot_mission_target(fig, ax, problem.mission_geometry)

    _plot_spacecraft_trajectory(fig, ax, problem.mission_geometry)

    # if "power_budget" or "star_sensor_redundancy" in problem._constraints.keys():
    _plot_occultation(fig, ax, problem.mission_geometry.E_solar, problem.mission_geometry.X_s,
                      name="Solar", color="black", hatch="\\\\")

    # if "communication_budget" in problem._constraints.keys():
    #     _plot_occultation(fig, ax, problem.geometry.E_solar,
    #                       problem.geometry.X_s,
    #                       name="Communication", color="green", hatch="//")

    if thrust_history is not None:
        _plot_thrust_history(fig, ax, problem, thrust_history)

    ax.ticklabel_format(style='sci', axis='x', scilimits=(0, 3))
    ax.ticklabel_format(style='sci', axis='y', scilimits=(0, 3))
    ax.set_ylabel("$y - coordinate$ [m]")
    ax.set_xlabel("$x - coordinate$ [m]")
    ax.set_title("Mission target, planetocentric Frame (J2000)")
    ax.grid(linewidth=0.2)
    ax.legend()


def plot_thrust_inefficiency_graph(problem, fig, ax, _thrust_inefficiency_log, x):
    time_array = problem.design_space.sampled_time_array
    ax.plot(time_array, _thrust_inefficiency_log)
    ax.grid(linewidth=0.2)
    ax.fill_between(time_array, 1, _thrust_inefficiency_log, where=_thrust_inefficiency_log > 1,
                    facecolor="red", interpolate=True, alpha=0.3)
    ax.fill_between(time_array, 0.25,
                    np.where((_thrust_inefficiency_log < 1.0) & (_thrust_inefficiency_log > 0.25),
                             _thrust_inefficiency_log, 1.0),
                    where=_thrust_inefficiency_log > 0.25,
                    facecolor="orange", interpolate=True, alpha=0.3)
    ax.fill_between(time_array, 0,
                    np.where(_thrust_inefficiency_log < 0.25, _thrust_inefficiency_log,
                             0.25),
                    where=_thrust_inefficiency_log < 2,
                    facecolor="green", interpolate=True, alpha=0.3)

    fitness = problem.fitness(x)
    obj = np.round(fitness[0], 4)
    ci = np.round(fitness[1:], 2)
    # print(fitness)
    ax.set_title(
        f"Fitness parameters (obj={obj}, violated={ci[ci > 0].size}, violated norm={np.linalg.norm(ci[ci > 0])})")
    ax.set_ylabel("Thrust inefficiency")
    ax.set_xlabel("Time, t [s]")

    quarter_ = ax.fill(np.NaN, np.NaN, 'green', alpha=0.4)
    half_ = ax.fill(np.NaN, np.NaN, 'orange', alpha=0.4)
    bad_ = ax.fill(np.NaN, np.NaN, 'red', alpha=0.4)
    ax.legend((quarter_[0], half_[0], bad_[0]), ("$\leq{}0.25$", "$0.25\leq{}T_{Eff}\leq{}1.0$", "$\geq{}1.0$"))


def plot_dynamics(problem, ax1, x, save=False, name=None):
    """
    :param problem:
    :param ax1: axis must be list of three ax.
    :param x:
    :return:
    """
    # Independent history of spacecraft dynamics.
    (_spacecraft_alpha_log,
     _spacecraft_omega_log,
     _spacecraft_theta_log) = problem.design_space(x)

    ax1[0].ticklabel_format(style='sci', axis='x', scilimits=(0, 3))
    ax1[0].ticklabel_format(style='sci', axis='y', scilimits=(0, 3))

    ax1[0].set_title(f"Spacecraft dynamics")
    ax1[0].set_ylabel("$\\alpha$ [rad/s/s]")
    _t_non_dim = problem.design_space.sampled_time_array / problem.design_space.sampled_time_array[-1]
    ax1[0].grid()
    ax1[0].plot(_t_non_dim, _spacecraft_alpha_log)

    ax1[1].set_ylabel("$\\omega$ [rad/s]")
    ax1[1].grid()
    ax1[1].plot(_t_non_dim, _spacecraft_omega_log)

    ax1[2].set_ylabel("$\\theta$ [rad]")
    ax1[2].grid()
    ax1[2].plot(_t_non_dim, _spacecraft_theta_log)
    ax1[2].set_xlabel("Time, $t/T$ [-]")

    if save:
        plt.savefig(f"plots/dynamics_{name}.png")
    plt.show()


def plot_design_space_landscape(problem, n=10, offset=0, xlim=(None, None), ylim=(None, None), name="noname",
                                save=False, show=True,
                                ylab=None, xlab=None,
                                constraint_contour=False,
                                detail=None):
    '''
    ======================
    3D surface (color map)
    ======================

    Demonstrates plotting a 3D surface colored with the coolwarm color map.
    The surface is made opaque by using antialiased=False.

    Also demonstrates using the LinearLocator and custom formatting for the
    z axis tick labels.
    '''

    from mpl_toolkits.mplot3d import Axes3D
    import matplotlib.pyplot as plt
    from matplotlib import cm
    from matplotlib.ticker import LinearLocator, FormatStrFormatter
    import numpy as np
    from matplotlib import ticker, cm
    from mpl_toolkits.axes_grid1.inset_locator import zoomed_inset_axes
    from mpl_toolkits.axes_grid1.inset_locator import mark_inset

    fig, ax = plt.subplots(figsize=(5, 4), dpi=400)

    # Make data.
    N_ = n
    # N_ = 100
    min, max = problem.get_bounds()

    if xlim == (None, None):
        X_ = np.linspace(min[0], max[0], N_)
    else:
        X_ = np.linspace(xlim[0], xlim[1], N_)

    if ylim == (None, None):
        Y_ = np.linspace(min[1], max[1], N_)
    else:
        Y_ = np.linspace(ylim[0], ylim[1], N_)

    X, Y = np.meshgrid(X_, Y_)
    Z = np.zeros((N_, N_))

    # def _f(x, y):
    #     return problem.fitness_function([x, y])
    #
    # vec_f = np.vectorize(_f)

    # Z = vec_f(X, Y)

    for i in range(N_):
        for j in range(N_):
            # print(f"i={i}, j={j}")
            Z[i, j] = np.sum(problem.fitness([X[i, j], Y[i, j]])) - offset

    N_LEVELS = 10
    CMAP = cm.viridis

    # CS = ax.contour(X, Y, Z)
    cax1 = ax.contourf(X, Y, Z, N_LEVELS, cmap=CMAP)
    cax1_ = ax.contour(cax1, colors="black", alpha=0.5, linewidths=0.25)

    if detail:
        x_cond = (X_ > detail[0][0]) & (X_ < detail[0][1])
        y_cond = (Y_ > detail[1][0]) & (Y_ < detail[1][1])

        mesh_z_idx = np.meshgrid(x_cond, y_cond)

        detail_X = X[mesh_z_idx]
        detail_Y = Y[mesh_z_idx]
        detail_Z = Z[mesh_z_idx]

        axins = zoomed_inset_axes(ax, 10, loc=1)
        detail_cax = axins.contourf(detail_X, detail_Y, detail_Z, N_LEVELS, cmap=CMAP)
        axins.contour(detail_cax, colors="black", alpha=0.5, linewidths=0.25)
        axins.set_xlim(detail[0][0], detail[0][1])
        axins.set_ylim(detail[1][0], detail[1][1])

        plt.xticks(visibile=False)
        plt.yticks(visibile=False)

        mark_inset(ax, axins, loc1=2, loc2=4, fc="none", ec="0.5")
        plt.draw()

        # detail_cax1 = ax.contourf(detail_X, detail_Y, detail_Z, N_LEVELS, cmap=CMAP)
        # detail_cax1_ = ax.contour(detail_cax1, colors="black", alpha=0.5, linewidths=0.25)

    if constraint_contour:
        cax2 = ax.contour(X, Y, Z, colors="black", alpha=0.8, linewidths=0.8, levels=[0.0, 1.0, 2.0, 3.0])
        ax.clabel(cax2, fontsize=4, inline=1)

        # if detail:
        # detail_cax2 = ax.contour(detail_X, detail_Y, detail_Z,
        #                          colors="black", alpha=0.8, linewidths=0.8, levels=[0.0, 1.0, 2.0, 3.0])
        # ax.clabel(detail_cax2, fontsize=4, inline=1)

    fig.colorbar(cax1)

    # if detail:
    # ax.clabel(detail_cax2, fontsize=4, inline=1)

    if xlab:
        plt.xlabel(xlab)

    if ylab:
        plt.ylabel(ylab)

    if save:
        plt.savefig(f"plots/{name}_landscape.pdf", bbox_inches="tight")

    if show:
        plt.show()


from scipy import integrate


def plot_solution(problem, x):
    """

    :return:
    """
    # Independent history of spacecraft dynamics.
    (_alpha_hist,
     _omega_hist,
     _theta_hist) = problem.design_space(x)
    fig = plt.figure(figsize=(14, 7), dpi=300)

    # Plot mission target environment.
    ax1 = plt.subplot2grid((3, 2), (0, 0), rowspan=3)
    ax2 = plt.subplot2grid((3, 2), (0, 1), colspan=1)
    ax3 = plt.subplot2grid((3, 2), (1, 1), colspan=1)
    ax4 = plt.subplot2grid((3, 2), (2, 1), colspan=1)

    # ax1
    thrust_history = problem.spacecraft.thr_u_vec()

    plot_mission_environment(problem, fig, ax1, thrust_history)

    # ax2
    _thrust_inefficiency_log = problem.f_thrust_inefficiency()[0]
    plot_thrust_inefficiency_graph(problem, fig, ax2, _thrust_inefficiency_log, x)

    # ax3
    aux, val = problem.f_star_sensor_exclusion()
    ax3.plot(problem.design_space.sampled_time_array, aux[0], label="s.s. 1", color="g", alpha=0.5)
    ax3.plot(problem.design_space.sampled_time_array, aux[1], label="s.s. 2", color="r", alpha=0.5)
    ax3.plot(problem.design_space.sampled_time_array, aux[2], label="s.s. both", color="b", alpha=0.5)
    ax3.legend()

    # ax4
    _f, _log = problem.f_power_from_available()[0]

    # print(_f)
    # print(_log)

    ax4.plot(problem.design_space.sampled_time_array, _f)

    # ax3.plot(self.time_array, _solar_power_log[0])
    # ax3.grid(linewidth=0.2)
    #
    # ax3.set_ylabel("Solar Power [W]")
    # ax3.set_xlabel("Time, t [s]")
    #
    solar_occult = problem.mission_geometry.E_solar
    #
    # eclipse_ = ax3.fill(np.NaN, np.NaN, 'grey', alpha=0.4)
    # power_ = ax3.fill(np.NaN, np.NaN, 'orange', alpha=0.4)
    # extra_ = ax3.fill(np.NaN, np.NaN, 'green', alpha=0.4)
    #
    # # a.legend([(p2[0], p1[0]), ], ['Stuff'])
    #
    ax4.fill_between(problem.design_space.sampled_time_array, 0, np.max(_f), where=solar_occult == 1,
                     facecolor="grey", interpolate=True, alpha=0.3)

    #
    ax4.fill_between(problem.design_space.sampled_time_array[:-1], 0, _f[:-1],
                     where=_log < 0.7,
                     facecolor="orange", interpolate=True, alpha=0.4)

    ax4.fill_between(problem.design_space.sampled_time_array[:-1], 0, _f[:-1],
                     where=_log > 0.7,
                     facecolor="green", interpolate=True, alpha=0.4)

    # ax3.legend((eclipse_[0], power_[0], extra_[0]), ("Eclipse", "$E_{req}$", "$E_+$"))

    plt.show()

# def plot_dynamics(self, x, name="None", save=False):
#     fig1, ax1 = plt.subplots(3, 1, figsize=(10, 6), dpi=400)
#     myplot.plot_dynamics(self, ax1, x, save, name)
