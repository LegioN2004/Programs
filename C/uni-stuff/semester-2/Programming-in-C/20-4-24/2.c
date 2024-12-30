// find n no of fibonacci series = 0, 1, 1, 2, 3, 5, 8, 13, ...............

#include <stdio.h>

int main() {
  int n, i = 1, a = 0, nextTerm;
  printf(
      "enter the range n till where you want to find the fibonacci series: ");
  scanf("%d", &n);
  printf("%d\n", a);  // 0
  while (i < n) {
    printf("%d\n", i);  // 1 1 2 3 5
    nextTerm = a + i;   // 1 2 3 5 8
    a = i;              // 1 1 2 3 5
    i = nextTerm;       // 1 2 3 5 8
  }
  return 0;
}
