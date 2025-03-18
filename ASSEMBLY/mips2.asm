.data
str: .asciiz "Hello world\n"
number1: .word 25
number2: .word 12

.text
.globl main
main:
  li   $v0, 4  
  la   $a0, str      
  syscall           

  la   $t0, number1  
  lw   $s1, 0($t0
  lw   $s2, 4($t0)   

  add  $t2, $s1, $s2 
  sw   $t2, 0($t0)  

  li   $v0, 10       
  syscall            
