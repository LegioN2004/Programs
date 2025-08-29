#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    if (len == 0) {
        printf("wrong length of string\n");
        return 0;
    }

    // Check if all characters are 'a' or 'b'
    for (int i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            printf("wrong string\n");
            return 0;
        }
    }

    if (str[0] == str[len - 1]) {
        printf("correct string\n");
    } else {
        printf("wrong string\n");
    }
    return 0;
}