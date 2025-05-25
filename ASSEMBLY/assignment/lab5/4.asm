# Recursive string reversal in MIPS assembly
# $a0 = address of string
# $a1 = left index (start with 0)
# $a2 = right index (start with strlen-1)

.data
str:    .asciiz "hello, world!"

.text
.globl main

main:
    la   $a0, str         # $a0 = address of string
    move $t0, $a0         # $t0 = address of string
    # Find string length
    li   $t1, 0           # $t1 = length counter
strlen_loop:
    lb   $t2, 0($t0)
    beq  $t2, $zero, strlen_done
    addi $t1, $t1, 1
    addi $t0, $t0, 1
    j    strlen_loop
strlen_done:
    addi $t1, $t1, -1     # $t1 = strlen - 1 (right index)
    li   $a1, 0           # $a1 = left index
    move $a2, $t1         # $a2 = right index
    jal  reverse_recursive

    # Print reversed string
    la   $a0, str
    li   $v0, 4
    syscall

    li   $v0, 10          # Exit
    syscall

# void reverse_recursive(char *str, int left, int right)
reverse_recursive:
    # Base case: if left >= right, return
    bge  $a1, $a2, rev_ret

    # Swap str[left] and str[right]
    add  $t0, $a0, $a1    # $t0 = &str[left]
    add  $t1, $a0, $a2    # $t1 = &str[right]
    lb   $t2, 0($t0)      # $t2 = str[left]
    lb   $t3, 0($t1)      # $t3 = str[right]
    sb   $t3, 0($t0)      # str[left] = str[right]
    sb   $t2, 0($t1)      # str[right] = str[left]

    # Recursive call: reverse_recursive(str, left+1, right-1)
    addi $sp, $sp, -4     # Save return address
    sw   $ra, 0($sp)
    addi $a1, $a1, 1      # left++
    addi $a2, $a2, -1     # right--
    jal  reverse_recursive
    lw   $ra, 0($sp)      # Restore return address
    addi $sp, $sp, 4

rev_ret:
    jr   $ra