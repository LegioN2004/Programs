#include <process.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *llink, *rlink;
};
struct node *header, *newnode, *ptr;

void insert_beginning(int *count) {
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the data you want to insert at the beginning: ");
  scanf("%d", &newnode->data);
  newnode->llink = 0;
  newnode->rlink = 0;
  ptr = header;
  ptr->llink = newnode;
  newnode->rlink = ptr;
  header = newnode;
  *count = 0;
  printf("The list after inserting the element is: ");
  ptr = header;
  while (ptr != 0) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->rlink;
  }
  printf("\n");
}

void insert_end(int *count) {
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter data that you want to insert at the end: ");
  scanf("%d", &newnode->data);
  newnode->llink = 0;
  newnode->rlink = 0;
  ptr = header;
  while (ptr->rlink != 0) ptr = ptr->rlink;
  ptr->rlink = newnode;
  newnode->llink = ptr;
  ptr = newnode;
  *count = 0;
  printf("The list after inserting the element is: ");
  ptr = header;
  while (ptr != 0) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->rlink;
  }
  printf("\n");
}

void insert_anywhere(int *count) {
  int pos, i = 1;
  printf("Enter the position at which you want to add the new node: ");
  scanf("%d", &pos);
  if (pos == *count + 1) {
    newnode = (struct node *)malloc(sizeof(struct node));
    *count = 0;
    printf("Enter data that you want to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->llink = 0;
    newnode->rlink = 0;
    ptr = header;
    while (ptr->rlink != 0) ptr = ptr->rlink;
    ptr->rlink = newnode;
    newnode->llink = ptr;
    ptr = newnode;
  } else if (pos > *count + 1) {
    printf("\nInvalid position...\n");
    return;
  } else if (pos == 1) {
    newnode = (struct node *)malloc(sizeof(struct node));
    *count = 0;
    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->llink = 0;
    newnode->rlink = 0;
    ptr = header;
    ptr->llink = newnode;
    newnode->rlink = ptr;
    header = newnode;
  } else {
    ptr = header;
    while (i < pos - 1) {
      ptr = ptr->rlink;
      i++;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    *count = 0;
    if (newnode == 0)
      printf("Insufficient memory...\n");
    else {
      printf("Enter data: ");
      scanf("%d", &newnode->data);
      newnode->llink = ptr;
      newnode->rlink = ptr->rlink;
      ptr->rlink = newnode;
      newnode->rlink->llink = newnode;
    }
  }
  printf("The list after inserting the element is: ");
  ptr = header;
  while (ptr != 0) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->rlink;
  }
  printf("\n");
}

void delete_beginning(int *count) {
  if (header == 0)
    printf("The list is empty.\n");
  else {
    ptr = header;
    header = ptr->rlink;
    ptr->rlink = 0;
    header->llink = 0;
    free(ptr);
  }
  *count = 0;
  printf("The list after deleting the element is: ");
  ptr = header;
  while (ptr != 0) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->rlink;
  }
  printf("\n");
}

void delete_end(int *count) {
  struct node *ptr1;
  ptr = header;
  while (ptr->rlink != 0) {
    ptr1 = ptr;
    ptr = ptr->rlink;
  }
  ptr1->rlink = 0;
  ptr->llink = 0;
  free(ptr);
  *count = 0;
  printf("The list after deleting the element is: ");
  ptr = header;
  while (ptr != 0) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->rlink;
  }
  printf("\n");
}

void delete_anywhere(int *count) {
  int pos, i = 1;
  printf("Enter the position of the node you want to delete: ");
  scanf("%d", &pos);
  if (pos > count) {
    printf("Invalid position...\n");
    return;
  }
  if (pos == 1) {
    ptr = header;
    header = ptr->rlink;
    ptr->rlink = 0;
    header->llink = 0;
    free(ptr);
  } else if (pos == *count) {
    struct node *ptr1;
    ptr = header;
    while (ptr->rlink != 0) {
      ptr1 = ptr;
      ptr = ptr->rlink;
    }
    ptr1->rlink = 0;
    ptr->llink = 0;
    free(ptr);
  } else {
    ptr = header;
    while (i < pos) {
      ptr = ptr->rlink;
      i++;
    }
    ptr->llink->rlink = ptr->rlink;
    ptr->rlink->llink = ptr->llink;
    free(ptr);
  }
  printf("The list after deleting the element is: ");
  *count = 0;
  ptr = header;
  while (ptr != 0) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->rlink;
  }
  printf("\n");
}

int main() {
  header = 0;
  int user_input, count = 0, choice = 1;
  while (choice) {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == 0)
      printf("Insufficient memory...\n");
    else {
      printf("Enter data: ");
      scanf("%d", &newnode->data);
      newnode->llink = 0;
      newnode->rlink = 0;
      if (header == 0)
        header = ptr = newnode;
      else {
        ptr->rlink = newnode;
        newnode->llink = ptr;
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
    ptr = ptr->rlink;
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
    else if (user_input == 2)
      insert_end(&count);
    else if (user_input == 3)
      insert_anywhere(&count);
    else if (user_input == 4)
      delete_beginning(&count);
    else if (user_input == 5)
      delete_end(&count);
    else if (user_input == 6)
      delete_anywhere(&count);
    else if (user_input == 7)
      exit(0);
    else
      printf(
          "You didn't press any of 1, 2, 3, 4, 5, 6 or 7. Please follow the "
          "instructions!!\n");
  }
  return 0;
}
