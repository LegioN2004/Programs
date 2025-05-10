.data
	N: .word 5
	newline: .asciiz "\n"

.text
	main:
		li $t0, 0 #store sum
		li $t1, 1 # i
		lw $t2, N #take the N value
		
	loop: 
		bgt $t1, $t2, end
		add $t0, $t0, $t1
		addi $t1, $t1, 1
		
		j loop
		
	end:
		li $v0, 1
		move $a0, $t0
		syscall
		
		li $v0, 4
		la $a0, newline
		syscall
		
		li $v0, 10
		syscall