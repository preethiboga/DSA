include 'emu8086.inc'
mov cx,9
mov si,0
l:
  cmp a[si],'e'
  je over
  jne l1
l1: 
  inc c
  cmp a[si],cx
  je l2
  jne l3
l2: 
  print 'key position:'
  mov ax,c
  call print_num
  hlt
l3:
  add si,2
  jmp l 
over: 
  print 'key not found'
  hlt 
define_print_num
define_print_num_uns
c dw 0  
a dw 10,9,7,0,2,'e'    