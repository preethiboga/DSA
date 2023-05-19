include 'emu8086.inc' 
mov ax,0
mov si,0 
label: 
cmp a[si],0
je over
cmp a[si],0
jne l
l:
  add ax,a[si] 
  add si,2
  jmp label
over:
  call print_num
define_print_num
define_print_num_uns    
a dw 1,2,3,4,5,0