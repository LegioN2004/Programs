echo "enter n: "
read n

for ((i = 1; i <= n; i++)) do 
    filename="file${i}.txt" > "/Users/milinda/Desktop/$filename"
    for (( j = 1; j <= i; j++)) do
        echo "CSE" >> "/Users/milinda/Desktop/$filename"
    done
done
