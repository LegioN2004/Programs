#include <stdio.h>

int main() {
    char str[100];
    int i = 0;
    printf("Enter the string: ");
    scanf("%s", str);

    while (str[i] != '\0') {
        if (str[i] != 'a' && str[i] != 'b') {
            printf("incorrect character '%c' in string\n", str[i]);
            return 0;
        }
        i++;
    }

    if (i == 0) {
        printf("String is wrong\n");
        return 0;
    }

    // here i is representing the character and strings are arrays in C so we can think of individual characters as characters in array
    // like 0th index mane first char must be equal to last character i.e n-1 in array
    // so for same start and end, all we can show is first index char is equal to last index
    if (str[0] == str[i-1])
        printf("String is correct\n");
    else
        printf("String is wrong\n");

    return 0;
}