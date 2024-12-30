#include <stdio.h>
int main() {
  int i = 0;
  do {
    i++;
    if (i == 2) continue;
    printf("In while loop");
  } while (i < 2);
  printf("%d \n", i);
  return 0;
}
