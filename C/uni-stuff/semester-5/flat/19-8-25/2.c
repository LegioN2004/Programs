#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0; // start state q0

    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (ch != '0' && ch != '1') {
            printf("Only 0 and 1\n");
            return 0;
        }

        switch (state) {
            case 0:
                if (ch == '1') state = 1;
                else state = 0;
                break;
            case 1:
                if (ch == '0') state = 2;
                else state = 1;
                break;
            case 2:
                if (ch == '1') state = 1;
                else state = 0;
                break;
        }
    }

    if (state == 2)
        printf("\nAccepted\n");
    else
        printf("Rejected\n");

    return 0;
}
