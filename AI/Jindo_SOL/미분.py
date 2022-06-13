
x = 1000
learning_rate = 0.1
for i in range(100):
    diff = 2 * (x-2)
    x = x- learning_rate * diff
    print(x)
