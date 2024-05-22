#include <stdio.h>

int main() {
  char *ptr;
  char string[] = "india123";
  ptr = string;
  ptr += 5;
  printf("%s\n", ptr);
  /* printf("%c\n", *ptr); */
  /* printf("%s\n", string); */
  /* printf("%s\n", ptr); */
  /* printf("%c\n", ptr); */
  /* printf("%d\n", ptr); */
  return 0;
}
