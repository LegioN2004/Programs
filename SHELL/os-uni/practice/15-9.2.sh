echo enter a number
read num

fact=1

for(( i = 2; i <= num; i++ )) {
    fact=$((fact * i))
    # 1 * 2, 2 * 3, 6 * 4
}

echo "Factorial is $fact" >> "/Users/milinda/Desktop/Factorial.txt"
