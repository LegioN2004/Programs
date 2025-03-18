.data 
		age: .word 29
.text
		li $v0, 1
		lw $a0, age
		syscall
