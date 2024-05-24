// write a C program to check whether a given number is prime or not
#include <stdio.h>

int main() {
  int a = 0, flag = 0;
  printf("Enter a number: ");
  scanf("%d", &a);

  for (int n = 1; n <= a; n++) {
    if (a % n == 0) {
      flag++;
    }
  }

  if (flag == 2)
    printf("%d is a prime number.\n", a);
  else
    printf("%d is not a prime number.\n", a);
  return 0;
}
