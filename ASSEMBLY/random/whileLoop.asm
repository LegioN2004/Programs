.data
	array: .word 3, 2, 1, 5, 7, 9
	space: .asciiz ", "
	
.text
	li $t0, 0 # i = 0
	
	while:
		beq $t0, 24, exit # kiman jega lage for integer
		lw $t2, array($t0) # array(index) index = t0 register
		addi $t0, $t0, 4 # jega bohai jabo lagibo, 0 = 3, 4 = 2, 8 = 1, ..............
		
		li $v0, 1
		move $a0, $t2
		syscall
		
		li $v0, 4
		la $a0, space
		syscall
		
		j while
		
	exit:
		li $v0, 10
		syscall
		
		