#include <stdio.h>
#include <stdlib.h>

typedef struct node {
		int data;
		struct node *next;
} Node;

Node *head = NULL;

void displayLL() {
		Node *temp = head;
		int count = 0;
		printf("The list is: ");
		while (temp != NULL) {
				count++;
				printf(" %d(%d) ", temp->data, count);
				temp = temp -> next;
		}
		printf("\n");
}

void insertBeginning() { 
		Node *newData = (Node *)malloc(sizeof(Node));
		printf("enter the newData to add at the beginning: ");
		scanf("%d", &newData->data);
		newData -> next = head;
		head = newData;
		displayLL();
}

void insertEnd() { 
		Node *newData = (Node *)malloc(sizeof(Node));
		printf("enter the newData to add at the end: ");
		scanf("%d", &newData->data);
		newData -> next = NULL;
		if(head == NULL){
				head = newData;
		}else {
				Node *temp = head -> next;
				while (head -> next != NULL) {
						temp = temp -> next;
				}
				temp -> next = newData;
		}
		displayLL();
}

void insertPosition(){
		Node *newData = (Node *)malloc(sizeof(Node));
		int position = 0;

		printf("enter the newData to add at the position: ");
		scanf("%d", &newData->data);

		printf("enter the position: ");
		scanf("%d", &position);
		if(position == 1){
				newData -> next = head;
				head = newData;
		} else {
				Node *temp = head;	
				for (int i = 1; i < position - 1 && temp != NULL; i++) {
						temp = temp -> next;
				}
				if (temp == NULL) {
						printf("Invalid position\n");
						free(newData);
						newData = NULL;
						return;
				}
				newData -> next = temp -> next;
				temp -> next = newData;	
		}
}

void deleteBeginning(){
		if (head == NULL) {
				printf("List is empty");
				return;
		} else {
				Node *temp = head;
				head = temp -> next;
				free(temp);
				temp = NULL;
				displayLL();
		}
}

void deleteEnd() {
		if (head == NULL) {
				printf("The list is empty.\n");
				return;
		}
		Node *temp = head, *prev = NULL;
		if (head->next == NULL) {
				head = NULL;
		} else {
				while (temp->next != NULL) {
						prev = temp;
						temp = temp->next;
				}
				prev->next = NULL;
				free(temp);
		}
		displayLL();
}


void deletePosition(){
		int pos = 0;
		printf("Enter the position: ");
		scanf("%d", &pos);
		if(head == NULL){
				printf("list is empty");
				return;
		}
		Node *temp = head; 
		if (pos == 1) {
				head = head -> next;	
				free(temp);
				temp = NULL;
		} else {
				Node *prev = NULL;
				if (temp == NULL) {
						printf("Invalid position!\n");
						return;
				}
				for (int i = 0; i < pos - 1 && temp != NULL; i++) {
						prev = temp;	
						temp = temp -> next;
				}
				prev -> next = temp -> next;
				free(temp);
				temp = NULL;
		}
		displayLL();
}

int main() {
		int choice = 0;
		while (1) {
				printf("1. Insert new Data in the beginning\n");
				printf("2. Insert new Data in the end\n");
				printf("3. Insert new Data at any position\n");
				printf("4. Delete data from the beginning\n");
				printf("5. Delete data from the end\n");
				printf("6. Delete data from any position\n");
				printf("7. Exit\n");
				printf("\nEnter your choice: ");
				scanf("%d", &choice);
				switch (choice) {
						case 1: {
								insertBeginning();
						} break;
						case 2: {
								insertEnd();
						} break;
						case 3: {
								insertPosition();
						} break;
						case 4: {
								deleteBeginning();
						} break;
						case 5: {
								deleteEnd();
						} break;
						case 6: {
								deletePosition();
						} break;
						case 7: {
								exit(0);
								break;
						}
						default: {
								printf("Invalid choice, try again\n");
						}
				}
		}
		return EXIT_SUCCESS;
}
