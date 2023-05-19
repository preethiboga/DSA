include 'emu8086.inc'
call scan_num
mov al,cl
mov bl,10 
mov ch,0
cmp al,0
jg label
label:
  div bl
  mov dl,al
  mov dh,ah
  mov al,ah
  mul ah
  mul dh
  add ch,al
  mov al,dl
  cmp al,0
  jg label
  cmp al,0
  jz l
l:
  cmp cl,ch
  jz l1
  jnz l2
l1:
  print 'arm' 
  ret
l2:
  print 'not arm' 
  ret  
define_scan_num   
  