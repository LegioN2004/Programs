#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

// this function will run that many times and will take data as well
Node *createNodeInLL(Node *head) {
  int data = 0;
  scanf("%d", &data);
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = data;
  p->next = NULL;

  Node *ptr;
  if (head == NULL) {
    head = p;
    ptr = head;
    return head;
  } else {
    ptr->next = p;
    ptr = p;
    return head;
  }
}

void printLL(Node *head) {
  Node *p = head;
  while (p != NULL) {
    printf("Element is: %d\n", p->data);
    p = p->next;
  }
}

int main() {
  int n = 0, i = 0;
  scanf("%d", &n);
  Node *head = NULL;  // Node type pointer head is initialized to NULL
  // creating a for loop to create n nodes in the linked list and then passing
  // the head and taking the return value to head
  for (int i = 0; i < n; i++) {
    // this function will run for n times, and it will create nodes that many
    // times and it'll be 0 indexed and they'll be linked as well.
    head = createNodeInLL(head);
  }
  printLL(head);

  return 0;
}