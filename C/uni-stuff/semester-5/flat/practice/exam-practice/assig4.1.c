#include <stdio.h>
int main()
{
    char str[100];
    int state = 0;

    printf("Enter a string that contains four 1's over {0,1}: ");
    if (scanf("%99s", str) != 1)
        return 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '0' && str[i] != '1')
        {
            printf("Invalid character '%c' in input\n", str[i]);
            return -1;
        }

        switch (state)
        {
        case 0:
            if (str[i] == '1')
                state = 1;
            else
                state = 0;
            break;
        case 1:
            if (str[i] == '1')
                state = 2;
            else
                state = 1;
            break;
        case 2:
            if (str[i] == '1')
                state = 3;
            else
                state = 2;
            break;
        case 3:
            if (str[i] == '1')
                state = 4;
            else
                state = 3;
            break;
        case 4:
            if (str[i] == '1')
                state = 5;
            else
                state = 4;
            break;
        case 5:
            state = 5;
            break;
        default:
            break;
        }
    }

    if (state == 4)
        printf("\n'%s' string is accepted", str);
    else
        printf("\n'%s' string is rejected", str);

    return 0;
}