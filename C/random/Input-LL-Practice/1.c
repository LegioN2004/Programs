#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} Node;
Node *header, *newnode, *ptr;

void insert_beginning(int *count) {
  *count = 0;
  newnode = (Node *)malloc(sizeof(Node));
  printf("\nEnter data you want to add at the beginning: ");
  scanf("%d", &newnode->data);
  newnode->link = header;
  header = newnode;
  printf("The list after you added another element is: ");
  ptr = header;
  while (ptr != 0) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->link;
  }
  printf("\n");
}

int main() {
  header = 0;
  int user_input, count = 0, choice = 1;
  while (choice) {
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == 0)
      printf("Insufficient memory...\n");
    else {
      printf("Enter data: ");
      scanf("%d", &newnode->data);
      newnode->link = 0;
      if (header == 0)
        header = ptr = newnode;
      else {
        ptr->link = newnode;
        ptr = newnode;
      }
      printf("Do you wish to continue(0,1): ");
      scanf("%d", &choice);
    }
  }
  printf("\nYour Linked List is created.\nThe list is: ");
  ptr = header;
  while (ptr != 0) {
    ++count;
    printf("%d(%d) ", ptr->data, count);
    ptr = ptr->link;
  }
  printf("\n");
  while (1) {
    printf(
        "\nWhere do you want to insert the new element?\n1. Press 1 to insert "
        "in beginning.\n2. Press 2 to insert at the end.\n3. Press 3 to insert "
        "at any location.\nWhere do you want to delete the element?\n4. Press "
        "4 to delete at the beginning.\n5. Press 5 to delete at the end.\n6. "
        "Press 6 to delete anywhere on the list.\n7. Press 7 to exit.\n\n");
    printf("Your Answer: ");
    scanf("%d", &user_input);
    if (user_input == 1)
      insert_beginning(&count);
    else if (user_input == 7)
      exit(0);
    else
      printf(
          "You didn't press any of 1, 2, 3, 4, 5, 6 or 7. Follow the "
          "instructions.\n");
  }
  return 0;
}
