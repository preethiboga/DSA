include 'emu8086.inc'
call scan_num
mov ax,1 
fact:
  mov dx,cx
  mul dx
  loop fact
call print_num
ret  
define_scan_num
define_print_num
define_print_num_uns  

  