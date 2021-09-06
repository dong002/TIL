import numpy as np
from scipy import stats
np.random.seed(0)
data_A = np.random.randint(0,100,10000)
mean = np.mean(data_A)
median = np.median(data_A)
mode = stats.mode(data_A)
print(mean.round(2))
print(median)
print("{} ({})". format(mode[0][0]. mode[1][0]))