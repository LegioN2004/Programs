 .data
 	promptMessage: .asciiz "enter a number to find its factorial "
 	resultMessage: .asciiz "\n the factorial of the number is "
 	theNumber: .word 0
 	theAnswer: .word 0
 
 .text
 	.globl main
 	main: 
 		# show the message from the user
 		li $v0, 4
 		la $a0, promptMessage
 		syscall
 		
 		# reads the number from the stdin
 		li $v0, 5 
 		syscall
 		
 		sw $v0, theNumber
 		
 		# call the factorial function 
 		lw $a0, theNumber
 		jal findFactorial
 		sw $v0, theAnswer
 		
 		#display the results
 		li $v0, 4
 		la $a0, resultMessage
 		syscall
 		
		li $v0, 1
		lw $a0, theAnswer
		syscall
		
		# tell the OS that this is the end of the program
		
		li $v0, 10
		syscall
		
# ------------------------------------------------------------

.globl findFactorial

findFactorial: 
		#making space to store two values below
		subu $sp, $sp, 8
		sw $ra, ($sp) # location 0
		sw $s0, 4($sp) # location 4
		
		# base case (req to stop recursion) when arg = 0
		li $v0, 1
		beq $a0, 0, factorialDone
		
		# findFactorial(number - 1)
		move $s0, $a0
		sub $a0, $a0, 1
		jal findFactorial # (recursive call)
		
		# magic happens here 
		mul $v0, $s0, $v0
		
		# function is done so getting the values back from the stack
		# we need to restore the stack
		factorialDone:
			lw $ra, ($sp) # restoring the value of the return address from the stack
			lw $s0, 4($sp) 
			addu $sp, $sp, 8 # the stack is growing downwards so we subtract now we adding 8 to put everything it was before
			
			jr $ra
			
			
			
	
