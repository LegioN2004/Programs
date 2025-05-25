.data
prompt: .asciiz "Enter a non-negative integer: "
result: .asciiz "Factorial: "
newline: .asciiz "\n"

.text
.globl main

main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $a0, $v0

    jal fact
    move $t0, $v0

    li $v0, 4
    la $a0, result
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    # Exit
    li $v0, 10
    syscall

fact:
    # Base case: if n < 1, return 1
    slti $t0, $a0, 1
    beq $t0, $zero, L1
    addi $v0, $zero, 1
    jr $ra

L1:
    # Recursive case
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)
    addi $a0, $a0, -1
    jal fact
    lw $a0, 0($sp)
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    mul $v0, $a0, $v0
    jr $ra