# Prints all odd numbers in a given range and writes to file
echo "Enter start of range:"
read start
echo "Enter end of range:"
read end

echo "" > "$HOME/Desktop/odd_startbers.txt"
while [ $start -le $end ]
do
  if [ $((start % 2)) -eq 1 ]; then
    echo $start >> "$HOME/Desktop/odd_startbers.txt"
  fi
  start=$((start+1))
done

echo "saved hoi gol in output file"
