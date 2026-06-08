%{
#include <stdio.h>
int vowel = 0;
int conso = 0;
%}

%% 
[aeiouAEIOU] { vowel++; /* plus korim jodi vowel ahe, top to bottom karne kaam koribo */ }

[a-zA-Z] { conso++; }

\n { return 0;}

. { /* nologa bostu ignore, excluding uporor bostu */ }
%%

int yywrap() { return 1; }

int main() {
    printf("Enter a string: ");
    yylex();
    printf("Vowels: %d, consonants: %d", vowel, conso);
    return 0;
}
