include 'emu8086.inc'
mov cx,1
mov var1,10
mov ax,cx 
mov bx,0
cmp ax,0
jg label
label: 
  mov dx,0
  div var1
  add var2,dx
  cmp ax,0
  jg label
  cmp ax,0
  jle l
l:
  mov ax,var2
  cmp ax,0
  jg l1
l1: 
  mov dx,0
  div var1 
  mov si,ax 
  mov di,dx
  mov ax,bx
  mul var1
  add ax,di
  mov dx,0   
  mov bx,ax
  mov ax,si 
  cmp ax,0
  jg l1
  cmp ax,0
  jle l2
l2:
  mov ax,bx
  mov bx,var2
  mul bx
  cmp ax,cx
  je l3
  cmp ax,cx
  jne l4
l3:
  print 'magic'
  hlt
l4:
  print 'not magic'
  hlt     
  
var1 dw 0
var2 dw 0  
var3 dw 0  
var4 dw 0 
