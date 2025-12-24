#include <stdio.h>

int main()
{
    char str[100];
    int state = 0;

    printf("Enter the string containing 'aba' as a substring: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 1;
            else
                state = 0;
            break;
        case 1:
            if (str[i] == 'a')
                state = 1;
            else
                state = 2;
            break;
        case 2:
            if (str[i] == 'a')
                state = 3;
            else
                state = 0;
            break;
        case 3:
            if (str[i] == 'a')
                state = 3;
            else
                state = 3;
            break;
            // default:
            //     state = 3;
        }
    }

    if (state == 3)
    {
        printf("state is accepted");
    }
    else
    {
        printf("state is rejected");
    }

    return 0;
}