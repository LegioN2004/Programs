echo "enter numbers to swap: "
read a
read b

a=$((a + b))
b=$((a - b))
a=$((a - b))

echo "after swap"
echo "value of a: $a"
echo "value of b: $b"

