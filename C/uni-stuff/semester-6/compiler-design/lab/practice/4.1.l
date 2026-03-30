%{
#include<stdio.h>
%}

%%

[0-9] { printf("integer: %s\n", yytext); }
[0-9]+\.[0-9]+|\.[0-9]+|[0-9]+\. { printf("float constant: %s\n", yytext); }
\n { return 0; }
[\t ] ;
. { printf("identifier %s\n", yytext); }

%%

// ([0-9]+\.[0-9]+)|(\.[0-9]+)(|[0-9]+\.)+ { printf("float constant: %s", yytext)}
// [0-9]+\.[0-9]+|[0-9]+\.|\.[0-9]+ { printf("floating point numbers: %s\n", yytext); }

int yywrap(){ return 1; }

int main() {
    printf("Enter input: ");
    yylex();
    return 0;
}

