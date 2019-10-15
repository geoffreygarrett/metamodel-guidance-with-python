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

    def __init__(self, patience=7, verbose=False, delta=0):
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
        self.delta = delta

    def __call__(self, val_loss, model):

        score = val_loss

        if self.best_score is None:
            self.best_score = score
            # self.save_checkpoint(val_loss, model)
        elif score < self.best_score - self.delta:
            self.counter += 1
            print(f'EarlyStopping counter: {self.counter} out of {self.patience}')
            if self.counter >= self.patience:
                self.early_stop = True
        else:
            self.best_score = score
            # self.save_checkpoint(val_loss, model)
            self.counter = 0

    # def save_checkpoint(self, val_loss, model):
    #     '''Saves model when validation loss decrease.'''
    #     if self.verbose:
    #         print(f'Validation loss decreased ({self.val_loss_min:.6f} --> {val_loss:.6f}).  Saving model ...')
    #     torch.save(model.state_dict(), 'checkpoint.pt')
    #     self.val_loss_min = val_loss
