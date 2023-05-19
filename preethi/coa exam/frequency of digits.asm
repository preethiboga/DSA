include 'emu8086.inc'
mov cx,122 
mov n,cx
mov ax,cx  
mov bx,10
l:
  cmp ax,0
  je l1
  cmp ax,0
  jne l2 
l1: 
  hlt
l2:
  mov dx,0
  div bx
  mov t1,dx 
  mov a1,ax
  jmp l7 
l7:
   mov ax,n 
   mov cx,0
l3:
  mov dx,0
  div bx 
  mov a2,ax
  cmp dx,t1
  je l4 
  jne l5
l4:
  inc cx 
  mov ax,a2
  cmp ax,0
  jne l3
  je l6
l5: 
  mov ax,a2
  cmp ax,0
  jne l3
  je l6
l6: 
  mov ax,t1
  call print_num  
  print '->'
  mov ax,cx
  call print_num  
  printn
  mov ax,a1  
  jmp l  
define_print_num
define_print_num_uns  
a1 dw 0
a2 dw 0
t1 dw 0
n dw 0  

        
     
    