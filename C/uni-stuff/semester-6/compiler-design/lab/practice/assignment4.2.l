%{
#include<stdio.h>
%}

%%
[ \t] ;
[a-zA-Z]+ { printf("word: %s\n", yytext); }
[0-9]+ { printf("number: %s\n", yytext); }
\n ;
. { printf("give proper input "); }
%%

int yywrap() { return 1; }

int main() { 
    printf("enter string: ");
    yylex();
    return 0;
}
