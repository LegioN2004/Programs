#!/bin/bash

# fibonacci series
echo "Enter number of terms:"
read n

a=0
b=1
output=""

for ((i = 0 ; i < n ; i++)){
    output="$output$a "
    c=$((a + b))
    a=$b
    b=$c
}

echo "$output is the fibonacci series for $n"
echo "$output is the fibonacci series for $n" > "/Users/milinda/Desktop/fibonacci.txt"

