import matplotlib.pyplot as plt
import numpy as np

img_path = "./AI/Jindo_SOL/img/ine.jpg"
img = plt.imread(img_path)
img = np.mean(img, axis=-1)
print(img.shape)

plt.imshow(img, cmap='gray')
plt.show()

test_list = [1,2,3,4,5,6,7,8]