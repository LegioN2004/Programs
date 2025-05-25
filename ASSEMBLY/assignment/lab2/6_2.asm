.data

memory: .space 28   

.text
.globl main
main:

    la $t0, memory  

    li $t1, 0   

loop:

    sll $t2, $t1, 3 

    sll $t3, $t1, 2  
    add $t3, $t3, $t0 
    addi $t3, $t3, 8 

    sw $t2, 0($t3)

    addi $t1, $t1, 1

    blt $t1, 5, loop

    sw $t1, 4($t0)   # Store i at baseaddress+4

    # Exit program
    li $v0, 10
    syscall
