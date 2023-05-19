include 'emu8086.inc'  
mov cx,100
mov si,100
mov cx,200
mov di,200
start:
   mov bx,2 
   mov cx,si
   cmp si,di
   jne back 
   cmp si,di
   je over
back: 
     mov ax,si
     cmp ax,2
     je prime
     mov dx,0
     div bx
     cmp dx,0
     je eq
     cmp dx,0
     jne neq 
eq:
  inc si
  jmp start
neq:
  add bx,1
  cmp bx,cx
  je prime
  cmp bx,cx
  jmp back
prime: 
  mov ax,si
  call print_num
  print " " 
  inc si
  jmp start 
over:
  hlt
define_print_num
define_print_num_uns    
  
  
        




