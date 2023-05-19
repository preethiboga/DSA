include 'emu8086.inc'
mov cl,254
mov al,cl
mov bl,10
mov ch,0
mov dl,2
cmp cl,0 
jg l1
l1:  
  mov ah,0
  div bl 
  mov dh,ah
  cmp ah,0
  jg l3
l3:
  mov var1,al
  mov al,ah
  mov ah,0
  div dl
  cmp ah,0
  jg l4
  mov al,var1
  cmp al,0
  jg l1
  cmp al,0
  jz l2
l4:
  mov ah,0
  mov al,dh
  call print_num
  add ch,dh
  mov  al,var1
  cmp al,0
  jg l1
  cmp al,0
  jz l2   
l2:  
  mov ah,0
  mov al,ch
  call print_num 
  define_scan_num
  define_print_num
  define_print_num_uns
  hlt 
var1 db 0
var2 db 0  
 
  