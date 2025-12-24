#include <stdio.h>

int main()
{
    char str[100];
    int state = 0; // q0: initial state

    printf("Enter a string with '0' and '1': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (state)
        {
            // q0 state
        case 0:
            if (str[i] == '0')
            {
                state = 0; // q1
            }
            else if (str[i] == '1')
            {
                state = 0;
            }
            break;
        }
    }
    if (state == 0)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }
    return 0;
}
