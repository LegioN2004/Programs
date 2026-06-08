%{

#include<stdio.h>
FILE *out;

int isPrime(int n){
        if(n < 2) return 0;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return 0;
    }
        return 1;
}

%}

%%

"//"[^\n]* {
    fprintf(out, "\n");
    printf("removed normal comments //\n");
}

"/*"([^*]|\*+[^*/]+)*\*+"/" { 
    fprintf(out, "\n");
    printf("removed block comments /**/\n");
}

"printf" { 
    fprintf(out, "PRINTF"); 
    printf("replaced printf with PRINTF\n");
}

"else" { 
    fprintf(out, "ELSE"); 
    printf("replaced else with ELSE\n");
}

"case" { 
    fprintf(out, "CASE"); 
    printf("replaced case with CASE\n");
}

int|char|double|float|string {
    fprintf(out, "%s", yytext);
    printf("datatype: %s\n", yytext);
}

if|while|for|do|case|else|return|switch|continue|break { 
    fprintf(out, "%s", yytext);
    printf("keyword: %s\n", yytext);
}

[a-zA-Z][a-zA-Z0-9_]*\( {
    fprintf(out, "%s", yytext);
    printf("function: %s\n", yytext);
} 

[0-9]+\.[0-9]+ {
    fprintf(out, "%s", yytext);
    printf("float: %s\n", yytext);
}

[0-9]+ {
    int n = atoi(yytext);
    if(isPrime(n)){
        fprintf(out, "%s", yytext);
        printf("Prime: %s\n", yytext);
    } else {
        fprintf(out, "%s", yytext);
        printf("Integer: %s\n", yytext);
    }
}

"=="|"!="|"&&"|"<="|">="|"||" {
    fprintf(out, "%s", yytext);
    printf("operator: %s\n", yytext);
}

[+\-\*/=<>!&|%] {
    fprintf(out, "%s", yytext);
    printf("operator: %s\n", yytext);
}

[(){};,:] { 
    printf("syntax: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    fprintf(out, "%s", yytext);
} 

\r { }

[ \t]+ { fprintf(out, " "); }

[\n] { fprintf(out, "\n"); } 

. { fprintf(out, "%s", yytext); }

%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("FILE.txt", "r");
    out = fopen("OUTPUT.txt", "w");

    yylex();

    fclose(yyin);
    fclose(out);
    return 0;
}
