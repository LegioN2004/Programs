	# 2. fib

	# .data
	# prompt:     .asciiz "nth: "
	# message:    .asciiz "It is "
	# .text
	#             .globl  main

	# main:
	# 	li      $v0,    4
	# 	la      $a0,    prompt
	# 	syscall

	# 	li      $v0,    5
	# 	syscall

	# 	move    $a0,    $v0

	# 	jal     fib
	# 	move    $s0,    $v0

	# 	li      $v0,    4
	# 	la      $a0,    message
	# 	syscall

	# 	li      $v0,    1
	# 	move    $a0,    $s0
	# 	syscall

	# 	li      $v0,    10
	# 	syscall

	# fib:
	# 	beq     $a0,    $zero,      fib_zero

	# 	li      $t0,    1
	# 	beq     $a0,    $t0,        fib_one

	# 	subu    $sp,    $sp,        8
	# 	sw      $ra,    0($sp)
	# 	sw      $a0,    4($sp)

	# 	sub     $a0,    $a0,        1
	# 	jal     fib
	# 	move    $t1,    $v0

	# 	lw      $a0,    4($sp)
	# 	sub     $a0,    $a0,        2
	# 	jal     fib
	# 	move    $t2,    $v0

	# 	add     $v0,    $t1,        $t2

	# 	lw      $ra,    0($sp)
	# 	addu    $sp,    $sp,        8
	# 	jr      $ra

	# fib_zero:
	# 	li      $v0,    0
	# 	jr      $ra

	# fib_one:
	# 	li      $v0,    1
	# 	jr      $ra


	# 3. recursive array all element addition

.data

array:  .word   1, 2, 3, 4, 5
length: 	5

.text

	la      $a0,        array
	la      $a1,        length

	jal     function
	move    $t0,        $s0

	li      $v0,        1
	move    $a0,        $t0
	syscall

function:
	la      $t0,        0($a0)
	la      $t1,        $a1

	subu    $sp,        $sp,    20
	subu    $sp,        $sp,    20

	beq     $t0,        $t1,    end
	addi    $t1,        $t1,    1
	addi    $t1,        $t0,    $t0

end:
	jr      $ra