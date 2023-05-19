include 'emu8086.inc'
mov cx,1
mov si,cx
mov cx,30
mov di,cx
start: 
  cmp si,di
  je over
  cmp si,di
  jne l1
l1:  
  mov ax,si
  mov bx,si
  sub bx,1 
  mov c,bx
  mov bx,1
  mov cx,0 
l: 
  mov dx,0
  mov ax,si
  div bx
  cmp dx,0
  je label 
  cmp dx,0
  jne l5
label:
  add cx,bx
  inc bx 
  cmp bx,c
  jle l
  cmp bx,c
  jg l2 
l2:
  cmp cx,si
  je l3
  cmp cx,si
  jne l4  
l3:
  mov ax,si 
  cmp ax,1
  jne l6 
  cmp ax,1
  je l7
l6:  
  call print_num
  print " "
  inc si
  jmp start  
l7:  
  inc si
  jmp start   
l4:
  inc si
  jmp start  
l5: 
   inc bx 
  cmp bx,c
  jle l
  cmp bx,c
  jg l2   
over:
  hlt
c dw 0
define_print_num
define_print_num_uns
       