# Creates n files and writes 'CSE' n times in each file
#!/bin/bash
echo "enter n: "
read n

for ((i = 1; i <= n; i++)); do
    filename="file${i}.txt" > "/Users/milinda/Desktop/$filename"  # Clear/create empty file
    for ((j = 1; j <= i; j++)); do
        echo "CSE" >> "/Users/milinda/Desktop/$filename"  # Append, don't overwrite
    done
done
echo "Created files file1.txt to file${n}.txt"

