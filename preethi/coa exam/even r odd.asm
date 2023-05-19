include 'emu8086.inc'
call scan_num 
printn
mov bx,2 
mov ax,cx
div bx
cmp dx,0
je l1
jne l2
l1:
  print 'even'
  ret
l2:
  print 'odd'  
  ret  
define_print_num
define_print_num_uns 
define_scan_num 