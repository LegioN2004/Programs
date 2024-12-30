#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#define size 5

void push(int stack[], int *top, int value) {
  int i;
  if (*top == size - 1)
    printf("\n\t\t\toverflowwwwwwww\n");
  else {
    *top += 1;
    stack[*top] = value;

    // display the stack
    printf("\n");
    printf("\t\t\t%d <--- Top\n", stack[*top]);
    for (i = *top - 1; i >= 0; i--) printf("\t\t\t%d\n", stack[i]);
  }
}

void pop(int stack[], int *top) {
  int i, item;
  if (*top == -1)
    printf("\n\t\t\tunderflowwwwww\n");
  else {
    item = stack[*top];
    *top -= 1;
    if (*top == -1)
      printf("\n\t\t\tLast element has been popped, now the stack is empty\n");
    else {
      printf("\n");
      printf("\t\t\t%d <--- Top\n", stack[*top]);
      for (i = *top - 1; i >= 0; i--) printf("\t\t\t%d\n", stack[i]);
    }
  }
}

void display(int stack[], int *top) {
  float free_space = (float)(size - (*top + 1)) / size * 100;
  if (*top == -1) {
    printf("\n\nThe stack is empty.\n");
    printf("The percentage of free space left in stack is: 100%%\n");
    printf("No element is at Top.\n");

  } else if (*top == size - 1) {
    printf("\n\nThe stack is full.\n");
    printf("The percentage of free space left in stack is: 0%%\n");
    printf("The element at Top is: %d\n", stack[*top]);

  } else {
    printf("\n\nThe stack is not full.\n");
    printf("The percentage of free space left in stack is: %0.2f%%\n",
           free_space);
    printf("The element at Top is: %d\n", stack[*top]);
  }
}

int main() {
  int stack[size];
  int input, value;
  int top = -1;
  while (1) {
    printf(
        "\n1. Push an element.\n2. Pop an element.\n3. Check the "
        "status of the stack.\n4. Exit.\n");
    printf(
        "\nEnter the number to perform the corresponding operation on stack: ");
    scanf("%d", &input);
    if (input == 1) {
      printf("Enter the value to insert: ");
      scanf("%d", &value);
      push(stack, &top, value);

    } else if (input == 2)
      pop(stack, &top);
    else if (input == 3)
      display(stack, &top);
    else if (input == 4)
      exit(0);
    else
      printf("\nPlease type 1, 2, 3 or 4. Follow the instructions!\n");
  }
  return 0;
}
