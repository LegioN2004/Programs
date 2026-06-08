/* A simple lex specification to recognize verbs, vowels and integers */

%{
#include<stdio.h>
%}

/* this [\t ]+ means do nothing for tab and extra spaces,  + = one or more ocurrences */
/* this is character class [], meaning everything inside is checked char by char */

%%

[?i:aeiou]+ {
    printf("%s is vowel\n", yytext);
}
(?i:is|are|when|go) {
    printf("%s is verb\n", yytext);
}
[0-9]+ {
    printf("%s is integer\n", yytext);
}
[a-zA-Z]+ {
    printf("%s is something else\n", yytext);
}

[ \t]+ ;
. ;

%%

int yywrap() {
    return 1;
}

int main() {
    printf("enter vowel/integer/verb: ");
    yylex();
    return 0;
}
