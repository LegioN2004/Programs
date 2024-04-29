#include <stdio.h>

int main() {
  int a = 0;
  printf("enter the numbers till where you want to find the even numbers: ");
  scanf("%d", &a);  // 1234
  for (int i = 1; i <= a; i++) {
    if (i % 2 == 0) {
      printf("%d \n", i);
    }
  }
}
