include 'emu8086.inc'
;mov cx,4
;cmp cx,0
;mov ax,1
;jg fact
;fact:
  ;mov dx,cx
  ;mul dx
  ;loop fact
;call print_num 
call scan_num
printn
mov ax,1 
mov bx,1
cmp cx,0 
jg l1
l1:
  mul cx  
  dec cx
  cmp cx,0
  jg l1
  cmp cx,0
  je l2
l2:
 mul bx
 call print_num
 ret
   
    

define_scan_num    
define_print_num
define_print_num_uns  