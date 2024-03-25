// find if the character is vowel or consonant

#include <stdio.h>

int main() {
  char a;
  printf("Enter the character: ");
  scanf("%c", &a);
  if (a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' ||
      a == 'o' || a == 'O' || a == 'u' || a == 'U') {
    printf("The char is vowel\n");
  } else {
    printf("The char is consonant\n");
  }
  return 0;
}
