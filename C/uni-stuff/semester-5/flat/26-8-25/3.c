#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    if (len < 2) {
        printf("wrong string length\n");
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            printf("wrong string\n");
            return 0;
        }
    }

    if ((str[0] == 'a' && str[1] == 'a') || (str[0] == 'b' && str[1] == 'b')) {
        printf("correct string\n");
    } else {
        printf("incorrect\n");
    }
    return 0;
}