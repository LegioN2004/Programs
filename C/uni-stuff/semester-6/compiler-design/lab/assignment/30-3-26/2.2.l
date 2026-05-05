%{
#include <stdio.h>
FILE *out;
int comments = 0;
%}

%%

//.*                { comments++; }   // single-line comment

"/*"([^*]|\*+[^*/])*\*+"/"   { comments++; }   // multi-line comment

\"([^\\\"]|\\.)*\"    { fprintf(out, "%s", yytext); }   // string literal

\'([^\\\']|\\.)\'     { fprintf(out, "%s", yytext); }   // char literal

.|\n                  { fprintf(out, "%s", yytext); }

%%

int main() {
    yyin = fopen("input.c", "r");
    out = fopen("output.c", "w");

    yylex();

    printf("Comments removed: %d\n", comments);

    return 0;
}

int yywrap(){ return 1; }
