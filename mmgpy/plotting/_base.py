from mmgpy.plotting._trace import *
import imageio


def _image_files_to_gif(folder, save_path):
    images = []
    filenames = os.listdir(folder)
    for filename in filenames:
        images.append(imageio.imread(os.path.join(folder, filename)))
    if save_path.split(".")[-1] != 'gif':
        save_path = f'{save_path}.gif'
    else:
        pass
    imageio.mimsave(save_path, images)


def plot_3d_surface(x, y, z, show=True, save=None, **kwargs):
    renderer = kwargs.pop('renderer', None)
    title = kwargs.pop('title', None)
    trace_manager = TraceManager3D()
    trace_manager.layout.update(
        title=title,
        scene=dict(
            xaxis_title='x1',
            yaxis_title='x2',
            zaxis_title='f'))
    trace_manager.add_surface(x, y, z, **kwargs)
    trace_manager.show(renderer) if show else None
    trace_manager.save(save) if save else None


def plot_2d_contour(x, y, show=True, save=True, **kwargs):
    renderer = kwargs.pop('renderer', None)
    trace_manager = TraceManager2D()
    trace_manager.layout.update(scene=dict(
        xaxis_title='x1',
        yaxis_title='x2'))
    trace_manager.add_contour(x, y, **kwargs)
    trace_manager.show(renderer) if show else None
    trace_manager.save(save) if save else None


# def make_ssifl_gif(ssifl_results):


if __name__ == "__main__":

    import os

    # _image_files_to_gif(os.listdir("./ssifl_test"), "./test.gif")
    # x = np.linspace(0, 1, 100)
    # y = np.linspace(0, 1, 100)
    # x, y = np.meshgrid(x, y)
    # z = np.sin(x * 6 * np.pi)
    # plot_surface_3d(x, y, z, save="test3.png")
    #
    from mmgpy.metamodel import SupportVectorRegression, RandomForestRegression, \
        FeedForwardNNRegression
    from mmgpy.benchmark import TestFunctionSet2DInputSpace
    from mmgpy.sampling import uniform_grid
    from sklearn.preprocessing import MinMaxScaler
    from mmgpy.algorithm import SSIFL


    def gif(model, name):

        F2D = TestFunctionSet2DInputSpace()

        def ssifl_test(m_model, F_):
            delta = 0.01
            epsilon = 0.1
            scaler = MinMaxScaler()
            ssifl = SSIFL(F_, 2, m_model, delta, epsilon, scaler=scaler,
                          tdmq=None,
                          verbose=True, hopt=True, maxiter=-1, cumulative=True,
                          importance='error',
                          **{'clip': False, 'v': 4.0}, logging=1)
            # ssifl.iterate_to_confidence()
            grid = uniform_grid([[0] * 2, [1] * 2], 100, flatten=False)
            flat = uniform_grid([[0] * 2, [1] * 2], 100, flatten=True)

            while ssifl.terminate is False:
                ssifl.iterate()
                iteration = ssifl._iteration
                n_samples = ssifl._s_num
                statistic = np.round(ssifl._log.statistic[-1] * 100, 2)
                epsilon = ssifl.epsilon
                confidence = np.round((1 - ssifl.delta) * 100, 2)

                title = (
                        "Samples:".ljust(20) + f"{n_samples}<br>"
                        + "Accuracy:".ljust(20) + f"{epsilon}<br>"
                        + "Confidence:".ljust(20) + f"{statistic}%")
                save_name_surf = f"{name}/img_surf_{str(iteration)}.pdf"
                plot_3d_surface(grid[0], grid[1], scaler.inverse_transform(
                    ssifl.meta_model.predict(flat).reshape(-1, 1)).reshape(100,
                                                                           100),

                                save=save_name_surf,
                                showscale=False,
                                title=title)

                # save_name_hist = f"ssifl_test3/img_hist_{str(iteration)}.png"
                # plot_2d_contour(*ssifl._log[-1]['x_new'].T,
                #                 save=save_name_hist,
                #                 showscale=False,
                #                 colourscale="Blues")

            return ssifl, scaler

        m_model1 = model
        # static_params={'gamma': 400, 'epsilon': 1e-4})
        F_1 = F2D[0]
        ssifl_test(m_model1, F_1)

    #
    m_model1 = FeedForwardNNRegression()
    gif(m_model1, "ffnn")
    # _image_files_to_gif("./rfr_no_imp_cum", "here.gif")
