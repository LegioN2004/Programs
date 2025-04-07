.data
	no1: .word 5
	no2: .word 4
.text
	
	lw $s0, no1
	lw $s1, no2
	
	sub $t1, $s0, $s1
	li $v0, 1
	# add $t0, $zero, $t1
	# can also do the following
	move $a0, $t1 # just moves the value of t0 to a0
	syscall