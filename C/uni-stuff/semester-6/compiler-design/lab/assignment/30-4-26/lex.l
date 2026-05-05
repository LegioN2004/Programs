%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE *out;

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}
%}

KEYWORD     if|while|for|do|return|switch|break|continue|default
DATATYPE    int|float|double|char|void|long|short|unsigned|signed
ID          [a-zA-Z_][a-zA-Z0-9_]*
OPERATOR    "=="|"!="|"<="|">="|"&&"|"||"|[+\-*/=<>!&|%]
FLOAT       [0-9]+\.[0-9]+
INTEGER     [0-9]+

%%

"//"[^\n]*                      {
                                    fprintf(out, "\n");
                                    printf("[COMMENT REMOVED]\n");
                                }

"/*"([^*]|\*+[^*/])*\*+"/"      {
                                    printf("[BLOCK COMMENT REMOVED]\n");
                                }

"printf"[ \t]*"("               {
                                    fprintf(out, "PRINTF(");
                                    printf("[REPLACED] printf -> PRINTF\n");
                                }

"else"                          {
                                    fprintf(out, "ELSE");
                                    printf("[REPLACED] else -> ELSE\n");
                                }

"case"                          {
                                    fprintf(out, "CASE");
                                    printf("[REPLACED] case -> CASE\n");
                                }

{DATATYPE}                      {
                                    fprintf(out, "%s", yytext);
                                    printf("[DATATYPE] %s\n", yytext);
                                }

{KEYWORD}                       {
                                    fprintf(out, "%s", yytext);
                                    printf("[KEYWORD] %s\n", yytext);
                                }

{ID}[ \t]*"("                   {
                                    fprintf(out, "%s", yytext);
                                    printf("[FUNCTION] %s\n", yytext);
                                }

{FLOAT}                         {
                                    fprintf(out, "%s", yytext);
                                    printf("[FLOAT] %s\n", yytext);
                                }

{INTEGER}                       {
                                    int n = atoi(yytext);
                                    fprintf(out, "%s", yytext);
                                    if (isPrime(n))
                                        printf("[PRIME] %s\n", yytext);
                                    else
                                        printf("[INTEGER] %s\n", yytext);
                                }

{OPERATOR}                      {
                                    fprintf(out, "%s", yytext);
                                    printf("[OPERATOR] %s\n", yytext);
                                }

[(){};,]                        {
                                    fprintf(out, "%s", yytext);
                                    printf("[SYNTAX] %s\n", yytext);
                                }

{ID}                            {
                                    fprintf(out, "%s", yytext);
                                    printf("[IDENTIFIER] %s\n", yytext);
                                }

\r                              { }

[ \t\n]+                        { fprintf(out, "%s", yytext); }

.                               { fprintf(out, "%s", yytext); }

%%

int main() {
    FILE *in = fopen("FILE.txt", "r");
    out = fopen("OUTPUT.txt", "w");
    if (!in || !out) {
        printf("File error\n");
        return 1;
    }
    yyin = in;
    yylex();
    fclose(in);
    fclose(out);
    printf("\nDone. Check OUTPUT.txt\n");
    return 0;
}

int yywrap() {
    return 1;
}
