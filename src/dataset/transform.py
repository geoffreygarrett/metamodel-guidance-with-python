import inspect
from collections import OrderedDict
from copy import deepcopy

import pandas as pd


# inspect.signature()
# ArgSpec(args=['self', 'a', 'b'], varargs=None

class TransformBase:
    class Step:

        def __init__(self, obj, type, target, method=None, wrapper=None, **kwargs):
            # try:
            #     if method is None:
            #         assert callable(obj)
            #     else:
            #         assert callable(getattr(obj, method))
            # except AssertionError:
            #     raise AttributeError("Provided object is not callable.") if method is None else AttributeError(
            #         "Object method is not callable.")

            self._type = type
            self._object = obj
            self._method = method
            self._target = target
            self._wrapper = wrapper
            self._kwargs = kwargs
            self.__doc__ = self.__repr__()

        def __call__(self, data):
            return self.wrapper(self._object, self._target, **self._kwargs)(
                data) if self._method is None else self.wrapper(getattr(self._object,
                                                                        self._method), self._target, **self._kwargs)(
                data)

        def __repr__(self):
            return f"{str(self._object)}"

        @property
        def wrapper(self):
            return self._wrapper

        @property
        def target(self):
            return self._target

        @property
        def object(self):
            return self._object

    def __init__(self, data_type=None):
        self._data_type = data_type
        self._step_names = []
        self._target = []

    def __call__(self, data, return_step="post", inplace=True):

        # Apply each step to the DataFrame.
        for step_name in self._step_names:

            # Apply step to DataFrame.
            getattr(self, step_name)(data)

            # If output of specific step is desired <return_step> argument will allow this.
            if step_name == return_step:
                break

        return data

    def __repr__(self):
        _names = self._step_names
        _documents = [str(getattr(self, name).__doc__) for name in self._step_names]
        _targets = [str(getattr(self, name).target) for name in self._step_names]

        _max_name_len = max(map(lambda x: len(x), _names))
        _max_document = max(map(lambda x: len(str(x)), _documents))
        _max_target_L = max(map(lambda x: len(str(x)), _targets))

        # print(_max_name_len)
        _header = []
        _pipeline_structure = [
            f"Step {idx}: ({name:{_max_name_len}})  | Doc: {_documents[idx]:{_max_document}}  | Target(s): {_targets[idx]:{_max_target_L}}"
            for
            idx, name in
            enumerate(_names)
        ]
        _header = '=' * max(map(lambda x: len(str(x)), _pipeline_structure))
        _footer = _header
        return "\n".join([_header] + _pipeline_structure + [_footer])

    @classmethod
    def from_ordered_dict(cls, ordered_dict: OrderedDict):
        _cls = cls()
        for key, value in ordered_dict.items():
            # Extract preprocessor and target.
            _preprocessor, _target = value if type(value) is tuple else (value, None)

            # For the case of a single target.
            _target = [_target] if (type(_target) is not list) and (_target is not None) else _target

            # Add step to steps.
            _cls._step_names.append(key)

            # Set wrapped preprocessor fit_transform method.
            setattr(_cls, f"{key}", _cls.Step(type="preprocessor",
                                              obj=_preprocessor,
                                              wrapper=cls.preprocessor_wrapper,
                                              target=_target,
                                              method="fit_transform"))

        return _cls

    @staticmethod
    def preprocessor_wrapper(function, target):
        raise NotImplementedError("preprocessor_wrapper not implemented in base Transform class.")

    @staticmethod
    def filter_wrapper(condition, target):
        raise NotImplementedError("preprocessor_wrapper not implemented in base Transform class.")

    @staticmethod
    def feature_wrapper(operation, target, feature_name):
        raise NotImplementedError("preprocessor_wrapper not implemented in base Transform class.")


class TransformDataFrame(TransformBase):

    def __init__(self, data_type=pd.DataFrame):
        super().__init__(data_type)

    @staticmethod
    def preprocessor_wrapper(function, target, **kwargs):
        def wrapper(df):
            _target = df.columns if target is None else target
            df.loc[:, _target] = function(df.loc[:, target].values)

        return wrapper

    @staticmethod
    def filter_wrapper(condition, target, **kwargs):
        def wrapper(df):
            _target = df.columns if target is None else target
            for t in _target:
                df.drop(df[condition(df.loc[:, t])].index, inplace=True)

        return wrapper

    @staticmethod
    def feature_wrapper(operation, target, **kwargs):

        feature_name = kwargs["feature_name"]

        def wrapper(df):
            # Ensure that feature_name does not already exist.
            try:
                assert feature_name not in df.columns
            except AssertionError:
                raise NameError(f"Column name: {feature_name} is already present in the DataFrame.")

            # If target argument is None, apply to entire DataFrame.
            _target = df.columns if target is None else target

            # Extract columns to operate on.
            _result = df.loc[:, _target]

            # Apply order of operations, if more than one.
            for func, kwargs in operation:
                _result = func(_result, **kwargs)

            _result_dim = len(_result.shape)

            # Update DataFrame with new feature if dim is 1.
            if _result_dim == 1:
                df[feature_name] = _result

            # Update DataFrame with new feature components if dim is > 1.
            elif _result_dim > 1:
                for i in range(_result_dim):
                    df[f"{feature_name}_{i + 1}"] = _result[:, i]

        return wrapper

    @classmethod
    def from_mat(cls, file_name, root_dir):
        pass  # TODO: Design convention for loading transinputform parameters for all transformers [MATLAB].

    @classmethod
    def from_npz(cls, file_name, root_dir):
        pass  # TODO: Design convention for loading transform parameters for all transformers [PYTHON].

    def to_mat(self, file_name, root_dir):
        pass  # TODO: Design convention for saving transform parameters for all transformers [MATLAB].

    def to_npz(self, file_name, root_dir):
        pass  # TODO: Design convention for saving transform parameters for all transformers [PYTHON].

    def add_feature(self, feature_name, operation, from_step="pre", target=None):

        # CATCHES AND CONSISTENCY.
        target = [target] if (type(target) is not list) and (target is not None) else target  # Case of a single target.

        _d = operation

        operation = [operation] if type(operation) is not list else operation  # Case of single operation.

        operation = list(
            map(lambda x: x if type(x) is tuple else (x, {}), operation))  # Case of function without kwargs.

        from_step = self._step_names[-1] if from_step is "post" else from_step  # Case of post-filtering.

        try:  # Case of non-existent step to filter.
            assert (from_step in self._step_names) or (from_step == "pre")
        except AttributeError:
            raise KeyError(f"Step {from_step} is not present in the pipeline.")

        # Define name of step.
        _attribute_name = f"{from_step}_feat_{feature_name}"

        # Set attribute to class for feature creation on DataFrame.
        _step = self.Step(type="feature", obj=operation, wrapper=self.feature_wrapper, target=target,
                          feature_name=feature_name)

        t = " -> ".join([str(func.__name__) + "(x" + str(kwargs) + ")" for func, kwargs in operation])
        t = t.replace("{}", "").replace("{", ",**{")
        _step.__doc__ = t

        setattr(self, _attribute_name, _step)

        # For the cast of pre_filtering.
        if from_step == "pre":
            self._step_names.insert(0, _attribute_name)

        # Add step to steps after to_step, and add target after to_step target.
        else:
            self._step_names.insert(self._step_names.index(from_step) + 1, _attribute_name)

    def add_filter(self, condition, to_step="pre", target=None):
        _id = 1

        # CATCHES AND CONSISTENCY.
        target = [target] if (type(target) is not list) and (target is not None) else target  # Case of a single target.

        to_step = self._step_names[-1] if to_step is "post" else to_step  # Case of post-filtering.

        # Ensure that filter is being applied to an existing step in the pipeline.
        try:
            assert (to_step in self._step_names) or (to_step == "pre")
        except AttributeError:
            raise KeyError(f"Step {to_step} is not present in the pipeline.")

        # Determine if existing filters exist, and apply to appropriate step.
        _add_after = to_step
        while True:
            _attribute_name = f"{to_step}_filter_{_id}"
            if hasattr(self, _attribute_name):
                _id += 1
                _add_after = _attribute_name
            else:
                break

        # Set attribute to class for lambda function corresponding to condition
        _filter_step = self.Step(type="filter", obj=condition, wrapper=self.filter_wrapper, target=target)
        _filter_step.__doc__ = inspect.getsource(condition).lstrip().rstrip().replace("condition=", "").replace(",", "")
        setattr(self, _attribute_name, _filter_step)

        # For the cast of pre_filtering.
        if to_step == "pre" and _id == 1:
            self._step_names.insert(0, _attribute_name)

        # Add step to steps after to_step, and add target after to_step target.
        else:
            self._step_names.insert(self._step_names.index(_add_after) + 1, _attribute_name)


if __name__ == "__main__":
    import numpy as np
    from sklearn import preprocessing

    df_orig = pd.read_parquet("test_data/dataSet_gridSampled_3.parquet")

    df = deepcopy(df_orig)

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

    print(tx1.scale_)
    print(tx1.min_)
    print(tx2.scale_)

    # tf1 -> ["f1", "f2", "f3", "f4"]
    df.loc[:, "f1":"f4"] = tf1.fit_transform(df.loc[:, "f1":"f4"].values)

    manual = df

    transform = TransformDataFrame.from_ordered_dict(OrderedDict([
        ("tx1", (preprocessing.MinMaxScaler(feature_range=(-1, 1)), ["x1", "x2", "x3"])),
        ("tx2", (preprocessing.Normalizer(norm='l2'), ["x1", "x2", "x3"])),
        ("tx3", (preprocessing.Normalizer(norm='l2'), ["x4", "x5", "x6", "x7"])),
        ("fx1", (preprocessing.MinMaxScaler(feature_range=(0, 1)), ["f1", "f2", "f3", "f4"]))
    ]
    ))

    transform.add_feature(from_step="tx1",
                          operation=[np.square, (np.sum, {"axis": 1}), np.sqrt],
                          target=["x1", "x2", "x3"],
                          feature_name="x8")

    transform.add_filter(to_step="pre",
                         condition=lambda x: x <= 0.05,
                         target=["x4", "x7"])

    df_auto = transform(deepcopy(df_orig))

    print(transform)



# print(manual)
# print(df_auto)
