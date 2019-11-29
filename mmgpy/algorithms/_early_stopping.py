import numpy as np


def generalisation_loss(error_validation):
    _error_opt = np.min(error_validation)
    return 100 * (error_validation[-1] / _error_opt - 1)


def progress(error_training, k):
    return 1000 * (np.sum(error_training[-k:]) /
                   (k * (np.min(error_training[-k:]))) - 1)


class LutzPrecheltEarlyStopping:

    @staticmethod
    def pq_a(error_validation, error_training, alpha, k):
        _generalisation_loss = generalisation_loss(error_validation)
        _progress = progress(error_training, k)
        return _generalisation_loss / _progress > alpha

    @staticmethod
    def gl_a(error_validation, alpha):
        _error_opt = np.min(error_validation)
        _generalisation_loss = generalisation_loss(error_validation)
        return _generalisation_loss > alpha

    @staticmethod
    def up_s(error_validation, s, k):
        s = int(s)
        count = 0
        strip_list = error_validation[::-1][::k][:s + 1]
        if len(strip_list) > s:
            for strip in range(s):
                if strip_list[strip] > strip_list[strip + 1]:
                    count += 1
                else:
                    count = 0
            if count == s:
                return True
            else:
                return False
        else:
            return False

    def __init__(self, k=10, verbose=False, criteria=(("PQ", 2.0), ("UP", 6)),
                 terminate_on="all"):
        """

        Parameters
        ----------
        k
        verbose
        criteria
        terminate_on

        References
        ----------
        ..  [1]

        """
        self.k = k
        self.verbose = verbose
        self.early_stop = False
        self.criteria = criteria
        self.terminate_on = terminate_on
        self.error_validation_history = [np.Inf] * k
        self.error_training_history = [np.Inf] * k

    def eval_criteria(self):
        """
        :return:
        """
        result = []
        for cls, arg in self.criteria:
            if cls == "PQ":
                result.append(self.pq_a(self.error_validation_history,
                                        self.error_training_history, arg,
                                        self.k))
            elif cls == "UP":
                result.append(
                    self.up_s(self.error_validation_history, arg, self.k))

            elif cls == "GL":
                result.append(self.gl_a(self.error_validation_history, arg))
        return result

    def __call__(self, val_loss, train_loss):
        self.error_validation_history.append(val_loss)
        self.error_training_history.append(train_loss)

        if self.terminate_on == "all":
            self.early_stop = np.all(self.eval_criteria())

        elif self.terminate_on == "any":
            self.early_stop = np.any(self.eval_criteria())

        else:
            raise AssertionError("<terminate_on> argument not recognised.")


if __name__ == "__main__":
    test_obj = [LutzPrecheltEarlyStopping(criteria=(("GL", 1.00),)),
                LutzPrecheltEarlyStopping(criteria=(("GL", 2.00),)),
                LutzPrecheltEarlyStopping(criteria=(("GL", 3.00),)),
                LutzPrecheltEarlyStopping(criteria=(("GL", 5.00),)),
                LutzPrecheltEarlyStopping(criteria=(("PQ", 0.50),)),
                LutzPrecheltEarlyStopping(criteria=(("PQ", 0.75),)),
                LutzPrecheltEarlyStopping(criteria=(("PQ", 1.00),)),
                LutzPrecheltEarlyStopping(criteria=(("PQ", 2.00),)),
                LutzPrecheltEarlyStopping(criteria=(("PQ", 3.00),)),
                LutzPrecheltEarlyStopping(criteria=(("UP", 2.00),)),
                LutzPrecheltEarlyStopping(criteria=(("UP", 3.00),)),
                LutzPrecheltEarlyStopping(criteria=(("UP", 4.00),)),
                LutzPrecheltEarlyStopping(criteria=(("UP", 6.00),)),
                LutzPrecheltEarlyStopping(criteria=(("UP", 8.00),))]

    test_val = np.linspace(100, 0.1, 100)[::-1]
    test_tra = np.linspace(100, 0.1, 100)[::-1]
    test_eva = [False] * len(test_obj)

    for val, tra in zip(test_val, test_tra):
        for idx, t in enumerate(test_obj):
            t(val, tra)
            test_eva[idx] = t.early_stop
            # print(test_eva)
