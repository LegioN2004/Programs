.data
	message: .asciiz "hello\n"
.text
	main:
		# jump at link and the target is the name of the function
		jal displayMessage
		
		addi $s0, $zero, 10
		
		li $v0, 1
		add $a0, $zero, $s0
		syscall

		# tells the system that the program is done
		li $v0, 10
		syscall
	
	displayMessage:
		#displays the text on the screen
		li $v0, 4
		la $a0, message
		syscall
		
		# returns the execution back to the function or place or procedure that called it, i.e main function
		jr $ra
