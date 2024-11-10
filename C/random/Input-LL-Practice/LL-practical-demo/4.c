#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;  // info
  struct node *next;
} Node;

Node *head;

void createNodeLL(Node *h) {
  int data;
  printf("Enter the data for the LL:\t");
  scanf("%d", data);
  if (h == NULL) {  // if true then
    head = (Node *)malloc(
        sizeof(Node));  // everything of p will be transferred to head;
    head->data = data;
    head->next = NULL;
  } else {
    /* ptr->next = p; */
    /* ptr = p;  // ptr ka value change karke p */
    /* return head; */
    while (h->next != NULL) {
      h = h->next;  // iterate each and every node;
      h->next =
          (Node *)malloc(sizeof(Node));  // allocate memory for the next node
      h->next->data = data;  // assign the data using the var to the next
                             // upcoming data field of the node mane heador
                             // nextor data k data r value di dise
      h->next->next = NULL;  // next of the new node will be null
    }
  }
}

void displayLL(Node *ptr) {
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

int main() {
  int n;
  /* printf("Enter the number of nodes you want in the linked list"); */
  /* scanf("%d", n); */
  /* // loop for the no of nodes */
  /* for (int i = 0; i < n; i++) { */
  /*   createNodeLL(head);  // then we'll pass on the next node to the LL. */
  /* } */
  createNodeLL(head);  // then we'll pass on the next node to the LL.
  createNodeLL(head);  // then we'll pass on the next node to the LL.
  createNodeLL(head);  // then we'll pass on the next node to the LL.
  createNodeLL(head);  // then we'll pass on the next node to the LL.
  displayLL(head);     // to display the LL.
  return 0;
}
