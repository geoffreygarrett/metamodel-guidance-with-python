from ._base import SurrogateModelBaseRegression
from .deeplearning import Trainer3
import torch.nn as nn
import torch
from .modules import activation_dict
from .modules.fx import RegressionOutput, BasicBlock
from src.dataset import DataSetFX
from .deeplearning.util import LutzPrecheltEarlyStopping
import skopt


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
        return "FFNN"

    def __init__(self, static_params={}, nn_module=SimpleRectangularNN):
        self.device = torch.device(
            "cuda" if torch.cuda.is_available() else "cpu")
        super().__init__()

        self._default_params = {
            "activation": "leaky_relu",
            "dropout_rate": 1e-3,
            "learning_rate": 1e-4,
            "n_hidden_layers": 3,
            "n_hidden_neurons": 600,
            "batch_size": None,
            "batch_size_fraction": 0.05,
            "num_epochs": 400,
            "early_stopping": LutzPrecheltEarlyStopping(5,
                                                        criteria=(
                                                            ("PQ", 0.75),))
        }
        self._hyper_param_space = {
            # "categorical__learning_rate": ([1e-4, 1e-3, 1e-2],),
            "real__learning_rate": (1e-4, 1e-2),
            "real__batch_size_fraction": (0.01, 0.20),
        }
        self._structure_hyper_param_space = {
            "categorical__activation": (['relu', 'leaky_relu', 'sigmoid'],),
            "real__dropout_rate": (1e-4, 5e-2),
            "integer__n_hidden_layers": (3, 10),
            "integer__n_hidden_neurons": (100, 300),
        }

        self._hyper_param = {}
        self._static_params = static_params
        self._model_cls = nn_module

    def fit(self, x_train, y_train, x_test=None, y_test=None, reset=False,
            verbose=False, tdmq=False, early_stopping=False):
        self.static_params["x_dim"] = len(x_train.T)
        self.static_params["f_dim"] = 1
        training_dataset = DataSetFX(
            output=y_train.reshape(-1, 1),
            input=x_train.reshape(-1, len(x_train.T)))
        validation_dataset = DataSetFX(
            output=y_test.reshape(-1, 1),
            input=x_test.reshape(-1, len(x_train.T)))

        batch_size = int(self.all_params["batch_size_fraction"] * len(
            training_dataset))
        batch_size = 2 if batch_size == 1 else batch_size
        while len(training_dataset) % batch_size == 1:
            batch_size += 1

        if early_stopping:
            _early_stopping = self.all_params["early_stopping"]
        else:
            _early_stopping = None

        self.model.train()
        self._trainer = Trainer3(
            PATH="meta_models/",
            training_dataset=training_dataset,
            validation_dataset=validation_dataset,
            model=self.model,
            optimizer=torch.optim.Adam,
            criterion=torch.nn.modules.loss.MSELoss,
            batch_size=batch_size,
            num_epochs=self.all_params["num_epochs"],
            learning_rate=self.all_params["learning_rate"])

        self._trainer.train(early_stopping=_early_stopping,
                            save_each_epoch=False,
                            save_final_model=False,
                            plot_jupyter=False,
                            verbose=verbose)

        self._model = self._trainer._model

    # @property
    # def model(self):
    #     if self._model is None:
    #         self._model = self._trainer._model
    #     else:
    #         pass
    #     return self._model

    def score(self, X, y):
        self.model.eval()
        with torch.no_grad():
            res = self._trainer._criterion(
                self.model(torch.tensor(X).to(self.device).float()),
                torch.tensor(y.reshape(-1, 1)).to(
                    self.device).float()).detach().cpu().numpy()
        return -res

    def predict(self, X):
        """

        :param X:
        :return:
        """
        return self.model(torch.tensor(X).to(
            self.device).float()).detach().cpu().numpy().flatten()

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
