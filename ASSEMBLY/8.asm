.data
	no1: .word 5
	no2: .word 10
.text
		lw $t0, no1($zero)
		lw $t1, no2($zero)
		add $t3, $t0, $t1
		li $v0, 1
		add $a0, $zero, $t3
		syscall
