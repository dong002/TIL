import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

cmap = cm.get_cmap('spring', lut=50)

fig, ax= plt.subplots(figsize=(10,10))
for i in range(50):
    ax.scatter(i, i, color=cmap(i))
plt.show()