# file = open("basic.txt","w")#파일생성및 파일 모드 설정 ex)w:write
# file.write("히히히히ㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣ까시발싸")
# file.close()#파일 닫기
# with open ("fdzz.txt","r") as file:# 이런식으로 with open as를쓰면 close가 필요없다
#     s = file.read()
# print(s)


# import random
# names = list("김동현백승민이준안진형박영재")
# with open("name.txt","w") as file:
#     for i in range(1000):
#         name = random.choice(names) + random.choice(names)
#         weight = random.randrange(40,100)
#         height = random.randrange(140,200)
#         file.write("{},{},{}\n".format(name,weight,height))
with open("name.txt","r") as file:
    for line in file:
        (name,weight,height) = line.strip().split(",")
        if(not name) or (not weight) or (not height):
            continue
        bmi = int(weight) / ((int(height) / 100) **2)
        result = ""
        if 25 <= bmi:
            result = "과체중"
        elif 18.5 <= bmi:
            result = "정상체중"
        else:
            result = "저체중"
        print('\n'.join([
            "이름: {}",
            "몸무게: {}",
            "키: {}",
            "BMI: {}",
            "결과: {}"
        ]).format(name, weight, height, bmi, result))
        print()