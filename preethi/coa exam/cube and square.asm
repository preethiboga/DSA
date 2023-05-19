include 'emu8086.inc'
call scan_num 
printn
mov ax,cx
mul ax  
print 'square:'
call print_num   
printn
mul cx 
print 'cube:'
call print_num 
printn  
define_print_num
define_print_num_uns
define_scan_num