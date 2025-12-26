# Calculates sum of numbers from n to 1 and writes to file
echo "Enter a number:"
read n
sum=0
expr=""
for ((i=n; i>=1; i--))
do
  sum=$((sum + i))
  if [ $i -eq 1 ]; then
    expr="$expr$i"
  else
    expr="$expr$i + "
  fi
done

echo "$sum" > "$HOME/Desktop/sum-digits.txt"
echo "Sum saved"
