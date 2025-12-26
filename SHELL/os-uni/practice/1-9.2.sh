echo "enter the values"

read n

if [ $(expr $n % 2) -eq 0 ]; then
    echo "$n is even" > "/Users/milinda/Desktop/even.txt"
else
    echo "$n is odd" > "/Users/milinda/Desktop/even.txt"
fi

