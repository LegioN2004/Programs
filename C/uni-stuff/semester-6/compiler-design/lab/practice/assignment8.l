%{
#include <stdio.h>
FILE *out;
%}

%%

"//"[^\n]*          {}

"/*"([^*]|\*+[^*/])*\*+"/"  { }

\n                  { fprintf(out, "\n"); }

\r                  { }

.                   { fprintf(out, "%s", yytext); }

%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("input.c", "r");
    out  = fopen("output.c", "w");

    if (!yyin) { printf("Cannot open input.c\n");  return 1; }
    if (!out)  { printf("Cannot open output.c\n"); return 1; }

    yylex();

    fclose(yyin);
    fclose(out);

    return 0;
}
