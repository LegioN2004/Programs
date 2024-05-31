// find the sum of n elements entered by the user using array
#include <stdio.h>

int main() {
  int n, sum = 0;
  printf("Enter no. of elements:\n");
  scanf("%d", &n);
  int a[n];

  for (int i = 0; i < n; i++) {
    printf("Enter #%d:\n", i + 1);
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i++) {
    sum = sum + a[i];
  }
  printf("sum=%d", sum);
  return 0;
}
