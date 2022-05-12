from ast import parse
from ntpath import join
from bs4 import BeautifulSoup
from urllib.request import urlopen
import os
import requests
num=0
with urlopen('https://apod.nasa.gov/apod/astropix.html') as response:
    soup = BeautifulSoup(response, 'html.parser')
    url = []
    string = []
    img = []
    for anchor in soup.find_all('a'):
        url = anchor.get('href', '/')
        string.append(url.split())

img="https://apod.nasa.gov/apod/"+string.pop(1)[0]
r = requests.get(img)
num += 1
file = open(f'C:\\Users\\s2102\\Desktop\\Target_bg\\img{3}.jpg','wb')
file.write(r.content)
file.close()
# with urlopen(img) as f:
#     if os.path.isfile('C:\Users\s2102\Desktop\Astro_BackGround\img.jpg'):
#         os.remove('C:\Users\s2102\Desktop\Astro_BackGround\img.jpg')
#     with open('C:\\Users\\s2102\\Desktop\\Astro_BackGround\\img.jpg','wb') as h:
#         img = f.read()
#         h.write(img)