echo "enter the number"

read n 

r=`expr $n % 2`

if [ $r -eq 0 ]
then 
    echo "the number $n is even" > "/Users/milinda/Desktop/RESULT.txt"
else
    echo "the number $n is odd" > "/Users/milinda/Desktop/RESULT.txt"
fi
