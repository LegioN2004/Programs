%{
#include <stdio.h>
FILE *out;

int isPrime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
%}

%%

"//"[^\n]*                      {
                                    fprintf(out, "\n");
                                    printf("[COMMENT REMOVED] //\n");
                                }


"/*"([^*]|\*+[^*/])*\*+"/"      {
                                    fprintf(out, "\n");
                                    printf("[BLOCK COMMENT REMOVED]\n");
                                }


"printf"[ \t]*"("               {
                                    fprintf(out, "PRINTF");
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

int|char|float|double|string {
                                    fprintf(out, "%s", yytext);
                                    printf("datatype: %s\n", yytext);
}

return|if|else|"else if"|for|do|while|break|switch|case {
                                    fprintf(out, "%s", yytext);
                                    printf("keywords: %s\n", yytext);
}

[a-zA-Z0-9_]+"(" {
                                    fprintf(out, "%s", yytext);
                                    printf("functions: %s\n", yytext);
}

[(){};:,] {
                                    fprintf(out, "%s", yytext);
                                    printf("syntax: %s\n", yytext);
}

"&&"|"=="|"+="|"<="|">="|"||" {
                                    fprintf(out, "%s", yytext);
                                    printf("operator: %s\n", yytext);
}

[+\-\*/=&!] {
                                    fprintf(out, "%s", yytext);
                                    printf("operator: %s\n", yytext);
}

[0-9]+\.[0-9]+ {
                                    fprintf(out, "%s", yytext);
                                    printf("floating: %s\n", yytext);
}

[0-9]+ {
    int n = atoi(yytext);
    if(isPrime(n)){
                                    fprintf(out, "%s", yytext);
                                    printf("Prime: %s\n", yytext);
    } else {
                                    fprintf(out, "%s", yytext);
                                    printf("integer: %s\n", yytext);
    }
}

[\t]+ { fprintf(out, "\t"); };

\r ;

[\n] { fprintf(out, "\n"); }

. { fprintf(out, "%s", yytext); }

%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("FILE.txt", "r");
    out  = fopen("OUTPUT.txt", "w");

    if (!yyin) { printf("Cannot open FILE.txt\n");  return 1; }
    if (!out)  { printf("Cannot open OUTPUT.txt\n"); return 1; }

    yylex();

    fclose(yyin);
    fclose(out);

    printf("\nDone. Check OUTPUT.txt\n");
    return 0;
}
