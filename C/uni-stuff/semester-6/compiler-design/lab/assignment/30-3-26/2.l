%{
#include <stdio.h>

FILE *out;
int comments = 0;
%}

%x SL
%x ML
%x STR
%x CHR

%%

"//"         { comments++; BEGIN(SL);  }
"/*"         { comments++; BEGIN(ML);  }
\"           { fprintf(out, "\"");     BEGIN(STR); }
\'           { fprintf(out, "\'");     BEGIN(CHR); }
.            { fprintf(out, "%s", yytext); }
\n           { fprintf(out, "\n");     }

<SL>\n       { fprintf(out, "\n"); BEGIN(INITIAL); }
<SL>.        { }

<ML>"*/"     { BEGIN(INITIAL); }
<ML>\n       { fprintf(out, "\n"); }
<ML>.        { }

<STR>\"      { fprintf(out, "\""); BEGIN(INITIAL); }
<STR>\\.     { fprintf(out, "%s", yytext); }
<STR>.       { fprintf(out, "%s", yytext); }

<CHR>\'      { fprintf(out, "\'"); BEGIN(INITIAL); }
<CHR>\\.     { fprintf(out, "%s", yytext); }
<CHR>.       { fprintf(out, "%s", yytext); }

%%

int main() {
    yyin = fopen("input.c", "r");
    out  = fopen("output.c", "w");

    if (!yyin || !out) {
        printf("Error opening file\n");
        return 1;
    }

    yylex();
    fclose(yyin);
    fclose(out);

    printf("Comments removed: %d\n", comments);
    printf("Clean code saved to output.c\n");
    return 0;
}

int yywrap() { return 1; }
