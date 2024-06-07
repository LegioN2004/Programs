// program to print reverse of a four digit number using for loop
#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    for (int i = 0; i < 4; i++)
    {
        int b = a % 10;
        printf("%d", b);
        a = a / 10;
    }
    return 0;
}
