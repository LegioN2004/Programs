%{ 
#include<stdio.h>
FILE *out;
int type = 0;
int keyword = 0;
int identifier = 0;
%}

%%

int|char|double {
    type++;
    printf("type: %s", yytext);
    fputc(out, "no of type: %d", type);
}

for|while|if|do {
    keyword++;
    printf("keyword: %s", yytext);
    fputc(out, "no of keyword: %d", type);
}

[a-zA-Z][a-zA-Z0-9_]+ {
    identifier++;
    printf("identifier: %s", yytext);
    fputc(out, "no of identifier: %d", identifier);
}

[+\-\*/=!&|] {
    printf("operator: %s", yytext);
    printf("operator: %s", yytext);
}

[ \t\r] {

}

. ;
%%

int yywrap() {return 1;}

int main() {
    printf("enter: \n");
    yyin = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    yylex();

    fclose(yyin);
    fclose(out);
    return 0;
}
