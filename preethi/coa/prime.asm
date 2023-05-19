include 'emu8086.inc'
call scan_num
mov bl,2
back:
  mov al,cl
  cmp al,2
  je prime
  mov ah,0
  div bl
  cmp ah,0
  je eq
  jne neq
eq:
 print 'not prime'
 ret
neq:
  add bl,1
  cmp bl,cl
  je prime
  jmp back
prime:  
  print 'prime'
  ret 
define_scan_num  


