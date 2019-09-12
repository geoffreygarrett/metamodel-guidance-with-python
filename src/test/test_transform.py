from dataset import DataSetFX, TransformDataFrame
from sklearn import preprocessing
from collections import OrderedDict
import os
import unittest
import pandas as pd
import pandas.testing as pd_testing

import numpy as np


class TransformTest(unittest.TestCase):

    def assertDataframeEqual(self, a, b, msg):
        try:
            pd_testing.assert_frame_equal(a, b)
        except AssertionError as e:
            raise self.failureException(msg) from e

    def setUp(self):
        self.addTypeEqualityFunc(pd.DataFrame, self.assertDataframeEqual)

        self.preprocess = OrderedDict(
            [
                ("tx1", (preprocessing.MinMaxScaler(feature_range=(-1, 1)),
                         ["x1", "x2", "x3"])),
                ("tx2", (preprocessing.Normalizer(norm='l2'),
                         ["x1", "x2", "x3"])),
                ("tx3", (preprocessing.Normalizer(norm='l2'),
                         ["x4", "x5", "x6", "x7"])),
                ("tf1", (preprocessing.MinMaxScaler(feature_range=(0, 1)),
                         ["f1", "f2", "f3", "f4"]))
            ])

        self.transform_test = TransformDataFrame.from_ordered_dict(self.preprocess)

        self.transform_test.add_filter(to_step="pre", condition=lambda x: x <= 0.05, target=["x4", "x5", "x6", "x7"])

        self.transform_test.add_feature(from_step="tx1",
                                        operation=[np.square, (np.sum, {"axis": 1}), np.sqrt],
                                        target=["x1", "x2", "x3"],
                                        feature_name="x8",
                                        documentation="Magnitude of angular rate vector.")

        self.test_ds = DataSetFX.from_parquet(file_name="dataSet_gridSampled_3.parquet", root_dir="test_data")

    def test_case_1(self):
        df = pd.read_parquet("test_data/dataSet_gridSampled_3.parquet")

        tx1 = preprocessing.MinMaxScaler(feature_range=(-1, 1))
        tx2 = preprocessing.Normalizer(norm='l2')
        tx3 = preprocessing.Normalizer(norm='l2')
        tf1 = preprocessing.MinMaxScaler(feature_range=(0, 1))

        # pre_filter_0
        df.drop(index=df[df["x4"] <= 0.05].index, inplace=True)
        df.drop(index=df[df["x5"] <= 0.05].index, inplace=True)
        df.drop(index=df[df["x6"] <= 0.05].index, inplace=True)
        df.drop(index=df[df["x7"] <= 0.05].index, inplace=True)

        # tx1 (transform) -> ["x1", "x2", "x3"]
        df.loc[:, "x1":"x3"] = tx1.fit_transform(df.loc[:, "x1":"x3"].values)

        # tx1 (feature) -> ["x8"]
        df["x8"] = np.sqrt(np.sum(np.square(df.loc[:, "x1":"x3"].values), axis=1))

        # tx2 -> ["x1", "x2", "x3"]
        df.loc[:, "x1":"x3"] = tx2.fit_transform(df.loc[:, "x1":"x3"].values)

        # tx3 -> ["x4", "x5", "x6", "x7"]
        df.loc[:, "x4":"x7"] = tx3.fit_transform(df.loc[:, "x4":"x7"].values)

        # tf1 -> ["f1", "f2", "f3", "f4"]
        df.loc[:, "f1":"f4"] = tf1.fit_transform(df.loc[:, "f1":"f4"].values)

        transformed = self.transform_test(self.test_ds.get_df())

        self.assertEqual(df, transformed)


if __name__ == '__main__':
    unittest.main()
