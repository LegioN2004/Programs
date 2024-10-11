#include <stdio.h>
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    // int *ptra = a // this syntax is correct because the name of the array is a pointer to the first element of the array, similar to &a[0]
    int *ptra = &a[2]; // this is the normal way to access the other elements
    printf("%d \n", a);
    printf("%d \n", ptra);
    printf("%d \n", *ptra);
    printf("%d \n", &a);
    return 0;
}
