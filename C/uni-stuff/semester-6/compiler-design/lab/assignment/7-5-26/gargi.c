#include <ctype.h>
#include <stdio.h>
#include <string.h>

char productions[10][10] = {"S=ABC", "A=a", "A=b", "A=#", "B=c",
                            "B=d",   "B=#", "C=e", "C=f", "C=#"};

char first[100];
int n = 10;

void findFirst(char c) {

  if (!isupper(c)) {
    printf("%c ", c);
    return;
  }

  for (int i = 0; i < n; i++) {

    if (productions[i][0] == c) {

      char next = productions[i][2];

      if (!isupper(next)) {
        printf("%c ", next);
      } else {

        findFirst(next);
      }
    }
  }
}

int main() {

  printf("FIRST(S) = { ");
  findFirst('S');
  printf("}\n");

  printf("FIRST(A) = { ");
  findFirst('A');
  printf("}\n");

  printf("FIRST(B) = { ");
  findFirst('B');
  printf("}\n");

  printf("FIRST(C) = { ");
  findFirst('C');
  printf("}\n");

  return 0;
}
