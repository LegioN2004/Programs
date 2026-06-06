%{
#include <stdio.h>
%}

%%

[\t ]+ ;

(is|am|are|was|were|be|being|been|do|does|did|have|has|had|go|goes|went|eat|eats|ate|run|runs|ran|play|plays|played) {
    printf("Verb: %s\n", yytext);
}

[a-zA-Z]+ {
    printf("Not a Verb %s\n", yytext);
}

.|\n

%%

int yywrap() { return 1; }

int main()
{
    printf("Enter a word: ");
    yylex();
    return 0;
}
