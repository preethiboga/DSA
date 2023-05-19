include 'emu8086.inc'  
print 'start:'
printn
call scan_num
printn 
mov si,cx   
print 'end:'
call scan_num
printn 
cmp si,1
je l7
l7:
  inc si
  jmp l
l:
   cmp si,cx
   jg l6  
   mov ax,si
   mov bx,2
   cmp ax,2
   je l1 
   cmp ax,2
   jne l2
l1: 
  mov ax,si
  call print_num  
 printn
  inc si
  jmp l
l3:
  inc si
  jmp l    
l2: 
  cmp bx,si
  je l1
  mov ax,si
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
   
  
    
  