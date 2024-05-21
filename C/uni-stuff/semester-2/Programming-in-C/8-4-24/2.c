/* 5 * 5, * wala block
 ******
 ******
 ******
 ******
 ******
 */
#include <stdio.h>

int main() {
  int n = 5;
  for (int rows = 0; rows < n; rows++) {
    for (int cols = 0; cols < n; cols++) {
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}
