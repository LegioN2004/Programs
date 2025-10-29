#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int i, j;

    int current[10], next[10];
    int currCount = 1, nextCount;

    current[0] = 0;

    printf("Enter a string (a/b): ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        char ch = input[i];
        nextCount = 0;

        for (j = 0; j < currCount; j++) {
            int state = current[j];

            if (state == 0) {
                if (ch == 'a') next[nextCount++] = 1;
                if (ch == 'b') next[nextCount++] = 0;
            }
            else if (state == 1) {
                if (ch == 'a') next[nextCount++] = 1;
                if (ch == 'b') next[nextCount++] = 2;
            }
            else if (state == 2) {
                if (ch == 'a') next[nextCount++] = 1;
                if (ch == 'b') next[nextCount++] = 0;
            }
        }

        currCount = nextCount;
        for (j = 0; j < currCount; j++)
            current[j] = next[j];
    }

    int accepted = 0;
    for (i = 0; i < currCount; i++) {
        if (current[i] == 2) {
            accepted = 1;
            break;
        }
    }

    if (accepted)
        printf("\nString ACCEPTED by NFA\n");
    else
        printf("\nString REJECTED by NFA\n");

    return 0;
}