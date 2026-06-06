%{
 #include<stdio.h>
 int word = 0;
 int vowel = 0;
 int consonant = 0;
%}

/* use one rule for word, vowel and consonant */

%%

[\t ] ;
[a-zA-Z]+ {
    word++;
    for(int i = 0; yytext[i] != '\0'; i++){
        char c = yytext[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowel++;
        else
            consonant++;
    }

}
[0-9]+ { printf("digit: %s\n", yytext); }
\n { return 0; }
. { printf("give proper input: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}


int main() {
    printf("Enter sentence: ");
    yylex();
    printf("word occurence: %d\n", word);
    printf("vowels: %d\n", vowel);
    printf("consonant: %d\n", consonant);
    return 0;
}

