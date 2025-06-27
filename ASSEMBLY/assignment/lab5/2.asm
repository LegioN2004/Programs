.data
prompt:     .asciiz "Enter the position (n) for Fibonacci: "
resultMsg:  .asciiz "Fibonacci number is: "
newline:    .asciiz "\n"

.text
            .globl  main

main:
	# Prompt user for input
	li      $v0,        4
	la      $a0,        prompt
	syscall

	# Read integer input
	li      $v0,        5
	syscall
	move    $a0,        $v0                                        # Move input to $a0 for function argument

	# Call fibonacci function
	jal     fibonacci
	move    $s0,        $v0                                        # Store result in $s0

	# Display result message
	li      $v0,        4
	la      $a0,        resultMsg
	syscall

	# Print Fibonacci result
	li      $v0,        1
	move    $a0,        $s0
	syscall

	# Print newline
	li      $v0,        4
	la      $a0,        newline
	syscall

	# Exit program
	li      $v0,        10
	syscall

	# Recursive fibonacci function
fibonacci:
	# Base case: if n == 0, return 0; if n == 1, return 1
	beq     $a0,        $zero,      fib_zero
	li      $t0,        1
	beq     $a0,        $t0,        fib_one

	# Recursive case
	addi    $sp,        $sp,        -12                            # Allocate stack space for $ra, $a0, and $t1
	sw      $ra,        8($sp)                                     # Save return address
	sw      $a0,        4($sp)                                     # Save current n

	addi    $a0,        $a0,        -1                             # n - 1
	jal     fibonacci

	sw      $v0,        0($sp)                                     # Save result of fibonacci(n-1)

	lw      $a0,        4($sp)                                     # Restore n
	addi    $a0,        $a0,        -2                             # n - 2
	jal     fibonacci

	lw      $t1,        0($sp)                                     # Load result of fibonacci(n-1)
	add     $v0,        $v0,        $t1                            # fibonacci(n-1) + fibonacci(n-2)

	lw      $ra,        8($sp)                                     # Restore return address
	addi    $sp,        $sp,        12                             # Deallocate stack space
	jr      $ra                                                    # Return

fib_zero:
	li      $v0,        0
	jr      $ra

fib_one:
	li      $v0,        1
	jr      $ra
