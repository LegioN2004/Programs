#include <stdio.h>

int main() {
  int numberCopy = 153, n = 1;
  for (int i = 1; numberCopy != 0; ++n) {
    numberCopy /= 10;
    printf("%d\n", n);
  }
  return 0;
}
