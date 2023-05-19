include 'emu8086.inc'
call scan_num 
mov cx,30
mov ax,cx
mov di,ax
mov var1,cx
call scan_num  
mov cx,24
mov bx,cx
mov si,bx
mov var2,cx  

cmp bx,ax
je l2
jne l3 

l2:  
 mov var3,ax
 mov ax,var1
 mov bx, var2
 mul bx
 div var3
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
var1 dw 0
var2 dw 0  
var3 dw 0
 