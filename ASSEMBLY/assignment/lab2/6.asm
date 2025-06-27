.data
	a: .word 01, 02, 03, 04, 05  # array of 5 elements

.text
	li $t1, 0       # index
	la $t0, a       # load address of array
	li $t2, 8

loop:
	mul $t3, $t1, $t2   # t3 = 8 * i
	sll $t4, $t1, 2     # i * 4 (offset)
	add $t4, $t4, $t0   # base + i * 4

	sw $t3, 0($t4)      # store 8 * i in a[i]

	addi $t1, $t1, 1    # i++

	blt $t1, 5, loop    # i < 5
