#include <stdio.h>

int main() {
  char ch[10] = "abc";
  printf("%d %s\n", sizeof(ch), ch);
  for (int i = 0; i < sizeof(ch); i++) {
    printf("%c", ch[i]);
  }

  /* char ch[10] = "abc"; */
  /* printf("%zu %s\n", sizeof(ch), ch); // Use %zu for size_t and %s for string
   */
  /* for (int i = 0; i < sizeof(ch); i++) { */
  /*   printf("%c", ch[i]); // Print each character */
  /* } */
  /* printf("\n"); */
  return 0;
}
