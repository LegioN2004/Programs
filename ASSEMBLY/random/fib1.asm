.data
prompt:     .asciiz "Enter n to find the nth Fibonacci number: "
resultMsg:  .asciiz "The Fibonacci number is: "

.text
.globl main
main:
    # Print prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # Read integer input (n)
    li $v0, 5
    syscall
    move $a0, $v0    # move input into $a0 (arg for fib)

    # Call fib function
    jal fib
    move $s0, $v0    # save result in $s0

    # Print result message
    li $v0, 4
    la $a0, resultMsg
    syscall

    # Print Fibonacci number
    li $v0, 1
    move $a0, $s0
    syscall

    # Exit
    li $v0, 10
    syscall

# --- Fibonacci Recursive Function ---
# Input: $a0 = n
# Output: $v0 = fib(n)

fib:
    # Base Case 0: if n == 0, return 0
    beq $a0, $zero, fib_base0

    # Base Case 1: if n == 1, return 1
    li $t0, 1
    beq $a0, $t0, fib_base1

    # Recursive Case:
    # Save $ra and $a0
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)

    # First recursive call: fib(n-1)
    addi $a0, $a0, -1
    jal fib
    move $t1, $v0      # store fib(n-1)

    # Restore $a0 for second call
    lw $a0, 0($sp)
    addi $a0, $a0, -2
    jal fib
    move $t2, $v0      # store fib(n-2)

    # Add the two results
    add $v0, $t1, $t2

    # Restore $ra and clean stack
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra

fib_base0:
    li $v0, 0
    jr $ra

fib_base1:
    li $v0, 1
    jr $ra
