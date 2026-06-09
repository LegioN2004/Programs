#include <ctype.h>
#include <stdio.h>

char prod[10][10];
int n;

void first(char c) {
  if (!isupper(c)) {
    printf("%c ", c);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (prod[i][0] == c) {
      first(prod[i][2]);
    }
  }
}
int main() {
  char nt;
  printf("Enter no of prods: \n");
  scanf("%d", &n);

  printf("Enter prods: \n");
  for (int i = 0; i < n; i++) {
    scanf("%s", prod[i]);
  }

  printf("Enter prod to find nt for: ");
  scanf(" %c", &nt);

  printf("first(%c) = { ", nt);
  first(nt);
  printf("} \n");
  return 0;
}
