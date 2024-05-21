/* print the following pattern
 *****
 ****
 ***
 **
 *
 */
#include <stdio.h>

int main() {
  int n = 5;
  for (int rows = 0; rows < n; rows++) {
    for (int cols = rows; cols < n; cols++) {
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}
