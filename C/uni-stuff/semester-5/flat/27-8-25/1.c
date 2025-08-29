#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);


    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    if (length > 0 && str[length - 1] == '1') {
        printf("Accepted string.\n");
    } else {
        printf("Rejected string.\n");
    }

    return 0;
}