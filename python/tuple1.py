tuple_test=(1,2,3)#튜플: 리스트랑 비슷하지만 값의 변경이 불가능
print(tuple_test[0])
(a,b)=(10,20)
[c,d]=[10,20]
print("a:",a)
print("b:",b)
print("c:",c)
print("d:",d)
a,b,c = 2,3,4#괄호가 없어도 튜플로 인식가능하다면 생략가능
print("a:",a)
print("b:",b)
print("c:",c)
a,b = b,a#이런식으로 간단하게 스왑가능
print("a:",a)
print("b:",b)
def test():
    return (10,20)
a,b = test()
print("a:",a)
print("b:",b)
