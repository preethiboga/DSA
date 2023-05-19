include 'emu8086.inc'
mov si,0
mov ax,a[si]
add si,2
l:
 cmp a[si],'e'
 je over
 jne l1 
over:
  call print_num
  hlt 
l1:
 cmp a[si],ax      ;change jl to jg to get max
 jl l2
 jge l3
l2:
  mov ax,a[si]
  add si,2
  jmp l
l3:
  add si,2
  jmp l
a dw 6,9,0,1,-10,'e'
define_print_num
define_print_num_uns      