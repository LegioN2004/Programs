.data
N:  .word   5
.text
.globl main

main:
	li      $t1,    1                  # index
	li      $t2,    0                  # sum
	lw      $t3,    N                  # length

loop:
	bgt     $t1,    $t3,    endLoop
	add     $t2,    $t2,    $t1
	addi    $t1,    $t1,    1
	j       loop

endLoop:
	li      $v0,    1
	move      $a0,    $t2
	syscall

	li      $v0,    10
	syscall