from cgi import print_environ_usage
from distutils.log import error
from unittest import result
from nltk.tokenize import sent_tokenize
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords

# 분석할 문자열
raw_text = "A barber is a person. a barber is good person. a barber is huge person. he Knew A Secret! The Secret He Kept is huge secret. Huge secret. His barber kept his word. a barber kept his word. His barber kept his secret. But keeping and keeping such a huge secret to himself was driving the barber crazy. the barber went up a huge mountain."

sentences = sent_tokenize(raw_text)#문장으로 분할
print(sentences)#문장별로 나누어진다.

vocab = {}
preprocessed_sentences = []
stopword = set(stopwords.words("english"))


for sentence in sentences:
    #단어 토큰화
    token_sentence = word_tokenize(sentence)
    results = []
    for word in token_sentence:
        word = word.lower()#전부 소문자로 만들어 단어의 개수를 줄인다
        if word not in stopword:#불용어를 솎아낸다
            if len(word) > 2:# 길이가 2이하인 단어들도 솎아낸다
                results.append(word)
                if word not in vocab:
                    vocab[word] = 0
                vocab[word] += 1
    preprocessed_sentences.append(results)
print(preprocessed_sentences)

print(vocab)#빈도도 볼수 있다

vocab_sorted = sorted(vocab.items(), key = lambda x:x[1], reverse=True)#빈도가 높은순으로 정렬
print(vocab_sorted)

word_to_index = {}
i=0
for (word,frequency) in vocab_sorted:
    if frequency > 1:
        i = i+1
        word_to_index[word] = i
print(word_to_index)#빈도가 높은 순으로 정렬 후, 인덱스 부여

vocab_size = 5

# 인덱스가 5 초과인 단어 제거
words_frequency = [word for word, index in word_to_index.items() if index >= vocab_size + 1]

# 해당 단어에 대한 인덱스 정보를 삭제
for w in words_frequency:
    del word_to_index[w]
print(word_to_index)

word_to_index['OOV'] = len(word_to_index)+1 #단어 집합에 없는 단어가 나왔을 경우 Out Of Vocabalary의 인덱스로 인코딩한다

encoded_sentences = []
for sentence in preprocessed_sentences:
    encoded_sentence = []
    for word in sentence:
        try:
            #단어 집합에 있는 단어라면 해당 단어 인덱스 출력
            encoded_sentence.append(word_to_index[word])
        except KeyError:
            encoded_sentence.append(word_to_index['OOV'])
    encoded_sentences.append(encoded_sentence)
print(encoded_sentences)
print('\n\n\n\n\n\n\n\n\n\n\n\n\n')
print(preprocessed_sentences)