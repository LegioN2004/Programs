// write a C program to add two numbers taken as user input and print the sum

#include <stdio.h>

int main() {
  int a, b, sum;
  printf("Enter the first number:");
  scanf("%d", &a);

  printf("Enter the second number:");
  scanf("%d", &b);

  sum = a + b;

  printf("The summation of %d and %d is %d", a, b, sum);

  return 0;
}
