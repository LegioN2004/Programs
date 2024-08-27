#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

void PrintLL(Node *ptr) {
  while (ptr != NULL) {
    printf("Element: %d \n", ptr->data);
    ptr = ptr->next;
  }
}

Node *insertAtFirst(Node *head, int data) {
  Node *ptr = (Node *)malloc(sizeof(Node));
  ptr->data = data;
  ptr->next = head;
  return ptr;
};

Node *insertAtIndex(Node *head, int data, int index) {
  Node *ptr = (Node *)malloc(sizeof(Node));
  Node *p = head;

  int i = 0;
  while (i != (index - 1)) {
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
};

Node *insertAtEnd(Node *head, int data) {
  Node *ptr = (Node *)malloc(sizeof(Node));
  Node *p = head;
  ptr->data = data;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return head;
};

Node *insertAfterNode(Node *head, Node *prevNode, int data) {
  Node *ptr = (Node *)malloc(sizeof(Node));
  Node *p = head;
  ptr->data = data;
  ptr->next = prevNode->next;
  prevNode->next = ptr;

  return head;
};

int main() {
  Node *head;
  Node *second;
  Node *third;
  Node *fourth;

  head = (Node *)malloc(sizeof(Node));
  second = (Node *)malloc(sizeof(Node));
  third = (Node *)malloc(sizeof(Node));
  fourth = (Node *)malloc(sizeof(Node));

  head->data = 10;
  head->next = second;

  second->data = 30;
  second->next = third;

  third->data = 40;
  third->next = fourth;

  fourth->data = 50;
  fourth->next = NULL;

  printf("LL before \n");
  PrintLL(head);
  /* printf("\n"); */
  /* head = insertAtFirst(head, 88); */

  /* head = insertAtIndex(head, 80, 1); */
  head = insertAfterNode(head, second, 80);
  printf("LL after \n");
  PrintLL(head);

  return 0;
}
