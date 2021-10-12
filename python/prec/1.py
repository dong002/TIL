# import datetime#날짜 시간관련 함수

# now = datetime.datetime.now()
# print("hello"+" "+"world")
# print(type(23))
# print(type("hello"))
# print("""안
# 녕
# 하
# 세
# 요""")
# print("히히후헤헤"*5)
# print("성길이바보"[0])
# print("성길이 바보"[-5])
# print("성길이 바보멍청이"[1:8])
# print("성기리 바보멍청이"[:4])
# print(len("성기리바보멍청이똥개말미잘우리집앞에있는비둘기"))
# print(386**2)
# #a = "{:d}만원".format(int((input())))
# b = 3.0000000000000000
# a = "{:g}".format(b)
# b = "Python"
# #.upper(),.lower() 변수 변동x = 비파괴적 함수
# print(a)
# print(b.upper())
# c = """
#          ㅐㅏ애저래더래ㅓ대러3대ㅏㅐㅇ나아앤앤
#          애젇애더ㅐ어대어ㅐ저애저애저어ㅓ재엊ㅇ
#     """
# print(c.strip())#strip:공백제거
# print("iloveyoudaring".isalnum())#is~:문자열의 구성파악
# s = "hey you! are you okey? hey..damm"
# print(s.rfind("hey"))#find:매개변수로 넘긴 단어가 있는지 확인
# print("damm" in s)#in:문자열안에 특정 문자열이 있는지 확인
# print("i"in s)
# f = "사랑푹사랑사랑푹사랑해애애ilove푹푹".split("푹")#split:쪼개기 함수
# print(f)
# print((30==3)and(30!=3))#&&
# print((30==3)or(30!=3))#||
# print(not(30==3))#!
# if now.second>30:
#     print("양수")
# if now.second<30:
#     print("음수")
# if now.second==30:
#     print("lucky!!")
# print(now.year,"년")
# print(now.month,"month\n",now.day,"day\n",now.hour,"hour\n",now.minute,"minute\n",now.second,"second")
# if now.hour>12:
#     print("{}시{}분{}초 오후임".format(now.hour,now.minute,now.second))
# if now.hour<12:
#     print("{}시{}분{}초 오전임".format(now.hour,now.minute,now.second))
# arr=[[1,2,3],[4,5,6],["one","two","three"],["four","five","six"]]
# print(arr[2][2])
# print(len(arr))
# print(arr)
# arr.append(7)
# print(arr)
# arr.insert([1][0],[3,6,9])#아마 이중리스트일 경우에 2번째 배열에는 값을 추가할수없나보다
# #(첫번째 배열에또다른 리스트는 가능하다)
# print(arr)
# at=[1,2,3,4,5,6,8,9,]
# print(at)
# at.insert(6, 7)
# print(at)
# del arr[5]
# print(arr)
# arr.pop(1)#이것도 위에것처럼 2번쨰 배열의 세부적인 값은 삭제가안된다 겁나 답답하다
# print(arr)
# print(arr.pop(0))#이런것도 된다 (명색이 pop인데 되야지..)
# print(arr)
# print(arr.pop())#이것도 되네(매개변수로 아무것도 제시안하면 마지막 삭제)
# del at[:6]
# print(at)
# arr.extend(at)
# print(arr)
# #arr.clear()#리스트관련 함수는 전부 파괴적 함수
# #print(arr)
# for i in at:
#    print(i)#for(int i=0; i<at; i++){printf("%d",at[i])}이코드를 줄인거임 ㄹㅇ 겁나간단하네
# number = [273, 103, 5, 32, 65, 9, 72, 800, 99]
# for i in number:
#     if i % 2 == 0:
#         print("{}는 짝수입니다".format(i))
#     else:
#         print("{}는 홀수입니다".format(i))
# for i in number:
#     print("{}는 {}자릿수입니다".format(i,len(str(i))))
  
# list_of_list = [
#     [1,2,3],
#     [4,5,6,7],
#     [8,9],
# ]
# for i in list_of_list:
#     for j in i:
#         print(j)
# numbers =[1,2,3,4,5,6,7,8,9]
# output = [[],[],[]]
# for number in numbers:
#     output[number%3-1].append(number)
# print(output)
# diction = {
#     "name": "달달한 7D건조 망고~",
#     "type": "달달구리",
#     "ingredient":["망고", "설탕","메타중아황산나트륨","치자황색소"],
#     "origin":"필리핀"
# }
# print(diction)#딕셔너리: 살짝 구조체 같으면서도 뭔가 애매꾸리하게 다름
# pets = [
#     {"name": "구름","age": 5},
#     {"name": "초코","age": 3},
#     {"name": "아지","age": 1},
#     {"name": "호랑이","age": 1}
# ]

# for i in pets:
#     print(i["name"],"{}살".format(str(i["age"])))
# numbers = [1,2,6,8,4,3,2,1,9,5,4,9,7,2,1,3,5,4,8,9,7,2,3]
# counter = {}
# for number in numbers:
#     if number in counter:
#         counter[number]+=1
#     else:
#         counter[number]=1
#print(counter)
# charactor = {
#     "name": "기사",
#     "level": 12,
#     "items": {
#         "sword": "불꽃의 검",
#         "armor": "풀플레이트"
#     },
#     "skill": ["베기", "세게 베기","아주 세게 베기"]
# }
# for i in charactor:
#     if type(charactor[i]) == dict:
#         for j in charactor[i]:
#             print(j,":",charactor[i][j])
#     elif type(charactor[i]) == list:
#         for j in charactor[i]:
#             print(i,":",j)
#     else:
#         print(i,":",charactor[i])
# # import time
# # num=0
# # tt=time.time()+5
# # while time.time()<tt:
# #     num+=1
# #print(num)
# k_l = ["name", "hp", "mp", "level"]
# v_l = ["기사",200,30,5]
# char = {}
# for i in range(4):
#     char[k_l[i]]=v_l[i]
# print(char) 
# limit = 10000
# i=1
# s_v = 0
# while s_v < limit:
#     s_v+=i
#     i+=1
# print("{}를 더할때,{}를 넘으며,그때의 값은 {}입니다".format(i-1,limit,s_v))
# a=0
# b=0
# m_v=0
# while a < 100:
#     a+=1
#     if m_v < a * (100-a):
#         m_v = a * (100-a)
#         b=a
# print("최대가 되는경우:{} * {} = {}".format(b,100-b,m_v))
# lists = [1,2,3,4,5]
# dic = {
#     "k1":"v1",
#     "k2":"V2",
#     "k3":"v3",
# }
# print(min(lists))#리스트나 매개변수로부터 최소값
# print(max(lists))#최댓값
# print(sum(lists))#알지?
# rlist = reversed(lists)
# print(rlist)#이터레이터
# print(list(rlist))#일케해야 반대로나오네
# for i in reversed(lists):#rlist는 제너리스트라안됨
#     print(i)
# print(lists[::-1])#이렇게도 뒤집을수있음
# print(enumerate(lists))#이터레이터
# print(list(enumerate(lists)))#튜플
# for i,value in enumerate(lists):
#     print("{}번쨰 요소는 {}입니다".format(i,value))
# print(dic.items())
# for k,e in dic.items():
#     print("{}={}".format(k,e))
# array=[i*i for i in range(0,20,2)]#최종결과 식을 for문앞에놓고 안에집어넣을수있음
# print(array)
# list2 = [i for i  in lists if i !=3]#if문도 들어간다
# print(list2)
# test = (
#     "이렇게 "
#     "괄호에,빼고 "
#     "입력하면 "
#     "마치 한줄처럼!"
# )
# print(test)
# print("헛!".join(str(lists)))#fun fact:1,2,3,4이런식으로 입력했던 숫자 리스트를 문자로 바꾸면 온점까지 출력된다
# #lietable:반복할수있는것.
# rlist = reversed(lists)
# for i in range(5):
#     print(next(rlist))
# print("ㄹㅇㅋㅋㅋㅋ루삥뻥빵뽕뿡뽱뿽".count("ㅋ"))
# onezero = [i for i in range(1,101) if "{:b}".format(i).count("0")==1]
# for i in onezero:
#     print("{} : {}".format(i,"{:b}".format(i)))
# print("합계:",sum(onezero))
# def p_n_t(n, *value):#*매개변수는 가변 변수로 값의 개수가 변할수있다
#     for i in range(n):
#         for v in value:
#             print(v)
# p_n_t(3,"히히","까시","발싸")
# def func(*v,n=2):#기본매개변수로,가변변수에 입력되지않으면 기본매개변수를 참조한다
#     for i in range(n):
#         for value in v:
#             print(value)
#         print()
# func("안녕하세용","사랑스러운","고양이에용")
# def mul(*values):
#     n=1
#     for i in values:
#         n*=i
#     return n
# print(mul(5,7,9,10))
# count = 0

# def fib(n):
#     print("피보나치({})를 구합니다".format(n))
#     global count
#     count += 1
#     if n==1:
#         return 1
#     if n==2:
#         return 1
#     else:
#         return fib(n-1) + fib(n-2)
# fib(35)
# print("---")
# print("10!에 사용된 덧셈횟수는{}닙니당".format(count))#불필요한 계산을 너무많이한다
# dic = {
#     1:1,
#     2:1
# }
# count = 0
# def fib(n):
#     global count
#     count += 1
#     if n in dic:
#         return dic[n]
#     else:
#         output = fib(n-1)+fib(n-2)
#         dic[n]=output#이런식으로 딕셔너리에 저장하는걸 메모화라고한다
#         return output
#print("35:",fib(35))
# a=int(input())
# cnt=0
# while a>1:
#     if a // 500 > 0:
#         a = a - 500
#         cnt += 1
#     elif a // 100 > 0:
#         a = a - 100
#         cnt += 1
#     elif a // 50 > 0:
#         a = a - 50
#         cnt += 1
#     elif a // 10 > 0:
#         a = a - 10
#         cnt+=1
# print(cnt)
# a=int(input("a를입력"))
# b=int(input("b를입력"))
# cnt=0
# while a!=1:
#     if(a%b==0):
#         a/=b
#         cnt+=1
#     else:
#         a-=1
#         cnt+=1
# print(cnt)
# name="보노보노"
# food="shell"
# prob="allergy"
# print("i am {1}, and i like {0} but i have {2}".format(name,food,prob))
# print("{0:<10}".format("hi"))
# print("{0:>10}".format("hi"))
# print("{0:^10}".format("hi"))
# print("{0:!<10}".format("hi"))
# print("{0:=^10}".format("hi"))
# y=3.55454362342534
# print("{0:0.4f}".format(y))
# print("{0:10.4f}".format(y))
# print("{{0}}".format(y))
# name="홍길동"
# age=50
# print(f'나의 이름은 {name}입니다.  나이는 {age}입니다.')
# print(f'나의 이름은 {name}입니다.  나이는 {age+50}입니다.')
# d={'name':"hongilldong",'age':30}
# print(f"my name is {d['name']}, i'm {d['age']}year's old")
# print("{0:!^12}".format("python"))
# a="dong"
# print(a.count("o"))#몇개있는지

# print(a.find("n"))#어디있는지
# print(a.index("n"))#어디있는지

# print(a.find("w"))#오류 x
# #print(a.index("w"))#오류 o

# print(".".join(a))#사이사이 끼워넣기

# print(a.upper())#대문자
# a=a.upper()
# print(a.lower())#소문자
# b="                           hi                            "
# print(b.lstrip())#왼쪽공백 없애기
# print(b.rstrip())#오른쪽공백 없애기

# print(a.replace("O", "I"))#대체하기
# c="life is too short so i want to eat pizza"
# print(c.split())#문자열을 특정값으로 나누기

# odd=[1,3,5,7,9]
# a=[]
# b=[1,2,3,4,5]
# c=["life","is","too","short"]
# d=[1,2,'life','too']
# e=[1,2,'life', ['is' ,'too']]
# print(e)
# print(b[0]+b[2])
# print(b[-1])#음수 ㄱㄴ
# q=[1,2,['a','b',["life",'too']]]
# print(q[2][2][0])
# print(b[0:2])
# g=b[:2]
# print(g)
# A=[1,2,3,4,5]
# d=A[1:3]
# print(d)
# a=[1,2,3]
# b=[4,5,6]
# print(a+b)
# print(a*3)
# del a[2]
# print(a)
# a=[1,2,3,4,5,6,7]
# del a[2:]#삭제
# a.append(8)#뒤쪽에 추가
# b=[3,1,4,1,5,9,2,5,6,8,7]
# b.sort()#정렬
# print(b)
# b.reverse()#반대로 정렬x그냥 가운데 요소를 기점으로 1ㄷ1 교환
# print(b)
# print(a)
# print(b.index(5))#요소값이 있는곳의 인덱스 반환
# d=[1,2,4,5]
# d.insert(2, 3)
# print(d)
# b.remove(5)#인덱스 0을 기준으로 가까운 요소값 삭제
# d.pop()#스택 원리로 맨뒤의 값부터 삭제
# print(d)
# t=[1,2,3,4,4,5,6,6]
# print(t.count(4))#요소의 개수
# t.extend([8,9])#리스트의 확장, 요소에 리스트 요구
# print(t)
# a=int(input())
# n=input().split()
# print(n)
# for i in range(a):
#     for j in range(a):
#         if(n[i]>n[j]):
#             t=n[i]
#             n[i]=n[j]
#             n[j]=t
# print(n)
# dic2={1:'life',2:'is',3:'too',4:'short'}
# dic2[5]='python'
# del dic2[3]
# a={1:'a'}
# print(dic2.keys())#딕셔너리의 키값 출력가능
# dic2.clear
# s1 = set([1,2,3])
# s2 = set("python")
# print(s2,s1)          
# s3 = set("life is too")
# print(s3)
# a=[1,2,3]
# b=a
# print(id(a))
# print(id(b))#a와 같아진다
# c=a[:]#이러면 주소값은 달라지고 요소값만 저장한다
# print(id(c))
# a=3
# b=5
# a,b=b,a#스왑문 
# money = 2900
# card = False
# if card | money >= 3000:
#     print("taxi")
# else:
#     print("run")
# pocket=['paper','phone','b','EAR','mask']
# if "money" in pocket:
#     print("bus")
# elif 'card' in pocket:
#     print('taxi')
# else:
#     print("work")
# coffee=10
# while 1:
#     money=int(input("input money"))
#     if money==300:
#         print("coffee")
#         coffee-=1
#     elif money > 300:
#         print("%d$ and coffee"%(money-300))
#         coffee -= 1
# a=0
# while a<10:
#     a+=1
#     if a%2==0:continue
#     print(a)
a=[1,2,3,4]
result=[]
for i in a:
    if i%2==0:
        result.append(i*3)
print(result)