echo enter values
read a
read b 
read c 

if [ $a -eq $b ] && [ $b -eq $c ] 
then
    echo "All the numbers are equal $a" > "/Users/milinda/Desktop/RESULT.txt"
else
    if [ $a -ge $b ] && [ $a -ge $c ]
    then
        echo "$a is greater" > "/Users/milinda/Desktop/RESULT.txt"
    elif [ $b -ge $a ] && [ $b -ge $c ]
    then
        echo "$b is greater" > "/Users/milinda/Desktop/RESULT.txt"
    else
        echo "$c is greater" > "/Users/milinda/Desktop/RESULT.txt"
    fi
fi

