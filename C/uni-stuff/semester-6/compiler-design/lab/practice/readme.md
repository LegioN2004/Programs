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
