// swap two variables
#include <stdio.h>

int main() {
  int x, y;
  printf("Enter values of X and Y:\n");
  scanf("%d%d", &x, &y);
  printf("Swapping X=%d Y=%d\n", x, y);
  x = x + y;
  y = x - y;
  x = x - y;
  printf("X=%d Y=%d\n", x, y);
  return 0;
}
