%{
#include <stdio.h>
// int words ;
// int consonant ;
// int vowel ;
// FILE *out;
// int isPrime(int n) {
//     if(n < 2) return 0;
//     for(int i = 2; i * i <= n; i++){
//         if(n % i == 0) return 0;
//     }
//     return 1;
// }
// int prev = 0;
int count = 1;
char op = '\0';
int num1 = 0, num2 = 0, result = 0;
%}

%%
[0-9]+(\.[0-9]+)* {
    if(count == 1){
        num1 = atoi(yytext);
        count = 0;
    } else {
        num2 = atoi(yytext);
        if(op == '+') result = num1 + num2;
        else if(op == '-') result = num1 - num2;
        else if(op == '*') result = num1 * num2;
        else if(op == '/'){
            if (num2 == 0){
                printf("Error: Division by zero!\n");
                num1 = 0; num2 = 0; op = '\0'; count = 1;
                return 0;
            }
            result = num1 / num2;
        }
        printf("result: %d", result);
        num1 = 0; num2 = 0; op = '\0'; count = 1;
    }
}
[+\*\-/] {
    op = yytext[0];
}
[ \t]+ { 
}
\r { }
[\n]+ { 
}
. {
    printf("%s", yytext);
}

%%

int yywrap() { return 1; }

int main() {
    //
    // [0-9]+ {
    //     int num = atoi(yytext);
    //     if(count == 1){
    //         prev = num;
    //         count = 0;
    //     } else {
    //         fprintf(out, "sum: %d, dif: %d", prev + num, prev - num);
    //         prev = num;
    //     }
    // }
    // "//"[^\n]* { printf("\n"); }
    // "/*"([^*]|\*+[^*/])*\*+"/" { printf("\n"); }
    // [a-zA-Z]+ {
    //     words++;
    //     char v[5] = {'a', 'e', 'i', 'o', 'u'};
    //     for(int i = 0; yytext[i] != '\0' ; i++){
    //         if(v[i] == yytext[i])
    //             vowel++;
    //         else
    //             consonant++;
    //     }
    // }
    // is|are {
    //     printf("verb: %s\n", yytext);
    // }
    // [a-z] {
    //     printf("lowercase: %s\n", yytext);
    // }
    // [A-Z] {
    //     printf("uppercase: %s\n", yytext);
    // }
    // [0-9] {
    //     printf("int: %s\n", yytext);
    // }
    // [0-9]+ {
    //     printf("digit: %s\n", yytext);
    // }
    // ([0-9]+\.[0-9]+)|(\.[0-9]+)|([0-9]+\.) {
    //     printf("float: %s\n", yytext);
    // }

    // yyin = fopen("input.txt", "r");
    // out  = fopen("output.txt", "w");

    // if (!yyin) { printf("Cannot open FILE.txt\n");  return 1; }
    // if (!out)  { printf("Cannot open OUTPUT.txt\n"); return 1; }

    yylex();
    printf("result: %d", result);
    // printf("no of words: %d\n", words);
    // printf("no of vowel: %d\n", vowel);
    // printf("no of consonant: %d\n", consonant);

    // fclose(yyin);
    // fclose(out);

    // printf("\nDone. Check OUTPUT.txt\n");
    return 0;
}
