#include <stdio.h>

int main() {
  int num;
  printf("Enter a number:\n");
  scanf("%d", &num);
  if (num % 2 == 0) {
    printf("%d is a Even number\n", num);
  } else {
    printf("%d is a Odd number\n", num);
  }
  return 0;
}
