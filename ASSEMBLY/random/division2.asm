.data

.text

    li $t0, 30
    li $t1, 5


    # div $s0, $t0, $t1 # can do this too
    # div $s0, $t0, 10
    div $t0, $t1
    
    mflo $s0 # quotient
    mfhi $s1 # remainder


    li $v0, 1
    move $a0, $s0
    syscall
