# print odd numbers
echo "Enter a starting range: "
read start
echo "Enter a ending range: "
read end

while [ $start -le $end ]; do 
    if [ $(($start % 2)) -eq 1 ]; then
        echo $start >> "$HOME/Desktop/odd.txt"
    fi
    start=$((start+1))
done


