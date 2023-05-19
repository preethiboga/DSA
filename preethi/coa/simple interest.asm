include 'emu8086.inc'
mov cx,100
mov p,cx
mov cx,2
mov bx,cx
mov cx,2
mov r,2
mov ax,100 
mul bx
mov bx,r
mul bx 
mov si,100
div si  
call print_num
define_print_num
define_print_num_uns  
p dw 0
t dw 0
r dw 0 
