include 'emu8086.inc'
call scan_num
printn
mov ax,cx
mov si,5
mov di,11 
cmp ax,0
jne l
l:
 mov dx,0
 div si
 cmp dx,0
 je l5
 jne l4
l5:
  print 'divisible by 5'  
  printn
  jmp l1
l1:  
  mov ax,cx 
  mov dx,0
  div di
  cmp dx,0
  je l2 
  jne l3
l2:
  print 'divisible by 11'
  printn
  hlt   
l3:
  print 'not divisible by 11'
  printn
  hlt 
l4:
  print 'not divisible by 5'
  printn
  jmp l1 
define_scan_num  
     
  
