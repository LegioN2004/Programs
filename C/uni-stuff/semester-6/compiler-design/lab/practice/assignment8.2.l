%{
#include <stdio.h>
int prev;
int first = 1;
FILE *out;
%}

%%

[0-9]+ {
    int num = atoi(yytext);
    
    if(first){
        prev = num;
        first = 0;
    } else {
        fprintf(out, "sum: %d, difference: %d\n", prev + num, prev - num);
        prev = num;
    }
}

.|\n ;
%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("input.txt", "r");
    out  = fopen("output.txt", "w");

    if (!yyin) { printf("Cannot open input.c\n");  return 1; }
    if (!out)  { printf("Cannot open output.c\n"); return 1; }

    yylex();

    fclose(yyin);
    fclose(out);

    return 0;
}
