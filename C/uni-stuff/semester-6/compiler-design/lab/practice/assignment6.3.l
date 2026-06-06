%{
    #include<stdio.h>
%}


%%

[a-zA-Z]+ {
    printf("alphabet: %s | length: %d\n", yytext, yyleng);
}

[0-9]+ {
    printf("numeric: %s | length: %d\n", yytext, yyleng);
}

[ \t\r] {}
\n {}
. {}
%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("input.txt", "r");
    yylex();
    return 0; 
}
