echo "Enter a number: "
read n

# Generate numbers 1 to 10 using seq
seq 1 10 | while read i
do
    echo "$n x $i = $((n * i))"
done
