%{
#include <stdio.h>
#include <string.h>

int total = 0;
int vowel_start = 0;

char longest[100] = "";
int max_len = 0;

// store words and frequency
char words[100][100];
int freq[100];
int unique = 0;

// helper to check if word already exists
int find_word(char *w) {
    for(int i = 0; i < unique; i++) {
        if(strcmp(words[i], w) == 0)
            return i;
    }
    return -1;
}
%}

%%

[A-Z]+ {
    total++;

    int len = strlen(yytext);
    printf("Word: %s | Length: %d\n", yytext, len);

    // check vowel start
    if(yytext[0]=='A'||yytext[0]=='E'||yytext[0]=='I'||yytext[0]=='O'||yytext[0]=='U')
        vowel_start++;

    // find longest
    if(len > max_len) {
        max_len = len;
        strcpy(longest, yytext);
    }

    char lower[100];
    strcpy(lower, yytext);
    for(int i=0;i<len;i++)
        lower[i] = lower[i] + 32;

    printf("Lowercase: %s\n", lower);

    int idx = find_word(yytext);
    if(idx == -1) {
        strcpy(words[unique], yytext);
        freq[unique] = 1;
        unique++;
    } else {
        freq[idx]++;
    }
}

[a-zA-Z0-9]+   ;   // ignore mixed words
[\t\n ]+       ;
.              ;

%%

int main() {
    yyin = fopen("input.txt", "r");
    yylex();

    printf("\nTotal uppercase words: %d\n", total);
    printf("Words starting with vowel: %d\n", vowel_start);
    printf("Longest word: %s\n", longest);

    printf("\nFrequency:\n");
    for(int i=0;i<unique;i++)
        printf("%s : %d\n", words[i], freq[i]);

    return 0;
}

int yywrap(){ return 1; }
