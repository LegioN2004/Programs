#include <stdio.h>

int main() {
  int n;
  printf("Enter a number:\n");
  scanf("%d", &n);

  if (n > 11 && n < 15) {
    printf("%d is in between 11 and 15", n);
  } else {
    printf("%d is not in between 11 and 15", n);
  }
  return 0;
}
