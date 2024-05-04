#include <stdio.h>

int main() {
  int n;
  printf("Enter a number:\n");
  scanf("%d", &n);

  if (n % 2 == 0) {
    printf("%d is a Even number", n);
  } else {
    printf("%d is not a Even number", n);
  }
  return 0;
}
