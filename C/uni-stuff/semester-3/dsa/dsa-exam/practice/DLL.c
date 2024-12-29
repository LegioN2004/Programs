#include <stdio.h>
#include <stdlib.h>

typedef struct node {
		int data;
		struct node * prev;
		struct node * next;
} Node;

Node *head = NULL;

void displayList(){
		if(head->next == NULL){
				printf("The list is empty \n");
				return;
		}
		Node *temp = head;
		int count = 0;
		printf("The list is: ");
		while (temp != NULL) {
				count++;
				printf("%d (%d)", temp->data, count);
				temp = temp -> next;
		}
		printf("\n");
}

void insertAtBeginning(){
		Node *newnode = (Node *)malloc(sizeof(Node));
		printf("enter the data to add at the beginning: ");
		scanf("%d", &newnode-> data);
		newnode->prev = NULL;
		newnode-> next = head;
		if(head != NULL){
				head -> prev = newnode; 
		}
		head = newnode;
		displayList();
}

void insertAtEnd(){
		Node *newnode = (Node *)malloc(sizeof(Node));
		printf("enter the data to add at the end: ");
		scanf("%d", &newnode-> data);
		if(head -> next == NULL){
				head = newnode;
		} else {
				Node *temp = head;
				while (temp-> next != NULL) {
						temp = temp -> next;
				}
				newnode -> next = NULL;
				newnode -> prev = temp;
		}
}

void insertAtPosition(){
		int pos = 0;
		printf("Enter the position: ");
		scanf("%d", &pos);

		Node *newnode = (Node *)malloc(sizeof(Node));
		printf("enter the value you want to add: ");
		scanf("%d", &newnode -> data);

		Node *temp = head, *prev = NULL;
		if(pos == 1){
				newnode-> prev = NULL;
				newnode-> next = head;
				if(head != NULL){
						head -> prev = newnode;
				}
				head = newnode;
		} else {
				for (int i = 1; i < pos - 1 && temp != NULL; i++) {
						temp = temp -> next;
				}
				if(temp == NULL){
						printf("Invalid position");
						free(newnode);
						return;
				}
				prev -> next = newnode;
				newnode -> prev = prev;
				newnode -> next = temp;
				temp -> prev = newnode;
		}
}

int main() {
		int choice;
		while (1) {
				printf(
						"\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
				printf(
						"4. Delete from beginning\n5. Delete from end\n6. Delete from "
						"position\n7. Exit\n");
				printf("Enter your choice: ");
				scanf("%d", &choice);

				switch (choice) {
						case 1:
								insertAtBeginning();
								break;
						case 2:
								insertAtEnd();
								break;
						case 3:
								insertAtPosition();
								break;
						/* case 4: */
						/* 		deleteFromBeginning(); */
						/* 		break; */
						/* case 5: */
						/* 		deleteFromEnd(); */
						/* 		break; */
						/* case 6: */
						/* 		deleteFromPosition(); */
						/* 		break; */
						case 7:
								exit(0);
						default:
								printf("Invalid choice! Try again.\n");
				}
		}
		return 0;
}
