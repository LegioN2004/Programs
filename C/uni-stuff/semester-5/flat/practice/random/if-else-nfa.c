#include <stdio.h>
#include <string.h>

int tranFun(char in, int state)
{
    if (in == '0' && state == 0)
    {
        return 0;
    }
    else if (in == '1' && state == 0)
    {
        return 2;
    }
    else if (in == '0' && state == 1)
    {
        return 3;
    }
    else if (in == '1' && state == 1)
    {
        return 0;
    }
    else if (in == '0' && state == 2)
    {
        return 1;
    }
    else if (in == '1' && state == 2)
    {
        return 3;
    }
    else if (in == '0' && state == 3)
    {
        return 4;
    }
    else if (in == '1' && state == 3)
    {
        return 1;
    }
    else if (in == '0' && state == 4)
    {
        return 2;
    }
    else if (in == '1' && state == 4)
    {
        return 4;
    }
    else
        return 0;
}
int main()
{
    char in[100], temp[100];
    printf("enter input");
    scanf("%c", &in);
    int state = 0;
    for (int i = 0; i < strlen(in); i++)
    {
        state = tranFun(in[i], state);
        printf("%d", state); /*for which state it worked for that this print staement krishna writtes*/
    }
    int len = strlen(in);
    if (state == 0)
        printf("accepted");
    else
        printf("rejected");
}