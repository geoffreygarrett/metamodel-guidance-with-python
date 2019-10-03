import numpy as np


def grid_sample(bounds, n_sample_dim, flatten=True, edges=True):
    linspace = [np.linspace(bounds[0][i], bounds[1][i], n_sample_dim) for i in range(len(bounds[0]))]
    _return = np.array(np.meshgrid(*linspace))
    return np.array([_return_i.flatten() for _return_i in _return.reshape(len(bounds[0]), -1)]) if flatten else _return


def grid_sample_custom(domain: np.ndarray, sample_dim: np.ndarray):
    # Numpy arrays in memory heap.
    result = np.zeros((np.prod(sample_dim), domain.shape[1]))
    current_sample = np.zeros(domain.shape[1])
    idx_s_v = np.array([0, 0])

    def recurse_variable(domain, sample_dim, current_sample=current_sample, idx_s_v=idx_s_v, result=result):
        grid_for_variable = np.linspace(domain[0][idx_s_v[1]], domain[1][idx_s_v[1]], sample_dim[idx_s_v[1]])
        for idx, s in enumerate(grid_for_variable):
            is_final_var = idx_s_v[1] == result.shape[1] - 1
            if is_final_var:
                current_sample[idx_s_v[1]] = s
                result[idx_s_v[0], :] = current_sample
                idx_s_v[0] += 1
            else:
                current_sample[idx_s_v[1]] = s
                idx_s_v[1] += 1
            if is_final_var:
                continue
            else:
                recurse_variable(domain, sample_dim, current_sample, idx_s_v)
        idx_s_v[1] -= 1

    recurse_variable(domain, sample_dim)
    return result


import itertools


def itertoolss(domain, sample_dim):
    grids = []
    for i in range(len(domain[0])):
        grid_for_variable = np.linspace(domain[0][i], domain[1][i], sample_dim[i])
        grids.append(grid_for_variable)

    return list(itertools.product(*grids))


if __name__ == "__main__":
    domain = np.array([[0, 0, 0, 0], [1, 1, 1, 1]])
    dim_n = np.array([20] * domain.shape[1])

    from time import time

    tic = time()
    x = grid_sample_custom(domain, dim_n)
    toc = time()
    print(toc - tic)

    tic = time()
    x = grid_sample(domain, 20)
    toc = time()
    print(toc - tic)

    tic = time()
    x = itertoolss(domain, dim_n)
    # print(x)
    toc = time()
    print(toc - tic)

    print(np.array(x))
