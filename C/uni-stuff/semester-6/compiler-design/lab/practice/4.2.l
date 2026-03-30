%{
#include<stdio.h>
%}

%%

[a-zA-Z]+ { printf("word: %s\n", yytext); }
[0-9]+ { printf("number: %s\n", yytext); }
\n { return 0; }
[\t ] ;
. ;

%%

int yywrap(){ return 1; }

int main() {
    printf("Enter input: ");
    yylex();
    return 0;
}

