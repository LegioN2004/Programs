#include <stdio.h>

int main() {
  int a, tax = 0;

  printf("Enter the income: ");
  scanf("%d", &a);

  if (a > 10000) {
    tax += (a - 10000) * 0.30;
    a = 10000;
  }
  if (a > 5000) {
    tax += (a - 5000) * 0.20;
    a = 5000;
  }
  if (a > 2500) {
    tax += (a - 2500) * 0.10;
  }

  printf("Tax: %d\n", tax);

  return 0;
}
