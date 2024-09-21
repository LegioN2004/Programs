#include <stdio.h>
#include <stdlib.h>
#define N 5
- int queue[N];
int front = -1;
int rear = -1;

void enqueue(int data) {
  int i = front;
  if (((rear + 1) % N) == front)
    printf("\n\t\t\tOVERFLOW...\n");
  else if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = data;

    printf("\n\t\t\t%d <--- Front & Rear.\n", queue[rear]);
  } else {
    rear = (rear + 1) % N;
    queue[rear] = data;

    // display the circular queue
    printf("\n");
    printf("\t\t\t%d <--- Front\n", queue[front]);
    i = (i + 1) % N;
    while (i != rear) {
      printf("\t\t\t%d\n", queue[i]);
      i = (i + 1) % N;
    }
    printf("\t\t\t%d <--- Rear\n", queue[rear]);
  }
}

void dequeue() {
  if (rear == -1 && front == -1)
    printf("\n\t\t\tUNDERFLOW...\n");
  else if (front == rear) {
    front = rear = -1;
    printf("\n\t\t\tLAST ELEMENT DEQUEUED. NOW THE QUEUE IS EMPTY...\n");
  } else {
    front = (front + 1) % N;
    if (front == rear) {
      printf("\n");
      printf("\t\t\t%d <--- Front & Rear\n", queue[front]);
    } else {
      // display the circular queue
      int i = front;
      printf("\n");
      printf("\t\t\t%d <--- Front\n", queue[front]);
      i = (i + 1) % N;
      while (i != rear) {
        printf("\t\t\t%d\n", queue[i]);
        i = (i + 1) % N;
      }
      printf("\t\t\t%d <--- Rear\n", queue[rear]);
    }
  }
}

int main() {
  int user_input, value;
  while (1) {
    printf("\n1. Enqueue an element.\n2. Dequeue an element.\n3. Exit.\n");
    printf("\nEnter the number to perform the corresponding operation on "
           "circular queue: ");
    scanf("%d", &user_input);
    if (user_input == 1) {
      printf("Enter the data to insert: ");
      scanf("%d", &value);
      enqueue(value);
    } else if (user_input == 2)
      dequeue();
    else if (user_input == 3)
      exit(0);
    else
      printf("\nPlease type 1, 2 or 3. Follow the instructions!\n");
  }
  return 0;
}
