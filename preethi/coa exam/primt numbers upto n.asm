include 'emu8086.inc'
call scan_num
printn
cmp cx,2
jge label
cmp cx,2
jl l5
label:
  cmp i,cx
  jle l
  cmp i,cx
  jg l6
l:  
   mov ax,i
   mov bx,2
   cmp ax,2
   je l1 
   cmp ax,2
   jne l2
l1: 
  mov ax,i
  call print_num  
  printn
  inc i
  jmp label
l3:
  inc i
  jmp label     
l2: 
  cmp bx,i
  je l1
  mov ax,i 
  mov dx,0
  div bx
  cmp dx,0
  je l3  
  cmp dx,0
  jne l4
l4:
  inc bx
  jmp l2
l5:
  print 'no prime numbers'
  hlt 
l6:
  hlt   
i dw 2 
define_scan_num  
define_print_num
define_print_num_uns  
   
  
    
  