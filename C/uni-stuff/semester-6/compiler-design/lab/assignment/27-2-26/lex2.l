%{

#include<stdio.h>

%}

%%

[0-9]+ { printf("is Integer: %s\n", yytext ); }
[a-zA-Z]+ { printf("is Word: %s\n", yytext); }
\n ;
[ \t] ;
. ;

%%

int yywrap() {return 1;}

int main() {
    printf("Enter somethig: ");
    yylex();
    return 0;
}
