// 3rd symbol from the right end is a

#include<stdio.h>

int main() {
    char str[100];
    printf("Enter a binary string: ");
    if (scanf("%99s", str) != 1) return 0;

    int len = 0;
    while (str[len] != '\0') len++;

    if (len < 2) {
        printf("Rejected\n");
        return 0;
    }

    if(str[len - 3] == 'a')
        printf("the string is correct");
    else
        printf("the string is wrong");

    return 0;
}