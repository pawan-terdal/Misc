"""Fit a Line."""

import numpy as np
from keras.models import Sequential
from keras.layers.core import Dense

trainX = np.arange(start=0, stop=1000)
trainY = np.array([(2*i + 3) for i in trainX])

model = Sequential()
model.add(Dense(1, input_dim=1))
# model.add(Dense(8))
model.add(Dense(1))

model.compile(loss="mean_squared_error",
              optimizer="adam")

model.fit(trainX, trainY, epochs=500, verbose=2)
print(model.predict(np.array([-100])))
