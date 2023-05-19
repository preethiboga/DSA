include 'emu8086.inc'   
mov si,0  
print 'enter n:'
call scan_num
printn
mov n,cx
mov bx,cx
create: 
  cmp n,0
  je intalize
  call scan_num
  printn
  mov a[si],cx
  add si,2
  dec n
  jmp create
intalize: 
  sub si,2
  mov n,bx
  print 'array elements reverse:'
printarray:
  cmp n,0  
  je over
  mov ax,a[si]
  call print_num
  print " "
  sub si,2
  dec n
  jmp printarray
  
over:
  hlt
define_scan_num
define_print_num
define_print_num_uns
n dw 0
a dw n dup(?)  
