// swapping of 2 numbers

#include <stdio.h>

int main() {
  int a, b, temp;
  printf("Enter the first number a = ");
  scanf("%d", &a);
  printf("Enter the second number b = ");
  scanf("%d", &b);
  temp = a;
  a = b;
  b = temp;
  printf("After swapping the values are a = %d and b = %d \n", a, b);
  return 0;
}
