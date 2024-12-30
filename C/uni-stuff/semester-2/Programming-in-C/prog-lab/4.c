// write a C program to add, subtract, multiply and divide two numbers taken as
// user input and print the results

#include <stdio.h>

int main() {
  float a, b, c;
  printf("Enter the first and second number: ");
  scanf("%f%f", &a, &b);
  c = a + b;
  printf("summation of %f and %f: %d\n", a, b, (int)c);
  c = a - b;
  printf("subtraction of %f from %f: %f\n", a, b, c);
  c = a * b;
  printf("multiplication of %f and %f: %f\n", a, b, c);
  c = a / b;
  printf("division of %f from %f: %f\n", a, b, c);

  return 0;
}
