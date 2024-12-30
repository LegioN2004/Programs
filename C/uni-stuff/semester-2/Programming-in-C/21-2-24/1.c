// to read a character in uppercase and then print it in lowercase

#include <stdio.h>

int main() {
  char lowerCase, upperCase;
  printf("Enter the lowercase char: ");
  scanf(" %c", &lowerCase);
  printf("Enter the uppercase char: ");
  scanf(" %c", &upperCase);
  printf("The uppercase value for %c is %c\n", lowerCase, lowerCase - 32);
  printf("The lowercase value for %c is %c\n", upperCase, upperCase + 32);
  return 0;
}
