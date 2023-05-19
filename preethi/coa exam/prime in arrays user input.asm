include 'emu8086.inc'
print 'enter n:'
call scan_num
printn
mov n,cx
mov bx,cx
mov si,0
print 'enter elements:'  
printn
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
  print 'array elements are:'  
  printn
printarray:
   cmp n,0 
   je l1
   mov ax,a[si]
   call print_num 
   printn
   add si,2
   dec n
   jmp printarray
l1: 
  mov si,0
  mov n,bx
l2:           
  cmp n,0
  je over 
  mov bx,2
  mov ax,a[si]  
  cmp ax,1
  je l6 
  jne l7
l6:
  add si,2
  dec n
  jmp l2
l7:  
  mov p,ax 
  cmp ax,2
  je l3   
  jne l4
l3:
  mov ax,p
  call print_num  
  printn
  add si,2
  dec n
  jmp l2  
l4: 
  cmp bx,p
  je l3  
  mov ax,p
  mov dx,0 
  div bx  
  cmp dx,0
  je l5 
  inc bx
  jmp l4

  
l5:
  add si,2
  dec n
  jmp l2 
over:
  hlt  
    
  
  
       
define_print_num
define_print_num_uns
define_scan_num   
n dw 0
a dw n dup(?)  
p dw 0   


   
        
   
  