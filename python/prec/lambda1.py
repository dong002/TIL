def call(func):
    for i in range(10):
        func()
def hello():
    print ("안뇽")
call(hello)#람다: 함수를 매개변수로 넘기는 함수
def power(item):
    return item * item
def under_3(item):
    return item < 3


lists = [1,2,3,4,5]
#output = map(power,lists)#리스트로 함수돌려서 리턴값을 다시 리스트에 저장
output = map(lambda x: x*x,lists)#이런식으로 함수 필요없이 바로할수도있다
print("map():",output)
print("map():",list(output))
#otherput = filter(under_3,lists)#map()함수와 비슷하나 참일때만 리스트에 저장
otherput = filter(lambda x: x<3, lists)
print("filter():",otherput)
print("filter():",list(otherput))


