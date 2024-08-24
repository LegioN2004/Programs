#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void PrintLL(struct node *ptr) {
  while (ptr != NULL) {
    printf("Element: %d \n", ptr->data);
    ptr = ptr->next;
  }
}

int main() {

  struct node *head;
  struct node *first;
  struct node *second;
  struct node *third;
  struct node *fourth;
  struct node *fifth;

  head = (struct node *)malloc(sizeof(struct node));
  first = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));
  fourth = (struct node *)malloc(sizeof(struct node));
  fifth = (struct node *)malloc(sizeof(struct node));

  head->data = 10;
  head->next = first;

  fifth->data = 60;
  fifth->next = first;

  first->data = 20;
  first->next = second;

  second->data = 30;
  second->next = third;

  third->data = 40;
  third->next = fourth;

  fourth->data = 50;
  fourth->next = NULL;

  PrintLL(head);

  return 0;
}
