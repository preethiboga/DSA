include 'emu8086.inc' 
call scan_num   
printn
cmp cx,0
jg l1
cmp cx,0
jl l2
cmp cx,0
je l3
l1:   
  print 'positive'
  ret
l2:
  print 'negative'
  ret
l3:
  print 'zero'
  ret    
         
define_scan_num    
define_print_num
define_print_num_uns     
