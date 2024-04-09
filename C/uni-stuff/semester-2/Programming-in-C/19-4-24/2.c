// find out palindrome

#include <stdio.h>

int main()
{
    int a, b = 0, n = 0;
    printf("Enter a number: ");
    scanf("%d", &a); // 121
    int c = a;
    while (a != 0) // 121
    {
        n = a % 10;     // 1 2 1
        b = b * 10 + n; // 1 21 121
        a = a / 10;     // 12 1 0
    }
    printf("b: %d\n", b);
    if (b == c)
    {
        printf("no is palindrome");
    }
    else
    {
        printf("number is not palindrome");
    }

    return 0;
}