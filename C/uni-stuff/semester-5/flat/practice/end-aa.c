#include <stdio.h>

int main() {
  char str[100], f = 'a';
  int i;

  printf("Enter the string to DFA: ");
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++) {
    switch (f) {
    case 'a': {
      if (str[i] == 'a')
        f = 'b';
      else if (str[i] == 'b') {
        f = 'a';
      }
      break;
    }
    case 'b': {
      if (str[i] == 'a')
        f = 'c';
      else if (str[i] == 'b') {
        f = 'a';
      }
      break;
    }
    case 'c': {
      if (str[i] == 'a')
        f = 'c';
      else if (str[i] == 'b') {
        f = 'a';
      }
      break;
    }
    }
  }
  // final state
  if (f == 'c')
    printf("String is accepted");
  else
    printf("String is not accepted");
  return 0;
}
