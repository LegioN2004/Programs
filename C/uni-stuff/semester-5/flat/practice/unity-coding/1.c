#include <stdio.h>
#include <string.h>

int dfa = 0;

void A(char c)
{
    if (c == '0')
    {
        dfa = 1;
    }
    else if (c == '1')
    {
        dfa = 2;
    }
    else
    {
        dfa = -1;
    }
}

void B(char c)
{
    if (c == '0')
    {
        dfa = 0;
    }
    else if (c == '1')
    {
        dfa = 2;
    }
    else
    {
        dfa = -1;
    }
}

void C(char c)
{
    if (c == '0')
    {
        dfa = 2;
    }
    else if (c == '1')
    {
        dfa = 2;
    }
    else
    {
        dfa = -1;
    }
}

int isAccepted(char str[])
{
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (dfa == 0)
            A(str[i]);
        if (dfa == 1)
            B(str[i]);
        if (dfa == 2)
            C(str[i]);
        else
            return 0;
    }
}

int main()
{
    return 0;
}