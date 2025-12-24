#include <stdio.h>

int main(void) {
    char str[100];
    printf("Enter a binary string: ");
    if (scanf("%99s", str) != 1) return 0;

    int len = 0;
    while (str[len] != '\0') len++;

    if (len < 2) {
        printf("Rejected\n");
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            printf("Rejected (invalid character '%c')\n", str[i]);
            return 0;
        }
    }

    if (str[len-2] == '0' && str[len-1] == '1')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}