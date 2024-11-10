#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;  // info
  struct node *next;
} Node;

void display(Node *ptr) {
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

int main() {
  Node *head;
  Node *first;
  Node *second;
  Node *third;
  Node *fourth;

  head = (Node *)malloc(sizeof(Node));
  first = (Node *)malloc(sizeof(Node));
  second = (Node *)malloc(sizeof(Node));
  third = (Node *)malloc(sizeof(Node));
  fourth = (Node *)malloc(sizeof(Node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = fourth;

  fourth->data = 4;
  fourth->next = NULL;

  display(head);
  return 0;
}
