include 'emu8086.inc'
Mov ax,8
Mov bx,2
Mov cx,3
call Print_num
ret
define_print_num
define_print_num_uns   
n db 8
MOV ax,02
MOV bx,02
MUL bx




