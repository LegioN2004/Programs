.data
	a: .word 5

.text
	li $t1, 0       # index
	lw $t0, a
	li $t2, 8

loop:
	mul $t3, $t1, $t2   # t3 = 8 * i
	sll $t4, $t1, 2     # i * 4
	add $t4, $t4, $t0   # base + i * 4
	addi $t4, $t4, 8    # base + 8 + i * 4

	sw $t3, 0($t4)      # 8 * i in ai

	addi $t1, $t1, 1    # i++

	blt $t1, 5, loop    # i < 5

	sw $t1, 4($t0)      # final value i to mem base + 4
