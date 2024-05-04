#include <stdio.h>

int main() {
  char a;
  printf("Enter a letter:\n");
  scanf("%c", &a);
  printf("Letter in Upper case = %c", a - 32);
  return 0;
}
