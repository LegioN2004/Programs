.data

message:        .asciiz "enter the number to find the factorial of: "
doneMessage:    .asciiz "the factorial of the number is: "
number:         .word   0
answer:         .word   0

.text

	li      $v0,        4
	la      $a0,        message
	syscall

	li      $v0,        5
	syscall

	sw      $v0,        number

	lw      $a0,        number
	jal     factorial
	sw      $s0,        answer

	li      $v0,        4
	la      $a0,        doneMessage
	syscall

	li      $v0,        1
	la      $a0,        answer
	syscall

factorial:

	subu    $sp,        $sp,            8
	sw      $ra,        0($sp)
	sw      $s0,        4($sp)


	li      $v0,        1
	beq     $a0,        0,              factDone

	jal     factorial

	mul     $s0,        $a0,            $s0
	sub     $a0,        $a0,            1

factDone:
	addu    $sp,        $sp,            8
	# sw      0($sp),     $ra
	# sw      4($sp),     $s0
	lw      $ra,        0($sp)
	lw      $s0,        4($sp)
	jr      $ra

