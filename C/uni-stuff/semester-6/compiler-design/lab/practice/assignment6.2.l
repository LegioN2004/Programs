%{
#include<stdio.h>
int count = 0;
char longest[100] = "";
%}

/* [ \t\r] {} ignores tabs, spaces and and carriage return (going back to the front) */
/* \n { return 0; } use this so that on pressing enter you get the output instead of waiting thinking of a loop but this works with ctrl + d. don't even use braces here since it's done above already */

%%
[a-zA-Z0-9_]+ {
    if(yyleng > count){
        count = yyleng;
        strncpy(longest, yytext, yyleng);
        longest[yyleng] = '\0';
    }
}
[ \t\r]+ {}
\n { return 0; }
. { }
%%

int yywrap() { return 1; }

int main() { 
    printf("enter input: ");
    yylex();
    printf("longest word: %s of length %d", longest, count);
    return 0;
}
