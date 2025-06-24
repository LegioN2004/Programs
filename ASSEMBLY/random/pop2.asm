.data
.align 2
array: .space 40
welcome_msg: .asciiz "Welcome! The list is currently empty. Ready to push/pop 10 times.\n"
iteration_msg: .asciiz "\nIteration "
prompt_msg: .asciiz ": Enter \"u\" to push, enter \"o\" to pop.\n"
push_msg: .asciiz "\nEnter the number that will be added to the list.\n"
added_msg: .asciiz "Added"
removed_msg: .asciiz "\n has been removed from the list.\n"
nothing_to_pop_msg: .asciiz "Nothing to pop.\n"
end_msg: .asciiz "End of list push/pop operations.\n"
saving_msg: .asciiz "Now saving some registers and calling procedure addproc.\n"
restoring_msg: .asciiz "Returned from addproc. Restoring registers.\n"
list_size_msg: .asciiz "The list has "
elements_msg: .asciiz " elements.\n"
contents_msg: .asciiz "The contents of the list are:\n"
sum_msg: .asciiz "The sum is "
newline: .asciiz "\n"

.text
.globl main

main:

    li $v0, 4
    la $a0, welcome_msg
    syscall


    la $t0, array
    li $t1, 0
    li $t2, 1

loop:
    # Check if 10 iterations are complete
    beq $t2, 11, end_loop

    # Print iteration message
    li $v0, 4
    la $a0, iteration_msg
    syscall

    # Print iteration number
    li $v0, 1
    move $a0, $t2
    syscall

    # Print prompt message
    li $v0, 4
    la $a0, prompt_msg
    syscall

    # Read user input (push or pop)
    li $v0, 12
    syscall
    move $t3, $v0        # $t3 = user input ('u' or 'o')

    # Check if user wants to push
    li $t4, 'u'
    beq $t3, $t4, push

    # Check if user wants to pop
    li $t4, 'o'
    beq $t3, $t4, pop

    # Invalid input, skip to next iteration
    j skip

push:
    # Check if array is full
    li $t4, 10
    beq $t1, $t4, skip   # If full, skip push

    # Prompt for value to push
    li $v0, 4
    la $a0, push_msg
    syscall

    # Read integer to push
    li $v0, 5
    syscall
    move $t5, $v0        # $t5 = value to push

    # Store value in array
    mul $t6, $t1, 4      # offset = size * 4
    add $t6, $t6, $t0    # address = base + offset
    sw $t5, 0($t6)       # Store value at calculated address

    # Increment size
    addi $t1, $t1, 1

    # Print added message
    li $v0, 4
    la $a0, added_msg
    syscall

    li $v0, 1
    move $a0, $t5
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    j skip

pop:
    # Check if array is empty
    beqz $t1, nothing_to_pop

    # Decrement size
    subi $t1, $t1, 1

    # Calculate address for loading value
    mul $t6, $t1, 4      # offset = (size - 1) * 4
    add $t6, $t6, $t0    # address = base + offset

    # Load value from array
    lw $t5, 0($t6)       # $t5 = value to pop

    # Print removed message
    li $v0, 1
    move $a0, $t5
    syscall

    li $v0, 4
    la $a0, removed_msg
    syscall

    j skip

nothing_to_pop:
    # Print nothing to pop message
    li $v0, 4
    la $a0, nothing_to_pop_msg
    syscall

skip:
    # Increment iteration counter
    addi $t2, $t2, 1
    j loop

end_loop:

    li $v0, 4
    la $a0, end_msg
    syscall

    li $v0, 4
    la $a0, saving_msg
    syscall

    move $a0, $t0
    move $a1, $t1
    jal addproc
    move $t9, $v0

    # Restore the array base address that was overwritten in addproc
    la $t0, array      # Add this line to fix the error

    li $v0, 4
    la $a0, restoring_msg
    syscall

    # Print list size
    li $v0, 4
    la $a0, list_size_msg
    syscall

    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 4
    la $a0, elements_msg
    syscall


    li $v0, 4
    la $a0, contents_msg
    syscall

print_loop:
    li $t2, 0              # Reset iteration counter
    beq $t2, $t1, print_sum

print_loop_body:
    # Print index (1-based)
    addi $t3, $t2, 1
    li $v0, 1
    move $a0, $t3
    syscall

    # Print space
    li $v0, 4
    la $a0, newline
    syscall

    # Calculate address of current element
    mul $t4, $t2, 4        # offset = index * 4
    add $t4, $t4, $t0      # address = base + offset

    # Debugging: Print calculated address
    li $v0, 1
    move $a0, $t4
    syscall

    # Load value from array
    lw $a0, 0($t4)         # Load value from array
    li $v0, 1
    syscall

    # Print newline
    li $v0, 4
    la $a0, newline
    syscall

    # Increment iteration counter
    addi $t2, $t2, 1
    bne $t2, $t1, print_loop_body

print_sum:
    # Print sum message
    li $v0, 4
    la $a0, sum_msg
    syscall

    # Print the sum
    li $v0, 1
    move $a0, $t9
    syscall

    # Print newline
    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 10
    syscall


addproc:
    addi $sp, $sp, -8      # Allocate space on stack
    sw $ra, 0($sp)         # Save return address
    sw $s0, 4($sp)         # Save $s0

    move $s0, $a0          # $s0 = base address of array
    move $t7, $a1          # Use $t7 instead of $t0 for size
    li $t8, 0              # Use $t8 instead of $t1 for index
    li $v0, 0              # $v0 = sum

sum_loop:
    beq $t8, $t7, sum_done # Exit loop if index == size

    # Calculate address of current element
    mul $t2, $t8, 4        # offset = index * 4
    add $t3, $s0, $t2      # address = base + offset

    # Load value from array
    lw $t4, 0($t3)         # Load value from array

    # Add value to sum
    add $v0, $v0, $t4

    # Increment index
    addi $t8, $t8, 1
    j sum_loop

sum_done:
    lw $ra, 0($sp)         # Restore return address
    lw $s0, 4($sp)         # Restore $s0
    addi $sp, $sp, 8       # Deallocate stack space
    jr $ra                 # Return to caller
