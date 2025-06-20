.data

.text

	main:
		addi $s0, $zero, 10
		
		jal incReg

		li $v0, 1
		move $a0, $s0
		syscall


	li $v0, 10
	syscall

	incReg:
		# we are supposed to store the old value, so we'll be using stack
		# so we'll have to give that much space so as to store the value properly
		# allocating 4 bytes for one integer, -ve because the stack goes down. By subtracting you are allocating space to the stack. By adding we are taking space away from the stack

		addi $sp, $sp, -4
		sw $s0, 0($sp) # storing the value at s0 to the 0th index of the stack pointer

		# modifying the value of s0
		addi $s0, $s0, 30

		li $v0, 1
		move $a0, $s0
		syscall

		# since we want to have the old value, we'll need to load the value from the memory to the register.

		lw $s0, 0($sp) # from RAM
		addi $sp, $sp, 4

		jr $ra
