a,b= input().split(' ')
c = int(input())
a = int(a)
b = int(b)
while True:
    min = b+c
    if min >= 60:
        if a == 23:
            a = 0
            b = b-60
        else:
            a = a+1
            b = b-60
    else:
        b = min
        break
print(a,b)
