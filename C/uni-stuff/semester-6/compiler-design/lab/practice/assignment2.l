%{
#include<stdio.h>
%}

/* this [\t ]+ means do nothing for tab and extra spaces,  + = one or more ocurrences */
/* this is character class [], meaning everything inside is checked char by char */

%%

[\t ]+ ;
([0-9]+\.[0-9]+)|([0-9]+\.)|(\.[0-9]+) { printf("floating number: %s\n", yytext);}
[a-z] { printf("small letter: %s\n", yytext);}
[A-Z] { printf("capital letter: %s\n", yytext);}
\n ;
. { printf("give correct input, %s\n", yytext);}

%%

int yywrap() {
    return 1;
}

int main() {
    printf("enter floating no/small letter/capital letter: \n");
    yylex();
    return 0;
}
