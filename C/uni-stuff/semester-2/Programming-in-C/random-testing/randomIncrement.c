#include <stdio.h>

int main() {
  int i = 1, d = i;
  printf("%d%d%d%d\n", i++, i++, i++, i);
  i = d;
  printf("%d%d%d%d\n", ++i, i++, i++, i);
  i = d;
  printf("%d%d%d%d\n", i, i++, ++i, i++);
  i = d;
  printf("%d%d%d%d\n", i, i++, i++, i++);
  i = d;
  printf("%d%d%d%d\n", i, ++i, i++, i++);
  return 0;
}
