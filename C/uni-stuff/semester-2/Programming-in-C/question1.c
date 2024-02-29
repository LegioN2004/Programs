// write a simple program in c to calculate simple interest by taking user input

#include <stdio.h>

int main()
{
    float i, p, r, t;
    printf("Enter the principal amount ");
    scanf("%d", &p);
    printf("Enter the time period ");
    scanf("%d", &t);
    printf("Enter the interest rate ");
    scanf("%d", &i);
    i = (p * r * t) / 100;
    printf("The final amount is %d", i);
    return 0;
}
