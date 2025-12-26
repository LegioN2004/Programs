# Compares two numbers and writes result to a file
echo enter values
read a
read b

    if [ $a -gt $b ]
    then
        echo "a is greater" > "/Users/milinda/Documents/random-backup/greater.txt"
    elif [ $b -gt $a ]
    then
        echo "a is smaller" > "/Users/milinda/Documents/random-backup/smaller.txt"
    else
        echo "both are equal"
    fi
