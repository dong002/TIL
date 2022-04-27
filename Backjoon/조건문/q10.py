a,b= input().split(' ')
a = int(a)
b = int(b)
if b >= 45 :
    b = b-45
else:
    b = 60-(45-b)
    if a == 0:
        a=23
    else: 
        a=a-1
print(a,b)