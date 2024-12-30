#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int data;
  struct queue *next;
} Queue;

Queue *front = NULL;
Queue *rear = NULL;

void display() {
  if (front == 0 && rear == 0) {
    printf("Queue is empty");
  } else {
    Queue *temp = front;
    printf("\nQueue contents (from top to bottom):\n");
    while (temp != NULL) {
      printf(" %d ", temp->data);
      temp = temp->next;
    }
  }
}

void enqueue() {
  int x = 0;
  printf("\nenter the data: ");
  scanf("%d", &x);
  Queue *newnode = (Queue *)malloc(sizeof(Queue));
  newnode->data = x;
  newnode->next = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = newnode;
  } else {  // when a new node will be created
    rear->next = newnode;
    rear = newnode;
  }
  display();
}

void dequeue() {
  Queue *temp = front;
  if (front == NULL && rear == NULL) {
    printf("underflow");
  } else {  // when a new node will be created
    printf("%d is removed", front->data);
    front = front->next;
    free(temp);
    temp = NULL;
  }
  display();
}

int main() {
  int choice = 0;
  while (1) {
    printf("\n\nEnter the operation\n");
    printf("1.enqueue 2.dequeue 3.display 4.peek 5.exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        enqueue();
      } break;

      case 2: {
        dequeue();
      } break;

      case 3: {
        display();
      } break;

      case 4: {
        peek();
      } break;

      case 5: {
        printf("Goodbyyyyyyyyyeeeeee");
        exit(0);
        return -1;
      } break;

      default: {
        printf("Give the current input");
      } break;
    }
  }
}
