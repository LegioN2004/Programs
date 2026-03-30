%{
#include<stdio.h>
int count;
%}

%%

[\t ]+ ;
[a-zA-Z]+ { count++; }
\n ;

%%


int main() {
    printf("Enter the text: ");
    yylex();
    printf("\ncount: %d", count);
    return 1;
}

int yywrap(){ return 1; }
