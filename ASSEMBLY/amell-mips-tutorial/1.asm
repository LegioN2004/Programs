.section .text
.globl __start
__start: #main function
li $v0, 4
#11=system code for printing a character, $v0=register that gets the system code for printing as value
li $a0, 13	
#'a'=our example character, $a0=register that accepts the character for printing
syscall
.section .data
