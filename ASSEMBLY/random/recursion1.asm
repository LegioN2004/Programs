.data

answer: .word   0
.text

	li      $v0,        5
	syscall

	sw      $v0,        $a0
	jal     factorial
	sw      $a0,        answer

	li      $v0,        1
	la      $a0,        answer
	syscall


factorial:

	subu    $sp,        $sp,    8
	sw      $ra,        ($sp)
	sw      $a0,        4($sp)

	li      $a0,        1
	beq     $a0,        0,      factDone

	lw      $s0,        4($sp)
	sub     $a0,        $a0,    1
	mul     $a0,        $s0,    $a0

factDone:

	addi    $sp,        $sp,    8
	lw      $ra,        ($sp)
	lw      $a0,        4($sp)







