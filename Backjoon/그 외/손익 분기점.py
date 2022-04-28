base_cost,cost,sales = input().split(' ')
count = 0
base_cost = int(base_cost)
cost = int(cost)
sales = int(sales)

if cost >= sales:
    print(-1)
else:
    count = base_cost//(sales - cost)
    print(count+1)

# while True:
#     if cost > sales:
#         print(-1)
#         break
#     count = count + 1
#     red = base_cost+(count*cost)
#     black = sales*count
#     if black > red:
#         print(count)
#         break
