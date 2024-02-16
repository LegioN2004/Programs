# CS50 Week 1 C

## Introduction

- What does a C code look like

```c
#include <stdio.h>
#include <cs50.h>

int main(void) {
  printf("hello, world\n"); // \n is used to change the cursor to the next line commonly known as escape sequence
}
```

- Why are we using a cs50 specific header for C here because it provides user-friendly input which is highly recommended for people doing cs50 classes and if it includes C
- Some stuff to note:
  - Using the the printf function and it allows to format text on a screen
  - \n is one of the sequence of symbols that is used to move the cursor to the next line, it is commonly known as **escape sequence** and it is also used by python, etc other languages
  - Humans who designed c decided that the code, the string of text must always stay on the same line (be it very long), it can be soft wrapped without pressing enter but it you can't do something like pressing enter and then add the other line of code. And so if you want a new line in C you will have to use `\n` in the end of a line to get a new line
  - The first line `#include` imports stuff such as library, header files etc which are code written by someone else that gives/adds more functionality to our c file so as to get some work done, here in order to print stuff we used the printf function but it needs the `stdio.h` **_header file_** to work. Header file declares that function to exist and it is just for efficiency. This just tells the compiler that we need the functionality from the stdio.h header library including the printf function and omitting the header file won't work.
  - In C, we have the cs50.h library for CS50 learning
  - Input is one of the hard part in C lang and cs50.h provides some functions and it helps us to
  - In C, to get the return value from a function we need to be specific using a equal sign which is known as the assignment operator to a variable. So when we use a single equals in C it means copy the value on the right over to the value on the left. And then to reuse it we can copy it to a variable using the `=` operator and then we can use that value as we like. Also we'll need to tell the type of value we'll be storing in that so we use string as the type in front of that variable
  - Now to add the input to the output we will need to do something like `printf("hello, %s\n", answer);` and this is known as format code in C, and the `%s` means a _placeholder for a string_ (and `%` is treated specially as **placeholders** in printf functions in C and as such lots of problems arises due to that) it is treated specially to mean _plug in some value here_. By using the `answer` variable we just plug in the value of the answer variable and it just gets added in the sentence by using `%s`, we can add something after the value by adding it after the `%s` in the same line.
    - NOTE: the double quotes will still be there and a `\n` for the newline cursor but to add the value from the variable we'll need to add a comma after the quotes followed by the variable which needs to be added.
    - So the first `%s` plugs in the first value after the comma and if there are 2 vars then we'll need 2 `%s`es which will then be added to them one after another serially.
    - Remember the spaces between the `%s`es also apply on the real output, so if I don't add the spaces in between the `%s` then the two variable output will also not show any spaces between them (if intended).
    - Since `%` are treated as placeholders in printf functions and if we want to print `%`(for whatever reason) then we'll need to do something like `%%` - adding 2 percentages to show one `%` precentage symbol in C. But in the new compilers this error has been removed and instead we get a memory address(random number, kinda maybe) and if we don't add any text after that single percentage then we get a space and no error.
  - Also while using the keyword `if` we'll need to give spaces before starting the brackets for the conditions. But you shouldn't with `get_string`, etc. You don't neeed the curly braces when you have a single line inside of the curly braces of if or any conditional statements.
  - We should reduce logic wherever we find some inconsistencies.
  - `get_int("What's x? ");`(`get_int` - prompts user for a line of text from stdin and returns...) and this gets a return integer value but it must be stored in a var for usage and as such we declare a variable and initialize that var to it.
    - Takes input from the console like scanf but can also show a message with it.
    - **note**: A conventional practice if we have a simple program if we single variables is to use 'i' if we have 'int', 'c' if we have 'char', if its a 'string' it can be called 's' and so on.
  - `get_char` takes a single char as the input and does something with that.
- **note**: Convention for indenting in C is four spaces, (vscode will show four spaces as four dots).
- Conditionals: for loop (used more by programmers since it is more succinct), while loop. Also to run the loop forever, we can give the condition directly as true in the while loop to run the loop forever, since the condition expects a boolean input and true never to false. Also we can do something like addding 1 or 0 which the computer generally inteprets as true and false respectively. Any other non-zero value is interpreted as true.
  - So we have the `stdbool.h` header file which includes the boolean true/false keywords to the file we are working with.
- **const** keyword: It is a keyword in C and some other languages which doesn't allow to modify further down the line after it is once declared with this keyword in the starting.
