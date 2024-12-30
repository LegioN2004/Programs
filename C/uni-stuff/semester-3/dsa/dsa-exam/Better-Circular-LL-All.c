#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};
struct Node *head = NULL;

// Helper Function to Display the List
void displayList() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  struct Node *temp = head;
  printf("\nThe Circular Linked List is: ");
  do {
    printf("%d ", temp->data);
    temp = temp->link;
  } while (temp != head);
  printf("\n");
}

// Insert at the Beginning
void insertAtBeginning() {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data to insert at the beginning: ");
  scanf("%d", &newNode->data);

  if (head == NULL) {
    head = newNode;
    newNode->link = head;  // Point to itself
  } else {
    struct Node *temp = head;
    while (temp->link != head) {
      temp = temp->link;
    }
    newNode->link = head;
    head = newNode;
    temp->link = head;  // Update the last node's link
  }
  displayList();
}

// Insert at the End
void insertAtEnd() {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data to insert at the end: ");
  scanf("%d", &newNode->data);

  if (head == NULL) {
    head = newNode;
    newNode->link = head;  // Point to itself
  } else {
    struct Node *temp = head;
    while (temp->link != head) {
      temp = temp->link;
    }
    temp->link = newNode;
    newNode->link = head;  // Point to the head
  }
  displayList();
}

// Insert at Any Position
void insertAtPosition() {
  int pos, i = 1;
  printf("Enter the position to insert: ");
  scanf("%d", &pos);

  if (pos == 1) {
    insertAtBeginning();
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data to insert: ");
  scanf("%d", &newNode->data);

  struct Node *temp = head;
  while (i < pos - 1 && temp->link != head) {
    temp = temp->link;
    i++;
  }

  if (i < pos - 1) {
    printf("Invalid position!\n");
    free(newNode);
    return;
  }

  newNode->link = temp->link;
  temp->link = newNode;
  displayList();
}

// Delete from the Beginning
void deleteFromBeginning() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  struct Node *temp = head, *last = head;
  if (head->link == head) {  // Only one node
    head = NULL;
  } else {
    while (last->link != head) {
      last = last->link;
    }
    head = head->link;
    last->link = head;
  }
  free(temp);
  displayList();
}

// Delete from the End
void deleteFromEnd() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  struct Node *temp = head, *prev = NULL;

  if (head->link == head) {  // Only one node
    head = NULL;
  } else {
    while (temp->link != head) {
      prev = temp;
      temp = temp->link;
    }
    prev->link = head;
  }
  free(temp);
  displayList();
}

// Delete from Any Position
void deleteAtPosition() {
  int pos, i = 1;
  printf("Enter the position to delete: ");
  scanf("%d", &pos);

  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  struct Node *temp = head, *prev = NULL;

  if (pos == 1) {
    deleteFromBeginning();
    return;
  }

  while (i < pos && temp->link != head) {
    prev = temp;
    temp = temp->link;
    i++;
  }

  if (i < pos) {
    printf("Invalid position!\n");
    return;
  }

  prev->link = temp->link;
  free(temp);
  displayList();
}

int main() {
  int choice;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Display List\n");
    printf("8. Exit\n");
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
        deleteAtPosition();
        break;
      case 7:
        displayList();
        break;
      case 8:
        exit(0);
      default:
        printf("Invalid choice! Try again.\n");
    }
  }

  return 0;
}
