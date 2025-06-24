    .data
message: .asciiz "Program completed.\n"

    .text
    .globl main

main:
    li $t2, 5          
    li $t3, 10         
    add $t1, $t2, $t3  

    add $t1, $t1, $t1  

    addi $t3, $zero, 1000  

    li $gp, 0x10010000  
    sw $t1, 16($gp)     
    lw $t2, 16($gp)     

    li $s5, 0x10010020  
    sw $t2, 4($s5)      

    li $s1, 5           
    li $s2, 10          
    bne $s1, $s2, loop1 

    j exit

loop1:
    li $a0, 1           

exit:
    li $v0, 4           
    la $a0, message     
    syscall             

    li $v0, 10          
    syscall

