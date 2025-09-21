#include<stdio.h>
#include<string.h>

void checkStateA(char n[]){
    if (n[0] == '0')
        stateB(&n[1]);
    else 
        stateD(&n[1]);
}

void stateB(char n[]){
    if (strlen(n) == 0)
        printf("string not accepted\n");
    else {
        if (n[0] == '0')
            stateC(&n[1]);
        else 
            stateD(&n[1]);
    }
}

int main()
{
    char c[100];

    printf("Enter the string: ");
    scanf("%99s", c)

    checkStateA(c);
    return 0;
}
