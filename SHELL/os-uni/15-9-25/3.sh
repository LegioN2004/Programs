# Generates Fibonacci series and writes to file
#!/bin/bash
echo "Enter number of terms:"
read n

a=0
b=1
output=""

for (( i=0; i<n; i++ ))
do
  output="$output$a "
  c=$((a + b))
  a=$b
  b=$c
done

echo "$output" > "$HOME/Desktop/result2.txt"
echo "Fibonacci series saved to Desktop"

