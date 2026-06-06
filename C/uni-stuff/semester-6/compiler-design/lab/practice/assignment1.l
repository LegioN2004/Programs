%{
#include<stdio.h>
%}

/* this [\t ]+ means do nothing for tab and extra spaces,  + = one or more ocurrences */
/* this is character class [], meaning everything inside is checked char by char */

%%

[\t ]+ ;
(?i:is|are|when) {
    printf("%s is verb", yytext);
}
(?i:aeiou)+ {
    printf("%s is vowel", yytext);
}
[0-9]+ {
    printf("%s is integer", yytext);
}
[a-zA-Z]+ {
    printf("%s is something else", yytext);
}
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
