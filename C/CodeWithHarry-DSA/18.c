#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

void printLL(Node *ptr) {
  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

Node *deleteFirstNode(Node *head) {
  Node *p = head;
  head = head->next;
  free(p);
  return head;
}

Node *deleteAtIndex(Node *head, int index) {
  Node *p = head;                       // 0
  Node *q = head->next;                 // 1
  for (int i = 1; i < index - 1; i++) { // 2 - 1 = 1, runs the loop 2x
    p = p->next;                        // 1 2
    q = q->next;                        // 2 3
  }
  p->next = q->next; // 1 linked to 3
  free(q);           // 2 removed
  return head;
}

Node *deleteLastNode(Node *head) {
  Node *p = head;
  Node *q = head->next;
  while (q->next != NULL) {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}

Node *deleteAtGivenValue(Node *head, int value) {
  Node *p = head;
  Node *q = head->next;
  while (q->data != value && q->next != NULL) {
    p = p->next;
    q = q->next;
  }
  // to make sure that the value matches as well since there are two conditions
  // here
  if (q->data == value) {
    p->next = q->next;
    free(q);
  }
  return head;
}

int main() {
  Node *head = (struct node *)malloc(sizeof(struct node));
  Node *first = (struct node *)malloc(sizeof(struct node));
  Node *second = (struct node *)malloc(sizeof(struct node));
  Node *third = (struct node *)malloc(sizeof(struct node));
  Node *fourth = (struct node *)malloc(sizeof(struct node));
  Node *fifth = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  head->next = first;

  first->data = 2;
  first->next = second;

  second->data = 3;
  second->next = third;

  third->data = 4;
  third->next = fourth;

  fourth->data = 5;
  fourth->next = fifth;

  fifth->data = 6;
  fifth->next = NULL;

  printf("Before deletion\n");
  printLL(head);

  /* head = deleteFirstNode(head); */
  /* head = deleteAtIndex(head, 2); */
  /* head = deleteLastNode(head); */
  head = deleteAtGivenValue(head, 3);

  printf("\nAfter deletion\n");
  printLL(head);

  return 0;
}
