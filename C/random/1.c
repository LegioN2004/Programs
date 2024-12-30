#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the Doubly Linked List
typedef struct node {
  int data;
  struct node *prev;  // Pointer to the previous node
  struct node *next;  // Pointer to the next node
} Node;

Node *head = NULL;  // Head pointer to the DLL

// Function to display the doubly linked list
void displayList() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  Node *temp = head;
  printf("The Doubly Linked List is: ");
  int i = 0;
  while (i < pos && head != NULL) {
    printf("%d ", temp->data);
    head = head->next;
    i++;
  }
  printf("\n");
}

// Insert at the beginning
void insertAtBeginning() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter data to insert at the beginning: ");
  scanf("%d", &newNode->data);

  newNode->prev = NULL;
  newNode->next = head;

  if (head != NULL) {
    head->prev = newNode;
  }
  head = newNode;
  displayList();
}

// Insert at the end
void insertAtEnd() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter data to insert at the end: ");
  scanf("%d", &newNode->data);

  newNode->next = NULL;
  if (head == NULL) {
    newNode->prev = NULL;
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;  // Traverse to the last node
    }
    temp->next = newNode;  // link the last node to the new node
    newNode->prev = temp;  // link the new node back to the last node
  }
  displayList();
}

// Insert at a specific position
void insertAtPosition() {
  int pos, i = 1;
  printf("Enter the position to insert: ");
  scanf("%d", &pos);

  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter data to insert: ");
  scanf("%d", &newNode->data);

  if (pos == 1) {
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
      head->prev = newNode;
    }
    head = newNode;
  } else {
    Node *temp = head;
    while (i < pos - 1 && temp != NULL) {
      temp = temp->next;  // Traverse to the node before the desired position
      i++;
    }

    if (temp == NULL) {
      printf("Invalid position!\n");
      free(newNode);
      return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
  }

  displayList();
}

// Delete from the beginning
void deleteFromBeginning() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  Node *temp = head;
  head = head->next;

  if (head != NULL) {
    head->prev = NULL;
  }

  free(temp);
  displayList();
}

// Delete from the end
void deleteFromEnd() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  Node *temp = head;
  if (temp->next == NULL) {  // Only one node in the list
    head = NULL;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;  // Traverse to the last node
    }
    temp->prev->next = NULL;
  }

  free(temp);
  displayList();
}

// Delete from a specific position
void deleteAtPosition() {
  int pos, i = 1;
  printf("Enter the position to delete: ");
  scanf("%d", &pos);

  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  Node *temp = head;

  if (pos == 1) {
    head = head->next;
    if (head != NULL) {
      head->prev = NULL;
    }
    free(temp);
  } else {
    while (i < pos && temp != NULL) {
      temp = temp->next;
      i++;
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
  }

  displayList();
}

// Menu-driven interface
int main() {
  int choice;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete at Position\n");
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
