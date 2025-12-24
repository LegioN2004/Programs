#include<stdio.h>

int main() {
    char str[100];
    int state = 0;

    printf("enter input for ending with '10': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (state)
        {
        case 0:
            if( str[i] == '1' ) state = 1;
            else state = 0;
            break;

        case 1:
            if( str[i] == '0' ) state = 2;
            else state = 1;
            break;

        case 2:
            if( str[i] == '1' ) state = 1;
            else state = 0;
            break;

        default:
            break;
        }
    }

    if (state == 2)
    {
        printf("state is accepted");
    }
    else
    {
        printf("state is rejected");
    }

    return 0;
}