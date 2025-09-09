#include <stdio.h>

int main() {
    char str[200];
    printf("Enter a string having a and b only ");
    scanf("%s", str);
    int state = 0, i = 0;
    char c;
    while ((c = str[i++]) != '\0') {
        switch (state) {
            case 0: state = (c == 'a') ? 1 : 0; break;
            case 1: state = (c == 'a') ? 2 : 0; break;
            case 2: state = (c == 'b') ? 3 : ((c == 'a') ? 2 : 0); break;
            case 3: state = (c == 'b') ? 4 : ((c == 'a') ? 2 : 0); break;
            case 4: state = 4; break; // trap state
        }
    }
    if (state != 4) {
        printf("correct\n");
    } else {
        printf("wronggg\n");
    }
    return 0;
}
