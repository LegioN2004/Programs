.data
	message: .asciiz "Enter value of the pi: "
	zeroFloat: .float 0.0
.text
	lwc1 $f0, zeroFloat
	
	li $v0, 4
	la $a0, message
	syscall
	
	#read users input
	li $v0, 6
	syscall