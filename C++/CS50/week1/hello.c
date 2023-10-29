#include <stdio.h>
#include "cs50.h"

int main(void) {
 // using the the printf function and it allows to format text on a screen
  // string answer = get_string("What's your name? "); // we also need to tell what type of value we need to store
  string first = get_string("What's your first name? ");
  string second = get_string("What's your last name? ");
  // printf("hello, %s \n", answer); // \n is used to change the cursor to the next line commonly known as escape sequence
  printf("hello, %s %s \n", first, second);

  printf("hello, I got 95%%\n"); // in the new compiler this error has been removed I guess
}
