.text
.globl main
main:

  li $v0, 11
  la $a0, 'a'
  syscall

  li $v0, 10
  syscall

