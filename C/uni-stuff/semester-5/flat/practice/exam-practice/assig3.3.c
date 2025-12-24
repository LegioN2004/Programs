#include <stdio.h>
int main()
{
    char str[100];
    int state = 0;

    printf("enter input for a string starting with 'aa' or 'bb': ");
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
            if (str[i] == 'a')
                state = 2;
            else if (str[i] == 'b')
                state = 5;
            break;

        case 2:
            if (str[i] == 'a')
                state = 2;
            else if (str[i] == 'b')
                state = 2;
            break;

        case 3:
            if (str[i] == 'b')
                state = 4;
            else if (str[i] == 'a')
                state = 5;
            break;

        case 4:
            if (str[i] == 'b')
                state = 4;
            else if (str[i] == 'a')
                state = 4;
            break;
        case 5:
                state = 5;
            break;

        default:
            break;
        }
    }

    if (state == 2 || state == 4)
    {
        printf("%s", str);
        printf("\nstate is accepted");
    }
    else
    {
        printf("%s", str);
        printf("\nstate is rejected");
    }

    return 0;
}