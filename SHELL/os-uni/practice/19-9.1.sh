# multiplication of numbers using seq
echo "Enter a number: "
read n

# till 10
seq 1 10 | while read i
do
    echo "$n x $i = $((n * i))"
done
    

