%{
#include<stdio.h>
int count;
%}

%%

[a-zA-Z]+ { count++; }
\n {return 0;}
[\t ]+ ;
. ;

%%

int yywrap(){ return 1; }

int main() {
    printf("Enter the text: ");
    yylex();
    printf("\ncount: %d", count);
    return 1;
}

