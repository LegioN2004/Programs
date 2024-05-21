#include <stdio.h>

int main() {
  enum week {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
  } c = Sunday;
  int a = c;
  int b = Monday;
  printf("%d\n%d\n", a, c);
  printf("%d\n", b);
  for (int i = Monday; i <= Sunday; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i = 0; i <= Sunday; i++) {
    printf("%d ", Monday);
  }
  return 0;
}
