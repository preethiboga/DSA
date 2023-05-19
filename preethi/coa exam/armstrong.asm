include 'emu8086.inc'
call scan_num
printn
mov ax,cx 
mov bx,10
l2:
  cmp ax,0
  je l1
  mov dx,0
  div bx 
  mov si,dx
  mov t,ax
  mov ax,si
  mul ax
  mul si
  add s,ax
  mov ax,t
  jmp l2
l1:
  cmp cx,s
  je l3
  jne l4
l3:
  print 'armstrong'
  hlt
l4:
  print 'not armstrong'
  hlt 
t dw 0
s dw 0         
define_scan_num

  
   
