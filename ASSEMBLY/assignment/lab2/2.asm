.data
values: .word 10, 20, 0, 0, 0  # Define initial data

.text
.globl main
main:
    # Initialize $gp if needed
    la $gp, values

    lw $s1, 0($gp)
    lw $s2, 4($gp)
    addi $s1, $s1, 5
    addi $s2, $s2, 9
    sw $s1, 8($gp)
    sw $s2, 12($gp)
    add $s2, $s2, $s1
    sw $s2, 16($gp)

    # Exit program
    li $v0, 10
    syscall