#include <stdio.h>

int main() {
  char *ptr;
  char string[] = "india123";
  ptr = string;
  printf("%s\n", ptr);
  ptr += 6;
  printf("%s\n", ptr);
  /* printf("%c\n", *ptr); */
  /* printf("%s\n", string); */
  /* printf("%s\n", ptr); */
  /* printf("%c\n", ptr); */
  /* printf("%d\n", ptr); */
  return 0;
}
