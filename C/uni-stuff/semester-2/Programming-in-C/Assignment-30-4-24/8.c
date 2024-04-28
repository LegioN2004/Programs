/*
Write a C program, which will print two digit numbers whose sum of both digit
is multiple of seven. e.g. 16,25,34......
*/

#include <stdio.h>

int main() {
  for (int i = 1; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if ((i + j) % 7 == 0) {
        printf("%d%d \n", i, j);
      }
    }
  }
  return 0;
}
