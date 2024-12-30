// we have a number like 1256, we just need to do 1 + 2 + 5 + 6 = 14, i.e find
// the sum of the digits of a number

#include <stdio.h>
int main() {
  int n, j = 0, k = 0;
  printf("Enter a number(4 digits only): ");
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) {
    k = n % 10;
    j += k;
    n = n / 10;
  }
  printf("The sum of the digits is: %d", j);
  return 0;
}