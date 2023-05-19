include 'emu8086.inc'
mov si,0  
;print 'enter n:'
;call scan_num    
;printn  
mov cx,5
mov n,cx
mov bx,cx 
create:
  call scan_num 
  ;printn
  mov a[si],cx
  add si,2
  dec n
  cmp n,0
  jg create 
  je print
print:
  mov si,0
  mov n,bx
printarray:
  mov ax,a[si]
  call print_num
  add si,2 
  dec n
  cmp n,0
  jg printarray
  jmp intalize
intalize:
  mov si,0 
  mov ax,0
  mov n,bx 
  jmp l 
l:
  cmp n,0
  je over
  jne l1
l1:
  add ax,a[si]
  add si,2 
  dec n
  jmp l 
over:
  call print_num
  hlt
a dw ? 
n dw 0 
c dw 0
define_print_num
define_print_num_uns 
define_scan_num   
    