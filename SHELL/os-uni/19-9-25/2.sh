echo "Enter how many prime numbers you want: "
read N

count=0
num=2
output=""

while [ $count -lt $N ]
do
    is_prime=1

    for (( i=2; i*i<=num; i++ ))
    do
        if (( num % i == 0 )); then
            is_prime=0
            break
        fi
    done

    if (( is_prime == 1 )); then
        output="$output$num "
        ((count++))
    fi

    ((num++))
done

echo "$output" > "$HOME/Desktop/primes.txt"

echo "saved to $HOME/Desktop/primes.txt"
