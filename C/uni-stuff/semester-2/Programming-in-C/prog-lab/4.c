#include <stdio.h>

int main() {
  float a, b, c;
  printf("Enter the first and second number:\n");
  scanf("%f%f", &a, &b);
  c = a + b;
  printf("The summation of %f and %f is %d\n", a, b, (int)c);
  c = a - b;
  printf("The subtraction of %f from %f is %f\n", a, b, c);
  c = a * b;
  printf("The multiplication of %f and %f is %f\n", a, b, c);
  c = a / b;
  printf("The division of %f from %f is %f\n", a, b, c);

  return 0;
}
