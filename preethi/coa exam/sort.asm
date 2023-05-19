include 'emu8086.inc'
mov si,0  
print 'enter n:'
call scan_num   
printn
mov n,cx
mov bx,cx
mov m,bx
create: 
  cmp n,0
  je intalize
  call scan_num 
  printn
  mov a[si],cx
  add si,2
  dec n
  jmp create
intalize:
  mov si,0
  mov n,bx 
  print 'elements are:' 
printarray: 
  cmp n,0
  je over
  mov ax,a[si]
  call print_num 
  printn
  add si,2
  dec n
  jmp printarray
over:
  mov dx,1000
  mov si,0
  mov n,bx
  mov di,0
l1: 
  cmp m,0
  je last
  cmp n,0
  je l2
  cmp dx,a[si]
  jg l3 
  add si,2
  dec n
  jmp l1
l3:
  mov dx,a[si]
  mov p,si
  add si,2
  dec n
  jmp l1 
l2:
  mov b[di],dx   
  add di,2
  mov dx,1000 
  dec m  
  mov si,p
  mov a[si],1000
  mov si,0
  mov n,bx
  jmp l1
last:
  mov di,0
  mov m,bx  
  
l4:
  cmp m,0
  je h 
  mov ax,b[di]
  call print_num  
  print " "
  add di,2
  dec m
  jmp l4
h:
  hlt         
ret
n dw 0
a dw n dup(?)  
b dw n dup(?)
p dw 0 
m dw 0
define_scan_num
define_print_num
define_print_num_uns
    
    
    
  
  
  
    
      
    
        
  
    