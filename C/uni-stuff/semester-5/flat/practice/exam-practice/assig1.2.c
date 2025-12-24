#include <stdio.h>

int main()
{
    char str[100];
    int state = 0;

    printf("Enter the string that ends with 01: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (ch != '0' && ch != '1')
        {
            printf("Invalid input: only 0 or 1 allowed.\n");
            return 0;
        }
        switch (state)
        {
        case 0:
            if (ch == '0')
                state = 1;
            else
                state = 0;
            break;

        case 1:
            if (ch == '0')
                state = 1;
            else
                state = 2;
            break;

        case 2:
            if (ch == '0')
                state = 1;
            else
                state = 0;
            break;

        default:
            break;
        }
    }

    if (state == 2)
    {
        printf("the string is accepted");
    }
    else
    {
        printf("the string is rejected");
    }
}
