include 'emu8086.inc'
mov cx,28
;printn
mov ax,cx
mov t,cx  
sub cx,1
mov n,cx 
mov cx,t
mov bx,1
mov c,bx
mov bx,2
l2: 
  cmp c,cx
  je l5
  cmp c,cx
  jne l6
l1:  
  cmp bx,n
  jg l2
  mov ax,cx 
  mov dx,0
   div bx
   cmp dx,0 
   je l3
   cmp dx,0
   jne l4
l3:
  add c,bx
  inc bx
  jmp l1
l4:
 inc bx
 jmp l1 
l5:
  print 'perfect'
  ret
l6:
  print 'not perfect'
  ret   
t dw 0
n dw 0 
c dw 0
define_print_num
define_print_num_uns
define_scan_num
         
