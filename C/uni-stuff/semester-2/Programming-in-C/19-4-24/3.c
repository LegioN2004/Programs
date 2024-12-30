// find prime number

#include <stdio.h>

int main() {
  int a, b;
  printf("Enter a number: ");
  scanf("%d", &b);
  a = b;
  if (a % 1 == 0 && b % a == 0) {
    printf("The number %d is prime", b);
  } else if (b == 0) {
    printf("check the input");
  } else {
    printf("The number is not prime");
  }
  return 0;
}