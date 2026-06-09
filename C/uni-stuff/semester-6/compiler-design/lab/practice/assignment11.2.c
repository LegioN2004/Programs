#include <ctype.h>
#include <stdio.h>

char prod[10][10];
int n;

int isEpsilon(char ch)
{
  for (int i = 0; i < n; i++)
    if (prod[i][0] == ch && prod[i][2] == '#')
      return 1;
  return 0;
}

void first(char ch)
{
  if (!isupper(ch))
    if (ch != '#')
      printf("%c", ch);

  for (int i = 0; i < n; i++)
    if (prod[i][0] == ch && prod[i][2] != '#')
      first(prod[i][2]);
}

void follow(char ch)
{
  if (ch == prod[0][0])
    printf("$ ");

  for (int i = 0; i < n; i++) {
    for (int j = 2; prod[i][j] != '\0'; j++) {
      if (prod[i][j] == ch) {
        int k = j + 1;
        while (prod[i][k] != '\0') {
          first(prod[i][k]);
          if (!isEpsilon(prod[i][k]))
            break;
          k++;
        }

        // lastor check tu iaat, last jetia aru aku nethake endingot
        if (prod[i][k] == '\0')
          if (prod[i][0] != ch)
            follow(prod[i][0]);
      }
    }
  }
}

int main()
{
  char nt;
  printf("Enter no of prods: \n");
  scanf("%d", &n);

  printf("Enter prods: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%s", prod[i]);
  }

  printf("Enter prod to find nt for: ");
  scanf(" %c", &nt);

  printf("first(%c) = { ", nt);
  follow(nt);
  printf("} \n");
  return 0;
}
