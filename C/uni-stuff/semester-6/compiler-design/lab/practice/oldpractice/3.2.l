%{
#include<stdio.h>
%}

%%

[0-9]+ { printf("digits: %s\n", yytext); }
.|\n { printf("else: %s\n", yytext); }

%%

int yywrap(){ return 1; }

int main() {
    printf("Enter input: ");
    yylex();
    return 0;
}

