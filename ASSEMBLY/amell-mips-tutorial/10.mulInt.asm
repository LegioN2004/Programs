# multiplication
.data

.text 
	# we can use mul(3 inputs), mult(2 inputs), sll(most efficient)
	addi $s0, $zero, 10
	addi $s1, $zero, 5
	
	mul $s0, $s0, $s1
	li $v0, 1
	add $a0, $zero, $s0
	syscall