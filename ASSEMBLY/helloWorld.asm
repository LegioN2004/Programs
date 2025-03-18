.data 
	Message: .asciiz "hello World goruuuuuuuu"
.text
	li $v0, 4
	la $a0, Message
	syscall