// NOTE: Video is half done, complete it later on

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1; // here -1 i.e the equality check is going on an index
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1; // size - 1 because it'll have n - 1 index, i.e last index value
    else
        return 0;
}

int Push(struct stack *s)
// also push doesn't need to return anything
{
    int n = 0;
    printf("\nEnter the no of elements of the array");
    scanf("%d\n", &n);
    printf("\nEnter the values of the array");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(s->arr[(s->top)++]));
    }

    printf("\narray of the stack before the change\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d (%d)\n", s->arr[i], i);
    }
}

int Pop(struct stack *s)
// firstly to implement pop you don't need any value to pop, instead you gotta return a value
{
    int n = 5;
    printf("Enter the value you want to pop from the list below: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d (%d)\n", s->arr[i], i);
        if (s->arr[(s->top)++] == 5)
         {
         free( 
         }

    }

}

int main()
{
    struct stack *s; // when we convert this to a struct pointer, we should give the -> syntax to give the values since it can't be accessed with '.' .
    s->size = 8;
    s->top = 0;                                    // stack is empty and so no pop operation possible so first check if the stack is full or not
    s->arr = (int *)malloc(s->size * sizeof(int)); // size of int because integer is being stored

    // pushing value manually
    // s -> arr[0] = 4;
    // s -> top++;
    // also note that the indices of the array of the stack will always remain positive

    // Check if the stack is empty
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    else if (isEmpty(s))
    {
        printf("Stack undeflow\n");
    }
    else
{
        printf("stack is not empty\n");
        Push(s);
    }
    return 0;
}
