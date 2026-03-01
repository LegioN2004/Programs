%{
#include <stdio.h>
%}

DIGIT    [0-9]
UP       [A-Z]
DOWN     [a-z]
FLOAT    ({DIGIT}*\.{DIGIT}+|{DIGIT}+\.{DIGIT}*)
EXP      ([eE][+-]?{DIGIT}+)


%%

{FLOAT}{EXP}?    { printf("Found a Float: %s\n", yytext); }
{DIGIT}+         { printf("Found an Integer: %s\n", yytext); }
{UP}+         { printf("Found an uppercase: %s\n", yytext); }
{DOWN}+         { printf("Found an lowercase: %s\n", yytext); }
[ \t\n]+         ;
.                { printf("Unknown character(give float or integer): %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}
