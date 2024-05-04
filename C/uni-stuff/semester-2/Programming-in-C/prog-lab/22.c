#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of terms:\n");
  scanf("%d", &n);
  printf("Even:\t");
  for (int i = 0; i <= n; i = i + 2) {
    printf("%d\t", i);
  }
  printf("\nOdd:\t");
  for (int i = 0; i <= n; i++) {
    if (i % 2 != 0) {
      printf("%d\t", i);
    }
  }
  return 0;
}
