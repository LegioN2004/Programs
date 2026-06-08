# Assignment 1

Q. A simple lex specification to recognize verbs, vowels and integers

```c
%{
#include<stdio.h>
%}

/* this [\t ]+ means do nothing for tab and extra spaces,  + = one or more ocurrences */
/* this is character class [], meaning everything inside is checked char by char */

%%

[?i:aeiou]+ {
    printf("%s is vowel\n", yytext);
}
(?i:is|are|when|go) {
    printf("%s is verb\n", yytext);
}
[0-9]+ {
    printf("%s is integer\n", yytext);
}
[a-zA-Z]+ {
    printf("%s is something else\n", yytext);
}

[ \t]+ ;
. ;

%%

int yywrap() {
    return 1;
}

int main() {
    printf("enter vowel/integer/verb: ");
    yylex();
    return 0;
}
```

output:

```bash
❯ flex assignment1.l && gcc lex.yy.c -ll && ./a.out
enter vowel/integer/verb: a is 1234
a is vowel
is is verb
1234 is integer

124 are i integer
124 is integer
are is verb
i is vowel
integer is something else
```

# Assignment 2

Q. A simple lex specification to recognize

1. Floating Numbers
2. Small letters and Capital letters

```c
%{
#include<stdio.h>
%}

/* this [\t ]+ means do nothing for tab and extra spaces,  + = one or more ocurrences */
/* this is character class [], meaning everything inside is checked char by char */

%%

[\t ]+ ;
([0-9]+\.[0-9]+)|([0-9]+\.)|(\.[0-9]+) { printf("floating number: %s\n", yytext);}
[a-z] { printf("small letter: %s\n", yytext);}
[A-Z] { printf("capital letter: %s\n", yytext);}
\n ;
. { printf("give correct input, %s\n", yytext);}

%%

int yywrap() {
    return 1;
}

int main() {
    printf("enter floating no/small letter/capital letter: \n");
    yylex();
    return 0;
}
```

Output:

```bash
❯ flex assignment2.l && gcc lex.yy.c -ll && ./a.out
enter floating no/small letter/capital letter:
3.1 Is A F loat
floating number: 3.1
capital letter: I
small letter: s
capital letter: A
capital letter: F
small letter: l
small letter: o
small letter: a
small letter: t
```

# Assignment 3

Q1. Write a LEX program to count the number of words in a given sentence.

```c
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
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E'
         || c == 'I' || c == 'O' || c == 'U')
            vowel++;
        else
            consonant++;
    }

}
\n { return 0; }
. { printf("give proper input: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter sentence: ");
    yylex();
    printf("number of words: %d\n", word);
    return 0;
}
```

output:

```c
❯ flex assignment3.1.l && gcc lex.yy.c -ll && ./a.out
Enter sentence: helo hi bye 2134
number of words: 3
```

Q2. Write a LEX program to check whether input is digit or not.

```c
%{
 #include<stdio.h>
 int word = 0;
 int vowel = 0;
 int consonant = 0;
%}

/* use one rule for word, vowel and consonant */

%%

[\t ] ;
[0-9]+ { printf("digit: %s\n", yytext); }
\n { return 0; }
. { printf("give proper input: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter number: ");
    yylex();
    return 0;
}
```

output:

```bash
❯ flex assignment3.2.l && gcc lex.yy.c -ll && ./a.out
Enter number: helo hi bye 2134
digit: 2134
```

Q3. Write a LEX program to find out the total no. of vowel and consonant in a given sentence.

```c
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
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E'
         || c == 'I' || c == 'O' || c == 'U')
            vowel++;
        else
            consonant++;
    }

}
\n { return 0; }
. { printf("give proper input: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter vowel/consonant: ");
    yylex();
    printf("vowels: %d\n", vowel);
    printf("consonant: %d\n", consonant);
    return 0;
}
```

output:

```c
❯ flex assignment3.l && gcc lex.yy.c -ll && ./a.out
Enter vowel/consonant: helo hi bye 2134
vowels: 4
consonant: 5
```

# Assignment 4

Q1. Write a lex program to identify and print integer and float constants and identifiers.

```c
%{
 #include<stdio.h>
%}

/* put float before lex since it chooses the longer number first and generally float are longest in length, eg: 3.14 > 3 */

%%

[\t ] ;
([0-9]+\.[0-9]+)|(\.[0-9]+)|([0-9]+\.) { printf("float: %s\n", yytext); }
[0-9]+ { printf("int: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("identifier: %s\n", yytext); }
\n { return 0; }
. { printf("unknown: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter input: ");
    yylex();
    return 0;
}
```

Output:

```c
❯ flex assignment4.1.l && gcc lex.yy.c -ll && ./a.out
Enter input: int a = 10
identifier: int
identifier: a
unknown: =
int: 10
```

Q2. Write a lex program to check whether the string is a word or a number.

```c
%{
#include<stdio.h>
%}

%%
[ \t] ;
[a-zA-Z]+ { printf("word: %s\n", yytext); }
[0-9]+ { printf("number: %s\n", yytext); }
\n ;
. { printf("give proper input "); }
%%

int yywrap() { return 1; }

int main() {
    printf("enter string: ");
    yylex();
    return 0;
}
```

Output:

```c
❯ flex assignment4.2.l && gcc lex.yy.c -ll && ./a.out
enter string: hello
word: hello
1234
number: 1234
```

# Assignment 5

1. Write a lex program to take input from file and remove multiple spaces

```c
%{
 #include<stdio.h>
%}

/* putchar is used to show output in terminal or printing */

%%

.|\n { putchar(yytext[0]); }

%%

int yywrap() {
    return 1;
}


int main() {
    yyin = fopen("input.txt", "r");
    yylex();

    fclose(yyin);
    return 0;
}
```

Output:

```bash
❯ flex assignment5.1.l && gcc lex.yy.c -ll && ./a.out
35
2
24 90
oairsnt
oairnst   oairents


arstoine
%{
#include <stdio.h>
int identifiers = 0;
int keywords = 0;
int digits = 0;
%}

%%

/* KEYWORDS must come BEFORE identifiers */
int|char|long|break|return|if|else|while|for|do|switch|case|default|continue|goto {
    keywords++;
    printf("Keyword: %s\n", yytext);
}

/* IDENTIFIERS: starts with letter/underscore, followed by 0+ letters/digits/underscores */
[a-zA-Z_][a-zA-Z0-9_]* {
    identifiers++;
    printf("Identifier: %s\n", yytext);
}

/* DIGITS: one or more digits (counts as ONE number) */
[0-9]+ {
    digits++;
    printf("Digit: %s\n", yytext);
}

/* Ignore whitespace */
[ \t]+      { }
\r          { }
[\n]        { }

/* Print other characters */
.           { printf("something else: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("enter the identifiers/keywords/digits: ");
    yylex();
    printf("\nno of identifiers: %d\n", identifiers);
    printf("no of keywords: %d\n", keywords);
    printf("no of digits: %d\n", digits);
    return 0;
}
```

file used `input.txt`:

```txt
35
2
24 90
oairsnt
oairnst   oairents


arstoine
```

2. Lex program to take input from file and remove multiple spaces

```c
%{
#include <stdio.h>
FILE *out;
%}

/* putchar(yytext[0])is used to show output in terminal or printing */
/* fputc(yytext[0], out) is used to print output in a file */

%%

[ \t]+      {
    fputc(' ', out);
    printf(" ");
}
\r          { }
[\n]+       {
    fputc('\n', out);
    printf("\n", yytext);
}
.           {
    fputc(yytext[0], out);
    printf("%s", yytext);
}

%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.txt", "r");
    if (!yyin) {
        printf("Error: cannot open input.txt\n");
        return 1;
    }

    out = fopen("output.txt", "w");
    if (!out) {
        printf("Error: cannot open output.txt\n");
        return 1;
    }

    yylex();
    printf("\noutput also in output.txt\n");
    fclose(yyin);
    fclose(out);
    return 0;
}

```

Output:

```bash
❯ flex assignment5.2.l && gcc lex.yy.c -ll && ./a.out
assignment5.2.l:18:18: warning: data argument not used by format string [-Wformat-extra-args]
   18 |     printf("\n", yytext);
      |            ~~~~  ^
1 warning generated.
35
2
24 90
oairsnt
oairnst oairents
arstoine

output also in output.txt
```

file used `input.txt`:

```txt
35
2
24 90
oairsnt
oairnst   oairents


arstoine
```

3. Lex program to determine no of identifiers, keywords, and digits

```c
%{
#include <stdio.h>
int identifiers = 0;
int keywords = 0;
int digits = 0;
%}

%%

int|char|long|break|return|if|else|while|for|do|switch|case|default|continue|goto {
    keywords++;
    printf("Keyword: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    identifiers++;
    printf("Identifier: %s\n", yytext);
}

[0-9]+ {
    digits++;
    printf("Digit: %s\n", yytext);
}

[ \t]+      { }
\r          { }
[\n]        { return 0; }

.           { printf("something else: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("enter the identifiers/keywords/digits: ");
    yylex();
    printf("\nno of identifiers: %d\n", identifiers);
    printf("no of keywords: %d\n", keywords);
    printf("no of digits: %d\n", digits);
    return 0;
}
```

output:

```bash
❯ flex assignment5.3.l && gcc lex.yy.c -ll && ./a.out
enter the identifiers/keywords/digits: int int a = 10 2043
Keyword: int
Keyword: int
Identifier: a
something else: =
Digit: 10
Digit: 2043

no of identifiers: 1
no of keywords: 2
no of digits: 2
```

# Assignment 6

Q1. Write a lex program to calculate and display the length of the matched string using yyleng.

```c
%{
#include<stdio.h>
%}

%%
[a-zA-Z0-9_]+ { printf("string: %s and it's length: %d\n", yytext, yyleng); }
[ \t\r\n] {}
. { }
%%

int yywrap() { return 1; }
int main() {
    printf("enter input: ");
    yylex();
    return 0; }
```

output:

```bash
❯ flex assignment6.1.l && gcc lex.yy.c -ll && ./a.out
enter input: hello hi
string: hello and it's length: 5
string: hi and it's length: 2
```

Q2. Write a lex program to find the longest word in the input.

```c
%{
#include<stdio.h>
int count = 0;
char longest[100] = "";
%}

/* [ \t\r] {} ignores tabs, spaces and and carriage return (going back to the front) */
/* \n { return 0; } use this so that on pressing enter you get the output instead of waiting thinking of a loop but this works with ctrl + d. don't even use braces here since it's done above already */

%%
[a-zA-Z0-9_]+ {
    if(yyleng > count){
        count = yyleng;
        strncpy(longest, yytext, yyleng);
        longest[yyleng] = '\0';
    }
}
[ \t\r]+ {}
\n { return 0; }
. { }
%%

int yywrap() { return 1; }

int main() {
    printf("enter input: ");
    yylex();
    printf("longest word: %s of length %d", longest, count);
    return 0;
}
```

output:

```bash
❯ flex assignment6.2.l && gcc lex.yy.c -ll && ./a.out
enter input: hello hi byeeeeeeeeee
longest word: byeeeeeeeeee of length 12
```

Q3. Write a lex program that reads input from a file, identifies sequence of alphabetic characters and numeric characters and calculates and display the total length of all alphabetic strings and numeric strings using yyleng.

```c
%{
    #include<stdio.h>
%}


%%

[a-zA-Z]+ {
    printf("alphabet: %s | length: %d\n", yytext, yyleng);
}

[0-9]+ {
    printf("numeric: %s | length: %d\n", yytext, yyleng);
}

[ \t\r] {}
\n {}
. {}
%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("input.txt", "r");
    yylex();
    return 0;
}
```

Output:

```bash
❯ flex assignment6.3.l && gcc lex.yy.c -ll && ./a.out
numeric: 35 | length: 2
numeric: 2 | length: 1
numeric: 24 | length: 2
numeric: 90 | length: 2
alphabet: hello | length: 5
alphabet: hi | length: 2
alphabet: bye | length: 3
alphabet: nothing | length: 7
```

`Input.txt` file used:

```txt
35
2
24 90
hello
hi   bye


nothing
```

# Assignment 7

Q1. Write a lex program that identifies and differentiates between positive and negative numbers.

```c
%{
    #include<stdio.h>
%}

%%

-[0-9]+ {
        printf("-ve number: %s\n", yytext);
}

[0-9]+ {
        printf("+ve number: %s\n", yytext);
}

[ \t\r] {}
\n {}
. {}
%%

int yywrap() { return 1; }

int main() {
    printf("enter +ve/-ve no: ");
    yylex();
    return 0;
}
```

Output:

```bash
❯ flex assignment7.1.l && gcc lex.yy.c -ll && ./a.out
enter +ve/-ve no: +21 -32
+ve number: 21
-ve number: -32
22
+ve number: 22
-49
-ve number: -49
```

Q2. Write a lex program that reads an input string and replaces every occurrences of "abc" with "ABC".

```c
%{
    #include<stdio.h>
%}

%%

[a-zA-Z0-9_]+ {
    for(int i = 0; i < yyleng; i++){
        if((yytext[i] == 'a') && (yytext[i+1] == 'b') && (yytext[i+2] == 'c')){
            yytext[i] = 'A';
            yytext[i + 1] = 'B';
            yytext[i + 2] = 'C';
        }
    }
        printf("%s\n", yytext);
}

[ \t\r] {}
\n {}
. {}
%%

int yywrap() { return 1; }

int main() {
    printf("Enter abc containing string: ");
    yylex();
    return 0;
}
```

Output:

```bash
❯ flex assignment7.2.l && gcc lex.yy.c -ll && ./a.out
Enter abc containing string: hello abc, i am abc cde
hello
ABC
i
am
ABC
cde
```

Q3. Write a lex program that reads an input string and replaces every occurrences of your own name.

```c
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
            printf("mili replaced with abc: %s\n", yytext);
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
```

output:

```bash
❯ flex assignment7.3.l && gcc lex.yy.c -ll && ./a.out
enter string containing mili: mili likes tech mili
abcd likes tech abcd
```

# Assignment 8

Q1. Lex program to read a C file and remove all the comments and save it in an output file.

```c
%{
#include <stdio.h>
FILE *out;
%}

%%

"//"[^\n]*          {}
"/*"([^*]|\*+[^*/])*\*+"/"  { }

[\n]                  { fprintf(out, "\n"); }
[\t\r] ;
.                   { fprintf(out, "%s", yytext); }

%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("input.c", "r");
    out  = fopen("output.c", "w");

    if (!yyin) { printf("Cannot open input.c\n");  return 1; }
    if (!out)  { printf("Cannot open output.c\n"); return 1; }

    yylex();

    fclose(yyin);
    fclose(out);

    return 0;
}
```

input.c:

```c
#include <stdio.h>

// this is a comment
/* this is a block comment */

// two more
// ...........

int main() {
  int a;
  int b = 1.1;
  int c = 1;
  return 0;
  for (int i = 0; i < 10; i++)
    if () {
    } else {
    }
  switch () {
  case 0:
    // commentssssssssss
    aorsitnrast;
  case 0:
    aorsitnrast
  }
}
```

output.c:

```c
#include <stdio.h>







int main() {
  int a;
  int b = 1.1;
  int c = 1;
  return 0;
  for (int i = 0; i < 10; i++)
    if () {
    } else {
    }
  switch () {
  case 0:

    aorsitnrast;
  case 0:
    aorsitnrast
  }
}
```

Q2. Lex program to reads integers from an input file, computes the sum and difference of every pair of consecutive numbers and write the results to an output file.

```c
%{
#include <stdio.h>
int prev;
int first = 1;
FILE *out;
%}

%%

[0-9]+ {
    int num = atoi(yytext);

    if(first){
        prev = num;
        first = 0;
    } else {
        fprintf(out, "sum: %d, difference: %d\n", prev + num, prev - num);
        prev = num;
    }
}

.|\n ;
%%

int yywrap() { return 1; }

int main() {
    yyin = fopen("input.txt", "r");
    out  = fopen("output.txt", "w");

    if (!yyin) { printf("Cannot open input.c\n");  return 1; }
    if (!out)  { printf("Cannot open output.c\n"); return 1; }

    yylex();

    fclose(yyin);
    fclose(out);

    return 0;
}
```

Output: (bat is like cat command for showing file contents)

```bash
❯ flex assignment8.2.l && gcc lex.yy.c -ll && ./a.out && bat input.txt output.txt
───────┬──────────────────────────────────────────────────────────────────────────────────────────────────────────────
       │ File: input.txt
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────────────────
   1 ~ │ 35
   2 ~ │ 2
   3 ~ │ 24 90
   4 ~ │ hello
   5 ~ │ hi   bye
   6 ~ │
   7 ~ │
   8   │ abc
   9 ~ │ nothing
───────┴──────────────────────────────────────────────────────────────────────────────────────────────────────────────
───────┬──────────────────────────────────────────────────────────────────────────────────────────────────────────────
       │ File: output.txt
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────────────────
   1 ~ │ sum: 37, difference: 33
   2 ~ │ sum: 26, difference: -22
   3 ~ │ sum: 114, difference: -66
───────┴──────────────────────────────────────────────────────────────────────────────────────────────────────────────
```

# Assignment 9

Q1. Write a LEX program to implement a simple calculator

```c
%{
#include <stdio.h>
#include <stdlib.h>
char op = '\0';
int count = 0;
double num1 = 0, num2 = 0, result = 0;
%}

%%

[0-9]+(\.[0-9]+)* {
    if(count == 0){
        num1 = atof(yytext);
        count = 1;
    } else {
        num2 = atof(yytext);

        if(op == '+') result = num1 + num2;
        else if(op == '-') result = num1 - num2;
        else if(op == '*') result = num1 * num2;
        else if(op == '/'){
            if (num2 == 0){
                printf("Error: Division by zero!\n");
                num1 = 0; num2 = 0; op = 0; count = 0;
                return 0;
            }
            result = num1 / num2;
        }
        printf("Result: %.2f\n", result);
        num1 = 0; num2 = 0; op = 0; count = 0;
    }
}

[+\-*/] {
    op = yytext[0];
}
[ \t\r]+ ;

\n ;
. ;
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}
```

Output:

```bash
❯ flex assignment9.l && gcc lex.yy.c -ll && ./a.out
1+2
Result: 3.00
3 * 4
Result: 12.00
2.1 * 5
Result: 10.50
3.1 * 2.2
Result: 6.82
3 /3
Result: 1.00
3-3
Result: 0.00
```

# Assignment 10

Q. Write a single LEX program to read the below given file "FILE.txt" to

1. detect all the keywords
2. detect all the functions
3. detect all the syntax
4. replace all "printf" by "PRINTF"
5. replace all "else" by "ELSE"
6. replace all "case" by "CASE"
7. remove comment lines
8. detect all the datatypes
9. detect all the operators
10. detect all the floating and prime nos.

and open it in an output file "OUTPUT.txt"

```c
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
```

output:

```bash
❯ flex assignment10.l && gcc lex.yy.c -ll && ./a.out && bat FILE.txt OUTPUT.txt
removed normal comments //
operator: %
syntax: {
operator: <
operator: >
operator: <
operator: >
datatype: double
operator: =
float: 0.0
syntax: ,
operator: =
float: 0.0
syntax: ;
datatype: char
operator: =
Integer: 0
syntax: ;
operator: %
syntax: }
Integer: 0
operator: -
Integer: 9
syntax: {
syntax: }
operator: +
syntax: (
syntax: {
syntax: }
operator: +
syntax: )
operator: %
operator: %
syntax: {
syntax: }
syntax: {
keyword: if
syntax: (
operator: ==
float: 0.0
operator: &&
operator: ==
Integer: 0
syntax: )
operator: =
function: atof(
syntax: )
syntax: ;
replaced else with ELSE
operator: =
function: atof(
syntax: )
syntax: ;
syntax: }
operator: +
operator: -
operator: *
operator: /
syntax: {
operator: =
Integer: 0
syntax: ;
syntax: }
syntax: {
function: switch(
syntax: )
syntax: {
replaced case with CASE
operator: +
syntax: :
function: printf(
syntax: :
operator: %
syntax: ,
operator: +
syntax: )
syntax: ;
keyword: break
syntax: ;
replaced case with CASE
operator: -
syntax: :
function: printf(
syntax: :
operator: %
syntax: ,
operator: -
syntax: )
syntax: ;
keyword: break
syntax: ;
replaced case with CASE
operator: *
syntax: :
function: printf(
syntax: :
operator: %
syntax: ,
operator: *
syntax: )
syntax: ;
keyword: break
syntax: ;
replaced case with CASE
operator: /
syntax: :
function: if(
operator: !=
Integer: 0
syntax: )
function: printf(
syntax: :
operator: %
syntax: ,
operator: /
syntax: )
syntax: ;
replaced else with ELSE
function: printf(
syntax: )
syntax: ;
keyword: break
syntax: ;
syntax: :
function: printf(
syntax: )
syntax: ;
syntax: }
operator: =
operator: =
float: 0.0
syntax: ;
operator: =
Integer: 0
syntax: ;
syntax: }
syntax: {
removed block comments /**/
syntax: }
operator: %
operator: %
datatype: int
function: main(
syntax: )
syntax: {
function: yylex(
syntax: )
syntax: ;
keyword: return
Integer: 0
syntax: ;
syntax: }
datatype: int
function: yywrap(
syntax: )
syntax: {
keyword: return
Integer: 1
syntax: ;
syntax: }
removed normal comments //
Prime: 2
Prime: 3
Prime: 5
Prime: 7
Prime: 11
removed normal comments //
float: 3.14
float: 0.5
float: 2.36
float: 11.11
```

FILE.txt

```txt
//THIS IS A LEX PROGRAM TO PRACTICE
%{
#include <stdio.h>
#include <stdlib.h>
double a = 0.0, b = 0.0;
char op = '\0';
%}
digit   [0-9]
num     {digit}+(\.{digit}+)?
%%
{num} {
         if (a == 0.0 && op == '\0')
             a = atof(yytext);
         else
             b = atof(yytext);
      }
[\+\-\*\/] { op = yytext[0]; }
[\n] {
         switch(op) {
             case '+': printf("Result: %lf\n", a + b); break;
             case '-': printf("Result: %lf\n", a - b); break;
             case '*': printf("Result: %lf\n", a * b); break;
             case '/':
                         if(b != 0)
                             printf("Result: %lf\n", a / b);
                         else
                             printf("Division by zero error\n");
                         break;
             default:  printf("Unknown operator\n");
         }
         a = b = 0.0;
         op = '\0';
      }
.          { /* ignore */ }
%%
int main(void) {
    yylex();
    return 0;
}
int yywrap()
{

 return 1;
 }

// THESE ARE PRIME NOS.

2 3 5 7 11

// THESE ARE FLOATING NOS.

3.14 0.5 2.36 11.11
```

OUTPUT.txt

```txt


%
#include <stdio.h>
#include <stdlib.h>
double a = 0.0 b = 0.0
char op = '\0'
%
digit [0-9]
num digit+\.digit+?
%%
num
 if a == 0.0 && op == '\0'
 a = atof(yytext
 ELSE
 b = atof(yytext

[\+\-\*\/]  op = yytext[0]
[\n]
 switch(op
 CASE '+' printf("Result %lf\n" a + b break
 CASE '-' printf("Result %lf\n" a - b break
 CASE '*' printf("Result %lf\n" a * b break
 CASE '/'
 if(b != 0
 printf("Result %lf\n" a / b
 ELSE
 printf("Division by zero error\n"
 break
 default printf("Unknown operator\n"

 a = b = 0.0
 op = '\0'

.

%%
int main(void
 yylex(
 return 0

int yywrap(


 return 1





2 3 5 7 11




3.14 0.5 2.36 11.11
```

# Assignment 11

Q. WAP in C to find the First of the given grammar: S->ABC, A->a|b|#, B->c|d|#, C->e|f|#

```c
#include <ctype.h>
#include <stdio.h>

char prod[10][10];
int n;

void first(char ch) { // ch = A, a, b, #

  if (!isupper(ch)) {
    printf("%c, ", ch);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (prod[i][0] == ch) { // ch = A, a, b, #
      first(prod[i][2]);    // A -> a | b | #
    }
  }
}

int main() {
  char ch;
  printf("Enter the no of productions: ");
  scanf("%d", &n); // 10

  printf("Enter the productions: \n");
  for (int i = 0; i < n; i++)
    scanf("%s", prod[i]);

  printf("Enter the non-terminal for first: ");
  scanf(" %c", &ch);

  printf("first(%c) = { ", ch);
  first(ch);
  printf("}\n");

  return 0;
}
```

Output:

```bash
❯ gcc follow.c && ./a.out
Enter number of productions: 10
Enter productions (e.g. S=AB, A=a, A=#): S=ABC
A=a
A=b
A=#
B=c
B=d
B=#
C=e
C=f
C=#
Enter non-terminal for first: A
first(A) = { a, b, # }
```

### Follow

```c
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char prod[10][10];
int n;

int hasEpsilon(char ch) {
  for (int i = 0; i < n; i++)
    if (prod[i][0] == ch && prod[i][2] == '#')
      return 1;
  return 0;
}

void first(char ch) {
  if (!isupper(ch)) {
    if (ch != '#')
      printf("%c ", ch);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (prod[i][0] == ch) {
      if (prod[i][2] != '#')
        first(prod[i][2]);
    }
  }
}

// A -> a
// A -> b
// A -> #

void follow(char c) {
  int i, j;

  if (c == prod[0][0])
    printf("$ ");

  for (i = 0; i < n; i++) {
    for (j = 2; prod[i][j] != '\0'; j++) {
      if (prod[i][j] == c) {

        int k = j + 1;

        while (prod[i][k] != '\0') {
          first(prod[i][k]);

          if (!hasEpsilon(prod[i][k]))
            break;

          k++;
        }

        if (prod[i][k] == '\0') {
          if (prod[i][0] != c)
            follow(prod[i][0]);
        }
      }
    }
  }
}

int main() {
  int i;
  char ch;

  printf("Enter number of productions: ");
  scanf("%d", &n);

  printf("Enter productions (e.g. S=AB, A=a, A=#):\n");
  for (i = 0; i < n; i++)
    scanf("%s", prod[i]);

  printf("Enter non-terminal for FOLLOW: ");
  scanf(" %c", &ch);

  printf("FOLLOW(%c) = { ", ch);
  follow(ch);
  printf("}\n");

  return 0;
}
```

Output:

```bash
❯ gcc follow.c && ./a.out
Enter number of productions: 10
Enter productions (e.g. S=AB, A=a, A=#): S=ABC
A=a
A=b
A=#
B=c
B=d
B=#
C=e
C=f
C=#
Enter non-terminal for FOLLOW: A
FOLLOW(A) = { c d e f $ }
```
