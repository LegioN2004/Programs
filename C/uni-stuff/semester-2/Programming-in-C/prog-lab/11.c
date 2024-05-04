#include <stdio.h>

int main() {
  int num;
  printf("Enter a number:\n");
  scanf("%d", &num);
  if (num > 11 && num < 15) {
    printf("True");
  } else {
    printf("False");
  }
  return 0;
}
