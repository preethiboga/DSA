include 'emu8086.inc'
mov cl,32
mov al,cl
mov bl,10
mov ch,0
cmp cl,0
jg l1
l1:  
  mov ah,0
  div bl
  add ch,ah 
  cmp al,0
  jg l1
  cmp al,0
  je l2
l2:  
  mov ah,0
  mov al,ch
  call print_num 
  define_scan_num
  define_print_num
  define_print_num_uns
  hlt  
 
  