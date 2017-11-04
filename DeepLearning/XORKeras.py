"""XOR Keras."""

import numpy as np
from keras.models import Sequential
from keras.layers.core import Dense

trainX = np.array([[0, 0], [0, 1], [1, 0], [1, 1]], dtype="float32")
trainY = np.array([[0], [1], [1], [0]], dtype="float32")

model = Sequential()
model.add(Dense(16, input_dim=2, activation="relu"))
# model.add(Dense(8, activation="relu"))
model.add(Dense(1, activation="sigmoid"))

model.compile(loss="mean_squared_error",
              optimizer="adam",
              metrics=["binary_accuracy"])

model.fit(trainX, trainY, epochs=500, verbose=2)

print(model.predict(trainX).round())
