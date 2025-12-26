# print sum of n to 1 
echo "Enter a number: "
read n

sum=0
output=""

for ((i=$n;i>=1;i--))
do 
    sum=$((sum + i))
    if [ $i -eq 1 ]; then
        output="$output$i"
    else
        output="$output$i + "
    fi
done

echo "$sum"


