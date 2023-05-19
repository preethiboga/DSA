include 'emu8086.inc'
call scan_num 
mov ch,cl
mov al,0
mov bl,1
mov dh,0 
mov dl,1
cmp cl,0
jg l1
l1: 
 cmp cl,ch
 je l2
l2:
  call print_num 
  dec cl
  cmp cl,ch
  jl l3  
l3:
  mov al,bl
  call print_num
  dec cl
  cmp cl,ch
  jl l4
l4: 
  add dh,dl
  mov al,dh
  call print_num 
  mov dh,dl
  mov dl,al 
  dec cl
  cmp cl,0
  jz l5 
  cmp cl,ch
  jl l4 
call print_num 
define_scan_num
define_print_num
define_print_num_uns  
  
l5: 
  hlt  
    
   
  
 
 
   
  
  
  
    

  