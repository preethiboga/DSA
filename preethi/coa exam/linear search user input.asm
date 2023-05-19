include 'emu8086.inc'
mov si,0  
print 'enter n:'
call scan_num   
printn
mov n,cx
mov bx,cx
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
  mov si,0
  mov n,bx 
  print 'enter key:'
  call scan_num 
l2: 
  cmp cx,a[si]
  je l3 
  jne l4
l3: 
  printn 
  mov ax,si
  print 'key found at'  
  call print_num
  hlt
l4:
  add si,2
  dec n
  cmp n,0
  jg l2
  je l5
l5: 
  printn
   print 'not found'
  hlt          
   
   
      
define_scan_num
define_print_num
define_print_num_uns  
n dw 0    
a dw n dup(?)  
k dw 0 
c dw 0
