// to find if a no is positive or negative

#include <stdio.h>

int main() {
  double a;
  printf("enter the value of a: ");
  scanf("%lf", &a);
  if (a < 0.0) {
    printf("The number is negative");
  } else if (a > 0.0) {
    printf("The number is positive");
  } else {
    printf("wrong input, you have entered 0");
  }
  return 0;
}
