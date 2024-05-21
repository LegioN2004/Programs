#include <stdio.h>

int main() {
  struct student {
    char name;
    int age;
    float marks;
  } s1, s2, s3, s4, s5, s6;

  s1.age = 20;
  s1.age = 1;
  s2.age = 2;
  s3.age = 3;
  s4.age = 4;
  s5.age = 5;
  s6.age = 6;
  s6.name = 'h';
  s6.marks = 10.200;
  printf("%d\n%d\n", s1, s2);
  printf("%d\n", s1.age);
  printf("%d\n", s2.age);
  printf("%d\n", s3.age);
  printf("%d\n", s4.age);
  printf("%d\n", s5.age);
  printf("%d\n", s6.age);
  printf("%c\n", s6.name);
  printf("%.3f\n", s6.marks);
  return 0;
}
