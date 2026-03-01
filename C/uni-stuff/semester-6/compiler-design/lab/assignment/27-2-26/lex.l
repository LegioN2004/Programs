%{

#include<stdio.h>

%}

%%

[0-9]*\.[0-9]+|[0-9]+\.[0-9]* { printf("Float: %s\n", yytext ); }
[0-9]+ { printf("Integer: %s\n", yytext ); }
[a-zA-Z][a-zA-Z0-9]* { printf("Identifiers: %s\n", yytext); }
\n ;
[ \t] ;
. ;

%%

int yywrap() {return 1;}

int main() {
    yylex();
    return 0;
}
