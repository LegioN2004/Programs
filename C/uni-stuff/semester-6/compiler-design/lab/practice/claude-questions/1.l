%{ 
#include<stdio.h>
int word = 0;
int consonant = 0;
int vowel = 0;
char longest[30] = "";
int n = 0;
%}

%%
[a-zA-Z]+ {
    for(int i = 0; yytext[i] != '\0'; i++){
        char hello[5] = { 'h', 'e', 'l', 'l', 'o' };
        char hello2[5] = { 'H', 'E', 'L', 'L', 'O' };
        if(yytext[i] == hello[i])
            yytext[i] = hello2[i];
    }
    word++;
    printf("word: %s\n", yytext);
    for(int i = 0; yytext[i] != '\0'; i++){
        int c = yytext[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            vowel++;
        } else
            consonant++;
    }
    if(yyleng > n) {
        n = yyleng;
        strncpy(longest, yytext, yyleng);
        longest[yyleng] = '\0';
    }
}


"//"[^\t]* { }

[0-9]+\.[0-9]+ {
    printf("float: %s\n", yytext);
}

[0-9] {
    printf("integer: %s\n", yytext);
}

[0-9]+ {
    printf("digit: %s\n", yytext);
}

[ \t\r] {}

. ;
%%

int yywrap() {return 1;}

int main() {
    printf("enter: \n");
    yylex();
    printf("no of vowels: %d\n", vowel);
    printf("no of consonant: %d\n", consonant);
    printf("no of word: %d\n", word);
    printf("longest word: %s, length: %d\n", longest, n);
    return 0;
}
