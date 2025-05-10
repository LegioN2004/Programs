.data
	array:  .word 3,4,6,7,8,9,2,3,4,6,7,8,3,6   # Array of 14 elements
	length: .word 14                           # Length of the array

.text
.globl main

main:
    la $t0, array
    li $t1, 0 #index
    lw $t2, length #length
    li $t3, 0 #sum

loop:
	beq $t1, $t2, end
	
	sll $t4, $t1, 2
	
	#address lena
	add $t5, $t0, $t4
    lw $t6, 0($t5) #value at address
    add $t3, $t3, $t6 #t3+=t6
    
    addi $t1, $t1, 1
    
    j loop
end:
	li $v0, 1
	move $a0, $t3
	syscall
	
	li $v0, 10
	syscall
	
  
