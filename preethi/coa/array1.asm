include 'emu8086.inc'
mov al,a[2] 
call print_num 
ret
a db 2,4,5
define_print_num
define_print_num_uns

