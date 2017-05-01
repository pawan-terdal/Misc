"""XOR Neural Net."""

import numpy as np


def sigmoid(x):
    """The Sigmoid Function."""
    return 1 / (1 + np.exp(-x))


def NOT(x):
    """OR Neuron."""
    fx = 10 - 20 * x
    return sigmoid(fx)


def AND(x1, x2):
    """AND Neuron."""
    fx = 20 * x1 + 20 * x2 - 30
    return sigmoid(fx)


def OR(x1, x2):
    """OR Neuron."""
    fx = 20 * x1 + 20 * x2 - 10
    return sigmoid(fx)


def XORNN(x1, x2):
    """XOR Neural Net."""
    return round(OR(AND(NOT(x1), x2), AND(x1, NOT(x2))))


print("0, 0 : " + str(XORNN(0, 0)))
print("0, 1 : " + str(XORNN(0, 1)))
print("1, 1 : " + str(XORNN(1, 1)))
print("1, 0 : " + str(XORNN(1, 0)))
