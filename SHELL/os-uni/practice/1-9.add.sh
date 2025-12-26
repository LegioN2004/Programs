# echo enter nos
# read a
# read b 
# c=$(echo "$a + $b" | bc -l)
# echo "The sum is $c" > "/Users/milinda/Desktop/hello.txt"

echo enter numbers
read a
read b 
c=$(echo "$a + $b" | bc)
echo "The sum is $c" > "/Users/milinda/Desktop/hello.txt"
