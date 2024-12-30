#include <process.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};
struct node *header, *newnode, *ptr;

void insert_beginning(int *count) {
  *count = 0;
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data you want to add at the beginning: ");
  scanf("%d", &newnode->data);
  newnode->link = header;
  header = newnode;
  ptr->link = newnode;
  printf("The list after you added another element is: ");
  ptr = header;
  while (ptr->link != header) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->link;
  }
  *count += 1;
  printf("%d(%d) ", ptr->data, *count);
  printf("\n");
}

void insert_end(int *count) {
  *count = 0;
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data you want to add to the end: ");
  scanf("%d", &newnode->data);
  newnode->link = header;
  ptr = header;
  while (ptr->link != header) ptr = ptr->link;
  ptr->link = newnode;
  ptr = newnode;
  printf("The list after you added another element is: ");
  ptr = header;
  while (ptr->link != header) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->link;
  }
  *count += 1;
  printf("%d(%d) ", ptr->data, *count);
  printf("\n");
}

void insert_anywhere(int *count) {
  int pos, i = 1;
  printf("\nEnter the position at which you want to add the new node: ");
  scanf("%d", &pos);
  if (pos == *count + 1) {
    *count = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data you want to add to the end: ");
    scanf("%d", &newnode->data);
    newnode->link = header;
    ptr = header;
    while (ptr->link != header) ptr = ptr->link;
    ptr->link = newnode;
    ptr = newnode;
  } else if (pos > *count + 1) {
    printf("Invalid position...\n");
    return;
  } else if (pos == 1) {
    *count = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data you want to add at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->link = header;
    header = newnode;
    ptr->link = newnode;
  } else {
    ptr = header;
    while (i < pos - 1) {
      ptr = ptr->link;
      i++;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    *count = 0;
    if (newnode == 0)
      printf("Insufficient memory...\n");
    else {
      printf("Enter data: ");
      scanf("%d", &newnode->data);
      newnode->link = ptr->link;
      ptr->link = newnode;
    }
  }
  printf("\nThe list after addition of new element is: ");
  ptr = header;
  while (ptr->link != header) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->link;
  }
  *count += 1;
  printf("%d(%d) ", ptr->data, *count);
  printf("\n");
}

void delete_beginning(int *count) {
  struct node *temp;
  temp = header;
  header = temp->link;
  free(temp);
  ptr->link = header;
  *count = 0;
  printf("The list after deletion of first element is: ");
  ptr = header;
  while (ptr->link != header) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->link;
  }
  *count += 1;
  printf("%d(%d) ", ptr->data, *count);
  printf("\n");
}

void delete_end(int *count) {
  struct node *ptr1;
  ptr = header;
  while (ptr->link != header) {
    ptr1 = ptr;
    ptr = ptr->link;
  }
  ptr1->link = header;
  free(ptr);
  *count = 0;
  ptr1 = header;
  printf("The list after deletion of last element is: ");
  while (ptr1->link != header) {
    *count += 1;
    printf("%d(%d) ", ptr1->data, *count);
    ptr1 = ptr1->link;
  }
  *count += 1;
  printf("%d(%d) ", ptr1->data, *count);
  printf("\n");
}

void delete_anywhere(int *count) {
  struct node *temp;
  int pos, i = 1;
  printf("Enter the position of the element you want to delete: ");
  scanf("%d", &pos);
  if (pos >= *count + 1) {
    printf("Invalid position...\n");
    return;
  } else if (pos == 1) {
    temp = header;
    header = temp->link;
    free(temp);
    ptr->link = header;
  } else {
    ptr = header;
    while (i < pos - 1) {
      ptr = ptr->link;
      i++;
    }
    temp = ptr->link;
    ptr->link = temp->link;
    free(temp);
  }
  *count = 0;
  printf("The list after deletion of the element is: ");
  ptr = header;
  while (ptr->link != header) {
    *count += 1;
    printf("%d(%d) ", ptr->data, *count);
    ptr = ptr->link;
  }
  *count += 1;
  printf("%d(%d) ", ptr->data, *count);
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
      newnode->link = 0;
      if (header == 0)
        header = ptr = newnode;
      else {
        ptr->link = newnode;
        ptr = newnode;
      }
      ptr->link = header;
      printf("Do you wish to continue(0,1): ");
      scanf("%d", &choice);
    }
  }
  printf("\nYour Linked List is created.\nThe list is: ");
  ptr = header;
  while (ptr->link != header) {
    ++count;
    printf("%d(%d) ", ptr->data, count);
    ptr = ptr->link;
  }
  ++count;
  printf("%d(%d) ", ptr->data, count);
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
          "You didn't press any of 1, 2, 3, 4, 5, 6 or 7. Follow the "
          "instructions!!\n");
  }
  return 0;
}
