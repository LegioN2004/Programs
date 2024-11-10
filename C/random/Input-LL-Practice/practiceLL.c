#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 200

typedef struct node {
  int data;
  struct node *link;
} Node;

Node *header, *ptr, *newnode;

int main() {
  header = 0;
  int choice = 1, user_input = 0, count = 0;
  while (choice) {
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == 0) {
      printf("Insufficient memory");
    } else {
      printf("Enter the digits: ");
      scanf("%d", &newnode->data);
      newnode->link = 0;
      // header null
      if (header == 0) {
        header = ptr = newnode;
      } else {
        ptr->link = newnode;
        ptr = newnode;
      }
    }
    printf("Do you want to continue(0, 1) ");
    scanf("%d", &choice);
  }

  printf("The created linked list is");
  ptr = header;
  while (ptr != 0) {
    ++count;
    printf("%d(%d)  ", ptr->data, count);
    ptr = ptr->link;
  }
  printf("\n");
  return 0;
}
