import subprocess
from scipy.io import savemat, loadmat
from mmgpy.surrogate.sampling import uniform_grid
import numpy as np
import os
import shutil
from tqdm import tqdm_notebook as tqdm
from mmgpy.optimise.constructor.examples import rs_bicycle_constructor


def ensure_exists(path):
    if not os.path.exists(path):
        os.makedirs(path)


def designs_to_folder(designs, design_dir: os.PathLike, constructor=rs_bicycle_constructor):
    """
    Function to save all design sample 'x<i>.mat' files in root_dir


    :param designs: SxN matrix, where S is number of samples and N is the design dimension.
    :param root_dir: Directory where the designs are to be saved.
    """

    _len = len(str(len(designs)))
    ensure_exists(design_dir)
    designs_t = tqdm(designs.T, desc="Saving designs", leave=False)

    for idx, x in enumerate(designs_t):
        mdict = {'X': constructor(x)}
        savemat(f'{design_dir}/X{idx + 1:0{_len}}.mat', mdict)


def grid_design_to_folder(xdim: int, ndim: int, design_folder: os.PathLike, edges=False):
    """
    Function generate and save grid sampled design files.

    """
    grid = uniform_grid(np.array([[0] * xdim, [1] * xdim]), ndim, flatten=True, edges=edges)
    designs_to_folder(grid, design_folder)
    return grid


def chunks(l, n):
    """Yield successive n-sized chunks from l."""
    for i in range(0, len(l), n):
        yield l[i:i + n]


def subprocess_cmd(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, shell=True)
    proc_stdout = process.communicate()[0].strip()


def run_simulations(design_path, app_path, overwrite=False):
    """
    Runs design files and saves the corresponding performance files.
    """
    files = os.listdir(design_path)
    evaluated = list(filter(lambda x: 'F' in x, files))
    if overwrite == False:
        try:
            assert len(evaluated) == 0
        except AssertionError:
            raise AssertionError(
                f"{design_path} already contains evaluated simulation designs. Set overwrite=True to delete existing.")
    elif len(evaluated) != 0:
        to_delete = tqdm(evaluated, desc="Overwriting", leave=False)
        for f in to_delete:
            os.remove(os.path.join(design_path, f))
    cmds = [f"{app_path} -i {os.path.join(design_path, file)} -o {os.path.join(design_path, file.replace('X', 'F'))}"
            for file in files]
    batches = tqdm(list(chunks(cmds, 10)), desc='Simulating', leave=False)
    for batch in batches:
        subprocess_cmd(';'.join(batch))


def get_simulation_results(design_path, delete_folder=True):
    files = os.listdir(design_path)
    out = list(filter(lambda x: 'F' in x, files))
    out.sort()
    _F = np.vstack([loadmat(os.path.join(design_path, fout))['rt_F'][-1] for fout in out])
    _S = np.dstack([loadmat(os.path.join(design_path, fout))['rt_S'] for fout in out])
    if delete_folder:
        shutil.rmtree(design_path)
    return _S, _F


def idx_target_sim_func(idx=None, tag="f", sim_name="rs_bicycle"):
    tag = f"_{tag}"

    def sim_func(*x):
        ROOT_DIR = "simulation"
        EVAL_DIR = f"data/{sim_name}/func"
        APP_DIR = "apps"
        APP = sim_name
        X = np.array(x)
        designs_to_folder(X, os.path.join(ROOT_DIR, EVAL_DIR, APP + tag))
        run_simulations(design_path=os.path.join(ROOT_DIR, EVAL_DIR, APP + tag),
                        app_path=os.path.join(ROOT_DIR, APP_DIR, APP, "src", APP),
                        overwrite=True)
        S, F = get_simulation_results(design_path=os.path.join(ROOT_DIR, EVAL_DIR, APP + tag))

        # Save final mat.
        save_path = os.path.join(ROOT_DIR, EVAL_DIR, f'{APP + tag}.mat')
        savemat(save_path, {"X": X, "S": S, "F": F})
        return F.T if idx is None else F[:, idx].T

    return sim_func


# def sim_func(x, tag="func_use", sim_name="rs_bicycle"):
#     tag = f"_{tag}"
#     ROOT_DIR = "simulation"
#     EVAL_DIR = f"data/{sim_name}/func"
#     APP_DIR = "apps"
#     APP = sim_name
#     X = x
#     print(ROOT_DIR)
#     print(EVAL_DIR)
#     print(APP)
#     print(os.path.join([ROOT_DIR, EVAL_DIR, APP + tag]))
#     designs_to_folder(x, os.path.join([ROOT_DIR, EVAL_DIR, APP + tag]))
#     run_simulations(design_path=os.path.join(ROOT_DIR, EVAL_DIR, APP + tag),
#                     app_path=os.path.join(ROOT_DIR, APP_DIR, APP, "src", APP),
#                     overwrite=True)
#     S, F = get_simulation_results(design_path=os.path.join(ROOT_DIR, EVAL_DIR, APP + tag))
#
#     # Save final mat.
#     savemat(os.path.join(ROOT_DIR, EVAL_DIR, f'{APP + tag}.mat'), {"X": X, "S": S, "F": F})
#     return F if idx is None else F[:, 0]

def idoe_ug_screening(sim_name, N, S):
    tag = f"_UG_N{N}_S{S}"
    ROOT_DIR = "simulation"
    EVAL_DIR = f"data/{sim_name}/idoe"
    APP_DIR = "apps"
    APP = sim_name

    # Generate uniform grid screening sample.
    X = grid_design_to_folder(N, S, os.path.join(ROOT_DIR, EVAL_DIR, APP + tag))
    run_simulations(design_path=os.path.join(ROOT_DIR, EVAL_DIR, APP + tag),
                    app_path=os.path.join(ROOT_DIR, APP_DIR, APP, "src", APP),
                    overwrite=True)
    S, F = get_simulation_results(design_path=os.path.join(ROOT_DIR, EVAL_DIR, APP + tag))

    # Save final mat.
    savemat(os.path.join(ROOT_DIR, EVAL_DIR, f'{APP + tag}.mat'), {"X": X, "S": S, "F": F})
