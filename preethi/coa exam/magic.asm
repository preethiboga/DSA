include 'emu8086.inc'
call scan_num    
printn
mov ax,cx
mov bx,10
l:
  cmp ax,0
  je l1
  jne l2
l2: 
  mov dx,0
  div bx
  add sum,dx
  jmp l
l1:
  mov ax,sum
  jmp l3
l3:
  cmp ax,0
  je l4
  jne l5
l4:
  mov ax,sum
  mov bx,rev
  mul bx
  cmp ax,cx
  je l6
  jne l7
l5:
  mov dx,0
  div bx
  mov t,ax 
  mov r,dx
  mov ax,rev
  mul bx
  add ax,r
  mov rev,ax
  mov ax,t
  jmp l3   
l6:
  print 'magic'
  hlt
l7:
  print 'not magic'
  hlt
define_print_num
define_print_num_uns    
define_scan_num
sum dw 0
rev dw 0      
t dw 0  
r dw 0
        
  
  