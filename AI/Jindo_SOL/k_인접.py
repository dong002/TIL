from random import randint
from turtle import distance


import numpy as np
n_centroid = 5
n_data = 100
centroids = np.random.randint(0,10,(n_centroid,3))
data = np.random.randint(0,10,(n_data,3))

# for sample in data:
#     x, y = sample[0], sample[1]
#     for centroid in centroids:
#         centroid_x,centroid_y = centroid[0], centroid[1]
#         distance = np.sqrt((x - centroid_x)**2 + (y - centroid_y)**2)

# for sample in data:
#     sample = sample.reshape((1,2))
#     distance = np.power(sample - centroids, 2)
#     distance = np.sum(distance, axis=-1)
#     distance = np.sqrt(distance)
#     print(distance.shape)

# for centroid in centroids:
#     centroid = centroid.reshape((1,2))
#     distance = np.power(sample - centroids, 2)
#     distance = np.sum(distance, axis=-1)
#     distance = np.sqrt(distance)
#     print(distance.shape)

centroids = centroids.reshape((1, n_centroid,3))
data = data.reshape((n_data,1,3))
distances = (centroids - data)**2
distances = np.sum(distances, -1)
distances = np.sqrt(distances)

print(distances.shape)