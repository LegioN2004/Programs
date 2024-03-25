// to find the largest of two numbers

#include <stdio.h>

int main() {
  int a, b;
  printf("enter the value of a: ");
  scanf("%d", &a);
  printf("enter the value of b: ");
  scanf("%d", &b);
  if (a > b) {
    printf("a is greater than b");
  } else if (b > a) {
    printf("b is greater than a");
  } else {
    printf("a is equal to b");
  }
  return 0;
}
