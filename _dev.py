from dataset import DataSetFX, TransformDataFrame
from sklearn import preprocessing
from collections import OrderedDict
import numpy as np

import pandas as pd

transform = TransformDataFrame.from_ordered_dict(OrderedDict([
    ("tx1", (preprocessing.MinMaxScaler(feature_range=(-1, 1)), ["x1", "x2", "x3"])),
    ("tx2", (preprocessing.Normalizer(norm='l2'), ["x1", "x2", "x3"])),
    ("tx3", (preprocessing.Normalizer(norm='l2'), ["x4", "x5", "x6", "x7"])),
    ("fx1", (preprocessing.MinMaxScaler(feature_range=(0, 1)), ["f1", "f2", "f3", "f4"]))
]
))

# transform.add_feature(which="tx1",
#                       operation=[(np.square, {"axis": 1}), (np.sum, {"axis": 1}), np.sqrt],
#                       target=["x1", "x2", "x3"])

transform.add_filter(step="pre",
                     condition=lambda x: x <= 0.05,
                     target=["x4", "x5", "x6", "x7"])

print(transform._steps)

ds1 = DataSetFX.from_parquet(
    file_name="dataSet_gridSampled_3.parquet",
    root_dir="data",
    # transform=transform
)

print(transform(ds1.get_df()))

# ds1_train, ds1_test = ds1.train_test_split()

# ds2 = DataSetFX.from_parquet(
#     file_name="dataSet_gridSampled_3.parquet",
#     root_dir="data",
#     transform=TransformFX
# )

# print(ds1.output.size)
#
# # print(ds1[1])
#
# print("train len -l: ", len(ds1_train))
# print("train len -o: ", ds1_train.output.shape)
# print("\n")
# print("test len: -l", len(ds1_test))
# print("test len: -o", ds1_test.input.shape)

# print(ds1_train.output.size)


# df = ds1.get_df()
# print(df.name)
# print(train.get_df().name)
# print(test.get_df().name)
