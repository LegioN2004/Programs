%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ci_match(const char *s) {
    char buf[256];
    int i;
    for (i = 0; s[i] && i < 255; i++)
        buf[i] = tolower((unsigned char)s[i]);
    buf[i] = '\0';
    return strcmp(buf, "abc") == 0;
}
%}

%%

[a-zA-Z0-9]*[aA][bB][cC][a-zA-Z0-9]+  {
    printf("'abc' INSIDE ALPHANUMERIC STRING: %s\n", yytext);
}

[a-zA-Z0-9]+[aA][bB][cC][a-zA-Z0-9]*  {
    printf("'abc' INSIDE ALPHANUMERIC STRING: %s\n", yytext);
}

[aA][bB][cC]  {
    if (strcmp(yytext, "abc") == 0)
        printf("EXACT 'abc': %s\n", yytext);
    else
        printf("CASE-INSENSITIVE 'abc' VARIANT: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]*  { printf("OTHER IDENTIFIER: %s\n", yytext); }

[\t\n ]+  ;
.         { printf("OTHER: %s\n", yytext); }

%%

int main() {
    yyin = fopen("input.txt", "r");
    if (!yyin) {
        printf("Error: cannot open input.txt\n");
        return 1;
    }
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap() { return 1; }
