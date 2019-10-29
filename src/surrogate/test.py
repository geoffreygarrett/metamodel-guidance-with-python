from sampling._cvt import *
from sampling import halton
from sampling import multivariate_normal

if __name__ == "__main__":
    bounds = [[0, 0], [1, 1]]
    test = CVT(bounds=bounds,
               k=60,
               z_sample_method=halton)

    vor = Voronoi(test._z)
    voronoi_plot_2d(vor)
    plt.show()

    samples = multivariate_normal(mean=[0.5, 0.5],
                                  covariance=np.array([[0.2, 0], [0, 0.01]]),
                                  n_sample=500,
                                  seed=1).T
    test._iterate(samples)

    for i in range(20):
        samples = multivariate_normal(mean=[0.5, 0.5],
                                      covariance=np.array([[0.2, 0], [0, 0.01]]),
                                      n_sample=500,
                                      seed=1).T

        test._iterate(samples)

        if i % 1 == 0:
            vor = Voronoi(test._z)
            voronoi_plot_2d(vor)
            plt.title(f"Iteration {i}")
            plt.show()
