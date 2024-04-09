// find the mulplication table of n

#include <stdio.h>
int main()
{
    int n, i, c = 1, d = 0;
    printf("Enter the value of which the multiplication table is to be calculated: ");
    scanf("%d", &i);
    printf("Enter the no of times multiplication is to be done: ");
    scanf("%d", &n);

    while (c <= n)
    {
        d = n * c;
        c++;
        printf("%d\n",d);
    }

    return 0;
}