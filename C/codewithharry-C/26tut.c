#include <stdio.h>

int main()
{
    int a = 7;
    int *ptr = &a;
    int *ptr1 = NULL;
    printf("The address of pointer to a is %p\n", &ptr);
    printf("The value of a is %d\n", *ptr);
    printf("The value of a is %d\n", a);
    printf("The value of ptr is %p\n", ptr1);
    printf("The value of ptr is %p\n", *ptr1);
    // printf("The memory address of a is %d\n", &a);
    // printf("The pointer of a is %d\n", *ptr);
    // printf("The pointer of ptr is %d\n", &ptr1);
    return 0;
}