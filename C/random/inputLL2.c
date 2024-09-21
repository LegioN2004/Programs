#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createLL(int n);
void displayLL(Node *head);

int main()
{
    int n = 0;
    Node *HEAD = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    HEAD = createLL(n);
    displayLL(HEAD);
    return 0;
}

Node *createLL(int n)
{
    int i = 0;
    Node *head = NULL;
    Node *temp = NULL;
    Node *p = NULL;

    // iterate n no of times for creating a LL of n nodes
    for (int i = 0; i < n; i++)
    {
        // for creating a individual isolated node
        temp = (Node *)malloc(sizeof(Node));
        printf("Enter the data: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        // if list is empty then make temp as first node
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    return head;
}

void displayLL(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        printf("Element: %d\n", p->data);
        p = p->next;
    }
}