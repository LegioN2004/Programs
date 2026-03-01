%{
#include <stdio.h>
int count = 0;
%}

%% 
[A-Z] { 
    printf("capital found: %s\n", yytext); 
    count++;
    }
[a-z] ;
\n { return 0;}
. ;
%%

int yywrap() { return 1; }

int main() {
    printf("Enter a string: ");
    yylex();
    printf("Total capital letters: %d", count);
    return 0;
}
