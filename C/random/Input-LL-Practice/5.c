#include <stdio.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} Node;

Node *head = NULL;

void displayList() {
  int pos = 1;
  if (head == NULL) {
    printf("the list is empty ");
    return;
  }
  Node *temp = head;
  printf("The doubly linked list is: ");
  while (temp != NULL) {
    printf("%d(%d) ", temp->data, pos++);
    temp = temp->next;
  }
  printf("\n");
}

void insertAtBeginning() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter the data you want at the front of the list: ");
  scanf("%d", &newNode->data);

  newNode->prev = NULL;
  newNode->next = head;

  if (head != NULL) {
    head->prev = newNode;
  }
  head = newNode;
  displayList();
}

void insertAtEnd() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter the data: ");
  scanf("%d", &newNode->data);

  newNode->next = NULL;
  if (head == NULL) {
    newNode->prev = NULL;
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    newNode->prev = temp;
  }
  displayList();
}

void insertAtPosition() {
  int pos = 0, i = 0;
  printf("enter the position: ");
  scanf("%d", &pos);

  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter the data: ");
  scanf("%d", &newNode->data);

  if (pos == 1) {
    insertAtBeginning();
    return;
  } else {
    Node *temp = head;
    // the following line always goes till the pos-1 position in all the LL
    while (i < pos - 1 && temp->next != NULL) {
      temp = temp->next;
      i++;
    }

    if (temp == NULL) {
      printf("Invalid position");
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

void deleteFromBeginning() {
  if (head == NULL) {
    printf("The list is empty\n");
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

int main() {
  int choice;

  while (1) {
    printf("1. Insert at beginning \n");
    printf("2. Insert at end \n");
    printf("3. Insert at any position \n");
    printf("4. delete from beginning \n");
    printf("4. delete from end \n");
    printf("4. delete from any position \n");
    printf("7. Display list \n");
    printf("8. Get the hell out of this code \n");
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
      //     break;
      // case 1:
      //     /* code */
      //     break;
      // case 1:
      //     /* code */
      //     break;
      // case 1:
      //     /* code */
      //     break;
      // case 1:
      //     /* code */
      //     break;
      default:
        printf("Invalid case, enter the value properly");
    }
  }

  return 0;
}
