#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0; // start state: q0

    printf("Enter a binary string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (ch != '0' && ch != '1') {
            printf("Invalid input: only 0 or 1 allowed.\n");
            return 0;
        }

        switch (state) { // 1001
            case 0: // q0
                if (ch == '0') state = 1; // q1
                else state = 0;           // q0
                break;

            case 1: // q1
                if (ch == '0') state = 1; // stay in q1
                else state = 2;           // q2
                break;

            case 2: // q2
                if (ch == '0') state = 1; // q1
                else state = 0;           // q0
                break;
        }
    }

    if (state == 2) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
