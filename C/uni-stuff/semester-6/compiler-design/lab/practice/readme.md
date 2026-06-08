## Bugs Found

**Bug 1 — Character class instead of alternation for keywords**

```lex
[if|else|while|for|do|int|char|float|string]+
```

Square brackets mean a character class — this matches single characters like `i`, `f`, `|`, `e` etc. NOT whole words. You need proper alternation:

```lex
if|else|while|for|do|int|char|float|string
```

**Bug 2 — Identifier rule misses single character identifiers**

```lex
[a-zA-Z_][a-zA-Z0-9_]+
```

The `+` after the second part means it needs at least 2 characters total. A single letter variable like `a` or `i` will never match. Change to `*`:

```lex
[a-zA-Z_][a-zA-Z0-9_]*
```

**Bug 3 — Digit rule misses multi digit numbers**

```lex
[0-9]
```

This matches one digit at a time. So `123` gets counted as 3 digits instead of 1 number. Add `+`:

```lex
[0-9]+
```

**Bug 4 — fprintf inside every rule**
You are printing the count inside the rule which means it prints every single time a token is matched. So if you have 3 keywords you get 3 lines printed progressively. Print only ONCE at the end after `yylex()` finishes.

**Bug 5 — No file error checking**
If `input.txt` does not exist the program crashes silently.

**Bug 6 — Whitespace not handled**
No rule for spaces, tabs, newlines — lex will hit the default rule and behave unexpectedly.

---

**`FILE *out;`**
Declares a global file pointer for the output file. Global so the lex rules can access it directly.

---

**`"//"[^\n]*`**
This matches a single line comment. Breaking it down:

- `"//"` matches the two forward slashes literally
- `[^\n]*` means zero or more of any character that is NOT a newline — so it grabs everything after `//` until the end of the line
- The action writes only `\n` to preserve the line structure — the comment text itself is thrown away

---

**`"/*"([^*]|\*+[^*/])*\*+"/"`**
This matches a block comment. Breaking it down:

- `"/*"` matches the opening of the block comment
- `([^*]|\*+[^*/])*` matches everything in between — either a non-star character OR one or more stars not followed by `/`
- `\*+"/"` matches the closing `*/`
- The action is completely empty — the entire block comment is thrown away including all lines inside it

## All Output Functions — Complete Guide

---

The regex is:

```lex
"/*"([^*]|\*+[^*/])*\*+"/"
```

# Part 1

```lex
"/*"
```

Matches the literal characters:

```text
/*
```

So input:

```c
/* hello */
^^
```

This part consumes the opening comment.

---

# Part 2

```lex
([^*]|\*+[^*/])*
```

This is the complicated part.

It means:

```text
Match everything inside the comment
```

Let's split it further.

---

## A

```lex
[^*]
```

### Meaning

`[]` = character class

`^` inside brackets means:

```text
NOT
```

So:

```lex
[^*]
```

means:

```text
Any character except *
```

Examples:

```text
a
b
1
?
space
/
```

match.

Example:

```text
*
```

does NOT match.

---

## B

```lex
\*+[^*/]
```

Let's split again.

### `\*+`

Means:

```text
one or more *
```

Examples:

```text
*
**
***
****
```

---

### `[^*/]`

Means:

```text
any character except
*
or
/
```

Examples:

```text
a
b
1
?
```

match.

Examples:

```text
*
/
```

do not match.

---

### Together

```lex
\*+[^*/]
```

means:

```text
one or more stars
followed by something
that is NOT *
and NOT /
```

Examples:

```text
*a
**b
***c
```

match.

Examples:

```text
*/
```

do NOT match.

This is important because:

```text
*/
```

is the end of the comment.

---

# Why the OR ?

```lex
([^*]|\*+[^*/])
```

means:

```text
Either:

a normal character that isn't *

OR

some * characters that are NOT ending the comment
```

---

# Why the \* outside?

```lex
([^*]|\*+[^*/])*
```

means:

```text
repeat zero or more times
```

So Lex keeps consuming:

```text
hello
abc
***
text
123
```

inside the comment.

---

# Part 3

```lex
\*+
```

Means:

```text
one or more *
```

Examples:

```text
*
**
***
```

---

# Part 4

```lex
"/"
```

Matches:

```text
/
```

Together:

```lex
\*+"/"
```

means:

```text
*/
```

or

```text
**/
```

or

```text
***/
```

etc.

In practice it recognizes the closing comment.

---

# Example Walkthrough

Input:

```c
/* hello */
```

### Step 1

```lex
"/*"
```

matches:

```text
/*
```

---

### Step 2

```lex
([^*]|\*+[^*/])*
```

matches:

```text
 hello
```

---

### Step 3

```lex
\*+"/"
```

matches:

```text
*/
```

Done.

---

# Easier Way to Remember

The entire regex:

```lex
"/*"([^*]|\*+[^*/])*\*+"/"
```

means:

```text
Start with /*

Consume everything inside

Do not accidentally stop
until the real */

is found
```

---

# Exam-Friendly Explanation

You can write:

```text
"/*"
```

→ matches beginning of comment.

```text
[^*]
```

→ matches any character except `*`.

```text
\*+[^*/]
```

→ matches one or more `*` not followed by `/`, so it doesn't terminate the comment.

```text
*
```

→ repeat zero or more times.

```text
\*+"/"
```

→ matches the closing `*/`.

Therefore the whole expression matches a C-style multi-line comment from `/*` to `*/`.

## 2. `fprintf`

```c
fprintf(out, "hello %s\n", yytext);
fprintf(stdout, "hello\n");
fprintf(stderr, "error!\n");
```

**What it does:** Same as printf but prints to a **specific file or stream** you give it

**When to use:** When you want to write to `output.txt` or any file — this is what you use in almost every lex file program

**Why use it:** Because you can direct output anywhere — a file, screen, or error stream

**Key difference from printf:**

```c
printf("hi\n");           /* always goes to screen */
fprintf(stdout, "hi\n"); /* same as printf */
fprintf(out, "hi\n");    /* goes to your file */
fprintf(stderr, "hi\n"); /* goes to error stream */
```

---

## 3. `putchar`

```c
putchar('A');
putchar(yytext[0]);
```

**What it does:** Prints exactly **one single character** to the screen

**When to use:** When you have a single character to print and do not need formatting

**Why use it:** Simpler and slightly faster than printf for one character — commonly used in lex when the `.` rule matches one character at a time

**Equivalent to:**

```c
putchar(yytext[0]);
printf("%c", yytext[0]);   /* both do the same thing */
```

---

## 4. `fputc`

```c
fputc('A', out);
fputc(yytext[0], out);
fputc('\n', out);
```

**What it does:** Writes exactly **one single character** to a **specific file**

**When to use:** When you want to write one character to your output file — used in lex when the `.` rule matches one character and you want it in the file

**Why use it:** Like putchar but for files instead of screen

**Equivalent to:**

```c
fputc(yytext[0], out);
fprintf(out, "%c", yytext[0]);  /* both do the same thing */
```

# What is atof and atoi

These are C library functions used to convert strings into numbers.

You need:

```c
#include <stdlib.h>
```

---

## `atoi()` — ASCII to Integer

Converts a string to an integer.

### Syntax

```c
int atoi(const char *str);
```

### Use in Lex

```lex
[0-9]+
{
    int n = atoi(yytext);
    printf("Integer = %d\n", n);
}
```

If input is:

```text
456
```

then:

```c
atoi("456")
```

returns:

```text
456
```

---

## `atof()` — ASCII to Float

Converts a string to a floating-point number.

### Syntax

```c
double atof(const char *str);
```

### Use in Lex

```lex
[0-9]+\.[0-9]+
{
    double x = atof(yytext);
    printf("Float = %f\n", x);
}
```

Input:

```text
3.14
```

Output:

```text
Float = 3.140000
```

---

## Easy Way to Remember

| Function | Full Form        | Converts          |
| -------- | ---------------- | ----------------- |
| `atoi()` | ASCII to Integer | `"123"` → `123`   |
| `atof()` | ASCII to Float   | `"3.14"` → `3.14` |
