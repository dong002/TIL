import numpy as np
from numpy import dot
from numpy.linalg import norm
# 문서1 : 저는 사과 좋아요
# 문서2 : 저는 바나나 좋아요
# 문서3 : 저는 바나나 좋아요 저는 바나나 좋아요

def cos_sim(A, B):
  return dot(A, B)/(norm(A)*norm(B))

doc1 = np.array([0,1,1,1])
doc2 = np.array([1,0,1,1])
doc3 = np.array([2,0,2,2])

print('문서 1과 문서2의 유사도 :',cos_sim(doc1, doc2))
print('문서 1과 문서3의 유사도 :',cos_sim(doc1, doc3))
print('문서 2와 문서3의 유사도 :',cos_sim(doc2, doc3))

# 문서 1과 문서2의 유사도 : 0.6666666666666667
# 문서 1과 문서3의 유사도 : 0.6666666666666667
# 문서 2와 문서3의 유사도 : 1.0000000000000002
# 이렇듯 코사인 유사도기법은 단어의 개수, 즉 문서의 길이가 길어져도 일정한 값을 측정할 수 있기때문에 다른길이를 가진 문서를 비교할때 좋다