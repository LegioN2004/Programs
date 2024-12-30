// binary to decimal conversion

#include <math.h>
#include <stdio.h>

int main() {
  int number, b, i = 0, c = 0;
  printf("Enter the binary number that you want to convert to decimal: \n");
  scanf("%d", &number);  // 101
  while (number != 0) {
    b = number % 10;       // 1 0 1
    number = number / 10;  // 101 10 1
    c = c +
        (b * pow(2, i));  // 1 * 2 ^ 0 = 1, 1 + 0 * 2 ^ 1 = 1, 1 + 1 * 2 ^ 2 = 5
    i = i + 1;
  }
  printf("%d\n", c);
  return 0;
}
