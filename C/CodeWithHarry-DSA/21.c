/*

In a double linked list, everything is the same like the circular and singly ones but the only thing that's different is the way double linked list nodes are written. It has two links i.e pointers(struct node type), 'prev' and 'next' instead of one. The prev of the head node points to NULL to show the starting and the next node of the tail node points to NULL as well for indicating the end.

In a double linked list, if we point a pointer to some node, we can go back and we can go previous as well, unlike other linked lists.

NOTE: That the pointer points the whole node and not the data or the pointer in the node. So the head 
*/

#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

int main()
{
    Node * n1 = (Node *) malloc(sizeof(Node));
    Node * n2 = (Node *) malloc(sizeof(Node));
    Node * n3 = (Node *) malloc(sizeof(Node));
    Node * n4 = (Node *) malloc(sizeof(Node));

    n1 -> prev = NULL;
    n1 -> next = n2;
    n1 -> data = 1;

    n2 -> prev = n1;
    n2 -> next = n3;
    n2 -> data = 2;

    n3 -> prev = n2;
    n3 -> next = n4;
    n3 -> data = 3;

    n4 -> prev = n3;
    n4 -> next = NULL;
    n4 -> data = 4;
    return 0;
}