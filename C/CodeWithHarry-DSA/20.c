#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void printLL(Node *head)
{
    Node *ptr = head;
    // following two lines till the loop is to make the loop run atleast once so that the ptr doesn't stay stuck to head which is the starting point and the condition at the same time
    // and for doing that in a better way we have the do-while loop
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

Node *insertHeadFirst(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node *));
    ptr->data = data;
    Node *p = head->next;
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    printLL(head);
    printf("\n");

    head = insertHeadFirst(head, 69);

    printLL(head);

    return 0;
}