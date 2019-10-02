import pandas as pd
import torch
import sys
import os


# Saving & Loading a General Checkpoint for Inference and/or Resuming Training
def save_checkpoint(PATH, epoch, model, optimizer, loss):
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


def get_lr(optimizer):
    for param_group in optimizer.param_groups:
        return param_group['lr']


class Trainer:
    def __init__(self, PATH, dataset, model=None, optimizer=None, criterion=None, preprocessing=None, batch_size=200,
                 num_epochs=150, learning_rate=1e-2):
        self._path = PATH
        self._dataset = dataset
        self._model = model
        self._optimizer = optimizer(model.parameters(), lr=learning_rate) if optimizer is not None else None
        self._criterion = criterion()
        self._preprocessing = preprocessing

        self._loss = None

        if os.path.exists(PATH):
            pass
        else:
            os.mkdir(PATH)
        self._scheduler = None
        # Device configuration
        self._device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        self._batch_size = batch_size
        self._num_epochs = num_epochs
        self._learn_rate = learning_rate
        self._train_log = pd.DataFrame(columns=["epoch", "train_loss", "test_loss", "learning_rate"])
        self._epoch = 0
        self._model.to(self._device)

    def add_scheduler(self, scheduler, **kwargs):
        self._scheduler = scheduler(self._optimizer, **kwargs)

    @property
    def learning_rate(self):
        return self._learning_rate

    @property
    def batch_size(self):
        return self._batch_size

    @property
    def num_epochs(self):
        return self._num_epochs

    @learning_rate.setter
    def learning_rate(self, x):
        self._learning_rate = x

    @batch_size.setter
    def batch_size(self, x):
        self._batch_size = x

    @num_epochs.setter
    def num_epochs(self, x):
        self._num_epochs = x

    def _train_loader(self, training_dataset):
        return torch.utils.data.DataLoader(dataset=training_dataset,
                                           batch_size=self._batch_size,
                                           shuffle=True)

    def _test_loader(self, test_dataset):
        return torch.utils.data.DataLoader(dataset=test_dataset,
                                           batch_size=self._batch_size,
                                           shuffle=True)

    def preprocess(self, f):
        if self.preprocessing:
            return self.preprocessing(f)
        else:
            return f

    def _train(self):

        _test_ds, _train_ds = self._dataset.train_test_split()
        train_loader = self._train_loader(_train_ds)
        test_loader = self._test_loader(_test_ds)

        # Train model.
        for epoch in range(self._epoch, self._num_epochs):
            self._epoch = epoch
            epoch_train_loss = 0
            epoch_test_loss = 0

            # Training.
            for i, (x, y) in enumerate(train_loader):
                # Move tensors to the configured device
                x = x.to(self._device)
                y = y.to(self._device)

                # Forward pass
                outputs = self._model(x.float())
                self._loss = self._criterion(outputs, y.float())

                # Backward and optimize
                self._optimizer.zero_grad()
                self._loss.backward(retain_graph=False)
                self._optimizer.step()
                epoch_train_loss += self._loss.item()

            train_loss_item = epoch_train_loss / len(train_loader)

            # Test the model
            # In test phase, we don't need to compute gradients (for memory efficiency)
            with torch.no_grad():

                for x, y in test_loader:
                    x = x.to(self._device)
                    y = y.to(self._device)

                    outputs = self._model(x.float())
                    self._loss = self._criterion(outputs, y.float())
                    epoch_test_loss += self._loss.item()
            learning_rate = get_lr(self._optimizer)
            test_loss_item = epoch_test_loss / len(test_loader)
            self._train_log = pd.concat([self._train_log, pd.DataFrame({"epoch": [self._epoch + 1],
                                                                        "train_loss": [train_loss_item],
                                                                        "test_loss": [test_loss_item],
                                                                        "learning_rate": [learning_rate]})])
            if self._scheduler:
                self._scheduler.step()

            print(
                f'Epoch [{self._epoch + 1:^5}/{self._num_epochs:^5}]  |  Train Loss: {train_loss_item: 8.6f}  |  Test Loss: {test_loss_item: 8.6f}  |  lr: {learning_rate: 6.5f}')
        self.save_checkpoint()

    def train(self):
        try:
            self._train()
        except KeyboardInterrupt:
            print('Interrupted')
            self.save_checkpoint()
            sys.exit(0)

    def load_checkpoint(self, PATH):
        self._path = PATH
        self._train_log = pd.read_csv(os.path.join(PATH, "train_log.csv"))
        # self._epoch, self._model, self._optimizer, self._loss =
        load_checkpoint(self, PATH)

    def save_checkpoint(self):
        self._train_log.to_csv(os.path.join(self._path, "train_log.csv"), index=False)
        save_checkpoint(self._path, self._epoch, self._model, self._optimizer, self._loss)

#     def predict(self, x):
#         if self.preprocessing:
#             return self.preprocessing(f)
#         else:
#             return f
