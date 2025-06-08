.data
	message: .asciiz "a < b"
	message2: .asciiz "a > b"
.text
	
	li $t0, 40
	li $t1, 5
	
	slt $t2, $t0, $t1 # if t0 < t1, then t2 = 1 true
	bne $t2, $zero, greater
	bne $t2, 1, lesser
	
	
	li $v0, 10
	syscall
	
	lesser:
		li $v0, 4
		la $a0, message
		syscall
		
		li $v0, 10
		syscall
	
	greater:
		li $v0, 4
		la $a0, message2
		syscall
		li $v0, 10
		syscall
		