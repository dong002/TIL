from konlpy.tag import Okt

okt = Okt()

def build_bag_of_words(document):
    document = document.replace(',', '') #온점제거와 형태소 분석
    tokenized_document = okt.morphs(document)

    word_to_index = {}
    bow = []

    for word in tokenized_document:
        if word not in word_to_index.keys():
            word_to_index[word] = len(word_to_index)
            bow.insert(len(word_to_index) - 1, 1)# BoW에 기본값 1을 할당한다.
        else:
            index = word_to_index.get(word)# 재등장하는 단어 인덱스
            bow[index] = bow[index] + 1
    return word_to_index, bow
doc1 = "정부가 발표하는 물가상승률과 소비자가 느끼는 물가상승률은 다르다."
vocab, bow = build_bag_of_words(doc1)
print(vocab)
print(bow)

doc2 = '소비자는 주로 소비하는 상품을 기준으로 물가상승률을 느낀다.'
doc3 = doc1+' '+doc2
vocab, bow = build_bag_of_words(doc3)
print(vocab)
print(bow)

