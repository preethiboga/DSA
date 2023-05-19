include 'emu8086.inc'
call scan_num
mov al,cl
mov bh,cl
sub bh,1
mov bl,1 
mov ch,0
l:
  div bl
  cmp ah,0
  je label
l2:
  cmp ch,cl
  je l3:
  cmp ch,cl
  jne l4:
l3:
  print 'perfect'
  ret
l4:
  print 'not perfect'
  ret
label:
 add ch,bl  
 inc bl 
  cmp bh,bl
  jg l
  cmp bh,bl
  je l2
define_scan_num
        
 
  
  
  