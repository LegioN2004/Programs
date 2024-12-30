// create a calculator

#include <stdio.h>

int main() {
  int ch, a, b;
  printf("1. Addition of 2 nos \n ");
  printf("2. Subtraction of 2 nos \n ");
  printf("3. Multiplication of 2 nos \n ");
  printf("4. Division of 2 nos \n ");
  scanf("%d", &ch);
  printf("enter the value of a: ");
  scanf("%d", &a);
  printf("enter the value of b: ");
  scanf("%d", &b);
  switch (ch) {
    case 1:
      printf("the value of is %d+%d=%d \n", a, b, (a + b));
      break;
    case 2:
      printf("%d-%d=%d \n", a, b, (a - b));
      break;
    case 3:
      printf("%d*%d=%d \n", a, b, (a * b));
      break;
    case 4:
      printf("%d/%d=%d \n", a, b, (a / b));
      break;
    default:
      printf("wrong choice, enter the correct input \n");
  }
  return 0;
}
