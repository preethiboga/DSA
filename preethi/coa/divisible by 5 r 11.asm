include 'emu8086.inc'
mov cx,55
mov ax,cx
mov si,5
mov di,11
cmp ax,0
jmp label
label:
  mov ax,cx
  div si
  cmp dx,0
  je l1
  cmp dx,0
  jne l2
l2:
  print 'not divisible by 5'
  jmp l1
l1:
  mov ax,cx
  div di
  cmp dx,0
  je  l3
  cmp dx,0
  jne l4
l3:
  print 'divisible by 5 & 11'
  hlt
l4:
  print 'not divisible by 11 but divisible by 5 '
  hlt      
  
