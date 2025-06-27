.data
prompt:     .asciiz "Enter a positive integer: "
resultMsg:  .asciiz "Factorial is: "

.text
            .globl  main

main:
	li      $v0,            4                          # print prompt
	la      $a0,            prompt
	syscall

	li      $v0,            5                          # read integer input
	syscall
	move    $t0,            $v0                        # $t0 = input number (n)

	li      $t1,            1                          # $t1 = result = 1 (initialize factorial)

factorial_loop:
	ble     $t0,            0,          end_loop       # if n <= 0, break loop
	mul     $t1,            $t1,        $t0            # result *= n
	subi    $t0,            $t0,        1              # n--
	j       factorial_loop

end_loop:
	li      $v0,            4
	la      $a0,            resultMsg
	syscall

	li      $v0,            1                          # print result
	move    $a0,            $t1
	syscall

	li      $v0,            10                         # exit
	syscall
