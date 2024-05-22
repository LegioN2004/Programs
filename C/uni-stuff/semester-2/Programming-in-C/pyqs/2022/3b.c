#include <stdio.h>

int main() {
  int x = 0;
  int a = x = ((-25 < 13) ? (7 % 10) : (10 % 7));
  int c = 7 % 10;
  printf("%d\n%d\n%d", a, x, c);
  return 0;
}
