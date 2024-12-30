// find the factorial of n

#include <stdio.h>
int main() {
  int n, d = 1;
  printf("Enter the value to find the factorial of: ");
  scanf("%d", &n);
  int i = n;
  while (i >= 1) {
    d = d * i;
    i--;
  }
  printf("The factorial of %d is %d\n", n, d);
  return 0;
}