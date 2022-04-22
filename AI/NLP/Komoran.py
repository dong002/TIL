from konlpy.tag import Komoran

komoran = Komoran()

text = "아버지가 방에 들어가신다"

morphs = komoran.morphs(text)
print(morphs)

pos = komoran.pos(text)
print(pos)

noun = komoran.nouns(text)
print(noun)