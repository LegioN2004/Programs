// give the fibonacci series upto this many no of times

#include <stdio.h>

int main() {
  int f, s, next, n;
  printf("Give the input: ");
  scanf("%d", &n);
  f = 0;
  s = 1;
  int i = 0;
  while (i <= n) {
    if (i <= 1) {
      next = i;
    } else {
      next = f + s;
      f = s;
      s = next;
    }
    printf("%d \n", next);
    i = i + 1;
  }
  return 0;
}
