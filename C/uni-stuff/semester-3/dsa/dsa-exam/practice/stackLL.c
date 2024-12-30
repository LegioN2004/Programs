#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int data;
  struct stack *link;
} Stack;

Stack *top = NULL;

void display() {
  if (top == NULL) {
    printf("stack underflow");
    return;
  } else {
    Stack *temp = top;
    printf("Stack contents from top to bottom\n");
    while (temp != NULL) {
      if (temp == top) {
        printf("\ntop ---> (%d)\n", temp->data);
      } else {
        printf("         (%d)\n", temp->data);
      }
      temp = temp->link;
    }
  }
}

void push() {
  Stack *newnode = (Stack *)malloc(sizeof(Stack));
  printf("enter the data:");
  scanf("%d", &newnode->data);
  newnode->link = top;
  top = newnode;
  display();
}

void pop() {
  Stack *temp = top;
  if (top == NULL) {
    printf("Stack underflow");
  } else {
    while (temp != NULL) {
      temp = top;
      printf("the popped element is %d", top->data);
      top = top->link;
      free(temp);
      temp = NULL;
    }
  }
  display();
}

void peek() {
  Stack *temp = top;
  if (top == NULL) {
    printf("The stack is empty");
  } else {
    printf("the top element is %d", top->data);
  }
}

int main() {
  int choice = 0;
  while (1) {
    printf("\nEnter the operation\n");
    printf("1.push 2.pop 3.display 4.peek 5.exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        push();
      } break;

      case 2: {
        pop();
      } break;

      case 3: {
        display();
      } break;

      case 4: {
        peek();
      } break;

      case 5: {
        return -1;
      } break;

      default: {
        printf("Give the current input");
      } break;
    }
  }
}
