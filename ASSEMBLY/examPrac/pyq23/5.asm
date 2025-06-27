.data

.text
	li      $a0,        2
	li      $a1,        2
	jal     multiply

	move    $a0,        $v0
	li      $v0,        1
	syscall

	li      $v0,        10
	syscall

multiply:
	mul     $v0,        $a0,    $a1
	jr      $ra

