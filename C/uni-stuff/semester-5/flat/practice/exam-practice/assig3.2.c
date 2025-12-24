#include <stdio.h>
int main()
{
    char str[1000];
    int state = 0;

    printf("enter input for a string starting and ending with 'a' or 'b': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 1;
            else if (str[i] == 'b')
                state = 3;
            break;

        case 1:
            if (str[i] == 'b')
                state = 2;
            else if (str[i] == 'a')
                state = 1;
            break;

        case 2:
            if (str[i] == 'a')
                state = 1;
            else if (str[i] == 'b')
                state = 2;
            break;

        case 3:
            if (str[i] == 'b')
                state = 3;
            else if (str[i] == 'a')
                state = 4;
            break;

        case 4:
            if (str[i] == 'b')
                state = 3;
            else if (str[i] == 'a')
                state = 4;
            break;

        default:
            break;
        }
    }

    if (state == 1 || state == 3)
    {
        printf("state is accepted");
    }
    else
    {
        printf("state is rejected");
    }

    return 0;
}