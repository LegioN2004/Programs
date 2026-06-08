%{
    #include<stdio.h>
%}

%%

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

[ \t\r] {}
\n {}
. {}
%%

int yywrap() { return 1; }

int main() {
    printf("Enter abc containing string: ");
    yylex();
    return 0; 
}
