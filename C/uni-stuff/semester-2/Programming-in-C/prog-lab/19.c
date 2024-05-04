#include <stdio.h>

int main() {
  int ans = 0;
  for (int i = 10; i < 100; i++) {
    while (i > 0) {
      ans = ans + i % 10;
      i = i / 10;
    }
    printf("%d", ans);
  }
  return 0;
}
