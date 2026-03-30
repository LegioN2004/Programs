%{
#include <stdio.h>
%}

%%

[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?   { printf("Scientific notation: %s\n", yytext); }
[0-9]+\.[0-9]+                      { printf("Float: %s\n", yytext); }
[0-9]+                              { printf("Integer: %s\n", yytext); }

[a-zA-Z0-9]*[0-9][a-zA-Z][a-zA-Z0-9]*  { printf("Alphanumeric: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*[0-9][a-zA-Z0-9]*  { printf("Alphanumeric: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*             { printf("Identifier: %s\n", yytext); }

[\t\n ]+                            ;
.                                   { printf("Unknown: %s\n", yytext); }

%%

int main() {
    yyin = fopen("input.txt", "r");
    if (!yyin) {
        printf("Error: cannot open input.txt\n");
        return 1;
    }
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap() { return 1; }
