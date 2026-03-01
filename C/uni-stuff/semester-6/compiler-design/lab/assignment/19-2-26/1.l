%{
#include <stdio.h>
%}

%%

[\t ]+                   ; /* Ignore whitespace */

[0-9]+                   { printf("INTEGER: %s\n", yytext); }

(?i:am|is|are|was|were|be|being|been|do|does|did|have|has|had|go|eat|run|write) { 
                           printf("VERB: %s\n", yytext); 
                         }

(?i:[aeiou])             { printf("VOWEL: %s\n", yytext); }

[a-zA-Z]+                { printf("WORD (Not a specific verb/vowel): %s\n", yytext); }

\n                       { return 0; /* End of input on newline */ }

.                        { printf("UNKNOWN: %s\n", yytext); }

%%

int yywrap() { return 1; }

int main() {
    printf("Enter text to analyze:\n");
    yylex();
    return 0;
}
