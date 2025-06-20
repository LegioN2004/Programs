.data

  newline: .asciiz "\n"

.text

	main:
		addi $s0, $zero, 10

		jal incReg

		li $v0, 4
		la $a0, newline
		syscall

    	jal printValue


	li $v0, 10
	syscall

	incReg:

		addi $sp, $sp, -4
		sw $s0, 0($sp) # storing the value at s0 to the 0th index of the stack pointer
		sw $ra, 4($sp)

		# modifying the value of s0
		addi $s0, $s0, 30

		# since we want to have the old value, we'll need to load the value from the memory to the register.
		jal printValue

		lw $s0, 0($sp) # from RAM
		lw $ra, 4($sp)
		addi $sp, $sp, 4

		jr $ra


  printValue:
      li $v0, 1
      move $a0, $s0
      syscall

      jr $ra



# .data
# 	num1: .word 1
# 	num2: .word 2

# .text
# main:

# 	lw $t2, num1
# 	lw $t3, num2
# 	add $t1,$t2,$t3
# 	add $t1,$t1,$t1
# 	addi $t3,$zero,1000
# 	lw $t2,16($gp)
# 	sw $t2,4($s5)
# 	loop1:
# 	bne $s1,$s2,loop1
