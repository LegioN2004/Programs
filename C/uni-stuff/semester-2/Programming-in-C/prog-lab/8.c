// swap three variables
#include <stdio.h>

int main() {
  int x, y, z;
  printf("Enter values of X,Y and Z:\n");
  scanf("%d%d%d", &x, &y, &z);
  printf("Swapping X=%d Y=%d Z=%d\n", x, y, z);
  x = x + y + z;
  y = x - y - z;
  z = x - y - z;
  x = x - y - z;
  printf("X=%d Y=%d Z=%d\n", x, y, z);
  return 0;
}
