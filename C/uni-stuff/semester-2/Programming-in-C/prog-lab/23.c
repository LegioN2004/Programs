#include <stdio.h>

int main() {
  int n, ans = 0;
  printf("Enter a number:\n");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("%d", i * i);
    if (i < n) {
      printf("+");
    }
    ans = ans + i * i;
  }
  printf("\nSUM = %d", ans);
  return 0;
}
