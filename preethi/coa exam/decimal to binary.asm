include 'emu8086.inc'
print 'enter n:'
call scan_num
printn
mov ax,cx
mov bx,2 
mov si,0
l1:
  cmp ax,0
  je l4
  mov dx,0
  div bx
  mov a[si],dx
  add si,2
  jmp l1  
l4:
  sub si,2
l2:
  cmp si,0
  jl l3
  mov ax,a[si]
  call print_num
  print ' '
  sub si,2
  jmp l2
l3:
  hlt
define_print_num
define_print_num_uns
define_scan_num
a dw ?