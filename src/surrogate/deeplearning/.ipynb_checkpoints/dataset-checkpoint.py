from torch.utils.data import DataLoader, Dataset
from scipy import io
import pandas as pd
import os
import numpy as np
from sklearn import model_selection
import torch


class BaseDataset:
    
    def __init__(self, data_dir="data", x=None, f=None):
        self._sub_dir = ''
        self._data_dir = data_dir
        self._filename = None
        self._x = torch.tensor(x) if x is not None else None
        self._f = torch.tensor(f) if f is not None else None
        
        self._preprocessing_f = []
        self._preprocessing_x = []
        
    def __len__(self):
        return self.f.shape[0]
    
    def __getitem__(self, index):
        # load image as ndarray type (Height * Width * Channels)
        # be carefull for converting dtype to np.uint8 [Unsigned integer (0 to 255)]
        # in this example, we use ToTensor(), so we define the numpy array like (H, W, C)
        return self.x[index], self.f[index]
    
    def save_to_mat(self):
        mdict = {"F": self.f.cpu().numpy(), "X": self.x.cpu().numpy()}
        io.savemat(os.path.join(self.filepath, self.filename), mdict)
        
        
    @property
    def sub_dir(self):
        return self._sub_dir
    
    @property
    def dir_(self):
        return os.path.join(self._data_dir, self._sub_dir)
    
    @sub_dir.setter
    def sub_dir(self, x):
        self._sub_dir = x
        
    @property
    def filename(self):
        return self._filename
    
    @filename.setter
    def filename(self, x):
        self._filename = x
        
    @property
    def filepath(self):
        return os.path.join(self._data_dir, self._sub_dir)
        
    @property
    def input_size(self):
        return len(self.x[0,:])
    
    @property
    def output_size(self):
        return len(self.f[0,:])
    
    @property
    def x(self):
        return self._x
    
    @property
    def f(self):
        return self._f
    
    def add_f_preprocessing(self, preprocesser):
        self._preprocessing_f.append(preprocesser)
        self._f = torch.tensor(preprocesser.fit_transform(self._f.cpu().numpy()))
        
    def add_x_preprocessing(self, preprocesser):
        self._preprocessing_x.append(preprocesser)
        self._x = torch.tensor(preprocesser.fit_transform(self._x.cpu().numpy()))
        
    def inverse_transform_x(self, x):
        _x = x.cpu().numpy()
        for _p in self._preprocessing_x.reversed():
            _x = _p.inverse_transform(_x)
        return _x
        
    def inverse_transform_f(self, f):
        _f = f.cpu().numpy()
        for _p in self._preprocessing_f.reversed():
            _f = _p.inverse_transform(_f)
        return _f
    
    def columns(self, which="both"):
        _result = []
        if (which=="x") or (which=="both"):
            _result += [f"x{i+1}" for i in range(self.input_size)]
        if (which=="f") or (which=="both"):
            _result += [f"f{i+1}" for i in range(self.output_size)] 
        else:
            raise ArgumentError("Argument not recognisied.")
        return _result
    
    @property
    def df(self):

        return pd.DataFrame(
            data=np.concatenate((self.x.cpu().numpy(), self.f.cpu().numpy()), axis=1),
            columns=self.columns())
    
    def _derived_dataset(self, x, f, tag, name=None):
        _return = BaseDataset(x=x, f=f)
        _return.sub_dir = self.sub_dir
        _return.filename = self.filename.split(".")[0] + name + tag + ".mat" if name else self.filename.split(".")[0] + tag + ".mat"
        return _return
    
    def train_test_split(self, name=None, frac_test=0.2, random_state=1):
        x_train, x_test, f_train, f_test = model_selection.train_test_split(
            self.x.cpu().numpy(), self.f.cpu().numpy(), 
            test_size=frac_test, 
            random_state=random_state)
        return (self._derived_dataset(x_train, f_train, "_train", name),
                self._derived_dataset(x_test, f_test, "_test", name))


class KristenDataset(BaseDataset):

    def __init__(self, filename, sub_dir="kristen"):
        super().__init__()

        self._filename = filename
        self._sub_dir = sub_dir
        self._mat = io.loadmat(os.path.join(self.filepath, filename))
        print(self._mat)
        self._x = torch.tensor(self._mat["X"])
        self._f = torch.tensor(self._mat["F"])
        

class GeoffreyDataset(BaseDataset):
    
    def __init__(self, filename, sub_dir="geoffrey"):
        super().__init__()

        _n = filename.split("_n_")[1][0]
        self._filename = filename
        self._sub_dir = sub_dir
        self._df = pd.read_csv(os.path.join(self.filepath, filename))
        self._x = torch.tensor(self._df.loc[:,"omega2":f"tw{_n}"].values)
        self._f = torch.tensor(self._df.loc[:,"obj":"ci3"].values)
