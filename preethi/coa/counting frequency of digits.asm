include 'emu8086.inc'
mov cx,1233
mov var1,cx 
mov var2,10
mov ax,cx
cmp ax,0
jg label
label: 
   mov v,0
   mov dx,0 
   div var2 
   mov var3,dx
   mov di,ax
   cmp dx,0
   jge c
c:
  mov ax,var1
count:
  mov dx,0
  div var2  
  cmp dx,var3
  je l1
  cmp dx,var3
  jne l2
l1:
  inc v  
  cmp ax,0
  jg count
  cmp ax,0
  je stop
l2: 
  cmp ax,0
  jg count 
  cmp ax,0
  je stop
stop: 
  mov ax,var3
  call print_num
  print "->" 
  mov ax,v   
  cmp ax,0
  je l3
  cmp ax,0
  jne l4
l3:
  mov ax,1
  call print_num 
  printn
  cmp ax,0
  jg label
  cmp ax,0
  je over
  define_print_num
  define_print_num_uns  
l4: 
  call print_num 
  printn 
  mov ax,di
  cmp ax,0
  jg label
  cmp ax,0
  je over 
    
   
over:
  hlt  
var1 dw 0
var2 dw 0
var3 dw 0   
v dw 0
    
  
  
       
   