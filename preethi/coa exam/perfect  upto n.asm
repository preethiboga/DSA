include 'emu8086.inc'
print 'enter start:'
call scan_num
mov di,cx 
printn
print 'enter end:'
call scan_num 
printn 
cmp di,1
je l10
l10:
 inc di
 jmp l1
l1: 
 cmp di,cx 
 jg l2
  mov si,1
  mov bx,2
  mov ax,0
  mov ax,di 
  mov n,ax
  sub ax,1
  mov c,ax
  mov ax,n
  cmp ax,0
  jg l3  
l2: 
  hlt
l3: 
  cmp bx,c
  jg l7
  mov ax,di
  mov dx,0
  div bx
  cmp dx,0
  je l4
  cmp dx,0
  jne l5
l4:
  add si,bx
  inc bx
  jmp l3
l5:
  inc bx
  jmp l3
l7:
  cmp si,di
  je l8
  cmp si,di
  jne l9
l8:
  mov ax,si
  call print_num   
  printn
  inc di 
  jmp l1
l9:
  inc di
  jmp l1 
           
   
 
   
i dw 2 
n dw 0  
c dw 0  
define_print_num
define_print_num_uns
define_scan_num

