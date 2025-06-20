.data

.text

	li $t0, 4
	
	sll $t1, $t0, 2
	
	li $v0, 1
	move $a0, $t1
	syscall
	
	