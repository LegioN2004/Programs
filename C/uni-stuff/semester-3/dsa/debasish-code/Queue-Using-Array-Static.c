#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front = 0;
int rear = 0;

void enqueue(int value) {
  int i;
  if (rear == N)
    printf("\n\t\t\tOVERFLOW...\n");
  else if (front == 0 && rear == 0) {
    front = rear = 1;
    queue[rear] = value;

    // display the queue
    printf("\n");
    printf("\t\t\t%d <--- Front & Rear\n", queue[front]);
  } else {
    ++rear;
    queue[rear] = value;

    // display the queue
    printf("\n");
    printf("\t\t\t%d <--- Front\n", queue[front]);
    for (i = front + 1; i <= rear - 1; i++) printf("\t\t\t%d\n", queue[i]);
    printf("\t\t\t%d <--- Rear\n", queue[rear]);
  }
}

void dequeue() {
  int i;
  if (front == 0 && rear == 0)
    printf("\n\t\t\tUNDERFLOW...\n");
  else if (front == rear) {
    front = rear = 0;
    printf("\n\t\t\tLAST ELEMENT DEQUEUED. NOW THE QUEUE IS EMPTY...\n");
  } else {
    ++front;
    if (front == rear) {
      printf("\n");
      printf("\t\t\t%d <--- Front & Rear\n", queue[front]);
    } else {
      printf("\n");
      printf("\t\t\t%d <--- Front\n", queue[front]);
      for (i = front + 1; i <= rear - 1; i++) printf("\t\t\t%d\n", queue[i]);
      printf("\t\t\t%d <--- Rear\n", queue[rear]);
    }
  }
}

int main() {
  int user_input, value;
  while (1) {
    printf("\n1. Enqueue an element.\n2. Dequeue an element.\n3. Exit.\n");
    printf(
        "\nEnter the number to perform the corresponding operation on queue: ");
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
