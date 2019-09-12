import os
from collections import OrderedDict

import numpy as np
import pandas as pd
import scipy.io as sio
import torch
from sklearn import model_selection
from torch.utils.data import Dataset
from .transform import TransformBase


class DataSetFX(Dataset):

    @staticmethod
    def df_to_fx(df):
        _df = df
        _F_col = list(filter(lambda f: "f" in f, _df.columns))
        _X_col = list(filter(lambda x: "x" in x, _df.columns))
        _F = _df.loc[:, _F_col].values
        _X = _df.loc[:, _X_col].values
        return {"F": _F, "X": _X}

    @staticmethod
    def fx_to_df(fx):
        _F = fx["F"]
        _X = fx["X"]
        _F_col = [f"f{i + 1}" for i in range(_F.shape[1])]
        _X_col = [f"x{i + 1}" for i in range(_X.shape[1])]
        return pd.DataFrame(data=np.concatenate((_F, _X), axis=1), columns=_F_col + _X_col)

    def __init__(self, output: np.ndarray, input: np.ndarray, file_name=None, root_dir=None,
                 transform: TransformBase = None, name=None):
        """
        :param output_f (numpy array):
        :param input_x (numpy array):
        :param file_path (string): Path to the file containing the DataSet.
        :param root_dir (string): Directory containing DataSet.
        :param transform_output (callable, optional): Optional transform to be applied to outputs.
        :param transform_input (callable, optional): Optional transform to be applied to inputs.
        """
        try:
            assert output.shape[0] == input.shape[0]
        except AssertionError:
            raise AttributeError("Number of input samples must equal output samples.")

        # Directory and file name for saving.
        self._root_dir = root_dir
        self._name = name if name is not None else file_name.split(".")[0] if file_name is not None else None

        # Transform managing class.
        self._transform = transform

        # Tensor form storage.
        _fx = self.df_to_fx(transform(self.fx_to_df({"F": output, "X": input}))) if transform else {"F": output,
                                                                                                    "X": input}
        self._output = torch.tensor(_fx["F"])
        self._input = torch.tensor(_fx["X"])

    def __len__(self):
        return self._output.shape[0]

    def __getitem__(self, idx):
        return self._input[idx], self._output[idx]

    def __add__(self, other):
        assert self.input_size == other.input_size
        assert self.output_size == other.output_size
        _root_dir = self.root_dir
        _transform = self.transform
        try:
            assert (self.transform == other.transform)
        except AssertionError:
            raise UserWarning("""
            Root dir is not equivalent for L.H.S. DataSet and R.H.S. DataSet,
                L.H.S. root dir is being used for resultant DataSet from __add__().
            """)
        try:
            assert (self.root_dir == other.root_dir)
        except AssertionError:
            raise UserWarning("""
            Transform class is not equivalent for L.H.S. DataSet and R.H.S. DataSet,
                L.H.S. Transform class is being used for resultant DataSet from __add__().
            """)
        return DataSetFX(
            output=np.concatenate((self.output, other.output)), input=np.concatenate((self.input, other.input)),
            root_dir=_root_dir, transform=_transform
        )

    @classmethod
    def from_csv(cls, file_name=None, root_dir=None, transform=None):
        _fx = cls.df_to_fx(pd.read_csv(os.path.join(root_dir, file_name)))
        return cls(output=_fx["F"], input=_fx["X"], file_name=file_name, root_dir=root_dir, transform=transform)

    @classmethod
    def from_parquet(cls, file_name, root_dir=None, transform=None):
        _fx = cls.df_to_fx(pd.read_parquet(os.path.join(root_dir, file_name)))
        return cls(output=_fx["F"], input=_fx["X"], file_name=file_name, root_dir=root_dir, transform=transform)

    @classmethod
    def from_npz(cls, file_name, root_dir=None, transform=None):
        _fx = np.load(os.path.join(root_dir, file_name))
        return cls(output=_fx["F"], input=_fx["X"], file_name=file_name, root_dir=root_dir, transform=transform)

    @classmethod
    def from_mat(cls, file_name, root_dir=None, transform=None):
        _fx = sio.loadmat(os.path.join(root_dir, file_name))
        return cls(output=_fx["F"], input=_fx["X"], file_name=file_name, root_dir=root_dir, transform=transform)

    @property
    def transform(self):
        return self._transform

    # @property
    # def output_transform(self):
    #     return self._output_transform
    #
    # @property
    # def input_transform(self):
    #     return self._input_transform

    @property
    def output(self):
        """
        :return (numpy array): [N x dim_f] Array of output values.
        """
        return self._output.numpy() # if self._transform.f is False else self._transform.inverse_f(self._output.numpy())

    @property
    def output_size(self):
        return self._output.shape[1]

    @property
    def input(self):
        """
        :return (numpy array): [N x dim_x] Array of input values.
        """
        return self._input.numpy()#  if self._transform.x is False else self._transform.inverse_x(self._input.numpy())

    @property
    def input_size(self):
        return self._input.shape[1]

    @property
    def root_dir(self):
        """
        :return (string): Root directory for saving/loading DataSet.
        """
        return self._root_dir

    @property
    def name(self):
        """
        :return (string): Name of DataSet derived from removing filename extension.
        """
        return self._name

    @property
    def fx(self):
        """
        :return (dict of numpy arrays): Dictionary of input (X) and output (F) arrays.
        """
        return {"F": self.output, "X": self.input}

    def to_mat(self, file_name, root_dir=None):
        _root_dir = root_dir if root_dir is not None else "."
        sio.savemat(os.path.join(root_dir, file_name), self.fx)

    def to_parquet(self, file_name, root_dir=None):
        _root_dir = root_dir if root_dir is not None else "."
        self.fx_to_df(self.fx).to_parquet(os.path.join(root_dir, file_name), index=False)

    def to_csv(self, file_name, root_dir=None):
        _root_dir = root_dir if root_dir is not None else "."
        self.fx_to_df(self.fx).to_csv(os.path.join(root_dir, file_name), index=False)

    def to_npz(self, file_name, root_dir=None):
        _root_dir = root_dir if root_dir is not None else "."
        np.savez(os.path.join(root_dir, file_name), F=self.output, X=self.input)

    def get_df(self, transformed=False):
        _F = self.output if ((transformed is False) or (self._transform.f is False)) else self._output.numpy()
        _X = self.input if ((transformed is False) or (self._transform.x is False)) else self._input.numpy()
        _df = self.fx_to_df({"F": _F, "X": _X})
        _df.transformed = transformed
        _df.name = self.name
        return _df

    def train_test_split(self, test_size=0.2, random_state=42, shuffle=True):
        input_train, input_test, output_train, output_test = model_selection.train_test_split(
            self.input,
            self.output,
            random_state=random_state,
            test_size=test_size,
            shuffle=shuffle)
        return (DataSetFX(output=output_train,
                          input=input_train,
                          transform=self.transform,
                          name=f"{self.name}_tst{test_size}_rs{random_state}_s{shuffle}_train".replace(".", ""),
                          root_dir=self.root_dir),
                DataSetFX(output=output_test,
                          input=input_test,
                          transform=self.transform,
                          name=f"{self.name}_tst{test_size}_rs{random_state}_s{shuffle}_test".replace(".", ""),
                          root_dir=self.root_dir))
