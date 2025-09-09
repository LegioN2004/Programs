#include <stdio.h>

int main() {
    char str[200];
    printf("Enter string that has a and b only: ");
    scanf("%s", str);
    int a = 0, b = 0, i = 0;
    char c;
    while ((c = str[i++]) != '\0') {
        if (c == 'a') a++;
        else if (c == 'b') b++;
    }
    if (a == 2 && b == 3) {
        printf("Accepted: Exactly two a's and three b's.\n");
    } else {
        printf("Rejected.\n");
    }
    return 0;
}
