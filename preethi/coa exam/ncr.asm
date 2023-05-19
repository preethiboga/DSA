include 'emu8086.inc'
print 'enter n;'
call scan_num 
printn
mov n,cx 
mov ax,1
fact1:  
  mov dx,cx
  mul dx 
  loop fact1
mov nfact,ax  
mov dx,0 
print 'enter r:'
call scan_num 
printn
mov r,cx  
mov ax,1
fact2:  
  mov dx,cx
  mul dx 
  loop fact2
mov rfact,ax 
mov ax,n
sub ax,r
mov cx,ax 
mov ax,1
fact3:
  mov dx,cx
  mul dx
  loop fact3
mov nrfact,ax
mov ax,rfact
mov bx,nrfact  
mov dx,0
mul bx  
mov si,ax
mov ax,nfact
mov dx,0
div si
call print_num
hlt
define_print_num
define_print_num_uns
define_scan_num
n dw 0
r dw 0
nfact dw 0
rfact dw 0
nrfact dw 0

