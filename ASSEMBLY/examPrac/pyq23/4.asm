.data
array:      .word   3, 4, 2, 9, 10, 29, 3, 4, 1, 7
length:     .word   10
message:    .asciiz "sum of array elements: "
.text
	la      $t0,    array
	li      $t1,    0                                  # index
	li      $t2,    0                                  # sum
	lw      $t3,    length

loop:

	beq     $t1,    $t3,     endLoop

	lw      $t4,    0($t0)
	add     $t2,    $t2,    $t4
	addi    $t0,    $t0,    4
	# sll $t0, $t0, 2
	addi    $t1,    $t1,    1

	j       loop

endLoop:
    move $s1, $t2

	li      $v0,    4
    la $a0, message
    syscall

	li      $v0,    1
    move $a0, $s1
    syscall

    li $v0, 10
    syscall
