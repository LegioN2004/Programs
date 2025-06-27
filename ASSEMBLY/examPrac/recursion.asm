.data

message:    .asciiz "enter a number to find its factorial: "
message2:   .asciiz "\nthe factorial of the number is: "
number:     .word   0
answer:     .word   0

.text

main:
    li $v0, 4
    la $a0, message
    syscall

    li $v0, 5
    syscall

    sw $v0, number

    lw $a0, number
    jal factorial
    sw $v0, answer

    li $v0, 4
    la $a0, message2
    syscall

    li $v0, 1
    lw $a0, answer
    syscall

    li $v0, 10
    syscall


factorial:

    subu $sp, $sp, 8
    sw $ra, 0($sp)
    sw $s0, 4($sp) # storing the value of a0 that has been passed in this function

    li $v0, 1
    beq $a0, 0, factorialDone

    move $s0, $a0
    sub $a0, $a0, 1

    jal factorial

    mul $v0, $s0, $v0


factorialDone:
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    addu $sp, $sp, 8
    jr $ra

