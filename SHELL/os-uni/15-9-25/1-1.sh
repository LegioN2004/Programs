# Swaps two numbers using arithmetic operations
echo "enter numbers to swap: "
echo "value of a: "
read a
echo "value of b: "
read b

a=$((a + b))
b=$((a - b))
a=$((a - b))

echo "after swap"
echo "value of a: $a"
echo "value of b: $b"

