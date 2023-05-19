include 'emu8086.inc'
call scan_num
mov si,cx
l1:
  mov ax,1
factn:
  mov dx,cx
  mul cx
  loop factn
mov nfact,ax
call scan_num
sub si,cx
mov cx,si
l2:
  mov ax,1
 factp:
  mov dx,cx
  mul cx
  loop factp
mov pfact,ax 
mov ax,nfact
mov bx,pfact
div bx
call print_num
define_print_num
define_print_num_uns 
define_scan_num
  



    
n dw 0
nfact dw 0  
pfact dw 0
