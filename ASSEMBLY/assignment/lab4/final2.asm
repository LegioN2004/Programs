.data
prompt: .asciiz "Provide an input string with less than 50 characters and only containing a-z or A-Z:\n"
error_msg: .asciiz "Error: Input contains invalid characters or is too long.\n"
compressed_msg: .asciiz "The compressed string is:\n"
ratio_msg: .asciiz "The compression ratio is "
period: .asciiz "."
newline: .asciiz "\n"
input_buffer: .space 51    # 50 chars + null terminator
output_buffer: .space 101  # Worst case: alternating chars with counts

.text
.globl main

main:
    # Print prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # Read input string
    li $v0, 8
    la $a0, input_buffer
    li $a1, 51
    syscall

    # Validate input string and calculate length
    la $t0, input_buffer   # $t0 = address of input buffer
    li $t1, 0              # $t1 = input length counter

validate_loop:
    lb $t2, 0($t0)         # Load current character
    beq $t2, 10, validate_end  # Check for newline
    beq $t2, 0, validate_end   # Check for null terminator

    # Check if character is alphabetical (a-z or A-Z)
    slti $t3, $t2, 'A'     # $t3 = 1 if char < 'A'
    beq $t3, 1, invalid_input

    slti $t3, $t2, '['     # '[' is one after 'Z' in ASCII
    bne $t3, 0, valid_char

    slti $t3, $t2, 'a'
    beq $t3, 1, invalid_input

    slti $t3, $t2, '{'     # '{' is one after 'z' in ASCII
    beq $t3, 0, invalid_input

valid_char:
    addi $t0, $t0, 1       # Move to next character
    addi $t1, $t1, 1       # Increment length counter
    bge $t1, 50, invalid_input  # Check if length exceeds 50
    j validate_loop

validate_end:
    # Save original input length
    move $s0, $t1

    # Compression algorithm
    la $t0, input_buffer   # $t0 = input buffer
    la $t1, output_buffer  # $t1 = output buffer
    li $t2, 0              # $t2 = input position
    li $t3, 0              # $t3 = output position

    lb $t4, 0($t0)         # $t4 = current character
    beq $t4, 0, print_result  # Check for empty string
    li $t5, 1              # $t5 = count of consecutive characters

compression_loop:
    addi $t2, $t2, 1       # Move to next input position
    add $t6, $t0, $t2      # Address of next character
    lb $t6, 0($t6)         # $t6 = next character

    # Check if end of string or character changes
    beq $t6, 0, output_current
    beq $t6, 10, output_current  # Newline acts as end of string
    beq $t6, $t4, increment_count

    # Output current character and count
output_current:
    # Output the character
    add $t7, $t1, $t3      # Address of output position
    sb $t4, 0($t7)         # Output the character
    addi $t3, $t3, 1       # Increment output position

    # Skip count if single occurrence
    li $t8, 1
    beq $t5, $t8, next_character

    # Convert count to ASCII digit(s)
    move $t8, $t5          # Copy count to $t8
    li $s1, 0              # Digit counter
    move $s2, $sp          # Save original stack pointer

digit_loop:
    # Divide by 10
    li $t9, 10
    div $t8, $t9
    mfhi $s3              # Remainder (digit)
    mflo $t8              # Quotient

    # Push digit onto stack
    addi $sp, $sp, -4
    sw $s3, 0($sp)
    addi $s1, $s1, 1      # Increment digit counter

    # Continue if quotient is not zero
    bnez $t8, digit_loop

    # Pop digits from stack and output
    move $s3, $s1         # Copy digit counter

output_digits:
    # Pop digit from stack
    lw $t8, 0($sp)
    addi $sp, $sp, 4

    # Convert to ASCII and output
    addi $t8, $t8, '0'
    add $t7, $t1, $t3
    sb $t8, 0($t7)
    addi $t3, $t3, 1

    # Decrement counter
    addi $s3, $s3, -1
    bnez $s3, output_digits

next_character:
    beq $t6, 0, end_compression
    beq $t6, 10, end_compression
    move $t4, $t6          # Update current character
    li $t5, 1              # Reset count
    j compression_loop

increment_count:
    addi $t5, $t5, 1       # Increment count
    j compression_loop

end_compression:
    # Null terminate output string
    add $t7, $t1, $t3
    sb $zero, 0($t7)

print_result:
    # Print compressed string message
    li $v0, 4
    la $a0, compressed_msg
    syscall

    # Print compressed string
    li $v0, 4
    la $a0, output_buffer
    syscall

    # Print newline
    li $v0, 4
    la $a0, newline
    syscall

    # Calculate compression ratio (input length / output length)
    mtc1 $s0, $f0          # Move input length to FP register
    cvt.s.w $f0, $f0       # Convert to single precision
    mtc1 $t3, $f1          # Move output length to FP register
    cvt.s.w $f1, $f1       # Convert to single precision
    div.s $f12, $f0, $f1   # Compression ratio = input / output

    # Print ratio message
    li $v0, 4
    la $a0, ratio_msg
    syscall

    # Print ratio as float
    li $v0, 2
    syscall

    # Print period
    li $v0, 4
    la $a0, period
    syscall

    # Exit program
    li $v0, 10
    syscall

invalid_input:
    # Print error message
    li $v0, 4
    la $a0, error_msg
    syscall

    # Exit program
    li $v0, 10
    syscall