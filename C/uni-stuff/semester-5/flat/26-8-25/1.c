// starts with a and ends with b
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
        printf("wrong length\n");
        return 0;
    }

    if (str[0] == 'a' && str[len - 1] == 'b') {
        for (int i = 0; i < len; i++) {
            if (str[i] != 'a' && str[i] != 'b') {
                printf("wrong string\n");
                return 0;
            }
        }
        printf("Correct string\n");
    } else {
        printf("wrong string\n");
    }
    return 0;
}