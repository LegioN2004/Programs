#include <stdio.h>

#include "cs50.h"

int main(void) {
  int b;
  char c = get_char("Do yo agree ");

  if (c == 'y' || c == 'Y') {
    printf("Agreed. \n");
  } else if (c == 'n' || c == 'N') {
    printf("not agreed. \n");
  } else {
    printf("idk . \n");
  }
}
