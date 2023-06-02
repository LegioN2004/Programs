# First java program input/output debugging and datatypes

- [structure of a java file](#structure-of-a-java-file)
  - [explanation of the main.java file](#exp)
        - [**_all about the function_**](#all-about-the-function)
        - [**_then rest of the code explanation_**](#then-rest-of-the-code-explanation)
        - [**_how to run_**](#how-to-run)
    - [All about the datatypes](#all-about-the-datatypes)
    - [explanation for the inputs.java file (some are in the file itself)](#explanation-for-the-inputsjava-file-some-are-in-the-file-itself)
- [explanation for the sum2nos.java file (some are in the file itself)](#explanation-for-the-sum2nosjava-file-some-are-in-the-file-itself)
  - [TypeCasting and TypeConversion](#typecasting-and-typeconversion)
- [explanation of the summary.java file (summary of the whole video)](#explanation-of-the-summaryjava-file-summary-of-the-whole-video)
- [explanation of the Basics.java file ( summary of the whole video )](#explanation-of-the-basicsjava-file--summary-of-the-whole-video)
- [misc stuff](#misc-stuff)

## structure of a java file

- Name: every file that ends with an extensions .java is a class itself; eg: main.java
    1. since it's name is main.java(or some name before ____.java) it should contain a public main class with that name (as in before the extension) in the file itself
    2. all the code that we'll be writing will be in this class main/name
- The Class in the name: remember if a variable name starts with a capital letter then it is a class name (by convention)
    1. If the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type , public class means that this class will be accessible by all other files , classes, etc.
    2. Like cpp , java also has a main function (by convention) from where the program starts , whenever we run the program the compiler will look for main , if it is not present then the compiler will throw error.
    3. You can run with the java compiler " javac _name-of-file_.java " and then java "_class-name-of-that-file_" (where name is the class (public) as well as the file name) but now it seems to work only for ide's so go for java then filename , also while running the executable(class file) with java you can use the class name only.

## explanation of the main.java file

``` java
    public class main { // inside this block of {} is the int main of java as found in cpp
        public static void main(String[] args) {
            System.out.println("hello world!!");
        }
}
```

Here class is name group of properties and functions , in the above eg's class we have this function

### **all about the functions**

1. All the functions that are in the classes are knows as methods.
2. Also the function name has to be main only like here `public static void main(String[] args)` it is reserved to be there, if it is not `main` it will not run since `main` function is the entry point of the function.
    - Function is a block/collection of code which can be used again and again.

### **then rest of the code explanation**

1. Here public means the same as in the class name part `public static void main(String[] args)` since `main` is necessary to run the program so it makes sense to make it available to be executed from anywhere i.e of the `public` class type , if we make it `private` then it will not be available like the `public` class and hence it will not be valid.
2. Meaning of `static`: this main function/method is a part of the `Main` class also main is required to be run without creating an object of this `main` class ,so we use the `static` type . Since nothing is running before the `main()` function then there is no use of making an object there.
3. `Static` variables and functions are the variables and functions that don't depend on the object.
4. `void` is the return type of the function, since we don't want any value here so we have used void(like in cpp).

### **how to run**

1. `(String[] args)` are the arguments , collection of strings.
2. Here args is the arguments given in the terminal with java command (like java Main 50 100 ..... ) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array.
3. If you use `javac -d directory file` this -d flag is used to give a directory to store the .class file.
4. Package is the folder where the java file will lie, eg `package com.kunal` , this `com.kunal` is a subfolder in the com folder (you can make more of those subfolders) , `.` period means subfolder.
5. Then comes = `System.out.println`("hello world!!"); this line means (`System.out`) in the command line do a (.print(_string_)) this prints a string in the command line, if we use ctrl/cmd+click on this we get.

    ``` java
        /****
         ** Prints a String and then terminate the line.  This method behaves as
            ** though it invokes {@link #print(String)} and then
            ** {@link #println()}.
            **
            ** @param x  The {@code String} to be printed.
            **/
        public void println(String x) {
            if (getClass() == PrintStream.class) {
                writeln(String.valueOf(x));
            } else {
                synchronized (this) {
                    print(x);
                    newLine();
                }
            }
        }
    ```

6. To print stuff we have the _`System`_ class , it is in file called `System.java`(since System starts with a capital letter hence we know it is a class) in the java.lang package. All the stuff available in the lang package can be accessed in the files created by the people who made java

7. `_println_` in the above src says that you will give a string and it'll print that string

8. `_out_` is a variable contained in the System class, it is basically a type of `PrintStream`(will be expained later), and `PrintStream` has something called println. out is like a reference variable for `PrintStream` and by default value of the standard output stream i.e the out is the commandline i.e laptop (idk what that means) or the place where the output will be shown, out's original value is null (like this here) `public static final PrintStream out = null;` which means that the output will be in the commandline but if we declare out = _`some file or anything`_ then it will take the output of that `println` into that file or something

9. So it means `System` has a variable called out which is of type `PrintStream` and this out has a method/function called `println`, since out is of type `PrintStream` so `println` is also in `PrintStream` : in the standard output stream print something

10. **_NOTE_** some of the reference  which can be added to the code itself instead of here are done in the file mentioned here

11. for _`input`_ in Main.java the code: `Scanner input = new Scanner(System.in);`  _`Scanner`_ is a public class (it allows us to take input in simple sense) which is a simple text scanner which can parse primitive types and strings using regular expressions, then the _`input`_ is a normal declared variable and by using `Scanner` , this input will read everything we want ,then we add a new object i.e 'new' which is a keyword then `Scanner()`, in the brackets here we need to pass from where we will pass the input (can be a file or keyboard), we pass the `System.in` which is used to pass standard input or output (_`.in`_ part refers to the keyboard input) also the default value of `System.in` is null we can also define it to be something else . `Object` is a type of `Scanner` and it has a value of `System.in` whenever input asks for something you will take the value from the keyboard this is the meaning ; again scanner is basically a class that specifies an input stream and using the variable (object) of the class we can take input.
    **also look for the main documentation in the IntellijIdea by ctrl+click**
    - better explanation of the **`System`** class: The System class contains several useful class fields and methods. It cannot be instantiated. Among the facilities provided by the `System` class are standard input, standard output, and error output streams; access to externally defined properties and environment variables; a means of loading files and libraries; and a utility method for quickly copying a portion of an array.
    - and of the **`.in`** part: The "standard" input stream. This stream is already open and ready to supply input data. Typically this stream corresponds to keyboard input or another input source specified by the host environment or user. In case this stream is wrapped in a `java.io.InputStreamReader`, `Console.charset()` should be used for the charset, or consider using `Console.reader()`.

12. Regarding the new keyword , it is used to

13. Every class in java extends the object class , eg: Scanner ; important concept

14. about the different next( ,Int,ln) variants

``` java
    System.out.println(input.nextInt()); // = nextInt prints the integer output
    System.out.println(input.next()); // = next prints the first string(/word) of a sentence of the input in the output
    System.out.println(input.nextln()); // = nextln prints the whole string of a sentence of the input in the output
```

- **_input is a variable pointing to the object of scannner class so it'll contain all the functions provided by the scanner class ; whatever input will be given it will be shown in output_**

## All about the datatypes

- Primitive data types are the ones which cannot be further broken into other datatypes . eg: "Kunal" this word can be further divided into individual letters i.e the `string` can be divided into `char` , but the `char` cannot be further divided into other data types, this last datatype which cannot be divided into further data type is known as primitive

- **NOTE** To know why we are adding 'f' to `float` and 'L' to `long` at their respective end of the data type declaration value , we need to know the size of the bitwise operators ( also the range of them will be in the bitwise operators ),
      - for now the size are = `int` and `float` has '4 bytes', `double` and `long` has '8 bytes'.
    1. All the decimal values are of the type _`double`_ by default so if there is a need to store them in float then we need to add an 'f' (remember lower case f only) after the end of the value
        - **as to why use double instead of `float` = `float` gives floating point errors sometimes by rounding off numbers, so to get more accurate value we use `double`**
        - also we can  store larger decimal values using the `double` type

    2. And the by default declaration type of `integer` values is _`int`_ so we use 'L' (remember upper case L only) at the end of the `long` type,
        - **why use long instead of int: because it can store more/long integer values**

- There contains a class for every data type known as 'wrapper classes' for giving additional funtionality to the primitive datatypes, and they are written as

``` java
    Integer rollno = 8;
    String name = "tera baap hu";
```

   1. as you can see it contains the capital first letter which by convention means classes so all the other datatypes are written like the above example ( more on that later on OOPs )

   2. how to `_comment_`  you can add single line comments using &ldquo;/&rdquo; and multi line comments using the following

   ``` java
    /** this is a multi line
    comment
    **/
   ```

## explanation for the inputs.java file (some are in the file itself)

- You can use debugging to see how each line is executed one by one, also add breakpoints to make sure which lines you want to debug
- About literals and identifiers:

    ``` java
       int a = 10;
    ```

  - here 10 is a _`literal`_ so in primitive datatypes literals are the syntactical representation of datatypes, i.e it can be used to represent specific values of a datatype and
  - and 'a', the '_reference variable_' is known as the '_identifier_' so it's basically the name of the identifier, variable, class, packages, or other stuff like interfaces in java, etc

- `int` values can be given in a long form by adding some underscores (eg 100_100_09707) which gets ignored while running
- `nextFloat()` takes `float` values, just like that you can end the after next ___ underline part with the datatype which you want to get some input about, see completion for some help
- '+' is used to join the sentences or strings together in "" as well as with the value of the variable ( as shown in the sum2nos.java file )

## explanation for the sum2nos.java file (some are in the file itself)

``` java
    public static void main(String[] args){
        Scanner num = new Scanner(System.in);
        float input = num.nextFloat();
        System.out.println(input);
    }
```

### TypeCasting and TypeConversion

- When we give int values in float datatype and after getting the output we see the result as 105.0 ( for c = 5).Because the int input is being converted to float, this is auto type conversion.

- So when one type of data is assigned to another type of variable, then **auto type conversion** will take place if the following conditions are met
    1. the two types should be compatible, for ex = `int` and `float`, etc.
    2. the destination type should be greater than the source type be it in the declaration value or the input value, for ex = here `int` is smaller than `float` so `float` converts to `int` but vice versa is false. Asking for `int` but giving float won't work since `int` < `float`.
    3. Java does auto type conversion when it stores an integer constant into a variable of types like `byte`,`short`, `long`, and `char` sometimes takes the **_ascii value_** of that.
    4. **So how to convert `int` to `float`** - this is known as _typecasting_ or _casting_ in compatible types. It is used as the auto type conversion is helpful but it might not fulfill all the needs, for example - if you want to assign an `integer` variable to a `byte` variable or a `float` value to an `integer` variable(this will not happen auto, since they are greater than the other). This is sometimes called **narrowing conversion** since it tells the `float` value to narrow down the `float` value to `integer`
        - It is done as in the following block of code . It is compressing a bigger number into a smaller type explicitly, it says convert it into an integer hence the decimal part will get removed. The following is in the case of integers

        ``` java
                int num = (int)(89.5f);
        ```

        - Also if a datatype can't handle the value as given to it, then it will print the modulo of the given value to the one that it can store. eg = for a given value 257 to `byte` , it will give '257 % 256 = _1_'
    5. In the following code block, the byte format is converted to the `int` type first due to the following reasons

        ``` java
            byte a = 40;
            byte b = 50;
            byte c = 100;
            int d = (a ** b) / c;
        ```

        - In the code provided above, the expressions a _b and (a_ b) / c involve operands of type byte. However, the result of these expressions is automatically promoted to type `int` before being assigned to the variable d. This is because the Java language specifies that arithmetic operations involving `byte`, `short`, or `char` operands are performed using `int` arithmetic, and the result is automatically promoted to type `int`.

        - So, in the line `int d = (a * b) / c;`, the expression (a * b) is evaluated first, and the result of this expression is an `int` value, since the operands a and b are promoted to type `int` before the multiplication is performed. The result of this multiplication, which is 2000, is then divided by the byte value 100, resulting in an `int` value of 20.

        - The result of the expression (a * b) / c is an `int` value, and this value is assigned to the `int` variable d. The fact that d is declared as an `int` does not affect the promotion of the `byte` operands to int before the arithmetic operations are performed.

        - So, the value of d is 20, which is an `int` value. The fact that a, b, and c are declared as byte variables does not affect the type of the result, which is automatically promoted to `int`.
    6. In the code `int number = 'A';`, it converts the `int` type to the `ascii` value equivalent, so the this is also an example of the auto type conversion
    7. java following unicode principles, so any type of language/emoji/other unicode characters can be printed using java

- Rules for the type conversion

    1. all the `byte`, `short` and `character` are promoted to `integer` types
    2. if any one of the operands (i.e + / - / division/ x ) has the `long` type then the whole operation will be promoted to `long`, if it is `float` then the whole operation will be promoted to `float`, and if `double` then it will be promoted to `double`.
        eg : `System.out.println(3 * 5.620389472987f);` // prints output 16.861168 (since the f flag is added after the decimal number so it'll print float value so the value is rounded off, but if f flag is not given then the output will not be rounded off since it is double by default)

## explanation of the summary.java file (summary of the whole video)

``` java
    double result = (f ** b) + (i / c) - (d - s); // two individual results of the operations
    System.out.println((f ** b) + " " + (i / c) + " " + (d - s));
    System.out.println(result); // main output
```

- here the `float`, `byte`, `integer`, `char`, `double`, `short` are declared and the result stores the value of the operation, first `System.out` prints the individual results of the operations separated by '+' and '-' and then the next `System.out` prints the total result of the whole
  - here in (f * b) prints the biggest of the two, so the `float` value is printed
  - here in (i / c) prints the biggest of the two, so the `int` value is printed
  - here in (d - s) prints the biggest of the two, so the `double` value is printed
  - **here** in short the `if` we have multiple types then all the others are converted to the biggest one
    in the main output , we got `float + int - double = double` we see that the result gets converted to `double` i.e the biggest one.

## explanation of the Basics.java file ( summary of the whole video )

- exp of `if` condition is in the file itself
- exp of `while` condition is in the file itself
- when you don't know how many times the loop is going to run use the `while` loop
- when you know how many times the loop is going to run use the `for` loop

## misc stuff

- the assignment operator uses '=' sign whereas the equals operator uses '=`' sign
- don't use the if-else statments to run a loop(it is too complicated), you will need to use recursive concept with a for loop, too much for a beginner.
- while loop runs the whole code block until the conditional test(the condition written in the braces) remains true and doesn't become false.
- use this to give a input string to a variable  `string a = x.next();` i.e use _`next()`_.
- In Java, the '==' operator checks for reference equality for objects, which means it checks if two object references point to the same memory location, not the content equality of strings. To check if two strings have the same content, you should use the `.equals()` method instead.
- **NOTE** regarding the + string concatenation (joining)
  String concatenation using + in a loop in Java is a bad practice because it can lead to performance and memory issues. Strings are immutable in Java, which means that once a string is created, it cannot be changed. When you concatenate strings using +, a new string object is created for each concatenation operation. This can lead to a lot of unnecessary object creation, which can impact performance and memory usage.A better way to concatenate strings in a loop is to use a `StringBuilder` object. A `StringBuilder` is a mutable string object that can be changed after it is created. This means that you can concatenate strings to a `StringBuilder` object without creating a new object for each concatenation operation. This can improve performance and memory usage.
