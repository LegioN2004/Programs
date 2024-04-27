/*
Write a C program, which will print two digit numbers whose sum of both digit
is multiple of seven. e.g. 16,25,34......
*/

#include <stdio.h>

int main() {
  int a = 0, b = 0;
  for (int i = 0; i < 10000; i++) {
    a = i % 10;
    b = a * 10 + b;
    if (b % 7 == 0) {
      printf("%d \n", a);
    }
    /* } else { */
    /*   printf("The end"); */
    /* } */
  }
  return 0;
}
