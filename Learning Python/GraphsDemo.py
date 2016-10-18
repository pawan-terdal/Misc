import scipy.stats as sp
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-5,5,.5)
plt.plot(x,sp.binom.pmf(x))
plt.show()