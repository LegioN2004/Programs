#include <process.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->link = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = newnode;
    rear->link = newnode;
    printf("\n\t\t\t%d <--- Front & Rear\n", rear->data);
  } else {
    rear->link = newnode;
    rear = newnode;
    rear->link = front;
    // display the circular queue
    temp = front;
    printf("\n\t\t\t%d <--- Front\n", front->data);
    temp = temp->link;
    while (temp->link != front) {
      printf("\t\t\t%d\n", temp->data);
      temp = temp->link;
    }
    printf("\t\t\t%d <--- Rear\n", rear->data);
    printf("\n");
  }
}

void dequeue() {
  struct node *temp,
      *temp1;  // temp for traversing, temp1 for deleting the node;
  if (front == NULL && rear == NULL)
    printf("\n\t\t\tUNDERFLOW...\n");
  else if (front == rear) {
    temp1 = front;
    front = rear = NULL;
    free(temp1);
    printf("\n\t\t\tLAST ELEMENT DEQUEUED. NOW THE CIRCULAR QUEUE IS EMPTY.\n");
  } else {
    temp1 = front;
    front = front->link;
    rear->link = front;
    temp1->link = NULL;
    free(temp1);

    // display the circular queue
    if (front == rear)
      printf("\n\t\t\t%d <--- Front & Rear\n", front->data);
    else {
      temp = front;
      printf("\n\t\t\t%d <--- Front\n", front->data);
      temp = temp->link;
      while (temp->link != front) {
        printf("\t\t\t%d\n", temp->data);
        temp = temp->link;
      }
      printf("\t\t\t%d <--- Rear\n", rear->data);
      printf("\n");
    }
  }
}

int main() {
  int user_input, value;
  while (1) {
    printf("\n1. Enqueue an element.\n2. Dequeue an element.\n3. Exit.\n");
    printf(
        "\nEnter the number to perform the corresponding operation on "
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
