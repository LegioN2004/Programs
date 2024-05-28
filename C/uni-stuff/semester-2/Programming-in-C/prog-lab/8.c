// swap three variables
#include <stdio.h>

int main() {
  int x, y, z;
  printf("Enter values of x,y and z: ");
  scanf("%d%d%d", &x, &y, &z);
  printf("Swapping x=%d y=%d z=%d\n", x, y, z);
  x = x + y + z;
  y = x - y - z;
  z = x - y - z;
  x = x - y - z;
  printf("x=%d y=%d z=%d", x, y, z);
  return 0;
}
