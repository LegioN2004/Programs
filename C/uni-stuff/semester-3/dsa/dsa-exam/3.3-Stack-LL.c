#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int data;
  struct stack *link;
} Stack;

// firstly top points to null/0
Stack *top = NULL;

// void display() {
//   Stack *temp = top;  // so temp points to stack now
//   if (top == NULL) {
//     printf("The stack is empty");
//   } else {
//     while (temp != NULL) {
//       printf("%d", temp->data);
//       temp = temp->link;
//     }
//   }
// }

void display() {
  if (top == NULL) {
    printf("\nThe stack is empty\n");
  } else {
    Stack *temp = top;  // Temporary pointer to traverse the stack
    printf("\nStack contents (from top to bottom):\n");
    while (temp != NULL) {
      if (temp == top) {
        printf("-----> %d (top)\n", temp->data);  // Mark the top element
      } else {
        printf("       %d\n", temp->data);  // Other elements
      }
      temp = temp->link;  // Move to the next node
    }
  }
}

void push() {
  int data = 0;
  printf("Enter the data you want to push");
  scanf("%d", &data);
  Stack *newnode = (Stack *)malloc(sizeof(Stack));
  // we'll store the value of the top to the first node created
  newnode->data = data;
  // and we'll store the address value of the top to the first node to link it
  // as a stack since TOP points to the new node so we'll point the address of
  // TOP to newnode 1
  newnode->link = top;
  top = newnode;
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

void pop() {
  Stack *temp = top;
  if (top == NULL) {
    printf("The stack is empty, stack underflow");
  } else {
    while (temp != NULL) {
      temp = top;  // top and temp both are pointing to the last element
      printf("the popped element is %d", top->data);
      top = top->link;
      free(temp);
      temp = NULL;
      display();
    }
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