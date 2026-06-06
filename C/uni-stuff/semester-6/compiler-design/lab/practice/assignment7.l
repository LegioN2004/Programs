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

[a-zA-Z0-9_]+ {
    for(int i = 0; i < yyleng; i++){
        if((yytext[i] == 'a') && (yytext[i+1] == 'b') && (yytext[i+2] == 'c')){
            yytext[i] = 'A';
            yytext[i + 1] = 'B';
            yytext[i + 2] = 'C';
        }
    }
        printf("%s\n", yytext);
}

[a-zA-Z0-9_]+ {
    for(int i = 0; i < yyleng; i++){
        if((yyleng =wl= 'm'))
    }
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
