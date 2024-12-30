// find the largest of 3 nos using ternary operators
#include <stdio.h>

int main() {
  int a = 8, b = 9, c = 7, large;
  large = ((a > b) ? ((a > c) ? printf("%d is greatest", a)
                              : printf("%d is greatest", c))
                   : ((b > c) ? printf("%d is greatest", b)
                              : printf("%d is greatest", c)));
  return 0;
}