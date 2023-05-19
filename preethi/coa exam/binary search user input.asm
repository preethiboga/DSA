include 'emu8086.inc'
mov si,0  
print 'enter n:'
call scan_num
printn
mov n,cx
mov bx,cx
mov ax,n
sub ax,1
mov cx,2
mov dx,0
mul cx 
mov e,ax
create:
  cmp n,0
  je over
  call scan_num  
  printn
  mov a[si],cx
  add si,2
  dec n
  jmp create
over:
  mov si,0
  mov n,bx
  print 'array elements are;'
printarray: 
  cmp n,0
  je l1
  mov ax,a[si]
  call print_num
  print ' '
  add si,2
  dec n
  jmp printarray 
l1:  
  printn
  print 'enter key:'
  call scan_num
  printn
  mov key,cx 
l7: 
   mov ax,e 
   mov cx,2
   cmp s,ax
  jg last
  jle l2
l2:
   mov dx,0
   add ax,s 
   div cx
   mov mid,ax
   mov dx,0
   div cx  
   cmp dx,0 
   je l3
   jne l4
l3: 
  mov si,mid 
  mov bp,a[si]
  cmp bp,key
  je found
  jne notfound
  
l4:  
  inc mid
  jmp l3
last: 
  print 'not found'
  hlt
found:
  print 'key found'
  mov ax,mid
  call print_num
  hlt
notfound:
 
  cmp key,bp
  jg l5
  jl l6
l5:
  inc mid 
  inc mid
  mov di,mid
  mov s,di
  jmp l7 
l6:
  dec mid 
  dec mid
  mov di,mid
  mov e,di
  jmp l7
 
      
   
   
   
   
   
n dw 0  
a dw n dup(?) 
s dw 0 
e dw 0 
key dw 0
mid dw 0
define_print_num
define_print_num_uns
define_scan_num       