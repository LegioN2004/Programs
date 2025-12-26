echo "enter n"
read n

sum=0

echo "enter $n floating point numbers"
for (( i = 0 ; i < n ; i++ )){
    read x
    sum=$(echo $sum + $x | bc -l) 
}

echo "Sum: $sum"
