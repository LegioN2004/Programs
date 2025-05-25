.data
prompt:     .asciiz "Enter a positive integer: "
resultMsg:  .asciiz "Factorial is: "

.text
.globl main

main:
    # Prompt user for input
    li $v0, 4
    la $a0, prompt
    syscall

    # Read integer input
    li $v0, 5
    syscall
    move $a0, $v0  # Move input to $a0 for function argument

    # Call factorial function
    jal factorial
    move $s0, $v0  # Store result in $s0

    # Display result message
    li $v0, 4
    la $a0, resultMsg
    syscall

    # Print factorial result
    li $v0, 1
    move $a0, $s0
    syscall

    # Exit program
    li $v0, 10
    syscall

# Recursive factorial function
factorial:
    # Base case: if n == 0, return 1
    li $t0, 0
    beq $a0, $t0, base_case

    # Recursive case
    addi $sp, $sp, -8       # Allocate stack space
    sw $ra, 4($sp)          # Save return address
    sw $a0, 0($sp)          # Save current n

    addi $a0, $a0, -1       # n - 1
    jal factorial           # Recursive call

    lw $a0, 0($sp)          # Restore n
    lw $ra, 4($sp)          # Restore return address
    addi $sp, $sp, 8        # Deallocate stack space

    mul $v0, $a0, $v0       # n * factorial(n - 1)
    jr $ra                  # Return

base_case:
    li $v0, 1               # Return 1
    jr $ra
