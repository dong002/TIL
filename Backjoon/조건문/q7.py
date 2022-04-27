a,b,c = input().split(' ')
a = int(a)
b = int(b)
c = int(c)
p = 0
k = 0
num = [a,b,c]
for i in num:
    temp = 0
    for j in range(3):
        if num[j] - i == 0:
            temp = temp + 1
        if temp == 2 and k != 1 and k != 2:
            p = 1000 + (i*100)
            k = 1
            break
        elif temp == 3 and k!=2:
            print(10000 + (i*1000))
            k = 2
            break
if k == 0:
    print(max(num)*100)
elif k == 1:
    print(p)

            


        