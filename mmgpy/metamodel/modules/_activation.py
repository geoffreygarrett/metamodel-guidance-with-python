import torch.nn as nn

activation_dict = nn.ModuleDict([
    ['relu', nn.ReLU(inplace=True)],
    ['leaky_relu', nn.LeakyReLU(negative_slope=0.01, inplace=True)],
    ['selu', nn.SELU(inplace=True)],
    ['none', nn.Identity()],
    ['sigmoid', nn.Sigmoid()],
    ['relu6', nn.ReLU6()],
    ['softsign', nn.Softsign()],
    ['tanh', nn.Tanh()],
    ['tanshrink', nn.Tanhshrink()],
])
