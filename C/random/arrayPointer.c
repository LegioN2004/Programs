#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("The value of arr[5] is %d\n", *(arr + 4));
    for (int i = 0; i < 5; i++)
    {
        printf("The value of arr[5] is %d\n", *(arr + i));
    }
    return 0;
}