from Crypto.Util.number import bytes_to_long, long_to_bytes
from Crypto.Util.Padding import unpad
from Crypto.Cipher import AES
from pwn import *
import hashlib

p = remote("host1.dreamhack.games", 23744)

p.recvuntil("Prime: ")
primeNum = int(p.recvline(), 16)

p.recvline()
p.sendlineafter(">>", "1")

p.recvline()
p.sendlineafter(">>", "1")

aes_key = hashlib.md5(str("1").encode()).digest()
cipher = AES.new(aes_key, AES.MODE_ECB)

p.recvuntil("Alice: ")
input = p.recvline()[:-1]
log.info(b"Alice : " + input)
flag = unpad(cipher.decrypt(bytes.fromhex(input.decode())), 16)

p.recvuntil("Bob: ")
input = p.recvline()[:-1]
log.info(b"Bob : " + input)
flag += unpad(cipher.decrypt(bytes.fromhex(input.decode())), 16)
log.info(b"flag : " + flag)