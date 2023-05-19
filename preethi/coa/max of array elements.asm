include 'emu8086.inc' 
mov si,0
mov ax,a[si]  
add si,2
label: 
    cmp a[si],0
    je over
    cmp a[si],0
    jne l
l: 
  cmp a[si],ax
  jg l1
  cmp a[si],ax
  jle l2
over:
  call print_num 
  hlt
l1:
  mov ax,a[si]
  add si,2
  jmp label 
l2: 
  add si,2
  jmp label     
define_print_num
define_print_num_uns    
a dw 1,2,19,4,5,0 