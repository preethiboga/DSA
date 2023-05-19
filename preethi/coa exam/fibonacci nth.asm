include 'emu8086.inc'
call scan_num 
printn
mov ax,0
mov bx,1
mov n,ax 
cmp n,cx
jl l1
l1:
  push ax
  inc n 
  cmp n,cx
  jl l2 
  cmp n,cx
  je l4 
     
l2: 
  mov dx,ax
  mov ax,bx
  push ax
  mov ax,dx
  inc n
  cmp n,cx
  jl l3  
  cmp n,cx
  je l4 
l3:
  mov p,bx
  add ax,bx  
  mov t,ax
 push ax
  mov ax,p
  mov bx,t
  inc n
  cmp n,cx
  jl l3
  cmp n,cx
  je l4
l4:
   pop ax
   call print_num
   hlt 
n dw 0  
p dw 0
t dw 0  
define_scan_num
define_print_num
define_print_num_uns    
  
  
