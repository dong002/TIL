#TF-IDF는 TF와 IDF를 곱한값을 의미하는데, 여기서 tf는 특정문서에서 특정단어가 등장한 횟수를 의미하고
#DF는 특정단어가 등장한 문서의 갯수, IDF는 DF의 반비례 이지만, 값이 너무 커지는 점 때문에 LOG를 이용한다.
import pandas as pd
from math import log

docs = [
  '먹고 싶은 사과',
  '먹고 싶은 바나나',
  '길고 노란 바나나 바나나',
  '저는 과일이 좋아요'
] 

voca = list(set(w for doc in docs for w in doc.split()))
voca.sort()


N = len(docs)# 문서 갯수

def tf(t,d):
    return d.count(t)

def idf(t):
    df = 0
    for doc in docs:
        df += t in doc
    return log(N/(df + 1))#분모에 0이 나오는걸 방지하기위애 +1

def tfidf(t, d):
    return tf(t,d)*idf(t)

result = []

for i in range(N):
    result.append([])
    d = docs[i]
    for j in range(len(voca)):
        t = voca[j]
        result[-1].append(tf(t, d))
tf_ = pd.DataFrame(result, columns=voca)
print(tf_)

result = []

for j in range(len(voca)):
    t = voca[j]
    result.append(idf(t))
idf_ = pd.DataFrame(result, index=voca ,columns=["IDF"])
print(idf_)