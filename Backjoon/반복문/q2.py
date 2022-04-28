a = int(input())
d = {}
for i in range(a):
    b,c = input().split(' ')
    b = int(b)
    c = int(c)
    d[i] = b+c
for i in d:
    print(d[i])