// find the reverse of a number
#include <stdio.h> //while loop

int main() {
  int n, ans = 0;
  printf("Enter a number:\n");
  scanf("%d", &n);

  while (n != 0) {
    ans = ans * 10 + n % 10;
    n = n / 10;
  }
  printf("Reverse:\n%d", ans);
  return 0;
}
