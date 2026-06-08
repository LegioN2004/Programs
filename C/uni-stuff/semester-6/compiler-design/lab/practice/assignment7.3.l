%{
    #include<stdio.h>
%}

%%

[a-zA-Z]+ {
    for(int i = 0; i < yyleng; i++){
        if((yytext[i] == 'm') && (yytext[i+1] == 'i') && (yytext[i+2] == 'l') && (yytext[i+3] == 'i')){
            yytext[i] = 'a';
            yytext[i + 1] = 'b';
            yytext[i + 2] = 'c';
            yytext[i + 3] = 'd';
        }
    }
    printf("%s", yytext);
}

[\t\r] {}

" " { printf(" "); }

. {}

%%

int yywrap() { return 1; }

int main() {
    printf("enter string containing mili: ");
    yylex();
    return 0; 
}
