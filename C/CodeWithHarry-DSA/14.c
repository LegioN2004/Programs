#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// function to traverse the linked list
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // allocate memory for nodes in the linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // link first and second nodes
    head->data = 1;
    head->next = second;

    // second and third nodes
    second->data = 2;
    second->next = third;

    // third and fourth nodes
    third->data = 3;
    third->next = fourth;

    // third node
    fourth->data = 4;
    fourth->next = NULL;

    linkedListTraversal(head);
    return 0;
}