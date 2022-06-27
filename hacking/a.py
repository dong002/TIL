num = ['0x52', '0x5c', '0x49', '0x10', '0x47']
for i in num:
    print(i)
    a = int(i, 16)
    b = bin(a ^ 0b0110000)
    print(chr(int(b, 2)), end='')