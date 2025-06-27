.data

.text

    li $t0, 4
    li $t1, 2
    li $t2, 3

    bgt $t1, $t0, setB
    bgt $t2, $t0, setC
    j printValue

    setB:
        move $t0, $t1
        j checkC

    setC:
        move $t0, $t2
        j printValue

    checkC:
        bgt $t2, $t0, setC
        j printValue

    printValue:
        li $v0, 1
        move $a0, $t0
        syscall
