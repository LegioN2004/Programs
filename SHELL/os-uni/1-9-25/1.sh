# Adds two numbers and writes the sum to a file
echo enter nos
read a
read b
c=$(echo "$a + $b" | bc -l)
echo "the sum is $c" > "$HOME/Desktop/hello.txt"
