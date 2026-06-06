%{
#include <stdio.h>
FILE *out;
%}

/* putchar(yytext[0])is used to show output in terminal or printing */
/* fputc(yytext[0], out) is used to print output in a file */

%%

[\t ]+      { fputc(' ', out); }
\r          { }
[\n]+       { fputc('\n', out); }
.           { fputc(yytext[0], out); }

%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.txt", "r");
    if (!yyin) {
        printf("Error: cannot open input.txt\n");
        return 1;
    }

    out = fopen("output.txt", "w");
    if (!out) {
        printf("Error: cannot open output.txt\n");
        return 1;
    }

    yylex();
    fclose(yyin);
    fclose(out);
    return 0;
}
