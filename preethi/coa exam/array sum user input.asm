include 'emu8086.inc'
mov si,0  
print 'enter n:'
call scan_num
printn
mov n,cx
mov bx,cx
create:
  call scan_num
  printn
  mov a[si],cx
  add si,2
  dec n
  cmp n,0
  jg create
  je intalize
intalize:
  mov si,0
  mov n,bx
  print 'array elements sum:'
printarray:
  add ax,a[si]
  add si,2
  dec n
  cmp n,0
  jg printarray
  je over
over:
  call print_num
define_scan_num
define_print_num
define_print_num_uns
n dw 0
a dw ?         