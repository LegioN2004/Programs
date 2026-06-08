%{
 #include<stdio.h>
%}

/* put float before lex since it chooses the longer number first and generally float are longest in length, eg: 3.14 > 3 */

%%

[\t ] ;
([0-9]+\.[0-9]+)|(\.[0-9]+)|([0-9]+\.) { printf("float: %s\n", yytext); }
[0-9]+ { printf("int: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("identifier: %s\n", yytext); }
\n { return 0; }
. { printf("unknown: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}


int main() {
    printf("Enter input: ");
    yylex();
    return 0;
}

