from src.surrogate.meta_models._base import SurrogateModelBaseRegression
from src.surrogate.meta_models.deeplearning import Trainer3
import torch.nn as nn
import torch
from src.surrogate.meta_models.modules import activation_dict
from src.surrogate.meta_models.modules.fx import RegressionOutput, BasicBlock
from src.dataset import DataSetFX
from src.surrogate.meta_models.deeplearning.util import \
    LutzPrecheltEarlyStopping
import skopt

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

DEFAULT_FFNNR_PARAMS = {
    # Architecture.
    "activation": "leaky_relu",
    "n_hidden_layers": 3,
    "n_hidden_neurons": 500,

    # Training.
    "dropout_rate": 1e-3,
    "learning_rate": 1e-4,
    "batch_size": 64,

    # "batch_size_fraction": 0.05,
    "num_epochs": 500,
    "early_stopping": LutzPrecheltEarlyStopping(10, criteria=(("PQ", 1.5),)),
    'optimizer': torch.optim.Adam,
    'criterion': torch.nn.modules.loss.MSELoss,

}

DEFAULT_FFNNR_ROUTINES = dict(
    initial=[
        {
            # Architecture optimisation.
            "integer__n_hidden_layers": (1, 3),
            # "integer__n_hidden_neurons": (600, 1000),
            "real__dropout_rate": (1e-4, 1e-2),
            "integer__batch_size": (70, 300),
            "real__learning_rate": (1e-6, 5e-4),
            # "categorical__activation": ["leaky_relu", "sigmoid"],
            "_function__learning_rate": 1e-4,
            "_function__early_stopping":
                LutzPrecheltEarlyStopping(10, criteria=(("PQ", 0.6),)),
            "_optimiser__name": "gp_minimize",
            "_optimiser__kwargs": {"n_calls": 15}
        },
    ],
    intermediate=[
        {
            # Training learning rate optimisation.
            "real__learning_rate": (1e-6, 5e-4),
            "_function__early_stopping":
                LutzPrecheltEarlyStopping(5, criteria=(("PQ", 2.0),))
        },

    ]
)


class SimpleRectangularNN(nn.Module):

    def __init__(self, model_params):
        Xdim = model_params["x_dim"]
        fdim = model_params["f_dim"]
        activation = model_params["activation"]
        dropout_rate = model_params["dropout_rate"]
        n_hidden_layers = model_params["n_hidden_layers"]
        n_hidden_neurons = model_params["n_hidden_neurons"]
        super().__init__()
        self.fc_in = nn.Sequential(
            *[nn.Linear(Xdim, n_hidden_neurons),
              activation_dict[activation],
              nn.Dropout(dropout_rate),
              nn.BatchNorm1d(n_hidden_neurons)]
        )
        self.fc_center = nn.Sequential(
            *[nn.Linear(n_hidden_neurons, n_hidden_neurons),
              activation_dict[activation],
              nn.Dropout(dropout_rate),
              nn.BatchNorm1d(n_hidden_neurons)
              ] * int(n_hidden_layers - 2)
        )
        self.fc_out = RegressionOutput(n_hidden_neurons, fdim)

    def forward(self, x):
        x = self.fc_in(x)
        x = self.fc_center(x)
        return self.fc_out(x)


class FeedForwardNNRegression(SurrogateModelBaseRegression):

    def __str__(self):
        return "Feed Forward Neural Network Regression (FFNNR)"

    def __init__(self, static_params={}, nn_module=SimpleRectangularNN):
        super().__init__(routines=DEFAULT_FFNNR_ROUTINES,
                         hyperparams_default=DEFAULT_FFNNR_PARAMS,
                         hyperparams_static=static_params)
        self._model_cls = nn_module
        self._trainer_cls = Trainer3

    @staticmethod
    def trainer_hyperparameters(hyperparameters):
        return {
            "learning_rate": hyperparameters["learning_rate"],
            # "batch_size_fraction": self.hyperparameters["batch_size_fraction"],
            "batch_size": hyperparameters["batch_size"],
            "num_epochs": hyperparameters["num_epochs"],
            "early_stopping": hyperparameters["early_stopping"],
            'optimizer': hyperparameters["optimizer"],
            'criterion': hyperparameters["criterion"],
        }

    @staticmethod
    def architecture_hyperparameters(hyperparameters):
        return {

            "dropout_rate": hyperparameters["dropout_rate"],
            "activation": hyperparameters["activation"],
            "n_hidden_layers": hyperparameters["n_hidden_layers"],
            "n_hidden_neurons": hyperparameters["n_hidden_neurons"]
        }

    # def fit(self, x_train, y_train, x_test=None, y_test=None, reset=False,
    #         verbose=False, tdmq=False, early_stopping=False):
    #     self.static_params["x_dim"] = len(x_train.T)
    #     self.static_params["f_dim"] = 1
    #     training_dataset = DataSetFX(
    #         output=y_train.reshape(-1, 1),
    #         input=x_train.reshape(-1, len(x_train.T)))
    #     validation_dataset = DataSetFX(
    #         output=y_test.reshape(-1, 1),
    #         input=x_test.reshape(-1, len(x_train.T)))
    #
    #     batch_size = int(self.all_params["batch_size_fraction"] * len(
    #         training_dataset))
    #     batch_size = 2 if batch_size == 1 else batch_size
    #     while len(training_dataset) % batch_size == 1:
    #         batch_size += 1
    #
    #     if early_stopping:
    #         _early_stopping = self.all_params["early_stopping"]
    #     else:
    #         _early_stopping = None
    #
    #     self.model.train()
    #     self._trainer = Trainer3(
    #         PATH="meta_models/",
    #         training_dataset=training_dataset,
    #         validation_dataset=validation_dataset,
    #         model=self.model,
    #         optimizer=torch.optim.Adam,
    #         criterion=torch.nn.modules.loss.MSELoss,
    #         batch_size=batch_size,
    #         num_epochs=self.all_params["num_epochs"],
    #         learning_rate=self.all_params["learning_rate"])
    #
    #     self._trainer.train(early_stopping=_early_stopping,
    #                         save_each_epoch=False,
    #                         save_final_model=False,
    #                         plot_jupyter=False,
    #                         verbose=verbose)
    #
    #     self._model = self._trainer._model

    # @property
    # def model(self):
    #     if self._model is None:
    #         self._model = self._trainer._model
    #     else:
    #         pass
    #     return self._model

    def copy_model(self, model, **kwargs):
        x_dim = len(kwargs["x"].T)
        f_dim = 1
        state_dict = model.state_dict()
        copied_model = self._model_cls(
            {**dict(x_dim=x_dim, f_dim=f_dim),
             **self.architecture_hyperparameters(self.hyperparameters)})
        copied_model.load_state_dict(state_dict)
        return copied_model

    def fit(self, x, y, **options):
        """
        Fits the data given the current default -> global static
        hyperparameters.

        Parameters
        ----------
        x
        y
        options

        Returns
        -------

        """
        hyperparameters = self.hyperparameters
        hyperparameters["early_stopping"] = None
        hyperparameters["num_epochs"] = 2000
        self._model, self._trainer = self._fit(x, y,
                                               model=self._model,
                                               **hyperparameters,
                                               **options)

    def _score(self, model, x, y, sample_weight=None, trainer=None):
        model.eval()
        with torch.no_grad():
            res = trainer._criterion(
                model(torch.tensor(x).to(device).float()),
                torch.tensor(y.reshape(-1, 1)).to(
                    device).float()).detach().cpu().numpy()
        return -res

    @staticmethod
    def _predict(model, x):
        """

        :param X:
        :return:
        """
        return model(torch.tensor(x).to(
            device).float()).detach().cpu().numpy().flatten()

        # def save(self, path):
        #     """
        #
        #     :param path:
        #     :return:
        #     """
        #     raise NotImplementedError("Not implemented in base class.")
        #
        # def load(self, path):
        #     """
        #
        #     :param path:
        #     :return:
        #     """
        #     raise NotImplementedError("Not implemented in base class.")


if __name__ == "__main__":
    test = FeedForwardNNRegression()
    import numpy as np

    x = np.array([[1, 2, 3, 4, 5, 6, 8, 9, 10]]).T / 10
    y = x.T[0]

    test.fit(x, y, validation_data=(x, y), verbose=True)
