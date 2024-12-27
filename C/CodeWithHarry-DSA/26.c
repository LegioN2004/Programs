#include <stdio.h>
#include <stdlib.h>

struct stack {
  int size;
  int top;
  int *arr;
};

int isEmpty(struct stack *ptr) {
  if (ptr->top == -1)  // if topmost element is -1 then it has nothing or empty
    return 1;          // here -1 i.e the equality check is going on an index
  else
    return 0;
}

int isFull(struct stack *ptr) {
  if (ptr->top == ptr->size - 1)
    return 1;  // size - 1 because it'll have to go till n - 1 index, i.e last
               // index value
  else
    return 0;
}

int displayStack(struct stack *s) {
  printf("\n the array after the change is\n");
  for (int i = 0; i < s->top; i++) {
    printf("%d (%d)\n", s->arr[i], i);
  }
}

int Push(struct stack *s)
// also push doesn't need to return anything
{
  // Check if the stack is empty
  if (isFull(s)) {
    printf("Stack overflow\n");
    return -1;
  } else {
    int n = 0;
    printf("\nEnter the no of elements of the array");
    scanf("%d\n", &n);
    printf("\nEnter the values of the array");
    for (int i = 0; i < n; i++) {
      s->top++;
      scanf("%d", &(s->arr[(s->top)]));
    }

    displayStack(s);
    // printf("\narray of the stack before the change\n");
    // for (int i = 0; i < n; i++) {
    //   printf("%d (%d)\n", s->arr[i], i);
    // }
  }
}

int Pop(struct stack *s)
// firstly to implement pop you don't need any value to pop, instead you gotta
// return a value
{
  if (isEmpty(s)) {
    printf("Stack undeflow\n");
    return -1;
  } else {
    int temp = s->arr[s->top];
    s->top--;
    printf("The value popped is %d\n", temp);
    displayStack(s);
  }
  return 0;
}

int main() {
  struct stack
      *s;  // when we convert this to a struct pointer, we should give the ->
           // syntax to give the values since it can't be accessed with '.' .
  s->size = 10;
  s->top = 0;  // stack is empty and so no pop operation possible so first check
               // if the stack is full or not
  s->arr = (int *)malloc(
      s->size * sizeof(int));  // size of int because integer is being stored

  // pushing value manually
  // s -> arr[0] = 4;
  // s -> top++;
  // also note that the indices of the array of the stack will always remain
  // positive

  int choice = 0;
  printf("\n Enter 1 for Push\n");
  printf("\n Enter 2 for Pop\n");
  printf("\n Enter 3 for Exit\n");
  scanf("%d", &choice);

  while (1) {
    switch (choice) {
      case 1:
        Push(s);
        break;
      case 2:
        Pop(s);
        break;

      default:
        break;
    }
  }

  return 0;
}
