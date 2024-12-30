#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *head = NULL;

void displayList() {
  Node *temp = head;
  if (head == NULL) {
    printf("there is nothing");
    return;
  } else {
    while (head != NULL) {
      printf("%d\n", temp->data);
      temp = temp->next;
    }
  }
}

void addBuilding(int number) {
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->data = number;
  newnode->next = head;
  head = newnode;
  displayList();
}

void remBuilding() {
  if (head == NULL) {
    printf("list is empty");
    return;
  }

  if (head->next == NULL) {
    free(head);
    head = NULL;
    printf("the last building has been destructed");
    return;
  }

  Node *temp = head;
  Node *prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  free(temp);
  temp = NULL;
  prev->next = NULL;
  printf("the last building has been destructed");
  return;
}

int main() {
  // Example usage
  addBuilding(101);
  addBuilding(102);
  addBuilding(103);
  displayList();

//   remBuilding();
//   displayList();

//   remBuilding();
//   displayList();

//   remBuilding();
//   displayList();

  return 0;
}
