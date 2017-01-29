import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

x = np.arange(-3, 3, 0.001)
plt.plot(x, stats.norm.pdf(x))
plt.show()