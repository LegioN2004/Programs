#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  int rno;  // info
  struct Student *next;
} student;

int main() {
  // created three nodes
  student *s1, *s2, *s3;

  // allocated memory to them
  s1 = (student *)malloc(sizeof(student));
  s2 = (student *)malloc(sizeof(student));
  s3 = (student *)malloc(sizeof(student));

  // here head is s1
  // allocated value to them
  s1->rno = 101;
  s2->rno = 102;
  s3->rno = 103;

  // created link amongst them
  s1->next = s2;
  s2->next = s3;
  s3->next = NULL;

  printf("Roll no = %d\n", s1->rno);
  printf("Roll no = %d\n", s1->next->rno);
  printf("Roll no = %d\n", s1->next->next->rno);
}
