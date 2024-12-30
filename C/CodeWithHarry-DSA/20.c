#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

void printLL(Node *head) {
  Node *ptr = head;
  // following two lines till the loop is to make the loop run atleast once so
  // that the ptr doesn't stay stuck to head which is the starting point and the
  // condition at the same time and for doing that in a better way we have the
  // do-while loop
  do {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
}

Node *insertAtFirst(Node *head, int data) {
  Node *ptr = (Node *)malloc(sizeof(Node *));
  ptr->data = data;
  Node *p = head->next;
  while (p->next != head) {
    p = p->next;
    // at this point p will be pointing to the last node of the circular linked
    // list
  }
  p->next = ptr;
  ptr->next = head;
  head = ptr;
  return head;
}

int main() {
  Node *head = (Node *)malloc(sizeof(Node));
  Node *second = (Node *)malloc(sizeof(Node));
  Node *third = (Node *)malloc(sizeof(Node));
  Node *fourth = (Node *)malloc(sizeof(Node));

  head->data = 4;
  head->next = second;

  second->data = 3;
  second->next = third;

  third->data = 6;
  third->next = fourth;

  fourth->data = 1;
  fourth->next = head;

  printf("Original Circular Linked List\n");
  printLL(head);
  printf("\n");

  printf("Circular Linked List after inserting 69 at the beginning\n");
  head = insertAtFirst(head, 69);

  printLL(head);

  return 0;
}