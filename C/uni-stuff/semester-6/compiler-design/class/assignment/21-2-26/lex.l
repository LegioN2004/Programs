%{
#include<stdio.h>
%}

%%

[0-9]+  { printf("Valid Match: %s\n", yytext); }
a(b|c)* { printf("Valid Match: %s\n", yytext); }
"if"*     { printf("Valid Match: %s\n", yytext); }
\/*     { printf("Valid Match: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*  { printf("All operators match: %s\n", yytext); }
[ \t\n]+   ;  /* Ignore whitespace */
.       { printf("Invalid Token\n"); }

%%

int main() {
    printf("Enter a string: ");
    yylex();
    return 0;
}
