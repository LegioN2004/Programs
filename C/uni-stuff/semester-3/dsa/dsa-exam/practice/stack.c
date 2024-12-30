#include <stdio.h>
#include <stdlib.h>

#define N 5
int stack[N];
int top = -1;

void display() {
  if (top == -1) {
    printf("\n stack is currently empty");
  } else {
    for (int i = top; i >= 0; i--) {
      printf("\n[%d] --> %d ", i, stack[i]);
    }
  }
}

void Push() {
  if (top == N - 1) {
    printf("\n overflow: stack is currently full");
  } else {
    top++;
    int val = 0;
    printf("\nenter the value you want to add: ");
    scanf("%d", &val);
    stack[top] = val;
    printf("\nPushed the value %d onto the stack", val);
  }
  display();
}

void Pop() {
  if (top == -1) {
    printf("Stack underflow: No elements in the stack");
  } else {
    int val = stack[top];
    top--;
    printf("Removed the %d element from the stack", val);
  }
  display();
}

void Top() {
  if (top == -1) {
    printf("Stack underflow: No elements in the stack");
  } else {
    printf("\n the element on the top is: %d", stack[top]);
  }
}

int main() {
  int choice;
  while (1) {
    printf("\n\n--- Stack Operations Menu ---");
    printf("\n1. Push (Add an element)");
    printf("\n2. Pop (Remove the top element)");
    printf("\n3. Display the stack");
    printf("\n4. View the top element");
    printf("\n5. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        Push();
        break;
      case 2:
        Pop();
        break;
      case 3:
        display();
        break;
      case 4:
        Top();
        break;
      case 5:
        printf("\nExiting the program. Goodbye!");
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Please try again.");
    }
  }
  return 0;
}
