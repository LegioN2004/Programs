#include <stdio.h>

int main() {
  int n, sum = 0, first, current_number;

  printf("Enter the number of integers in the list: ");
  scanf("%d", &n);

  printf("Enter the first integer: ");
  scanf("%d", &first);

  for (int i = 1; i < n; i++) {
    printf("Enter the next integer: ");
    scanf("%d", &current_number);

    sum += first * current_number;

    first = current_number;
  }

  printf("Sum of products of consecutive numbers: %d\n", sum);

  return 0;
}
