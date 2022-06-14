
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
from regex import B

N = 100 

cmap = cm.get_cmap('spring', lut =N)
x = np.random.normal(40,5,(N,))
y = (x>40).astype(int)

a, b = -1, 38
test_x = np.linspace(30,50,100)
pred = a*test_x +b
pred = 1/(1+ np.exp(-pred))
learning_rate = 0.03
# z = a*x + b
# a = 1/(1+np.exp(-z))

fig, ax = plt.subplots(figsize=(10,5))
ax.scatter(x,y)
ax.plot(test_x, pred)

for i in range(N):
    X,Y = y[i], y[i]
    z = a*X + b
    pred = 1/(1+np.exp(-z))
    
    J = -(y*np.log(pred)+(1-y)*np.log(1-pred))

    dJ_dpred = -(y/pred - (1-y)/(1-pred))
    dJ_dz = dJ_dpred *pred * (1-pred)
    dJ_da = dJ_dz *x
    dJ_db = dJ_dz *1

    a = a - learning_rate * dJ_da
    b = b - learning_rate * dJ_db

plt.show()