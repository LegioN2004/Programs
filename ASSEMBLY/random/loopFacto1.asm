.data
message1:   .asciiz   "Enter the number: "
message2:   .asciiz   "The factorial is: "
.text
            .globl  main

main:
	li      $v0,    4
	la      $a0,    message1
	syscall

	li      $v0,    5
	syscall
	move    $t0,    $v0

	li      $t1,    1

fact:
	ble     $t0,    0,          endLoop
	mul     $t1,    $t1,        $t0
	subu    $t0,    $t0,        1
	j       fact

endLoop:
	li      $v0,    4
	la      $a0,    message2
	syscall

	li      $v0,    1
	move    $a0,    $t1
	syscall

	li      $v0,    10
	syscall