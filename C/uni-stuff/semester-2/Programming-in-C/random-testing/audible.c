#include <stdio.h>

int main() {
  for (int i = 1; i <= 100000000; i++) {
    printf("\a");
    // infinite audio signal, gcc ka gaaaaaaaaaanaaaaaaaaaaaa
  }
  return 0;
}
