#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} Node;

Node *head = NULL;

void displayList() {
  if (head == NULL) {
    printf("The list is empty \n");
    return;
  }
  Node *temp = head;
  int count = 0;
  printf("The list is: ");
  while (temp != NULL) {
    printf(" %d(%d) ", temp->data, count);
    count++;
    temp = temp->next;
  }
  printf("\n");
}

void insertAtBeginning() {
  Node *newnode = (Node *)malloc(sizeof(Node));
  printf("enter the data to add at the beginning: ");
  scanf("%d", &newnode->data);
  newnode->prev = NULL;
  newnode->next = head;
  if (head != NULL) {
    head->prev = newnode;
  }
  head = newnode;
  displayList();
}

void insertAtEnd() {
  Node *newnode = (Node *)malloc(sizeof(Node));
  printf("enter the data to add at the end: ");
  scanf("%d", &newnode->data);

  newnode->next = NULL;
  if (head == NULL) {
    newnode->prev = NULL;
    head = newnode;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
  }
  displayList();
}

void insertAtPosition() {
  int pos = 0;
  printf("Enter the position: ");
  scanf("%d", &pos);

  Node *newnode = (Node *)malloc(sizeof(Node));
  printf("enter the value you want to add: ");
  scanf("%d", &newnode->data);

  Node *temp = head;
  if (pos == 1) {
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL) {
      head->prev = newnode;
    }
    head = newnode;
  } else {
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
      temp = temp->next;
    }
    if (temp == NULL) {
      printf("Invalid position");
      free(newnode);
      return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
      temp->next->prev = newnode;
    }
    temp->next = newnode;
  }
  displayList();
}

void deleteFromBeginning() {
  Node *temp = head;
  if (head == NULL) {
    printf("List is empty");
  } else if (head->next == NULL) {
    head = NULL;
  } else {
    head = temp->next;
    if (head != NULL) {
      head->prev = NULL;
    }
  }
  free(temp);
  temp = NULL;
  displayList();
}

void deleteFromEnd() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  Node *temp = head;
  if (temp->next == NULL) {
    head = NULL;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->prev->next = NULL;
  }
  free(temp);
  displayList();
}

void deleteFromPosition() {
  int pos = 0;
  printf("Enter the position to delete: ");
  scanf("%d", &pos);

  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  Node *temp = head;

  if (pos == 1) {
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
  } else {
    for (int i = 1; i < pos && temp != NULL; i++) {
      temp = temp->next;
    }
    if (temp == NULL) {
      printf("Invalid position!\n");
      return;
    }
    if (temp->next != NULL) {
      temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
      temp->prev->next = temp->next;
    }
    free(temp);
    temp = NULL;
  }
  displayList();
}

int main() {
  int choice;
  while (1) {
    printf(
        "\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
    printf(
        "4. Delete from beginning\n5. Delete from end\n6. Delete from "
        "position\n7. Display list\n8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insertAtBeginning();
        break;
      case 2:
        insertAtEnd();
        break;
      case 3:
        insertAtPosition();
        break;
      case 4:
        deleteFromBeginning();
        break;
      case 5:
        deleteFromEnd();
        break;
      case 6:
        deleteFromPosition();
        break;
      case 7:
        displayList();
        break;
      case 8:
        exit(0);
        break;
      default:
        printf("Invalid choice! Try again.\n");
    }
  }
  return 0;
}
