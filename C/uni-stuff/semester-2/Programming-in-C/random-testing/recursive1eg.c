#include <stdio.h>

int sum(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + sum(n - 1);  // 5 + 4 = 9 + 3 = 12 + 2 = 14 + 1 = 15
  }
}
int main() {
  int n = 5;
  int result = sum(n);
  printf("Sum of first %d numbers is %d\n", n, result);
  return 0;
}
