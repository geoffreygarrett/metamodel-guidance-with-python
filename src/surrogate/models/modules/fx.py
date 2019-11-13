import torch.nn as nn
from ._activation import *


class BaseResidualBlock(nn.Module):

    def __init__(self, input_size, output_size, activation="relu"):
        super().__init__()
        self.input_size = input_size
        self.output_size = output_size
        self.blocks = nn.Identity()
        self.activation = activation_dict[activation]
        self.shortcut = nn.Identity()

    def forward(self, x):
        residual = self.shortcut(x)
        x = self.blocks(x)
        x += residual
        x = self.activation(x)
        return x


class ResidualBlock(BaseResidualBlock):

    def __init__(self, hidden_size, activation="relu"):
        super().__init__(hidden_size, hidden_size, activation=activation)
        self.shortcut = nn.BatchNorm2d(hidden_size)
        self.blocks = nn.Sequential(
            nn.Linear(in_features=hidden_size, out_features=hidden_size),
            self.activation,
            nn.Linear(in_features=hidden_size, out_features=hidden_size),
            nn.BatchNorm1d(hidden_size)
        )


class BasicBlock(nn.Module):

    def __init__(self, input_size, output_size, activation="relu"):
        super().__init__()
        self.activation = activation_dict[activation]
        self.block = nn.Sequential(
            nn.Linear(in_features=input_size, out_features=output_size),
            self.activation,
            nn.BatchNorm1d(output_size)
        )

    def forward(self, x):
        return self.block(x)


class RegressionOutput(nn.Module):

    def __init__(self, in_features, out_features):
        super().__init__()
        self.block = nn.Sequential(
            nn.Linear(in_features=in_features,
                      out_features=out_features),
        )

    def forward(self, x):
        return self.block(x)
