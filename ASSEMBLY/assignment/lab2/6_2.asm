.data

memory: .space 28
newline: .asciiz "\n"

.text
.globl main
main:

    la $t0, memory

    li $t1, 0

loop:

    sll $t2, $t1, 3 # 0*8, 1*8
    sll $t3, $t1, 2 # 0*4, 1*4
    
    add $t3, $t3, $t0 # 4-7
    addi $t3, $t3, 8 # 8, 12

    sw $t2, 0($t3) # t3[0]=0, t3[1]=8

    addi $t1, $t1, 1 # i=t1=1, t1=2

    li $v0, 1
    lw $a0, 0($t3)
    syscall
    
    li $v0, 4
    la $a0, newline
    syscall

    blt $t1, 5, loop

    sw $t1, 4($t0)

    li $v0, 10
    syscall
