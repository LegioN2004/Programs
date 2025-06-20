.data
 
  value1: .word 10
  value2: .word 10

.text
  lw $t0, value1
  lw $t1, value2

  mult $t0, $t1
  mflo $s0

  li $v0, 1
  move $a0, $s0
  syscall
