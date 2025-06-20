.data
	# in ram
	prompt: .asciiz "enter your age: "
	message: .asciiz "\n your age is: "

.text
	
	li $v0, 4
	la $a0, prompt
	syscall
	
	# input
	li $v0, 5 # 5 is the syscall for int input
	syscall
	
	# for using the value of v0, we'll need to use another register
	move $t0, $v0
	
	# display the message
	li $v0, 4
	la $a0, message
	syscall
	
	# print the age
	li $v0, 1
	move $a0, $t0
	syscall