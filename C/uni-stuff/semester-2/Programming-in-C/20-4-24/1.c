// find the no of prime numbers in a given range.

#include <stdio.h>

int main() {
  int start, end;
  printf(
      "Enter the start and end point between which you want to find the "
      "prime numbers \n");
  scanf("%d%d", &start, &end);
  for (int i = start; i <= end; i++) {
    int isPrime = 1;
    if (i <= 1) {
      isPrime = 0;
    } else {
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          isPrime = 0;
          break;
        }
      }
    }
    if (isPrime) printf("%d\n", i);
  }
  printf("\n");
  return 0;
}
