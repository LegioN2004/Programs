#include <stdio.h>

int main() {
  int a, b, c;
  printf("Enter a number:\n");
  scanf("%d%d%d", &a, &b, &c);
  if (a > b) {
    if (a > c) {
      printf("%d is the largest number of the three", a);
    } else {
      printf("%d is the largest number of the three", c);
    }

  } else {
    if (b > c) {
      printf("%d is the largest number of the three", b);
    } else {
      printf("%d is the largest number of the three", c);
    }
  }
  return 0;
}
