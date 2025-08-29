#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int state = 0, i = 0;
    char c = str[i];

    while ((c = str[i]) != '\0') {
        switch (state) {
            case 0:
                if (c == 'b') state = 1;
                else state = 0;
                break;
            case 1:
                if (c == 'a') state = 2;
                else if (c == 'b') state = 1;
                else state = 0;
                break;
            case 2:
                if (c == 'b') state = 3;
                else state = 0;
                break;
            case 3:
                if (c == 'b') state = 1;
                else if (c == 'a') state = 2;
                else state = 0;
                break;
        }
        i++;
    }

    if (state == 3) {
        printf("correct string.\n");
    } else {
        printf("incorrect.\n");
    }

    return 0;
}