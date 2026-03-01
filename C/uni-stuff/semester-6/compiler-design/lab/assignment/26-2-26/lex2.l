%{
#include<stdio.h>
%}


%%
[0-9]+    { printf("%s is a digit\n", yytext); }
[a-zA-Z]+ { printf("%s is not a digit\n", yytext); }
.         { printf("%s is not a digit\n", yytext); }
%%

int main() {
    printf("Enter ssomething: ");
    yylex();
    return 0;
}
int yywrap() { return 1; }
