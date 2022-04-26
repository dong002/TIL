import re
r = re.compile('a.c')# a와 c사이에 어떠한 글자라도 올 수 있다 ex) abc,a1c,a;c
print(r.search('kkk'))# 아무런 값도 출력되지 않는다.
print(r.search('abc'))# 출력 결과: <re.Match object; span=(0, 3), match='abc'>

r = re.compile("ab?c")# b가 있을 수 도있고, 없을 수 도 있다. ex) abc or ac
print(r.search('abbc'))# None
print(r.search('ac'))# <re.Match object; span=(0, 2), match='ac'>

r = re.compile('ab*c')# ?와 비슷하지만 b가 몇개든 올 수 있다. ex) abbbbbbbbbbbbbbc
print(r.search('abbbbbbbbbbbbc'))# <re.Match object; span=(0, 14), match='abbbbbbbbbbbbc'>

r = re.compile('ab+c')# *와 비슷하지만 b가 무조건 1개 이상이여야 한다.
print(r.search('ac'))# None

r = re.compile('^ab')# 문장이 ab로 시작한다면 매칭된다
print(r.search('zab'))# None
print(r.search('abz'))# <re.Match object; span=(0, 2), match='ab'>

r = re.compile('ab{2}c')# 중괄호에 적힌 숫자만큼 반복한다 ex) abbc
r = re.compile('ab{2,8}c')# 2이상, 8이하 만큼 b가 반목되었다면 매칭한다.
r = re.compile('ab{2,}c')# 2이상 반복되었다면 매칭한다.
print(r.search('abbbbbbbbbbbbbbbbbbbbbbbbc'))# <re.Match object; span=(0, 26), match='abbbbbbbbbbbbbbbbbbbbbbbbc'>

r = re.compile('[a-c]')# a부터 c까지의 문자중 하나를 포함한다면 매칭된다. [0-9],[A-Z]등으로도 사용가능하다.
print(r.search('mlmkljklmljhljkhlkjljlkja'))# <re.Match object; span=(24, 25), match='a'>

r = re.compile('[^abc]')# [a-c]와 반대로 a부터 c까지의 문자를 포함하고 있지 않다면 매칭된다.
print(r.search('b'))# None
print(r.search('f'))# <re.Match object; span=(0, 1), match='f'>

r = re.compile('ab.')
print(r.search('kkkabc'))# 매칭된다.
print(r.match('kkkabc'))# match함수는 문자열의 첫부분부터 정규식을 충족하지않으면 매칭되지 않기 때문에 None이 출력된다
print(r.match('abckkk'))# 이럼된다.

text = "사과 딸기 바나나 수박"
print(text.split(" "))