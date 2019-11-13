import torch
import os
import numpy as np


# Saving & Loading Model for Inference
# https://pytorch.org/tutorials/beginner/saving_loading_models.html#save-load-state-dict-recommended
def save_model_state_dict(model, path, name="model_state_dict"):
    torch.save(model.state_dict(), os.path.join(path, name + ".pt"))


def load_model_state_dict(model, path, name="model_state_dict"):
    """
    * Note that this function is for inference and therefore model.eval() is already called. Training should not
    be resumed using this function.
    :param path:
    :param model:
    :param name:
    :return:
    """
    model.load_state_dict(os.path.join(path, name + ".pt"))
    model.eval()
    return model


# Save/Load Entire Model
# https://pytorch.org/tutorials/beginner/saving_loading_models.html#save-load-entire-model
def save_entire_model(model, path, name='pickled_model'):
    torch.save(model, os.path.join(path, name + ".pt"))


def load_entire_model(path, name="pickled_model"):
    # Model class must be defined somewhere
    model = torch.load(os.path.join(path, name + ".pt"))
    model.eval()


# Saving & Loading a General Checkpoint for Inference and/or Resuming Training
# https://pytorch.org/tutorials/beginner/saving_loading_models.html#saving-loading-a-general-checkpoint-for-inference-and-or-resuming-training
def save_general_checkpoint(model, optimizer, epoch, loss, path, name="checkpoint"):
    torch.save({'epoch': epoch,
                'model_state_dict': model.state_dict(),
                'optimizer_state_dict': optimizer.state_dict(),
                'loss': loss},
               os.path.join(path, name + '.pt'))


def load_general_checkpoint(model, optimizer, path, name='checkpoint'):
    checkpoint = torch.load(os.path.join(path, name + ".pt"))
    model.load_state_dict(checkpoint['model_state_dict'])
    optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
    epoch = checkpoint['epoch']
    loss = checkpoint['loss']
    return model, optimizer, epoch, loss


def get_lr(optimizer):
    for param_group in optimizer.param_groups:
        return param_group['lr']


# Saving & Loading a General Checkpoint for Inference and/or Resuming Training
def save_checkpoint(epoch, model, optimizer, loss, PATH):
    torch.save({'epoch': epoch,
                'model_state_dict': model.state_dict(),
                'optimizer_state_dict': optimizer.state_dict(),
                'loss': loss},
               os.path.join(PATH, "model.ckpt"))


def load_checkpoint(trainer, PATH):
    checkpoint = torch.load(os.path.join(PATH, "model.ckpt"))
    trainer._model.load_state_dict(checkpoint['model_state_dict'])
    trainer._optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
    trainer._epoch = checkpoint['epoch']
    trainer._loss = checkpoint['loss']


class EarlyStopping:
    """Early stops the training if validation loss doesn't improve after a given patience."""

    def __init__(self, patience=7, verbose=False, abs_delta=None, rel_delta=None):
        """
        Args:
            patience (int): How long to wait after last time validation loss improved.
                            Default: 7
            verbose (bool): If True, prints a message for each validation loss improvement.
                            Default: False
            delta (float): Minimum change in the monitored quantity to qualify as an improvement.
                            Default: 0
        """
        self.patience = patience
        self.verbose = verbose
        self.counter = 0
        self.best_score = None
        self.early_stop = False
        self.val_loss_min = np.Inf
        self.abs_delta = abs_delta
        self.rel_delta = rel_delta

    def __call__(self, val_loss, model):

        score = -val_loss
        delta = np.max([
            np.abs(val_loss * self.best_score) if self.abs_delta else 0.0,
            self.abs_delta if self.abs_delta else 0.0,
        ])
        if self.best_score is None:
            self.best_score = score
            # self.save_checkpoint(val_loss, model)
        elif score < self.best_score - delta:
            self.counter += 1
            print(f'EarlyStopping counter: {self.counter} out of {self.patience}') if self.verbose else None
            if self.counter >= self.patience:
                self.early_stop = True
        else:
            self.best_score = score
            # self.save_checkpoint(val_loss, model)
            self.counter = 0


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

    def __init__(self, k=5, verbose=False, criteria=(("PQ", 2.0), ("UP", 6)), terminate_on="all"):
        """

        :param k:
        :param verbose:
        :param criteria:
        :param terminate_on: "all" or "any"
        """
        self.k = k
        self.verbose = verbose
        self.early_stop = False
        self.criteria = criteria
        self.terminate_on = terminate_on
        self.error_validation_history = []
        self.error_training_history = []

    def eval_criteria(self):
        """
        :return:
        """
        result = []
        for cls, arg in self.criteria:
            if cls == "PQ":
                result.append(self.pq_a(self.error_validation_history, self.error_training_history, arg, self.k))

            elif cls == "UP":
                result.append(self.up_s(self.error_validation_history, arg, self.k))

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
