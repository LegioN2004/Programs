.data
prompt:     .asciiz "Enter 1 to push, 2 to pop: "
push_prompt:.asciiz "Enter value to push: "
array:      .space 40         # 10 integers * 4 bytes = 40 bytes
newline:    .asciiz "\n"
sum_msg:    .asciiz "Sum of list elements: "

.text
.globl main

main:
    la $t0, array        # $t0 = base address of array
    li $t1, 0            # $t1 = size (number of elements in array)

    li $t2, 0            # loop counter
loop:
    beq $t2, 10, end_loop

    # Prompt user
    li $v0, 4
    la $a0, prompt
    syscall

    # Read input
    li $v0, 5
    syscall
    move $t3, $v0        # $t3 = user choice (1 = push, 2 = pop)

    beq $t3, 1, push
    beq $t3, 2, pop
    j skip               # Invalid input

push:
    # Check if array is full
    li $t4, 10
    beq $t1, $t4, skip   # If full, skip push

    # Prompt for value
    li $v0, 4
    la $a0, push_prompt
    syscall

    # Read integer
    li $v0, 5
    syscall
    move $t5, $v0        # $t5 = value to push

    # Store value in array
    mul $t6, $t1, 4      # offset = size * 4
    add $t6, $t6, $t0    # address = base + offset
    sw $t5, 0($t6)

    addi $t1, $t1, 1     # size++

    j skip

pop:
    beqz $t1, skip       # if size == 0, do nothing
    subi $t1, $t1, 1     # size--

skip:
    addi $t2, $t2, 1     # loop counter++
    j loop

end_loop:
    # Call addproc(array, size)
    move $a0, $t0        # $a0 = base address
    move $a1, $t1        # $a1 = size
    jal addproc

    # Print sum
    li $v0, 4
    la $a0, sum_msg
    syscall

        # After returning from addproc
    move $t0, $v0        # save the sum in $t0

      move $t0, $v0        # save result from addproc

    li $v0, 4
    la $a0, sum_msg
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 4
    la $a0, newline
    syscall


    
    li $v0, 10
    syscall

# Procedure: addproc
# Input: $a0 = address of array, $a1 = number of elements
# Output: $v0 = sum of elements

addproc:
    addi $sp, $sp, -8
    sw $ra, 0($sp)
    sw $s0, 4($sp)

    move $s0, $a0        # base address
    move $t0, $a1        # number of elements
    li $t1, 0            # index
    li $v0, 0            # sum

sum_loop:
    beq $t1, $t0, sum_done

    mul $t2, $t1, 4
    add $t3, $s0, $t2
    lw $t4, 0($t3)
    add $v0, $v0, $t4

    addi $t1, $t1, 1
    j sum_loop

sum_done:
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    addi $sp, $sp, 8
    jr $ra
