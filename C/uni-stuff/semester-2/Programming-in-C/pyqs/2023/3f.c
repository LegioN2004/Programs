#include <stdio.h>

int main()
{
    int a = 10, *b, **c;
    b = &a;
    c = &b;
    *b++;
    **c++;
    printf("A=%d\t B=%\t C=%d", a, b, c);
    return 0;
}