.data

    string: .asciiz "hello world"

.text

    li $v0, 1
    la $a0, string
    syscall