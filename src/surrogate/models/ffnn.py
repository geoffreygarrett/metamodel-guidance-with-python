from ._base import SurrogateModelBaseRegression
from .deeplearning import Trainer3
import torch.nn as nn
import torch
from .modules import activation_dict
from .modules.fx import RegressionOutput, BasicBlock
from src.dataset import DataSetFX
from .deeplearning.util import LutzPrecheltEarlyStopping


class SimpleRectangularNN(nn.Module):

    def __init__(self, model_params):
        Xdim = model_params["Xdim"]
        fdim = model_params["fdim"]
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

    def __init__(self, static_params=None, nn_module=SimpleRectangularNN):
        super().__init__()
        self._default_params = {
            "activation": "relu",
            "dropout_rate": 1e-3,
            "learning_rate": 1e-3,
            "n_hidden_layers": 3,
            "n_hidden_neurons": 50,
            "batch_size_part_of_20": 2,
            "num_epochs": 3000,
            "early_stopping": LutzPrecheltEarlyStopping(5)
        }
        self._hyper_params = {
            "categorical__activation": (['relu', 'leaky_relu', 'sigmoid'],),
            "real__dropout_rate": (1e-4, 5e-2),
            "categorical__learning_rate": ([1e-4, 1e-3, 1e-2],),
            "integer__n_hidden_layers": (3, 10),
            "integer__n_hidden_neurons": (100, 300),
            "integer__batch_size_part_of_20": (1, 10),
            # "integer__num_epochs": (10, 500)
        }
        self._static_params = static_params
        self._model_cls = nn_module

    def fit(self, X=None, y=None):
        """

        :param X:
        :param y:
        :return:
        """
        training_dataset = DataSetFX(
            output=self._static_params["training_data"][1].reshape(-1, self._static_params["fdim"]),
            input=self._static_params["training_data"][0].reshape(-1, self._static_params["Xdim"]))

        validation_dataset = DataSetFX(
            output=self._static_params["training_data"][1].reshape(-1, self._static_params["fdim"]),
            input=self._static_params["training_data"][0].reshape(-1, self._static_params["Xdim"]))

        batch_size = int(self.all_params["batch_size_part_of_20"] / 20. * len(training_dataset))
        batch_size = 2 if batch_size == 1 else batch_size

        while len(training_dataset) % batch_size == 1:
            batch_size += 1

        self.model.train()
        self._trainer = Trainer3(
            PATH="models/",
            training_dataset=training_dataset,
            validation_dataset=validation_dataset,
            model=self.model,
            optimizer=torch.optim.Adam,
            criterion=torch.nn.modules.loss.MSELoss,
            batch_size=batch_size,
            num_epochs=self.all_params["num_epochs"],
            learning_rate=self.all_params["learning_rate"])

        self._trainer.train(early_stopping=self.all_params["early_stopping"],
                            save_each_epoch=False,
                            save_final_model=False,
                            plot_jupyter=False)

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
            res = self._trainer._criterion(self.model(torch.tensor(X).float()),
                                           torch.tensor(y.reshape(-1, 1)).float()).detach().cpu().numpy()
        # print(res)
        # print(type(res))
        return -res

    def predict(self, X):
        """

        :param X:
        :return:
        """
        return self.model(torch.tensor(X).float()).detach().cpu().numpy().flatten()

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
