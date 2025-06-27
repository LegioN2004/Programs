.data

value:      .word   -4
message1:   .asciiz "the value is positive\n"
message2:   .asciiz "the value is negative"

.text

	lw      $t0,    value

	bgt     $t0,    0,          positive_label
	blt     $t0,    0,          negative_label


positive_label:
	li      $v0,    4
	la      $a0,    message1
	syscall
	li      $v0,    10
	syscall

negative_label:
	li      $v0,    4
	la      $a0,    message2
	syscall
	li      $v0,    10
	syscall
