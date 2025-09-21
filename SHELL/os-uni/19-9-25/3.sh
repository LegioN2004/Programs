echo "Enter start of range:"
read start
echo "Enter end of range:"
read end

num=$start
echo "" > "$HOME/Desktop/odd_numbers.txt"
while [ $num -le $end ]
do
  if [ $((num % 2)) -eq 1 ]; then
    echo $num >> "$HOME/Desktop/odd_numbers.txt"
  fi
  num=$((num+1))
done

echo "saved hoi gol in output file"