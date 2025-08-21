// #include <stdio.h>
// #include <string.h>
//
// int main() {
//     char str[100];
//     int state = 0; // start state: q0
//
//     printf("Enter a binary string: ");
//     scanf("%s", str);
//
//     for (int i = 0; str[i] != '\0'; i++) {
//         switch (state) {
//             case 0: // q0
//                 if (str[i] == 'a') state = 1; // q1
//                 else if(str[i] == 'b') state = 0;           // q0
//                 break;
//
//             case 1: // q1
//                 if (str[i] == 'a') state = 2; // q1
//                 else if(str[i] == 'b') state = 3;           // q0
//                 break;
//
//             case 2: // q2
//                 if (str[i] == 'a') state = 2; // q1
//                 else if(str[i] == 'b') state = 3;           // q0
//                 break;
//
//             case 3: // q2
//                 if (str[i] == 'a') state = 1; // q1
//                 else if(str[i] == 'b') state = 3;           // q0
//                 break;
//         }
//     }
//
//     if (state == 3) {
//         printf("Accepted\n");
//     } else {
//         printf("Rejected\n");
//     }
//
//     return 0;
// }


#include <stdio.h>

int main() {
    char str[100];
    int state = 0; // q0: initial state

    printf("Enter a string with 'a' and 'b': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        switch (state) {
            case 0: // q0
                if (str[i] == 'a') {
                    state = 1; // q1
                } else if (str[i] == 'b') {
                    state = 0; // q0
                }
                break;

            case 1: // q1
                if (str[i] == 'a') {
                    state = 2; // q2 (accepting state)
                } else if (str[i] == 'b') {
                    state = 0; // q0
                }
                break;

            case 2: // q2 (accepting state)
                if (str[i] == 'a') {
                    state = 2; // q2
                } else if (str[i] == 'b') {
                    state = 0; // q0
                }
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
