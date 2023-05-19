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
m1: 
 mov cx,a[si]
 mov max,cx
 add si,2
 dec n
 cmp n,0
 jg m2 
 je m5
m2:
  mov dx,a[si]
  cmp dx,max
  jg m3        ;for min jg=jl,jle=jge
  jle m4
m4:
  add si,2
  dec n
  cmp n,0
  jg m2    
  je m5
m3:  
  mov max,dx
  add si,2
  dec n
  cmp n,0
  jg m2
  je m5  
m5:
  mov ax,max
  print 'max ele:'
  call print_num
define_print_num
define_print_num_uns
define_scan_num
n dw 0
a dw ? 
max dw 0      