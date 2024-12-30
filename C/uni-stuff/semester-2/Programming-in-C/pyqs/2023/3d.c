#include <stdio.h>

int main() {
  int a = 0;
  for (; a;);
  printf("A = %d\n", a);
  a++;
  printf("Values of A = %d\n", a);              // should print 1, it does
  printf("Values of A = %d and %d\n", a, a++);  // why not 1 and 1
  printf("Values of A = %d\n", a++);            // here it should be 2
  return 0;
}
