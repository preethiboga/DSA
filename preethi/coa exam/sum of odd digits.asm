include 'emu8086.inc'
call scan_num
printn
mov ax,cx 
mov bx,10
mov cx,2
l1: 
  cmp ax,0
  je l2  
  mov dx,0
  div bx 
  mov t,ax
  mov ax,dx 
  mov si,dx
  mov dx,0
  div cx
  cmp dx,0
  je  l3
  jne l4
l3:
  mov ax,t
  jmp l1
l4:
  add s,si
  mov ax,t
  jmp l1
l2:
  mov ax,s
  call print_num
  hlt
s dw 0  
t dw 0
define_print_num
define_print_num_uns
define_scan_num    
  
    
  