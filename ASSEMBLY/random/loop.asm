.data

.text

	loop: 
		sll $t1, $t3, 2
		add $t1, $t1, $s6
		lw $t0, 0($t1)
		bne $t0, $s5, Exit
		addi $s3, $s3, 1
		j loop
	Exit:
		li $v0, 1
		syscall