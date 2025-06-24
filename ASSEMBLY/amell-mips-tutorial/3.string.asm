.data

    string: .asciiz "hello world"

.text

    la $t0, string  # Load address of the string into $t0

    li $v0, 4
    move $a0, $t0
    syscall