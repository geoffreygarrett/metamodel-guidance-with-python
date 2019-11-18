import skopt
from sklearn.externals import joblib


class SurrogateModelBaseRegression:

    @classmethod
    def skopt_mapping(cls, type):
        try:
            assert type in ["integer", "real", "categorical"]
        except AssertionError:
            AssertionError("type={} not recognised.".format(type))
        return {"integer": skopt.space.Integer,
                "real": skopt.space.Real,
                "categorical": skopt.space.Categorical}[type]

    def __init__(self):
        self._hyper_params = None
        self._default_params = None
        self._static_params = None

        self._trainer = None
        self._model_cls = None
        self._model = None

    def hyper_params_x(self, x):
        new_keys = []
        for key in self._hyper_params.keys():
            new_keys.append(key.split("__")[-1])
        return dict(zip(new_keys, x))

    def reset_model(self):
        self._model = None

    @property
    def model(self):
        if self._model is None:
            # print(self.all_params)
            self._model = self._model_cls(self.all_params)
        else:
            pass
        return self._model

    @property
    def all_params(self):
        return {**self.default_params, **self.hyper_params,
                **self.static_params}

    @property
    def space(self):
        _space = []
        for key, value in self.hyper_params.items():
            _type, _name = key.split("__")
            _space.append(self.skopt_mapping(_type)(*value, name=_name))
        return _space

    def fit(self, X=None, y=None, **kwargs):
        """
        :param X:
        :param y:
        :return:
        """
        try:
            self.model.fit(X, y)
        except AttributeError:
            raise NotImplementedError(
                "Either base used, which has no model attribute, or default .fit method doesn't exist for model."
            )

    def score(self, X, y, sample_weight=None, **kwargs):
        """

        :param X:
        :param y:
        :param sample_weight:
        :return:
        """
        try:
            return self.model.score(X, y, sample_weight=sample_weight)
        except AttributeError:
            raise NotImplementedError(
                "Either base used, which has no model attribute, or default .score method doesn't exist for model."
            )

    def predict(self, X, **kwargs):
        """
        Method to return prediction based on input.
        :param X:
        :return:
        """
        try:
            return self.model.predict(X)

        except AttributeError:
            raise NotImplementedError(
                "Either base used, which has no model attribute, or default .predict method doesn't exist for model."
            )

    def save(self, path, **kwargs):
        """

        :param path:
        :return:
        """
        joblib.dump(self._model, path)

    def load(self, path, **kwargs):
        """

        :param path:
        :return:
        """
        self._model = joblib.load(path)
