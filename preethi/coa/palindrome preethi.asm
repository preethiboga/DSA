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
   mov al,ch
   mul bl
   add al,dh
   mov ch,al  
   mov  al,dl
   cmp al,0
   jg label
   cmp al,0
   jz l
l:
  cmp ch,cl
  jz l2
  jnz l3
l2:
 print 'pal'
 ret
l3:
  print 'not pal'
  ret  
define_scan_num   
   