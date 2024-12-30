// print n nos
#include <stdio.h>

int main() {
  int a, b;
  printf("Enter the values a, b: ");
  scanf("%d%d", &a, &b);
  while (a <= b) {
    a++;
    printf("%d\n", a);
  }

  return 0;
}