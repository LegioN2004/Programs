.data

  str: .asciiz "Hello, world!\n"
  number1: .word 25
  number2: .word 12

.text
.globl main
main:

  li $v0, 4
  la $a0, str
  syscall

  la $t0, number1
  lw $s1, 0($t0)
  la $t1, number2
  lw $s2, 0($t1)
  add $s3, $s1, $s2
  

  li $v0, 1
  move $a0, $s3
  syscall

  li $v0, 10
  syscall

