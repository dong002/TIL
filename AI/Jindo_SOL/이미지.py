import matplotlib.pyplot as plt
import numpy as np

img_path = "./AI/Jindo_SOL/img/ine.jpg"
img = plt.imread(img_path)
img = np.mean(img, axis=-1)
H,W = img.shape

sobel_x = np.array([[-1,0,1],
                    [-2,0,2],
                    [-1,0,1]])
sobel_y = np.array([[1,2,1],
                    [0,0,0],
                    [-1,-2,-1]])
img_filltered = np.zeros(shape=(H-2,W-2))
img_filltered2 = np.zeros(shape=(H-2,W-2))

for i in range(H-2):
    for j in range(W-2):
        window = img[i:i+3,j:j+3]
        z = np.abs(np.sum(window * sobel_x))
        img_filltered[i,j]=z
        z = np.abs(np.sum(window * sobel_y))
        img_filltered2[i,j]=z
        


fig, axes = plt.subplots(1,3, figsize=(1,5))
axes[0].imshow(img, cmap='gray')
axes[1].imshow(img_filltered, cmap='gray')
axes[2].imshow(img_filltered2, cmap='gray')
fig.tight_layout()
plt.show()

test_list = [1,2,3,4,5,6,7,8]