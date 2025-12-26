echo "enter values"
read a
read b 
read c 

if [ $a -eq $b ] && [ $b -eq $c ]; then 
    echo "All the numbers are equal $a" > "/Users/milinda/Desktop/result.txt"
else
    if [ $a -ge $b ] && [ $a -ge $c ]; then
        echo "$a is greatest" > "/Users/milinda/Desktop/result.txt"
    elif [ $b -ge $a ] && [ $b -ge $c ]; then
        echo "$b is greatest" > "/Users/milinda/Desktop/result.txt"
    else
        echo "$c is greatest" > "/Users/milinda/Desktop/result.txt"
        
    fi
fi
