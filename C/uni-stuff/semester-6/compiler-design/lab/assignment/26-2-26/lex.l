%{
#include<stdio.h>
int count = 0;
%}

%%
[a-zA-Z]+ { count++; } /* counter tu hoi */
\n { return 0; }
[ \t] ;
. ;
%%

int main() {
    printf("Enter a string: ");
    yylex();
    printf("Count is: %d", count);
    return 0;
}

int yywrap() { return 1; }
