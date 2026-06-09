%{
#include <stdio.h>
int identifiers = 0;
int keywords = 0;
int digits = 0;
%}

%%

int|char|long|break|return|if|else|while|for|do|switch|case|default|continue|goto {
    keywords++;
    printf("Keyword: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* { 
    identifiers++;
    printf("Identifier: %s\n", yytext);
}

[0-9]+ { 
    digits++;
    printf("Digit: %s\n", yytext);
}

[ \t]+      { }
\r          { return 0; }
[\n]        { }

.           { printf("something else: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("enter the identifiers/keywords/digits: ");
    yylex();
    printf("\nno of identifiers: %d\n", identifiers);
    printf("no of keywords: %d\n", keywords);
    printf("no of digits: %d\n", digits);
    return 0;
}
