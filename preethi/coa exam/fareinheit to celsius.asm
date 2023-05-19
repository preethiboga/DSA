include 'emu8086.inc'
mov cx,10
mov bx,0 
mov bx,5 
mov si,9
sub cx,32 
mov ax,0
mov ax,cx
mul bx 
mov dx,0
div si
call print_num  
hlt
define_print_num
define_print_num_uns
define_scan_num
 