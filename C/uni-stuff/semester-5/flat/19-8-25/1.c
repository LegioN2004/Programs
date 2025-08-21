#include <stdio.h>

int main() {
    char str[100];
    int state = 0; // Dfa states start hobo

    printf("Enter a string: ");
    scanf("%99s", str);

    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = str[i];

        if (ch != 'a' && ch != 'b') {
            printf("\nOnly a and b allowed.\n");
            return 0;
        }

        switch (state) {
            case 0: state = (ch == 'a') ? 1 : 0; break;
            case 1: state = (ch == 'a') ? 1 : 2; break;
            case 2: state = (ch == 'a') ? 3 : 0; break;
            case 3: state = 3; break; // stays here
        }
    }

    if (state == 3)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");
    return 0;
}

