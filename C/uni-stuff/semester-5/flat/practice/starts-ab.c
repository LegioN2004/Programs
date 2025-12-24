#include <stdio.h>

int main() {

  char str[100], state = 'a';

  printf("enter the string: ");
  scanf("%s", str);
  for (int i = 0; str[i] != '\0'; i++) {
    switch (state) {
    case 'a': {
      if (str[i] == 'a') {
        state = 'b';
      } else if (str[i] == 'b') {
        state = 'd';
      }
      break;
    }
    case 'b': {
      if (str[i] == 'a') {
        state = 'd';
      } else if (str[i] == 'b') {
        state = 'c';
      }
      break;
    }
    case 'c': {
      if (str[i] == 'a') {
        state = 'c';
      } else if (str[i] == 'b') {
        state = 'c';
      }
      break;
    }
    case 'd': {
      state = 'd';
      break;
    }
    }
    printf("string: '%c' and state: '%c'\n", str[i], state);
  }

  if (state == 'c') {
    printf("String has been accepted");
  } else if (state == 'd') {
    printf("String has been rejected(dead state)");
  } else {
    printf("String has been rejected");
  }
  return 0;
}
