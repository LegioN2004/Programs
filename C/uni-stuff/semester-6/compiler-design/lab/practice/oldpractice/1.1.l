%{
#include<stdio.h>
%}

%%

[\t ]+ ;
(?i:am|is|are|was|be|being) { printf("\nVerb: %s\n", yytext); }
(?i:[aeiou]) { printf("Vowel: %s\n", yytext); }
[a-zA-Z]+ { printf("Consonant/Word: %s\n", yytext); }
[0-9]+ { printf("Integers: %s\n", yytext); }
\n ;
. { printf("Unknown: %s", yytext); }

%%

// \n {return 0;} // stops scanning on newline
// if input is finished stop scanning
int yywrap(){ return 1; }

int main() {
    printf("Enter your text: ");
    yylex();
    return 0;
}


