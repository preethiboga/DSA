include 'emu8086.inc'
call scan_num
printn
mov ax,cx
mov bx,2
cmp cx,2
je l1 
cmp cx,2
jne l2
l1:
  print 'prime'
  hlt
l3:
  print 'not prime'
  hlt      
l2: 
  cmp bx, cx
  je l1
  mov ax,cx 
  mov dx,0
  div bx
  cmp dx,0
  je l3  
  cmp dx,0
  jne l4
l4:
  inc bx
  jmp l2  
define_scan_num    
   
  
    
  