a = int(input())
num=1
count = 0
while True:
    count += 1
    if a == 1:
        print(1)
        break
    if a <= num:
        print(count)
        break
    num = num+(count*6)
    

