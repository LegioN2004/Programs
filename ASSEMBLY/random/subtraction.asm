.data
  
  value1: .word 21
  value2: .word 12


.text

  lw $t0, value1
  lw $t1, value2

  sub $t3, $t0, $t1

  li $v0, 1
  move $a0, $t3
  syscall
