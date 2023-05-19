include 'emu8086.inc'
mov si,0
l:
  cmp a[si],'e'
  je over
  jne l1
l1:
  mov ax,a[si]
  mov n,ax
  mov bx,2
  cmp ax,1
  je l6 
  cmp ax,2
  je l2
  jne l3
l2: 
  mov ax,n
  call print_num
  print '->'
  print 'prime' 
  printn 
  add si,2
  jmp l
l3:
  mov ax,n
  mov dx,0
  div bx
  cmp dx,0
  je l4
  jne l5
l4: 
  mov ax,n
  call print_num
  print '->'
  print 'not prime'
  printn  
  add si,2
  jmp l
l5:
  inc bx
  cmp bx,n
  je l2
  jl l3 
over:
  hlt  
l6:
  call print_num
  print '->'
  print 'not prime'
  printn  
  add si,2
  jmp l    
n dw 0
define_print_num
define_print_num_uns
a dw 1,2,3,4,5,6,7,8,9,10,'e'  
    
      
    