%{
#include<stdio.h>
%}

%%

[\t ]+ ;
([0-9]+\.[0-9]+)|([0-9]+\.)|(\.[0-9]+) { printf("floating point numbers: %s\n", yytext); }
\n ;
. { printf("unknown characters: %s\n", yytext); }

%%

int yywrap() { return 1; }

int main() {
    printf("enter your input: ");
    yylex();
    return 1;
}
