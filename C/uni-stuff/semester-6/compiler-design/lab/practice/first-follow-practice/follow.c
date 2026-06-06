#include <ctype.h>
#include <stdio.h>
#include <string.h>

char prod[10][10];
int n;

int hasEpsilon(char ch) {
  for (int i = 0; i < n; i++)
    if (prod[i][0] == ch && prod[i][2] == '#')
      return 1;
  return 0;
}

void first(char ch) {
  if (!isupper(ch)) {
    if (ch != '#')
      printf("%c ", ch);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (prod[i][0] == ch) {
      if (prod[i][2] != '#')
        first(prod[i][2]);
    }
  }
}

// A -> a
// A -> b
// A -> #

void follow(char c) {
  int i, j;

  if (c == prod[0][0])
    printf("$ ");

  for (i = 0; i < n; i++) {
    for (j = 2; prod[i][j] != '\0'; j++) {
      if (prod[i][j] == c) {

        int k = j + 1;

        while (prod[i][k] != '\0') {
          first(prod[i][k]);

          if (!hasEpsilon(prod[i][k]))
            break;

          k++;
        }

        if (prod[i][k] == '\0') {
          if (prod[i][0] != c)
            follow(prod[i][0]);
        }
      }
    }
  }
}

int main() {
  int i;
  char ch;

  printf("Enter number of productions: ");
  scanf("%d", &n);

  printf("Enter productions (e.g. S=AB, A=a, A=#):\n");
  for (i = 0; i < n; i++)
    scanf("%s", prod[i]);

  printf("Enter non-terminal for FOLLOW: ");
  scanf(" %c", &ch);

  printf("FOLLOW(%c) = { ", ch);
  follow(ch);
  printf("}\n");

  return 0;
}
