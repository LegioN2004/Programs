// starts with 1 and ends with 0

#include <stdio.h>
int main(){

    char str[100];
    int len = 0;
    printf("Enter the string: ");
    if (scanf("%99s", str) != 1) return 0;

    while (str[len] != '\0') len++;

    if(len < 2) {
        printf("String is too small");
        return 0;
    }

    if(str[0] == '1' && str[len - 1] == '0')
        printf("accepted");
    else
        printf("not accepted");

    return 0;
}