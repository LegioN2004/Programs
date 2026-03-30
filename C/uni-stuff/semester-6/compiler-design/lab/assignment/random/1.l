%{
#include <stdio.h>

int word_count = 0;
%}

%%
[a-zA-Z]+     { word_count++; }   // each word increases count
[\t\n ]+      ;                  // ignore spaces, tabs, newline
.             ;                  // ignore everything else
%%

int main() {
    printf("Enter sentence:\n");
    yylex();
    printf("Total words = %d\n", word_count);
    return 0;
}

int yywrap() {
    return 1;
}
