%{
#include <stdio.h>
#include <stdlib.h>

FILE *out;

int prev;
int first = 1;
%}

%%
[0-9]+ {
    int num = atoi(yytext);

    if (first) {
        prev = num;
        first = 0;
    } else {
        fprintf(out, "Sum: %d, Diff: %d\n", prev + num, prev - num);
        prev = num;
    }
}

.|\n   ;

%%

int main() {
    yyin = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    if (!yyin || !out) {
        printf("File error\n");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(out);
    return 0;
}

int yywrap() {
    return 1;
}
