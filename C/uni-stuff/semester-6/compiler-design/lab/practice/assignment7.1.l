%{
    #include<stdio.h>
%}

%%

-[0-9]+ {
        printf("-ve number: %s\n", yytext);
}

[0-9]+ {
        printf("+ve number: %s\n", yytext);
}

[ \t\r] {}
\n {}
. {}
%%

int yywrap() { return 1; }

int main() {
    printf("enter +ve/-ve no: ");
    yylex();
    return 0; 
}
