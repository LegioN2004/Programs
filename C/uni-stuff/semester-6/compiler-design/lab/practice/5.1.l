%{
#include<stdio.h>
%}

%%

.|\n { putchar(yytext[0]); }
 

%%

int yywrap(){ return 1; }

int main() {
    yyin = fopen("input.txt", "r");
    yylex();

    fclose(yyin);
    return 0;
}

