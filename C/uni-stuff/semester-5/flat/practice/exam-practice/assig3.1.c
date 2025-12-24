#include <stdio.h>
int main(){
    char str[1000];
    int state = 0;

    printf("enter input for a string starting with 'a' and ending with 'b': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (state)
        {
        case 0:
            if( str[i] == 'a' ) state = 1;
            else state = 3;
            break;

        case 1:
            if( str[i] == 'b' ) state = 2;
            else state = 1;
            break;

        case 2:
            if( str[i] == 'a' ) state = 1;
            else state = 2;
            break;

        case 3:
            state = 3;

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