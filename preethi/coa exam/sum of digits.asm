include 'emu8086.inc'
call scan_num
printn
mov ax,cx 
mov bx,10
l1: 
  cmp ax,0
  je l2  
  mov dx,0
  div bx
  add s,dx  
  jmp l1
l2:
  mov ax,s
  call print_num
  hlt
s dw 0
define_print_num
define_print_num_uns
define_scan_num    
  
    
  