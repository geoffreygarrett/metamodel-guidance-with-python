from torch import nn
import torch

activation_dict = nn.ModuleDict([
    ['relu', nn.ReLU(inplace=True)],
    ['leaky_relu', nn.LeakyReLU(negative_slope=0.01, inplace=True)],
    ['selu', nn.SELU(inplace=True)],
    ['none', nn.Identity()],
    ['sigmoid', nn.Sigmoid()],
    ['relu6', torch.nn.ReLU6()],
    ['softsign', torch.nn.Softsign()],
    ['tanh', torch.nn.Tanh()],
    ['tanshrink',torch.nn.Tanhshrink()],
])


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

    def __init__(self, hidden_size, activation="relu", kernel_size=1, stride=1):
        super().__init__(hidden_size, hidden_size, activation=activation)
        self.shortcut = nn.BatchNorm2d(hidden_size)
        self.blocks = nn.Sequential(
            nn.Conv2d(in_channels=hidden_size,
                      out_channels=hidden_size,
                      kernel_size=kernel_size,
                      stride=stride),
            self.activation,
            nn.Conv2d(in_channels=hidden_size,
                      out_channels=hidden_size,
                      kernel_size=kernel_size,
                      stride=stride),
            nn.BatchNorm2d(hidden_size)
        )


class BasicBlock(nn.Module):

    def __init__(self, input_size, output_size, activation="relu", kernel_size=1, stride=1):
        super().__init__()
        self.activation = activation_dict[activation]
        self.block = nn.Sequential(
            nn.Conv2d(in_channels=input_size,
                      out_channels=output_size,
                      kernel_size=kernel_size,
                      stride=stride),
            self.activation,
            nn.BatchNorm2d(output_size)
        )

    def forward(self, x):
        return self.block(x)


class RegressionOutput(nn.Module):

    def __init__(self, in_channels, out_channels, kernel_size=1, stride=1):
        super().__init__()
        self.block = nn.Sequential(
            nn.Conv2d(in_channels=in_channels,
                      out_channels=out_channels,
                      kernel_size=kernel_size,
                      stride=stride),
        )

    def forward(self, x):
        return self.block(x)


if __name__ == "__main__":
    test1 = ResidualBlock(5)
    test2 = BasicBlock(5, 5)
    print(test1.forward(torch.ones(1, 5)))
    print(test2.forward(torch.ones(1, 5)))
