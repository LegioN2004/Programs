.data
prompt: .asciiz "Enter nth number: "
output: .asciiz "Output: "

.text

	li      $v0,    4
	la      $a0,    prompt
	syscall

	li      $v0,    5
	syscall
	move    $a0,    $v0

	jal     facto
	move    $t0,    $v0

	li      $v0,    4
	la      $a0,    output
	syscall

	li      $v0,    1
	move    $a0,    $t0
	syscall

	li      $v0,    10
	syscall


facto:

	sub     $sp,    $sp,    12
	sw      $ra,    0($sp)
	sw      $a0,    4($sp)
	sw      $s0,    8($sp)

	li      $v0,    1
	ble     $a0,    1,      endFact

	move    $s0,    $a0
	sub     $a0,    $a0,    1
	jal       facto

	mul     $v0,    $v0,    $s0

endFact:

	lw      $ra,    0($sp)
	lw      $a0,    4($sp)
	lw      $s0,    8($sp)
	addi    $sp,    $sp,    12
	jr      $ra


