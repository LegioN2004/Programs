#include <process.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *temp1;  // temp -- for traversing, temp1 -- last second node, temp2
                     // -- node to be deleted

void enqueue(int value) {
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->link = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = newnode;
    printf("\n");
    printf("\t\t\t%d <--- Front & Rear\n", front->data);
  } else {
    temp1 = rear;
    rear->link = newnode;
    rear = newnode;

    // display the queue
    temp = front;
    printf("\n");
    printf("\t\t\t%d <--- Front\n", temp->data);
    temp = temp->link;
    while (temp != temp1->link) {
      printf("\t\t\t%d\n", temp->data);
      temp = temp->link;
    }
    printf("\t\t\t%d <--- Rear\n", rear->data);
  }
}

void dequeue() {
  struct node *temp, *temp2;
  if (front == NULL && rear == NULL)
    printf("\n\t\t\tUNDERFLOW...\n");
  else if (front == rear) {
    temp2 = front;
    front = rear = NULL;
    free(temp2);
    printf("\n\t\t\tLAST ELEMENT DEQUEUED. NOW THE QUEUE IS EMPTY...\n");
  } else {
    temp2 = front;
    front = front->link;
    free(temp2);
    if (front == rear) {
      printf("\n");
      printf("\t\t\t%d <--- Front & Rear\n", front->data);
    } else {
      temp = front;
      printf("\n");
      printf("\t\t\t%d <--- Front\n", temp->data);
      temp = temp->link;
      while (temp != temp1->link) {
        printf("\t\t\t%d\n", temp->data);
        temp = temp->link;
      }
      printf("\t\t\t%d <--- Rear\n", rear->data);
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
