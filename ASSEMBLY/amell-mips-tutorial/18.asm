.data
	num1: .word 1
	num2: .word 2

.text
main:
	
	lw $t2, num1
	lw $t3, num2
	add $t1,$t2,$t3
	add $t1,$t1,$t1
	addi $t3,$zero,1000
	lw $t2,16($gp)
	sw $t2,4($s5)
	loop1:
	bne $s1,$s2,loop1
	