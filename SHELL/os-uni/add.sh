echo The sum is: $c
read a
read b
c=`expr $a + $b`
d=$(echo "$a + $b" | bc -l)
echo "The sum is: $c"
echo "The float sum is: $d"
