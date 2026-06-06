%{
#include<stdio.h>
int vowels = 0;
int consonant = 0;
%}

%%

[aeiouAEIOU] { vowels++; }
[a-zA-Z] { consonant++; }
\n { return 0; }
[\t ] ;
. ;

%%

int yywrap(){ return 1; }

int main() {
    printf("Enter input: ");
    yylex();
    printf("count vowels: %d\n", vowels);
    printf("count consonant: %d\n", consonant);
    return 0;
}

