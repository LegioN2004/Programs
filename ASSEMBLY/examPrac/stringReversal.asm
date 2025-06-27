.data
prompt:     .asciiz "Enter a string: "
beforeMsg:  .asciiz "\nOriginal string: "
afterMsg:   .asciiz "\nReversed string: "
string:     .space  100                                         # space to store input string

.text
            .globl  main

main:
	# Prompt the user
	li      $v0,            4
	la      $a0,            prompt
	syscall

	# Read string input
	li      $v0,            8
	la      $a0,            string
	li      $a1,            100
	syscall

	# Print original string
	li      $v0,            4
	la      $a0,            beforeMsg
	syscall

	li      $v0,            4
	la      $a0,            string
	syscall

	# Remove newline character if present
	la      $t2,            string
remove_newline:
	lb      $t3,            0($t2)
	beqz    $t3,            done_remove_newline
	li      $t4,            10                                     # ASCII for newline
	beq     $t3,            $t4,                    set_null
	addi    $t2,            $t2,                    1
	j       remove_newline
set_null:
	sb      $zero,          0($t2)
done_remove_newline:

	# Compute string length
	la      $a0,            string
	jal     strlen
	move    $t1,            $v0                                    # $t1 = length

	# Call recursive reverse function
	la      $a0,            string                                 # $a0 = start addr
	add     $a1,            $a0,                    $t1            # $a1 = end addr (points to '\0')
	addi    $a1,            $a1,                    -1             # move to last real char (before '\0')
	jal     reverse

	# Print reversed string
	li      $v0,            4
	la      $a0,            afterMsg
	syscall

	li      $v0,            4
	la      $a0,            string
	syscall

	# Exit
	li      $v0,            10
	syscall

	##########################################################
	# strlen: compute length of null-terminated string
	# Input : $a0 = base address of string
	# Output: $v0 = length (excluding null terminator)
	##########################################################
strlen:
	li      $v0,            0                                      # length counter
strlen_loop:
	lb      $t0,            0($a0)                                 # load byte from string
	beq     $t0,            $zero,                  strlen_done
	addi    $v0,            $v0,                    1              # length++
	addi    $a0,            $a0,                    1              # move to next char
	j       strlen_loop
strlen_done:
	jr      $ra

	##########################################################
	# reverse: recursively reverse characters from $a0 to $a1
	# Input : $a0 = pointer to start char
	#         $a1 = pointer to end char
	# Modifies string in-place
	##########################################################
reverse:
	# base case: if start >= end, stop
	bge     $a0,            $a1,                    reverse_end

	# load bytes
	lb      $t0,            0($a0)                                 # char at start
	lb      $t1,            0($a1)                                 # char at end

	# swap
	sb      $t1,            0($a0)
	sb      $t0,            0($a1)

	# recursive call: reverse(start+1, end-1)
	addi    $a0,            $a0,                    1
	addi    $a1,            $a1,                    -1
	jal     reverse

reverse_end:
	jr      $ra
