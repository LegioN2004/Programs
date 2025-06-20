.data

.text

	li $t0, 2
	li $t1, 2

	div $t3, $t0, $t1

		li $v0, 1
		move $a0, $t3
		syscall
