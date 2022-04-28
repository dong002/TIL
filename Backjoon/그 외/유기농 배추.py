a = int(input())
for i in range(a):
    mx,my,num = input().split(' ')
    mx = int(mx)
    my = int(my)
    num = int(num)
    arr = {0: 'None'}
    y_arr = {0: 'None'}
    for j in range(num):
        x,y=input().split(' ')
        x = int(x)
        y = int(y)
        arr[j] = f'{x},{y}'
        # y_arr[j] = f'{y}'
    print(arr)
    # for j in range(mx):
