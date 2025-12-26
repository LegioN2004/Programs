#!/bin/bash
echo "Enter how many prime numbers you want:"
read n

count=0
num=2
output=""

while [ $count -lt $n ]
do
  flag=0

  for (( i=2; i<num; i++ ))
  do
    if [ $((num % i)) -eq 0 ]; then
      flag=1
      break
    fi
  done

  if [ $flag -eq 0 ]; then
    output="$output$num "
    count=$((count + 1))
  fi

  num=$((num + 1))
done

echo "$output"
echo "$output" > "$HOME/Desktop/primes.txt"

