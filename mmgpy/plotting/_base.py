from plotting._trace import *
import imageio


def _image_files_to_gif(filenames, save_path):
    images = []
    for filename in filenames:
        images.append(imageio.imread("ssifl_test/" + filename))
    if save_path.split(".")[-1] != 'gif':
        save_path = f'{save_path}.gif'
    else:
        pass
    imageio.mimsave(save_path, images)


import os

_image_files_to_gif(os.listdir("./ssifl_test"), "./test.gif")


def plot_surface_3d(x, y, z, show=True, save=None, **kwargs):
    renderer = kwargs.pop('renderer', None)
    trace_manager = TraceManager3D()
    trace_manager.layout.update(scene=dict(
        xaxis_title='x1',
        yaxis_title='x2',
        zaxis_title='f'))
    trace_manager.add_surface(x, y, z, **kwargs)
    trace_manager.show(renderer) if show else None
    trace_manager.save(save) if save else None

# def make_ssifl_gif(ssifl_results):

#
# if __name__ == "__main__":
#     # x = np.linspace(0, 1, 100)
#     # y = np.linspace(0, 1, 100)
#     # x, y = np.meshgrid(x, y)
#     # z = np.sin(x * 6 * np.pi)
#     # plot_surface_3d(x, y, z, save="test3.png")
#     #
#     from metamodel import SupportVectorRegression
#     from benchmark import TestFunctionSet2DInputSpace
#     from sampling import uniform_grid
#     from sklearn.preprocessing import MinMaxScaler
#     from algorithm import SSIFL
#
#     F2D = TestFunctionSet2DInputSpace()
#
#
#     def ssifl_test(m_model, F_):
#         delta = 0.01
#         epsilon = 0.1
#         scaler = MinMaxScaler()
#         ssifl = SSIFL(F_, 2, m_model, delta, epsilon, scaler=scaler, tdmq=None,
#                       verbose=True, hopt=True, maxiter=-1, cumulative=True,
#                       importance='error',
#                       **{'clip': False, 'v': 3})
#         # ssifl.iterate_to_confidence()
#         grid = uniform_grid([[0] * 2, [1] * 2], 100, flatten=False)
#         flat = uniform_grid([[0] * 2, [1] * 2], 100, flatten=True)
#
#         while ssifl.terminate is False:
#             ssifl.iterate()
#             iteration = ssifl._iteration
#             save_name = f"ssifl_test/img{str(iteration)}.png"
#             plot_surface_3d(grid[0], grid[1], scaler.inverse_transform(
#                 ssifl.meta_model.predict(flat).reshape(-1, 1)).reshape(100,
#                                                                        100),
#                             save=save_name,
#                             showscale=False)
#
#         return ssifl, scaler
#
#
#     m_model1 = SupportVectorRegression(
#         static_params={'gamma': 400, 'epsilon': 1e-4})
#     F_1 = F2D[0]
#     ssifl_test(m_model1, F_1)
