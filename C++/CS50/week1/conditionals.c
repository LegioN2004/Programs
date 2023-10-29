#include <stdio.h>
#include "cs50.h"


int main(void) {
  int x = get_int("What's x? "); // and this gets a return value but it must be stored to be used 
  int y = get_int("What's y? "); // and this gets a return value but it must be stored to be used 

  if (x > y)
    printf("x is greater than y\n");
  else if (x < y) 
  {
    printf("x is not greater than y\n");
  }
  else
    printf("x is equal to y\n");
}
