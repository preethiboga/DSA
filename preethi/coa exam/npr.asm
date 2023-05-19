include 'emu8086.inc'
print 'enter n:'
call scan_num
printn
mov n,cx
print 'enter r:'
call scan_num
printn
mov r,cx  
mov bx,n
sub bx,r
mov p,bx
mov cx,n
mov ax,1
fact1:
  mov dx,cx
  mul dx
  loop fact1
mov n,ax 
printn
mov cx,p
mov ax,1
fact2:
  mov dx,cx
  mul dx
  loop fact2
mov p,ax
mov ax,n
mov bx,p
div bx 
call print_num
hlt
define_print_num
define_print_num_uns  
define_scan_num
n dw 0
r dw 0
p dw 0
    
