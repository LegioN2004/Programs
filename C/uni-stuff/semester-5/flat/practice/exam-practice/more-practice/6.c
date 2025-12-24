// string contains either 01 or 10

#include <stdio.h>

int main(void) {
    char s[200];
    printf("Enter a binary string: ");
    if (scanf("%199s", s) != 1) return 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '0' && s[i] != '1') {
            printf("Rejected (invalid character '%c')\n", s[i]);
            return 0;
        }
        if (s[i+1] == '\0') break;
        if ((s[i] == '0' && s[i+1] == '1') || (s[i] == '1' && s[i+1] == '0')) {
            printf("Accepted\n");
            return 0;
        }
    }

    printf("Rejected\n");
    return 0;
}