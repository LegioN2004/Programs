.data
prompt: .asciiz "Enter a number to find its factorial: "
output: .asciiz "The factorial is: "

.text
        .globl  main

main:
	# Prompt the user
	li      $v0,        4
	la      $a0,        prompt
	syscall

	# Read input n
	li      $v0,        5
	syscall
	move    $a0,        $v0                                    # $a0 = n

	# Call factorial(n)
	jal     factorial
	move    $t0,        $v0                                    # Store result in $t0

	# Print output message
	li      $v0,        4
	la      $a0,        output
	syscall

	# Print result
	li      $v0,        1
	move    $a0,        $t0
	syscall

	# Exit
	li      $v0,        10
	syscall


	# Recursive factorial function
	# Input:  $a0 = n
	# Output: $v0 = factorial(n)
factorial:
	addi    $sp,        $sp,    -12                            # allocate stack space
	sw      $ra,        0($sp)                                 # save return address
	sw      $a0,        4($sp)                                 # save argument n
	sw      $s0,        8($sp)                                 # save $s0 (for intermediate result)

	li      $v0,        1
	ble     $a0,        1,      end_fact                       # if n <= 1, return 1

	move    $s0,        $a0                                    # save n into $s0
	addi    $a0,        $a0,    -1                             # n = n - 1
	jal     factorial                                          # recursive call: factorial(n-1)

	mul     $v0,        $v0,    $s0                            # result = n * factorial(n-1)

end_fact:
	lw      $ra,        0($sp)                                 # restore return address
	lw      $a0,        4($sp)                                 # restore argument n
	lw      $s0,        8($sp)                                 # restore $s0
	addi    $sp,        $sp,    12                             # deallocate stack
	jr      $ra                                                # return to caller
