#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  int rno;  // info
  struct Student *next;
} student;

student *head;

// create a student pointer and a function to input students
void create(student *h) {
  int rno;
  printf("Enter the roll no\n");
  scanf("%d", &rno);
  // if the h is NULL, then we neeed to initialize the head and the value from
  // the user
  if (h == NULL) {  // no students in the list
    head = (student *)malloc(sizeof(student));
    head->rno = rno;
    head->next = NULL;
  } else {  // if already some students are there in the list
            // need to reach the last node in order to t
    while (h->next != NULL) {
      h = h->next;
      h->next = (student *)malloc(sizeof(student));
      h->next->rno = rno;
      h->next->next = NULL;
    }
  }
}

void display(student *h) {
  while (h != NULL) {
    printf("%d\n", h->rno);
    h = h->next;
  }
}

int main() {
  create(head);
  create(head);
  create(head);
  create(head);
  create(head);
  display(head);
  return 0;
}
