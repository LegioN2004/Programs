#include <stdio.h>
int main(){
    char str[100];
    int state = 0;

    printf("Enter a string that ends with 'aa' or 'bb': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {

        if(str[i] != 'a' && str[i] != 'b'){
            printf("Give a proper string containing a and b");
            break;
            return -1;
        }

        switch (state)
        {
        case 0:
            if( str[i] == 'a' ) state = 1;
            else if( str[i] == 'b' ) state = 3;
            break;

        case 1:
            if( str[i] == 'a' ) state = 2;
            else if( str[i] == 'b' ) state = 3;
            break;

        case 2:
            if( str[i] == 'a' ) state = 2;
            else if( str[i] == 'b' ) state = 3;
            break;

        case 3:
            if( str[i] == 'b' ) state = 4;
            else if( str[i] == 'a' ) state = 1;
            break;

        case 4:
            if( str[i] == 'a' ) state = 1;
            else if( str[i] == 'b' ) state = 4;
            break;

        default:
            break;
        }
    }

    if( state == 2 || state == 4)
        printf("\n'%s' string is accepted", str);
    else
        printf("\n'%s' string is rejected", str);

    return 0;
}