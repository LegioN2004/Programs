// find whether a person is eligible to vote or not

#include <stdio.h>

int main() {
  int age;
  printf("Enter age\n");
  scanf("%d", &age);
  if (age >= 18) {
    printf("Is eligible to vote");
  } else {
    printf("Is not eligible to vote");
  }
  return 0;
}
