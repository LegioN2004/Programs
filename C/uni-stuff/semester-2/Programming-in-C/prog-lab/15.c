// find the sum of the series 1/1, 1/2, 1/3, 1/4, 1/5, .................

#include <stdio.h>

int main() {
  int n;
  float ans = 0;
  printf("Enter a number:\n");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("1/%d", i);
    if (i < n) {
      printf("+");
    }
    ans = ans + 1.0 / i;
  }
  printf("\nSUM = %f", ans);
  return 0;
}