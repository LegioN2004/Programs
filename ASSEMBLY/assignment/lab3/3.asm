.data
	a: .word 24
	b: .word 9
	c: .word 10
	
.text 
	main:
		lw $t5, a
		lw $t2, b
		lw $t3, c
		
		bgt $t2, $t5, setValueB
		bgt $t3, $t5, setValueC
		j printValue
		
	setValueB:
		move $t5, $t2
		j checkC	
	setValueC:
		move $t5, $t3
		j printValue
		
	checkC:
		bgt $t3, $t5, setValueC
		j printValue
		
	printValue:
		li $v0, 1
		move $a0, $t5
		syscall 
