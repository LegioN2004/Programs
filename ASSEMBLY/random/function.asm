.data
	message: .asciiz "hello world"
	newline: .asciiz "\n"
.text
	
	main:

		li $v0, 4
		la $a0, message
		syscall
		
		li $v0, 4
		la $a0, newline
		syscall
		
		li $t1, 5
		li $t2, 5
		
		jal printAdd
		
		
		
	printAdd:
		
		add $t3, $t1, $t2
		
		li $v0, 1
		move $a0, $t3
		syscall
		
		jr $ra
		

	
