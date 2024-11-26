#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void displayList()
{
    int no = 1;
    if (head == NULL)
    {
        printf("the list is empty \n");
        return;
    }
    Node *temp = head;
    printf("The Circular linked list is: ");
    do
    {
        printf("%d(%d) ", temp->data, no++);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertAtBeginning()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the value: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // the node points to itself
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next; // go till the last node
        }
        newNode->next = head; // newNode points to the current head
        head = newNode;       // update head to the new node
        temp->next = head;    // update the last node to point to the new node
    }
    displayList();
}

void insertAtEnd()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the value: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // the node points to itself
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next; // go till the last node
        }
        temp->next = newNode; // the temp points to the newNode
        newNode->next = head; // update head to the new node
    }
    displayList();
}

void insertAtPosition()
{
    int pos, i = 1;
    printf("Enter the position you want to enter the value at: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertAtBeginning();
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    Node *temp = head;
    while (i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }

    if (i < pos - 1)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    displayList();
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("the list is empty. \n");
        return;
    }

    Node *temp = head, *last = head;
    if (head->next == head)
    {
        printf("Only one node");
        head = NULL;
    }
    else
    {
        while (last->next != head) // until it reaches head traverse till then
        {
            // traverse till the last node
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    free(temp);
    displayList();
}
void deleteAtPosition()
{
    int pos = 0, i = 1;
    printf("Enter the position you want to delete from: ");
    scanf("%d", pos);

    if (head == NULL)
    {
        printf("The list is empty. \n");
    }

    Node *temp = head, *prev = NULL;

    if (pos == 1)
    {
        deleteFromBeginning();
        return;
    }
    while (i < pos && temp->next != head)
    {
        prev = temp;
        temp = temp->next; // reaches the last node
        i++;
    }

    if (i < pos)
    {
        printf("Invalid position");
        return;
    }

    prev->next = temp->next; // join the prev node to the one after the to be deleted node
    free(temp);
    displayList();
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("The list is empty");
        return;
    }

    Node *temp = head, *last = head;
    if (head->next == head)
    {
        printf("There is only one node");
    }
    else
    {
        while (temp->next != head)
        {
            last = temp;
            temp = temp->next;
        }
        // last->next = temp->next;
        last->next = head;
    }
    free(temp);
    displayList();
}

int main()
{
    int choice = 1;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            displayList();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}