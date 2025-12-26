# Swaps two numbers using arithmetic operations (alternate)
echo "enter numbers to swap: "
read a
read b

a=$((a+b))
b=$((a-b))
a=$((a-b))

echo "value of a: $a"
echo "value of b: $b"

