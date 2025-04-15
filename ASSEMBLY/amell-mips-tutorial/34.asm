 .data
 	promptMessage: .asciiz "enter a number to find its factorial"
 	resultMessage: .asciiz "\n the factorial of the number is"
 	theNumber: .word 0
 	theAnswer: .word 0
 
 .text
 	.globl main
 	main: 
 		# read the number from the user
 		li $v0, 4
 		la $a0, promptMessage
 		syscall
 		
 		li $v0,5 
 		syscall
 		
 		sw $v0, theNumber
 		
 		# call the factorial function 
 		lw $a0, theNumber
 		jal findFactorial
 		sw $v0, theAnswer
 		