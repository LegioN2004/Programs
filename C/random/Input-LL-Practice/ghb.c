#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};
struct node *header = NULL;

void display_list() {
  struct node *ptr = header;
  printf("The list is: ");
  while (ptr) {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
  printf("\n");
}

void insert(int pos) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (!newnode) {
    printf("Insufficient memory...\n");
    return;
  }
  printf("Enter data: ");
  scanf("%d", &newnode->data);

  if (pos == 1 || !header) {
    newnode->link = header;
    header = newnode;
  } else {
    struct node *ptr = header;
    for (int i = 1; i < pos - 1 && ptr->link; i++) ptr = ptr->link;
    newnode->link = ptr->link;
    ptr->link = newnode;
  }
  display_list();
}

void create_list() {
  int choice = 1;
  printf("Creating Linked List.\n");
  while (choice) {
    insert(0x7FFFFFFF);  // Insert at end by default
    printf("Do you wish to add another node? (0 for No, 1 for Yes): ");
    scanf("%d", &choice);
  }
}

int main() {
  int user_input, pos;

  create_list();  // Create the list with user input data

  while (1) {
    printf(
        "\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. "
        "Exit\nChoice: ");
    scanf("%d", &user_input);
    if (user_input == 4) break;
    if (user_input == 1)
      pos = 1;
    else if (user_input == 2)
      pos = 0x7FFFFFFF;  // Insert at end
    else if (user_input == 3) {
      printf("Enter position: ");
      scanf("%d", &pos);
    } else
      continue;
    insert(pos);
  }
  return 0;
}