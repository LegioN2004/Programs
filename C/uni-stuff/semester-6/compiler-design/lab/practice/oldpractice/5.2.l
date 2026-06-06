%{
#include<stdio.h>
FILE *out;
%}

%%

[ ]+ { fputc(' ', out); }
\n { fputc('\n', out); }
. { fputc(yytext[0], out); }

%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    yylex();
    fclose(yyin);
    fclose(out);
    return 0;
}
