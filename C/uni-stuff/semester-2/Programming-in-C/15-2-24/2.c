// find a certain digit from a 4 digit number

#include <stdio.h>

int main() {
  int a, b, d, temp;
  printf("Enter the number: ");
  scanf("%d", &a);
  printf("Enter the digit you want to find from the number: ");
  scanf("%d", &b);
  // loop to reverse the number so as to find the correct position
  /* for (int j = 1; j < ; j++) { */
  /* } */

  for (int i = 1; i <= a; i++) {
    d = a % 10;
    a = a / 10;
    if (b == d) {
      printf("The digit %d is found at the %dth position \n", b, i);
    }
  }
  return 0;
}
