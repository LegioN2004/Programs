// Write a C program to display and find the sum of the series 1+11+111+....111
// upto n. For eg. if n=4, the series is : 1+11+111+1111. Take the value of 'n'
// as input from the user.

#include <math.h>
#include <stdio.h>

int main() {
  int a = 4, result = 0, newValue = 0;
  for (int i = 0; i < a; i++) {
    newValue = newValue + pow(10, i);
    result += newValue;
  }
  printf("%d \n", result);
  return 0;
}
