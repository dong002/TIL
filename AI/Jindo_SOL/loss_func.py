
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
t_a, t_b = 3, -1
N = 2

00
X = np.random.normal(loc=0, scale=1, size=(N, ))
noise = 0.3*np.random.normal(loc=0, scale=1, size=(N, ))
Y = t_a * X + t_b
Y = Y+noise

a,b = -2, 5
X_min, X_max = X.min(), X.max()
Y_min = a*X_min + b
Y_max = a*X_max + b

fig, ax= plt.subplots(figsize=(10,10))
ax.scatter(X, Y, alpha=0.5)
ax.plot([X_min, X_max], [Y_min, Y_max])

ax.axvline(x=0, linestyle=":", linewidth=1)
ax.axhline(y=0, linestyle=":", linewidth=1)

learning_rate = 0.01
iteration = 100
cmap = cm.get_cmap('spring',lut=iteration)

fig2, ax2 = plt.subplots(figsize=(10,5))
ax2.axhline(y=t_a, color='red', linestyle=":")
ax2.axhline(y=t_b, color='blue', linestyle=":")

for i in range(N):
    x,y = X[i], Y[i]
    pred = a*x+b

    diff_a = 2*(y-pred)*(-x)
    diff_b = 2*(y-pred)*(-1)

    a = a - learning_rate * diff_a
    b = b - learning_rate * diff_b

    X_min, X_max = X.min(), X.max()
    Y_min = a*X_min + b
    Y_max = a*X_max + b
    ax.plot([X_min, X_max], [Y_min, Y_max])

plt.show()