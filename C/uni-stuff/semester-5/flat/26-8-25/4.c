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
        printf("wrong string\n");
        return 0;
    }

    // Check if all characters are 'a' or 'b'
    for (int i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            printf("wrong string\n");
            return 0;
        }
    }

    if ((str[len-2] == 'a' && str[len-1] == 'a') || (str[len-2] == 'b' && str[len-1] == 'b')) {
        printf("correct string\n");
    } else {
        printf("incorrect srting\n");
    }
    return 0;
}
