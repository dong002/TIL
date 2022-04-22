from konlpy.tag import Okt

okt = Okt()

text = "우리엄마는 매일 내게 말했어 언제나 남자를 조심하라고"

morphs = okt.morphs(text)
print(morphs)

pos = okt.pos(text)
print(pos)

noun = okt.nouns(text)
print(noun)

text = "오늘 날씨가 좋아욬ㅋㅋ"
print(okt.normalize(text))
print(okt.phrases(text))