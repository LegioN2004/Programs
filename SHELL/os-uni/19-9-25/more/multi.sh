# Prints multiplication table for a given number (multi.sh)
echo "Enter num:"
read num
echo "Multiplication Table for $num:"
for i in $(seq 1 $num); do
    product=$((num * i))
    echo "$num x $i = $product"
done
