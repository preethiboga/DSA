include 'emu8086.inc'
call scan_num
mov al,1  
mov ch,1
fact:
  mul cl
  cmp cl,0
  jg l1
  cmp cl,0
  jz l2  
l1:
  dec cl
  cmp cl,0
  jg fact
l2:
  mul ch
call print_num
ret
define_print_num
define_print_num_uns   
define_scan_num   