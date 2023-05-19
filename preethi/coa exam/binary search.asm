include 'emu8086.inc'  
mov cx,7
mov di,2 
l:  
  mov ax,s
  mov bx,e
l6: 
  cmp ax,bx
  jg over
  cmp ax,bx
  jle l7
l7:
 add ax,bx 
 mov dx,0
 div di
 mov mid,ax
l1:
  mov si,mid
  mov ax,mid
  mov dx,0
  div di
  cmp dx,0
  je l8 
  jne l9
l9:
  add si,1
  jmp l8  
l8:  
  cmp a[si],cx 
  je l2
  jne l3
l2:
  print 'key found at position:'
  mov ax,si
  mov dx,0
  div di
  add ax,1 
  call print_num  
  hlt
l3:
  cmp cx,a[si]
  jg l4
  jl l5
l4:
  mov ax,mid
  add ax,2
  mov s,ax
  jmp l
l5:  
  mov bx,mid
  sub bx,2
  mov e,bx
  jmp l   
over: 
  print 'key not found'
  hlt

    
  
     
  
define_print_num
define_print_num_uns
  
a dw 1,2,3,4,5,6,7,8,9,10
s dw 0 
e dw 18  
mid dw 0 
t dw 0
    
    
  