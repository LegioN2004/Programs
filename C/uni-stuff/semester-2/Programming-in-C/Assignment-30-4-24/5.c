// find the reverse of an integer number

#include <stdio.h>

int main() {
  int a = 0, temp = 0;
  printf("Enter the integer at number you want to find the reverse of: ");
  scanf("%d", &a);
  if (a >= 0) {
    // while (a != 0) {
    for (int i = 0; i < a;) {
      int b = a % 10;
      temp = temp * 10 + b;
      a = a / 10;
    }
    printf("the reversed number is: %d", temp);
  } else {
    printf("The number is not an integer, correct the input");
  }
  return 0;
}
