.data
prompt: .asciiz "Enter n to find nth Fibonacci number: "
output: .asciiz "The nth Fibonacci number is: "

.text
.globl main

main:
    # Prompt the user
    li $v0, 4
    la $a0, prompt
    syscall

    # Read input n
    li $v0, 5
    syscall
    move $a0, $v0      # $a0 = n

    # Call fibonacci(n)
    jal fibonacci
    move $t0, $v0      # Store result in $t0

    # Print message
    li $v0, 4
    la $a0, output
    syscall

    # Print result
    li $v0, 1
    move $a0, $t0
    syscall

    # Exit
    li $v0, 10
    syscall


# Recursive Fibonacci function
# Input:  $a0 = n
# Output: $v0 = fibonacci(n)
fibonacci:
    addi $sp, $sp, -12     # make space on stack
    sw $ra, 0($sp)         # save return address
    sw $a0, 4($sp)         # save n
    sw $s0, 8($sp)         # save s0 (used to store results)

    li $v0, 0
    beq $a0, 0, end_fib    # if n == 0, return 0

    li $v0, 1
    beq $a0, 1, end_fib    # if n == 1, return 1

    # Recursive call: fibonacci(n-1)
    addi $a0, $a0, -1
    jal fibonacci
    move $s0, $v0          # store result of fibonacci(n-1)

    # Recursive call: fibonacci(n-2)
    lw $a0, 4($sp)
    addi $a0, $a0, -2
    jal fibonacci

    add $v0, $v0, $s0      # result = fib(n-1) + fib(n-2)

end_fib:
    lw $ra, 0($sp)
    lw $a0, 4($sp)
    lw $s0, 8($sp)
    addi $sp, $sp, 12
    jr $ra
