// starts with aa or bb

#include <stdio.h>

int main()
{

    char str[100];
    int state = 0;

    printf("Enter the string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {

        if (str[i] != 'a' && str[i] != 'b')
            printf("incorrect character '%c' in string", str[i]);
        // break;

        switch (state)
        {
        case 0:
            if (str[i] == 'a')
                state = 1;
            else
                state = 3;
            break;

        case 1:
            if (str[i] == 'a')
                state = 2;
            else
                state = 5; // dead state
            break;

        case 2:
            if (str[i] == 'a')
                state = 2;
            else
                state = 2;
            break;

        case 3:
            if (str[i] == 'b')
                state = 4;
            else
                state = 5;
            break;

        case 4:
            if (str[i] == 'a')
                state = 4;
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

    if(state == 2 || state == 4)
        printf("String is correct");
    else
        printf("String is wrong");

    return 0;
}