%{
#include <stdio.h>

FILE *out;
%}

%%
"//".*                         ;

"/*"([^*]|\*+[^*/])*\*+"/"     ;

.|\n                           { fputc(yytext[0], out); }

%%

int main() {
    yyin = fopen("input.c", "r");
    out = fopen("output.c", "w");

    if (!yyin || !out) {
        printf("File error\n");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(out);
    return 0;
}

int yywrap() {
    return 1;
}
