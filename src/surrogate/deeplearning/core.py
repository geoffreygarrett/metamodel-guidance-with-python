import pandas as pd
import torch
import sys
import os

from .util import save_checkpoint
from .util import load_checkpoint
from .util import save_general_checkpoint
from .util import save_model_state_dict
from .util import load_model_state_dict
from .util import save_entire_model
from .util import load_entire_model
from .util import load_general_checkpoint
from .util import get_lr


class Trainer:
    def __init__(self, PATH, dataset, model=None, optimizer=None, criterion=None, batch_size=200,
                 num_epochs=150, learning_rate=1e-2):
        self._path = PATH
        self._dataset = dataset
        self._model = model
        self._optimizer = optimizer(model.parameters(), lr=learning_rate) if optimizer is not None else None
        self._criterion = criterion()

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


class Trainer2:

    @staticmethod
    def load_inference_model_pickle(path):
        return load_entire_model(path)

    @staticmethod
    def load_inference_model_state(path, model):
        return load_model_state_dict(model, path)

    @staticmethod
    def ensure_path_exists(path):
        if os.path.exists(path):
            pass
        else:
            os.mkdir(path)
        return path

    @staticmethod
    def ensure_unique_path_exists(path, tail=False):
        if os.path.exists(path):
            extension = 0
            while os.path.exists(path + "_" + str(extension)):
                extension += 1
            os.mkdir(path + "_" + str(extension))

        else:
            os.mkdir(path)

        if tail:
            return os.path.split(path)[-1]
        else:
            return path

    def __init__(self, PATH,
                 training_dataset,
                 testing_dataset,
                 validation_dataset,
                 model=None,
                 optimizer=None,
                 criterion=None,
                 batch_size=200,
                 num_epochs=150,
                 learning_rate=1e-2):

        # Ensure unique path exists to avoid saving over existing.
        self._path = self.ensure_unique_path_exists(PATH)

        # Various datasets for model training.
        self._training_dataset = training_dataset
        self._testing_dataset = testing_dataset
        self._validation_dataset = validation_dataset

        # Load components of the training.
        self._model = model
        self._optimizer = optimizer(model.parameters(), lr=learning_rate) if optimizer is not None else None
        self._criterion = criterion()
        self._loss = None
        self._scheduler = None

        # Device configuration
        self._device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        self._batch_size = batch_size
        self._num_epochs = num_epochs
        self._learning_rate = learning_rate
        self._train_log = pd.DataFrame(columns=["epoch", "train_loss", "test_loss", "learning_rate"])
        self._epoch = 0
        self._model.to(self._device)

    def add_scheduler(self, scheduler, **kwargs):
        self._scheduler = scheduler(self._optimizer, **kwargs)

    @property
    def learning_rate(self):
        return self._learning_rate

    @property
    def num_epochs(self):
        return self._num_epochs

    @learning_rate.setter
    def learning_rate(self, x):
        self._learning_rate = x

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

    def _validation_loader(self, validation_dataset):
        return torch.utils.data.DataLoader(dataset=validation_dataset,
                                           batch_size=self._batch_size,
                                           shuffle=True)

    def _train(self, verbose,
               early_stopping=None,
               save_each_epoch=True,
               save_final_model=True,
               plot_jupyter=False):

        # ██████╗  █████╗ ████████╗ █████╗     ██╗      ██████╗  █████╗ ██████╗ ███████╗██████╗ ███████╗
        # ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗    ██║     ██╔═══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝
        # ██║  ██║███████║   ██║   ███████║    ██║     ██║   ██║███████║██║  ██║█████╗  ██████╔╝███████╗
        # ██║  ██║██╔══██║   ██║   ██╔══██║    ██║     ██║   ██║██╔══██║██║  ██║██╔══╝  ██╔══██╗╚════██║
        # ██████╔╝██║  ██║   ██║   ██║  ██║    ███████╗╚██████╔╝██║  ██║██████╔╝███████╗██║  ██║███████║
        # ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝
        train_loader = self._train_loader(self._training_dataset)
        test_loader = self._test_loader(self._testing_dataset)
        validation_loader = self._validation_loader(self._validation_dataset)

        # ████████╗██████╗  █████╗ ██╗███╗   ██╗██╗███╗   ██╗ ██████╗
        # ╚══██╔══╝██╔══██╗██╔══██╗██║████╗  ██║██║████╗  ██║██╔════╝
        #    ██║   ██████╔╝███████║██║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗
        #    ██║   ██╔══██╗██╔══██║██║██║╚██╗██║██║██║╚██╗██║██║   ██║
        #    ██║   ██║  ██║██║  ██║██║██║ ╚████║██║██║ ╚████║╚██████╔╝
        #    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝
        for epoch in range(self._epoch, self._num_epochs):
            self._epoch = epoch
            epoch_train_loss = 0
            epoch_test_loss = 0
            epoch_validation_loss = 0

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

            # POST TRAINING
            train_loss_item = epoch_train_loss / len(train_loader)

            # ████████╗███████╗███████╗████████╗██╗███╗   ██╗ ██████╗
            # ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██║████╗  ██║██╔════╝
            #    ██║   █████╗  ███████╗   ██║   ██║██╔██╗ ██║██║  ███╗
            #    ██║   ██╔══╝  ╚════██║   ██║   ██║██║╚██╗██║██║   ██║
            #    ██║   ███████╗███████║   ██║   ██║██║ ╚████║╚██████╔╝
            #    ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝
            # In test phase, we don't need to compute gradients (for memory efficiency)
            with torch.no_grad():

                for x, y in test_loader:
                    x = x.to(self._device)
                    y = y.to(self._device)

                    outputs = self._model(x.float())
                    loss = self._criterion(outputs, y.float())
                    epoch_test_loss += loss.item()

            # POST TESTING
            test_loss_item = epoch_test_loss / len(test_loader)

            # ██╗   ██╗ █████╗ ██╗     ██╗██████╗  █████╗ ████████╗██╗ ██████╗ ███╗   ██╗
            # ██║   ██║██╔══██╗██║     ██║██╔══██╗██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║
            # ██║   ██║███████║██║     ██║██║  ██║███████║   ██║   ██║██║   ██║██╔██╗ ██║
            # ╚██╗ ██╔╝██╔══██║██║     ██║██║  ██║██╔══██║   ██║   ██║██║   ██║██║╚██╗██║
            #  ╚████╔╝ ██║  ██║███████╗██║██████╔╝██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║
            #   ╚═══╝  ╚═╝  ╚═╝╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝
            # In test phase, we don't need to compute gradients (for memory efficiency)
            with torch.no_grad():

                for x, y in validation_loader:
                    x = x.to(self._device)
                    y = y.to(self._device)

                    outputs = self._model(x.float())
                    loss = self._criterion(outputs, y.float())
                    epoch_validation_loss += loss.item()

            # POST VALIDATION
            validation_loss_item = epoch_validation_loss / len(validation_loader)

            # ██████╗  ██████╗ ███████╗████████╗    ███████╗██████╗  ██████╗  ██████╗██╗  ██╗
            # ██╔══██╗██╔═══██╗██╔════╝╚══██╔══╝    ██╔════╝██╔══██╗██╔═══██╗██╔════╝██║  ██║
            # ██████╔╝██║   ██║███████╗   ██║       █████╗  ██████╔╝██║   ██║██║     ███████║
            # ██╔═══╝ ██║   ██║╚════██║   ██║       ██╔══╝  ██╔═══╝ ██║   ██║██║     ██╔══██║
            # ██║     ╚██████╔╝███████║   ██║       ███████╗██║     ╚██████╔╝╚██████╗██║  ██║
            # ╚═╝      ╚═════╝ ╚══════╝   ╚═╝       ╚══════╝╚═╝      ╚═════╝  ╚═════╝╚═╝  ╚═╝
            # LOGGING.
            learning_rate = get_lr(self._optimizer)
            self._train_log = pd.concat([self._train_log, pd.DataFrame({"epoch": [self._epoch + 1],
                                                                        "train_loss": [train_loss_item],
                                                                        "test_loss": [test_loss_item],
                                                                        "validation_loss": [validation_loss_item],
                                                                        "learning_rate": [learning_rate]})])

            # Use scheduler if present.
            if self._scheduler:
                self._scheduler.step()

            # Verbosity printouts if desired.
            if verbose:
                if verbose is True:
                    print(
                        f'Epoch [{self._epoch + 1:^5}/{self._num_epochs:^5}]  |  Train Loss: {train_loss_item: 8.6f}  |  Test Loss: {test_loss_item: 8.6f}  |  lr: {learning_rate: 6.5f}')
                elif type(verbose) is int:
                    if self._epoch % verbose == 0:
                        print(
                            f'Epoch [{self._epoch + 1:^5}/{self._num_epochs:^5}]  |  Train Loss: {train_loss_item: 8.6f}  |  Test Loss: {test_loss_item: 8.6f}  |  lr: {learning_rate: 6.5f}')

            if save_each_epoch:
                self.save_general_epoch_checkpoint()

            # Early stopping if provided.
            if early_stopping is not None:
                # early_stopping needs the validation loss to check if it has decreased,
                # and if it has, it will make a checkpoint of the current model
                early_stopping(epoch_validation_loss, self._model)

                if early_stopping.early_stop:
                    print("Early stopping...")
                    # self.save_final_checkpoint() if save else None
                    break

        if save_final_model:
            self.save_final_model()

        return self._train_log

    def train(self, verbose=False,
               early_stopping=None,
               save_each_epoch=True,
               save_final_model=True,
               plot_jupyter=False):
        try:
            return self._train(verbose,
                               early_stopping,
                               save_each_epoch,
                               save_final_model,
                               plot_jupyter
                               )
        except KeyboardInterrupt:
            print('Interrupted')
            self.save_general_epoch_checkpoint()
            sys.exit(0)

    def load_last_checkpoint(self, path):
        try:
            TRAIN_LOG_PATH = os.path.join(self._path, "train_log.csv")
            CHECKPOINT_PATH = os.path.join(self._path, "checkpoints")
            CHECKPOINT_NAME = os.path.split(os.listdir(CHECKPOINT_PATH)[-1])[-1]
        except FileNotFoundError:
            raise FileNotFoundError("No checkpoints detected for current path of trainer.")

        self._path = path
        self._train_log = pd.read_csv(TRAIN_LOG_PATH)
        self._model, self._optimizer, self._epoch, self._loss = load_general_checkpoint(self._model,
                                                                                        self._optimizer,
                                                                                        path=CHECKPOINT_PATH,
                                                                                        name=CHECKPOINT_NAME)

    def load_checkpoint_epoch(self, path, epoch):
        try:
            TRAIN_LOG_PATH = os.path.join(self._path, "train_log.csv")
            CHECKPOINT_PATH = os.path.join(self._path, "checkpoints")
            CHECKPOINT_NAME = "checkpoint_" + str(epoch) + ".pt"
        except FileNotFoundError:
            raise FileNotFoundError("No checkpoints detected for current path of trainer.")

        self._path = path
        self._train_log = pd.read_csv(TRAIN_LOG_PATH)
        self._model, self._optimizer, self._epoch, self._loss = load_general_checkpoint(self._model,
                                                                                        self._optimizer,
                                                                                        path=CHECKPOINT_PATH,
                                                                                        name=CHECKPOINT_NAME)

    def save_general_epoch_checkpoint(self):
        TRAIN_LOG_PATH = os.path.join(self._path, "train_log.csv")
        CHECKPOINT_PATH = self.ensure_path_exists(os.path.join(self._path, "checkpoints"))
        CHECKPOINT_NAME = 'checkpoint_' + str(self._epoch)

        self._train_log.to_csv(TRAIN_LOG_PATH, index=False)
        save_general_checkpoint(self._model, self._optimizer, self._epoch, self._loss,
                                path=CHECKPOINT_PATH,
                                name=CHECKPOINT_NAME)

    def save_final_model(self, type={'model_state_dict'}):
        _allowed_type = {'model_state_dict', 'model_pickle'}

        try:
            assert type.issubset(_allowed_type)
        except AssertionError:
            raise AssertionError("Argument for save_final_model(type=X) must be in: ", _allowed_type)

        self._train_log.to_csv(os.path.join(self._path, "train_log.csv"), index=False)

        if 'model_state_dict' in type:
            save_model_state_dict(self._model, self._path)

        if 'model_pickle' in type:
            save_entire_model(self._model, self._path)

