.data
	message1: .asciiz "a < b"
	message2: .asciiz "a > b"
.text
	
	li $t0, 3 # a
	li $t1, 2 # b
	
	bgt $t0, $t1, exit
	
	li $v0, 4
	la $a0, message1
	syscall
	
	li $v0, 10
	syscall
	
	exit: 
		li $v0, 4
		la $a0, message2
		syscall 
		
		li $v0, 10
		syscall
	