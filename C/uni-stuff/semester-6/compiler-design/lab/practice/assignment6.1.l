%{
#include<stdio.h>
%}

%%
[a-zA-Z0-9_]+ { printf("string: %s and it's length: %d\n", yytext, yyleng); }
[ \t\r\n] {}
. { }
%%

int yywrap() { return 1; }
int main() { 
    printf("enter input: ");
    yylex();
    return 0; }
