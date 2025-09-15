echo "Enter the number of terms: "
read n

a=0
b=1
output="$a $b "

for (( i=2; i<n; i++ ))
do
  c=$((a + b))
  output="$output$c "
  a=$b
  b=$c
done

echo "$output" > "$HOME/Desktop/result2.txt"

