#include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N];
// -1 means that the stack is empty and nothing is in the stack
int front = -1;
int rear = -1;

//   if (top == -1) {
//     printf("\nStack is currently empty.");
//   } else {
//     printf("\nCurrent stack contents (top to bottom):");
//     for (int i = top; i >= 0; i--) {
//       printf("\n[%d] -> %d", i, stack[i]);
//     }
//   }

void display() {
  if (front == -1 && rear == -1) {
    printf("queue is underflow");
  } else {
    for (int i = front; i < rear + 1; i++) {
      printf("%d", queue[i]);
    }
  }
}

void Enqueue() {
  int data = 0;
  printf("Enter the data to enqueue");
  scanf("%d", &data);
  if (rear == N - 1) {
    printf("Queue is full, overflow");
    // if queue is empty then both the front and the rear will point to -1
  } else if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = data;
  } else {
    // since it enters from the rear end, so we'll just make the rear point to
    // the next i.e the next position from where it is currently, will be the
    // rear. The front will remain the same here throughout.
    rear++;
    queue[rear] = data;
  }
}

void Dequeue() {
  if (front == -1 && rear == -1) {
    printf("Underflow");
  } else if (front == rear) {
    front = rear = -1;
  } else {
    // front is now pointing to the next value from the previous one. Now the
    // previous one is garbage and so it can be removed so that is how we do
    // dequeue.
    printf("The dequeued element from the queue is", queue[front]);
    front++;
    // and once it reaches the last element i.e both pointing to the same value
    // so then it'll be made to point to -1 i.e the last element is to be
    // removed so we'll make that garabage and then remove it. So after both
    // points to -1, it'll mean that nothing is present in the queue.
  }
}

int main() {
  int choice;
  while (1) {
    printf("\n\n--- Queue Operations Menu ---");
    printf("\n1. Enqueue (Add an element)");
    printf("\n2. Dequeue (Remove the top element)");
    printf("\n3. Display the stack");
    printf("\n4. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        Enqueue();
        break;
      case 2:
        Dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("\nExiting the program. Goodbye!");
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Please try again.");
    }
  }
  return 0;
}
