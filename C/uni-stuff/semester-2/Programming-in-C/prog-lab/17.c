#include <stdio.h>

int main() {
  int a = 0, b = 0;
  printf("enter the number you want to find the reverse of: ");
  scanf("%d", &a);  // 1234
  while (a != 0) {
    int temp = a % 10;  // 4 3 2 1
    b = b * 10 + temp;
    a = a / 10;
  }
  printf("%d", b);
}
