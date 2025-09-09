#include <stdio.h>

int main() {
    char str[20];
    printf("Enter string that has 0 and 1 only: ");
    scanf("%s", str);
    int state = 0, i = 0;
    char c;
    while ((c = str[i++]) != '\0') {
        switch (state) {
            case 0:
                if (c == '1')
                    state = 1;
                else
                    state = 0;
                break;
            case 1:
                if (c == '1')
                    state = 2;
                else
                    state = 1;
                break;
            case 2:
                if (c == '1')
                    state = 3;
                else
                    state = 2;
                break;
            case 3:
                if (c == '1')
                    state = 4;
                else
                    state = 3;
                break;
            case 4:
                if (c == '1')
                    state = 5;
                else
                    state = 4;
                break;
            case 5:
                state = 5;
                break;
        }
    }
    if (state == 4) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }
    return 0;
}
