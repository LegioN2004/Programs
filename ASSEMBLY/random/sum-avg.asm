.data
	array: 	.word 1, 2, 3
	length: .word 3
	sum: 	.word 0
	average:.word 0
.text
	main:
		la $t0, array # base address
		lw $t2, length
		li $t1, 0 # i
		li $t3, 0 # for 0 because t3 = sum
	
	loop:
		lw $t4, ($t0)
		add $t3, $t3, $t4
		
		add $t1, $t1, 1
		add $t0, $t0, 4 # add to the base address to go to the next value in the array
		blt $t1, $t2, loop
		
		sw $t3, sum
			
		li $v0, 1
		move $a0, $t3
		syscall
	
	div $t5, $t3, $t2
	sw $t5, average
	
	li $v0, 1
	move $a0, $t5
	syscall
	
	li $v0, 10
	syscall