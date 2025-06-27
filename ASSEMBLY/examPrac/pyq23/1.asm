.data

.text

    li $t0, 1
    li $t1, 2

    add $s0, $t0, $t1

    li $v0, 1
    move $a0, $s0
    syscall

