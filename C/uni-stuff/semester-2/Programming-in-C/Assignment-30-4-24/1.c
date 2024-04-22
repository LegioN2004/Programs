/*
 A number is called an Armstrong number if the sum of the cubes of the digits
 of the number is equal to the number. For example 153 = 1^3 + 5^3 + 3^3. Write
 a C program that asks the user to enter a number and returns if it is Armstrong
 or not.
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  int numberCopy, number, remainder, result = 0, n = 0;
  printf("Enter the number: ");
  scanf("%d", &number);
  numberCopy = number;

  for (; numberCopy != 0; numberCopy /= 10, ++n);

  numberCopy = number;

  while (numberCopy != 0) {
    remainder = numberCopy % 10;
    result += pow(remainder, n);
    numberCopy /= 10;
  }

  if (result == number) {
    printf("Armstrong number\n");
  } else
    printf(" Not an Armstrong number\n");
  return 0;
}
