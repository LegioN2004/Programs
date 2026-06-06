%{
#include<stdio.h>
int keywords = 0, identifiers = 0, digits = 0;
FILE *out;
%}

%%

(if|else|then|while|int|float) { printf("keywords: %s\n", yytext); }
[0-9]+ { printf("digits: %s\n", yytext); }

%%

int yywrap() { return 0; }

int main() {
    yyin = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    yylex();

    fclose(yyin);
    fclose(out);
    return 0;
}
