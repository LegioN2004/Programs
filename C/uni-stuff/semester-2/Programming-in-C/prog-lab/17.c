// find if the number has three 5s in a row or not
#include <stdio.h>

int main() {
  int n, x, i = 0;
  printf("Enter a number:\n");
  scanf("%d", &n);
  x = n;

  while (x > 0) {
    if (x % 10 == 5) {
      i++;
    } else {
      i = 0;
    }
    if (i == 3) {
      break;
    }
    x /= 10;
  }
  if (i == 3) {
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}
