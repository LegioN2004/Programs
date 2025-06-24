.data

newline:    .asciiz "\n"

.text

            .globl  main

main:
	li      $a0,        5                      # number to calculate factorial of
	jal     factorial                          # call factorial function
	move    $t0,        $v0                    # save result to $t0

	# print result
	li      $v0,        1
	move    $a0,        $t0
	syscall

	# print newline
	li      $v0,        4
	la      $a0,        newline
	syscall

	# exit program
	li      $v0,        10
	syscall

	# factorial function
	# input: $a0 = n
	# output: $v0 = factorial(n)
factorial:
	addi    $sp,        $sp,        -8         # make space on stack
	sw      $ra,        4($sp)                 # save return address
	sw      $a0,        0($sp)                 # save argument n

	li      $t1,        1
	blt     $a0,        $t1,        base_case  # if n <= 1, return 1

	addi    $a0,        $a0,        -1         # n = n - 1
	jal     factorial                          # recursive call: factorial(n-1)

	lw      $a0,        0($sp)                 # restore original n
	mul     $v0,        $a0,        $v0        # n * factorial(n - 1)

	lw      $ra,        4($sp)                 # restore return address
	addi    $sp,        $sp,        8          # pop stack
	jr      $ra                                # return

base_case:
	li      $v0,        1                      # <--️ FIX: Set return value to 1
	lw      $ra,        4($sp)
	addi    $sp,        $sp,        8
	jr      $ra