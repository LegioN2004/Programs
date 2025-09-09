echo "enter n: "
read n
for ((i = 1; i <= n; i++)); do
    > "/Users/milinda/Desktop/file$i.txt"
    for ((j = 1; j <= i; j++)); do
        echo "CSE$j" >> "/Users/milinda/Desktop/file$i.txt"
    done
done

