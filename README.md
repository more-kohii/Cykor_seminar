# Cykor_seminar
---
## 과제 3줄 요약
1. due date : 5/1(월) 23:59
2. ez_rop, oneshot, oneshot1, onetime은 꼭 풀기
3. 나머지 3개 중 최소한 두개는 writeup에 최대한 고민해본 내용적어서 내기.
    -> 과제 체점 할 때도 반영할 예정입니다.
---
## Tip
- pwntools 에서 ELF로 여러 정보 찾기
  ```python
  from pwn import *

  e = ELF("[바이너리 경로]")
  l = ELF("[LIBC 경로]")
  
  #바이너리의 함수 주소 찾기.
  addr = e.symbols['함수이름']

  #plt & got 찾기
  plt = e.plt['함수이름']
  got = e.got['함수이름']
  
  #libc offset 찾기
  offset = l.symbols['함수이름']
  binsh = list(l.search(b"/bin/sh"))[0]
  ```
- Debuging??
  보통 send 전에 pause()를 걸고 gdb에서 attach 해주면 됨..
  
  창 2개 사용 (1개는 python 실행, 1개는 gdb attach 용도)

  [pwngdb](https://github.com/scwuaptx/Pwngdb) 플러그인 사용하면 해당 바이너리 gdb로 열고 at 입력하면 바로 attach 됨.
  아니면 pwntools가 process로 바이너리를 실행하면 pid 나오는데
  ```
  gdb -q -p [pid]
  ```
  이렇게 해줘도 attach 가능.

  attach 되면 원하는 부분에 breakpoint 걸고 c 누르고 입력 필요하면 pause 풀어주기



  




  

