.data
	greater: .asciiz "greater\n"
	smaller: .asciiz "smaller\n"

.text
	main: 
		li $t0, 5
		li $t1, 10
		
		bgt $t0, $t1, greater1
		
		jal smaller1
		
		li $v0, 10
		syscall
		
	greater1:
		li $v0, 4
		la $a0, greater
		syscall
		
		li $v0, 10
		syscall
	
		
	smaller1: 
		li $v0, 4
		la $a0, smaller
		syscall
		
		jr $ra