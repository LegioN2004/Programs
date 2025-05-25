.data
array:      .word 5, 10, 15, 20, 25
length:     .word 5
resultMsg:  .asciiz "Sum of array elements is: "

.text
.globl main

main:
    # Load base address of array into $a0
    la $a0, array

    # Load length of array into $a1
    lw $a1, length

    # Call sum_array function
    jal sum_array
    move $s0, $v0  # Store result in $s0

    # Display result message
    li $v0, 4
    la $a0, resultMsg
    syscall

    # Print sum result
    li $v0, 1
    move $a0, $s0
    syscall

    # Exit program
    li $v0, 10
    syscall

# Recursive sum_array function
sum_array:
    # Base case: if length == 0, return 0
    li $t0, 0
    beq $a1, $t0, sum_base

    # Recursive case
    addi $sp, $sp, -12      # Allocate stack space for 3 words
    sw $ra, 8($sp)          # Save return address
    sw $a0, 4($sp)          # Save current array address
    
    lw $t1, 0($a0)          # Load current element
    sw $t1, 0($sp)          # Save current element value
    
    addi $a0, $a0, 4        # Move to next element
    addi $a1, $a1, -1       # Decrement length
    jal sum_array           # Recursive call

    lw $t1, 0($sp)          # Restore current element value
    lw $a0, 4($sp)          # Restore array address
    lw $ra, 8($sp)          # Restore return address
    addi $sp, $sp, 12       # Deallocate stack space

    add $v0, $v0, $t1       # Add current element to sum
    jr $ra                  # Return

sum_base:
    li $v0, 0
    jr $ra