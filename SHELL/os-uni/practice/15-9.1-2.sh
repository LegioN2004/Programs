# swap with using thrid variable

echo "enter the value of a"
read a
echo "enter the value of b"
read b

c=$a
a=$b
b=$c

echo "value of a: $a"
echo "value of b: $b"

# a = 5, b = 4, a = a + b = 9, b = a - b = 4, a = a - b
