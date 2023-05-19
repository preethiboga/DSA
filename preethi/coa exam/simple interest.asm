include 'emu8086.inc'
print 'enter p:'
call scan_num
printn
mov p,cx
print 'enter t:'
call scan_num
printn
mov t,cx 
print 'enter r:'
call scan_num
printn
mov r,cx 
mov bx,100
mov ax,p
mov si,t
mul si
mov si,r
mul si 
mov dx,0
div bx
call print_num
hlt
define_print_num
define_print_num_uns
define_scan_num 
p dw 0
t dw 0
r dw 0
