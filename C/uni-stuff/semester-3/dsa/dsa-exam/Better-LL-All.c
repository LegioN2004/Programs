#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;  // Points to the start of the list

// Function to display the current list and return the count of nodes
void displayList() {
  struct Node *temp = head;
  int count = 0;
  printf("The list is: ");
  while (temp != NULL) {
    count++;
    printf("%d(%d) ", temp->data, count);
    temp = temp->next;
  }
  printf("\n");
}

// Insert a new node at the beginning
void insertAtBeginning() {
  struct Node *newData = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data to insert at the beginning: ");
  scanf("%d", &newData->data);
  newData->next = head;
  head = newData;
  displayList();
}

// Insert a new node at the end
void insertAtEnd() {
  struct Node *newData = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data to insert at the end: ");
  scanf("%d", &newData->data);
  newData->next = NULL;

  if (head == NULL) {
    head = newData;
  } else {
    struct Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newData;
  }
  displayList();
}

// Insert a node at a specified position
void insertAtPosition() {
  int pos, i = 1;
  printf("Enter the position to insert a new node: ");
  scanf("%d", &pos);

  struct Node *newData = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data for the new node: ");
  scanf("%d", &newData->data);

  if (pos == 1) {
    newData->next = head;
    head = newData;
  } else {
    struct Node *temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
      temp = temp->next;
    }
    if (temp == NULL) {
      printf("Invalid position!\n");
      free(newData);
      return;
    }
    newData->next = temp->next;
    temp->next = newData;
  }
  displayList();
}

void deleteFromBeginning() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  struct Node *temp = head;
  head = head->next;
  free(temp);
  displayList();
}

void deleteFromEnd() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  struct Node *temp = head, *prev = NULL;
  if (head->next == NULL) {
    free(head);
    head = NULL;
  } else {
    while (temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
  }
  displayList();
}

// Delete a node from a specified position
void deleteFromPosition() {
  int pos;
  printf("Enter the position of the node to delete: ");
  scanf("%d", &pos);

  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  struct Node *temp = head;
  if (pos == 1) {
    head = head->next;
    free(temp);
  } else {
    struct Node *prev = NULL;
    if (temp == NULL) {
      printf("Invalid position!\n");
      return;
    }
    for (int i = 1; i < pos && temp != NULL; i++) {
      prev = temp;
      temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
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
        "position\n7. Exit\n");
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
        exit(0);
      default:
        printf("Invalid choice! Try again.\n");
    }
  }
  return 0;
}
