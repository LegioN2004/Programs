echo enter nos
read a
read b
c=$(echo "$a + $b" | bc -l)
echo "the sum is $c" > "/Users/milinda/Documents/random-backup/hello.txt"
