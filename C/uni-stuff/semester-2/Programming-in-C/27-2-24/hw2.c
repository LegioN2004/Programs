// to find if the year is leap or not

#include <stdio.h>

int main() {
  int a;
  printf("enter the value of a: ");
  scanf("%d", &a);
  if (a % 400 == 0) {
    printf("is a leap year ");
  } else if (a % 100 == 0 && a % 400 != 0) {
    printf("is not a leap year ");
  } else if (a % 100 != 0 && a % 4 == 0) {
    printf("is a leap year ");
  } else {
    printf("is not a leap year ");
  }
  return 0;
}
