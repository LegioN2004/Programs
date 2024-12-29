#include <process.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};
struct node *top = NULL;

void push(int value) {
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->link = top;
  top = newnode;
  // display...
  temp = top;
  printf("\n");
  printf("\t\t\t%d <--- Top\n", temp->data);
  temp = temp->link;
  while (temp != NULL) {
    printf("\t\t\t%d\n", temp->data);
    temp = temp->link;
  }
}

void pop() // popping means the same thing as deleting from the beginning of a
           // list.
{
  int item;
  struct node *temp, *temp1;
  temp = top;
  if (top == NULL)
    printf("\n\t\t\tUNDERFLOW...\n");
  else {
    item = top->data;
    top = top->link;
    temp->link = NULL;
    free(temp);
    if (top == NULL)
      printf("\n\t\t\tLAST ELEMENT POPPED. NOW THE STACK IS EMPTY...\n");
    else {
      // display the stack
      temp1 = top;
      printf("\n");
      printf("\t\t\t%d <--- Top\n", temp1->data);
      temp1 = temp1->link;
      while (temp1 != NULL) {
        printf("\t\t\t%d\n", temp1->data);
        temp1 = temp1->link;
      }
    }
  }
}

void status() {
  if (top == NULL) {
    printf("\n\nThe stack is empty.\n");
    printf("No element is at Top.\n");
  } else {
    printf("\n\nThe stack is not empty.\n");
    printf("The element at Top is: %d\n", top->data);
  }
}

int main() {
  int user_input, value;
  while (1) {
    printf("\n1. Push an element.\n2. Pop an element.\n3. Check the status of "
           "the stack.\n4. Exit.\n");
    printf(
        "\nEnter the number to perform the corresponding operation on stack: ");
    scanf("%d", &user_input);
    if (user_input == 1) {
      printf("Enter the data to insert: ");
      scanf("%d", &value);
      push(value);
    } else if (user_input == 2)
      pop();
    else if (user_input == 3)
      status();
    else if (user_input == 4)
      exit(0);
    else
      printf("\nPlease type 1, 2, 3 or 4. Follow the instructions!\n");
  }
  return 0;
}
