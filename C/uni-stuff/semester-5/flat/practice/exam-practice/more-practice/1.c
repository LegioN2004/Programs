#include <stdio.h>

int main()
{
    char str[100];
    int state = 0;

    printf("Enter the string ending with the same symbol, in {a, b}: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {

        if (str[i] != 'a' && str[i] != 'b')
        {
            printf("\n\nInvalid character '%c' in input", str[i]);
            return -1;
        }

        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 1;
            else
                state = 4;
            break;

        case 1:
            if (str[i] == 'a')
                state = 1;
            else
                state = 2;
            break;

        case 2:
            if (str[i] == 'b')
                state = 2;
            else
                state = 1;
            break;

        case 3:
            if (str[i] == 'b')
                state = 3;
            else
                state = 4;
            break;

        case 4:
            if (str[i] == 'a')
                state = 4;
            else
                state = 3;
            break;

        default:
            break;
        }
    }

    if(state == 1 || state == 3)
        printf("\n\nThe string is correct");
    else
        printf("\nThe string is wrong");

}