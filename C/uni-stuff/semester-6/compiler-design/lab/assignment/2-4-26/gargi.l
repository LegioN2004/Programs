%{
#include <stdio.h>
#include <stdlib.h>

double num1 = 0, num2 = 0, result = 0;
char   op   = 0;
int    count = 0;
%}

%%

[0-9]+(\.[0-9]+)?  {
    if (count == 0) {
        num1 = atof(yytext);
        count = 1;
    } else {
        num2 = atof(yytext);

        if      (op == '+') result = num1 + num2;
        else if (op == '-') result = num1 - num2;
        else if (op == '*') result = num1 * num2;
        else if (op == '/') {
            if (num2 == 0) {
                printf("cannot divide by zero!\n");
                num1 = 0; num2 = 0; op = 0; count = 0;
                return 0;
            }
            result = num1 / num2;
        }
        printf("Answer : %.2f\n", result);
        num1 = 0; num2 = 0; op = 0; count = 0;
    }
}

[+\-*/]  {
    op = yytext[0];
}

[ \t\n]  { /* skip whitespace */ }

.        {
    printf("Unknown input: %s\n", yytext);
}

%%

int main() {
    printf("Enter your calculation\n");
    printf("Press Ctrl+D to exit.\n\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
