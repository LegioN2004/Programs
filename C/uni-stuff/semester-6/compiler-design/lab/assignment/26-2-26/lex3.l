%{
#include<stdio.h>
int vowel = 0;
int conso = 0;
%}

%%
[aeiouAEIOU] { vowel++; } /* vowel counter tu hoi */
[a-zA-Z] { conso++; } /* conso counter tu hoi */
\n { return 0; }
[ \t] ;
. ;
%%

int main() {
    printf("Enter a string: ");
    yylex();
    printf("Vowels count: %d, consonant count: %d", vowel, conso);
    return 0;
}

int yywrap() { return 1; }

