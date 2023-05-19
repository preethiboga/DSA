include 'emu8086.inc'
call scan_num
mov ax,cx
mov di,ax
call scan_num
mov bx,cx
mov si,bx
cmp ax,bx 
je l2
jne l3
l2:
 call print_num
 define_scan_num
 define_print_num
 define_print_num_uns
 hlt
l3:
 cmp ax,bx
 jl l4
 jg l5
l4:
 add ax,di
 cmp ax,bx
 je l2
 jne l3
l5:
  add bx,si
  cmp ax,bx
  je l2
  jne l3