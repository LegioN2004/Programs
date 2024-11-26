#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 200

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL; // Points to the start of the list

int display()
{
    Node *temp = head;
    int count = 0;
    printf("The list is: ");
    while (temp != NULL)
    {
        count++;
        printf("%d (%d)", temp->data, count);
        temp = temp->next;
    }
    printf("\n");
    return count;
}

void insert_beginning()
{
    Node *newData = (Node *)malloc(sizeof(Node));
    printf("Enter the data to insert at the beginning: ");
    scanf("%d", &newData->data);
    newData->next = head;
    head = newData;
    display();
}

void insert_end()
{
    Node *newData = (Node *)malloc(sizeof(Node));
    printf("Enter the data to insert at the beginning: ");
    scanf("%d", &newData->data);
    // sets the last node to NULL
    newData->next = NULL;
    // checks if the list is empty
    if (head == NULL)
    {
        // if the list is empty, the new node is the head
        head = newData;
    }
    else
    {
        // if the list is not empty,
        Node *temp = head; // a new temp ptr var is created
        // to iterate till the end
        while (temp->next != NULL)
        {
            // goes till the end
            temp = temp->next;
        }
        // and then adds the new node to the end
        temp->next = newData;
    }
    display();
}

void insert_position()
{
    int pos;
    printf("Enter the position to insert a new node: ");
    scanf("%d", &pos);

    Node *newData = (Node *)malloc(sizeof(Node));
    printf("Enter data for the new node: ");
    scanf("%d", &newData->data);

    if (pos == 1)
    {
        newData->next = head;
        head = newData;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Invalid position!\n");
            free(newData);
            return;
        }
        newData->next = temp->next;
        temp->next = newData;
    }
    display();
}

void delete_beginning()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    display();
}

void delete_end()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    Node *temp = head, *prev = NULL;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    display();
}

void delete_position()
{
    int pos;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    Node *temp = head;
    if (pos == 1)
    {
        head = head->next;
        free(temp);
    }
    else
    {
        Node *prev = NULL;
        // to go till the position of the node to be deleted
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("invalid position\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
    display();
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            insert_beginning();
            break;
        }
        case 2:
        {
            insert_end();
            break;
        }
        case 3:
        {
            insert_position();
            break;
        }
        case 4:
        {
            delete_beginning();
            break;
        }
        case 5:
        {
            delete_end();
            break;
        }
        case 6:
        {
            delete_position();
            break;
        }
        case 7:
        {
            exit(0);
            break;
        }
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
