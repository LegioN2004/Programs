.data

    var: .float 3.14

.text

    li $v0, 2
    lwc1 $f12, var
    syscall
