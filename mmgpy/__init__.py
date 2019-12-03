import os

# TODO: Fix code detection on github with github-linguist. Over reporting of
#  jupyter.

DATA_DIR = os.path.join(os.getcwd(), "../data")
TRAINED_MODELS_DIR = os.path.join(os.getcwd(), "../models")
SIMULATION_DIR = os.path.join(os.getcwd(), "../simulation")
DOE_DIR = os.path.join(os.getcwd(), "../simulation")

__all__ = ["sampling",
           "problems",
           "optimise",
           "metamodel",
           "matlab",
           "plotting",
           "benchmark"]
