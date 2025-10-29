#include <stdio.h>

int main()
{
    char str[100], f = 'A'; // f is initial state
    int i = 0;
    printf("enter any string containing 0 and 1: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (f)
        {
        case 'A':
        {
            if (str[i] == '0')
                f = 'B';
            else if (str[i] == '1')
                f = 'A';
            break;
        }
        case 'B':
        {
            if (str[i] == '0')
                f = 'C';
            else if (str[i] == '1')
                f = 'A';
            break;
        }
        case 'C':
        {
            if (str[i] == '0')
                f = 'C';
            else if (str[i] == '1')
                f = 'A';
            break;
        }
        default:
            break;
        }
    }
    if (f == 'C')
        printf("String ACCEPTED by NFA %c\n", f);
    else
        printf("String REJECTED by NFA %c\n", f);

    return 0;
}
