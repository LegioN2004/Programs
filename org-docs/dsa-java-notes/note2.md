
# Table of Contents

1.  [structure of a java file](#org9efbf65)
    1.  [every file that ends with an extensions .java is a class itself; eg: main.java](#orgacd93df)
    2.  [since it&rsquo;s name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself](#org0f94c15)
    3.  [all the code that we&rsquo;ll be writing will be in this class main/name](#orgc4601ab)
    4.  [remember if a variable name starts with a capital letter then it is a class name (by convention)](#org7e216e5)
    5.  [if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type](#org9b40821)
    6.  [public class means that this class will be accessible by all other files , classes, etc](#orga22fde6)
    7.  [like cpp , java also has a main function (by convention) from where the program starts , whenever we run the program the compiler will look for main , if it is not present then the compiler will throw error](#org8c9d671)
        1.  [function is a block/collection of code which can be used again and again](#org4e50d0c)
    8.  [you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run](#org7a97db6)
    9.  [explanation of the main.java file](#org67873dd)
    10. [here class is name group of properties and functions , in the above eg&rsquo;s class we have this function](#orga38282a)
    11. [all the functions that are in the classes are knows as methods](#orge91c68c)
        1.  [also the function name has to be main only like here &ldquo; public static void main(String[] args) &rdquo; it is reserved to be here if it is not main it will not run](#org3fdc6a8)
    12. [since main function is the entry point of the function](#orgf36a80d)
    13. [here public means the same as in the class name part &ldquo; public static void main(String[] args) &rdquo; since main is necessary to run the program so it makes sense to make it available to be executed from anywhere i.e public class type , if we make it private then it will not be available like the public class and hence it will not be valid](#org8382226)
    14. [here static means:this main function/method is a part of the -Main- class also main is required to be run without creating an object of this Main class ,so we use the static type . Since nothing is running before the main() function then there is no use of making an object there](#orgf461d2f)
        1.  [so static variables and functions are the variables and functions that don&rsquo;t depend on the object](#orgcdd35c3)
    15. [void is the return type of the function, since we don&rsquo;t want any value here so we have used void(like in cpp)](#org2a8a471)
    16. [(String[] args) are the arguments , collection of strings](#orgc442c4a)
        1.  [here args is the arguments given in the terminal with java command (like java Main 50 100 &#x2026;) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array](#org2a2fc92)
    17. [if you use javac -d <span class="underline">directory</span> <span class="underline">name</span>: this -d flag is used to give a directory to store the .class file](#org3ea68b3)
    18. [package is the folder where the java file will lie, eg package com.kunal , this com.kunal is a subfolder in the com folder (you can make more of those subfolders) , &rsquo;.&rsquo; period means subfolder](#orgc15d193)
    19. [then comes = System.out.println(&ldquo;hello world!!&rdquo;); = this prints a string , if we use ctrl/cmd+click on this we get](#org2cb7f70)
        1.  [to print stuff we have the <span class="underline">System</span> class , it is in file called System.java(since System starts with a capital letter hence we know it is a class) in the java.lang package. All the stuff available in the lang package can be accessed in the files created by the people who made java](#orgc5817bd)
        2.  [<span class="underline">println</span> in the above src says that you will give a string and it&rsquo;ll print that string](#org6f51cde)
        3.  [<span class="underline">out</span> is a variable contained in the System class, it is basically a type of PrintStream(will be expained later), and PrintStream has something called println. out is like a reference variable for PrintStream and by default value of the standard output stream i.e the out is the commandline i.e laptop (idk what that means) or the place where the output will be shown, out&rsquo;s original value is null (like this here) = public static final PrintStream out = null; which means that the output will be in the commandline but if we declare out = <span class="underline">some file or anything</span> then it will take the output of that println into that file or something](#orgbabd0af)
        4.  [## so it means System has a variable called out which is of type PrintStream and this out has a method/function called println, since out is of type PrintStream so println is also in PrintStream : in the standard output stream print something](#org6e0ba48)
    20. [**NOTE** some of the reference  which can be added to the code itself instead of here are done in the file mentioned here](#org39de136)
        1.  [for input in Main.java the code: ~ Scanner input = new Scanner(System.in); ~  Scanner is a public class (it allows us to take input in simple sense) which is a simplet text scanner which can parse primitive types and strings using regular expressions, then the input is a variable and by using Scanner , this input will read everything we want ,then we add a new object i.e &rsquo;new&rsquo; which is a keyword then Scanner(), in the brackets here we need to pass from where we will pass the input (can be a file or keyboard) (the standard input System.in refers to the keyboard input) also the default value of System.in is null we can also define it to be something else . object is a type of scanner and it has a value of System.in whenever input asks for something you will take the value from the keyboard this is the meaning ; again scanner is basically a class that specifies an input stream and using the variable (object) of the class we can take input](#org898c538)



<a id="org9efbf65"></a>

# structure of a java file


<a id="orgacd93df"></a>

## every file that ends with an extensions .java is a class itself; eg: main.java


<a id="org0f94c15"></a>

## since it&rsquo;s name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself


<a id="orgc4601ab"></a>

## all the code that we&rsquo;ll be writing will be in this class main/name


<a id="org7e216e5"></a>

## remember if a variable name starts with a capital letter then it is a class name (by convention)


<a id="org9b40821"></a>

## if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type


<a id="orga22fde6"></a>

## public class means that this class will be accessible by all other files , classes, etc


<a id="org8c9d671"></a>

## like cpp , java also has a main function (by convention) from where the program starts , whenever we run the program the compiler will look for main , if it is not present then the compiler will throw error


<a id="org4e50d0c"></a>

### function is a block/collection of code which can be used again and again


<a id="org7a97db6"></a>

## you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run


<a id="org67873dd"></a>

## explanation of the main.java file

    public class main { // inside this block of {} is the int main of java as found in cpp
        public static void main(String[] args) {
            System.out.println("hello world!!");
        }
    }


<a id="orga38282a"></a>

## here class is name group of properties and functions , in the above eg&rsquo;s class we have this function

    public static void main(String[] args) {
        System.out.println("hello world!!");
    }


<a id="orge91c68c"></a>

## all the functions that are in the classes are knows as methods


<a id="org3fdc6a8"></a>

### also the function name has to be main only like here &ldquo; public static void main(String[] args) &rdquo; it is reserved to be here if it is not main it will not run


<a id="orgf36a80d"></a>

## since main function is the entry point of the function


<a id="org8382226"></a>

## here public means the same as in the class name part &ldquo; public static void main(String[] args) &rdquo; since main is necessary to run the program so it makes sense to make it available to be executed from anywhere i.e public class type , if we make it private then it will not be available like the public class and hence it will not be valid


<a id="orgf461d2f"></a>

## here static means:this main function/method is a part of the -Main- class also main is required to be run without creating an object of this Main class ,so we use the static type . Since nothing is running before the main() function then there is no use of making an object there


<a id="orgcdd35c3"></a>

### so static variables and functions are the variables and functions that don&rsquo;t depend on the object


<a id="org2a8a471"></a>

## void is the return type of the function, since we don&rsquo;t want any value here so we have used void(like in cpp)


<a id="orgc442c4a"></a>

## (String[] args) are the arguments , collection of strings


<a id="org2a2fc92"></a>

### here args is the arguments given in the terminal with java command (like java Main 50 100 &#x2026;) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array


<a id="org3ea68b3"></a>

## if you use javac -d <span class="underline">directory</span> <span class="underline">name</span>: this -d flag is used to give a directory to store the .class file


<a id="orgc15d193"></a>

## package is the folder where the java file will lie, eg package com.kunal , this com.kunal is a subfolder in the com folder (you can make more of those subfolders) , &rsquo;.&rsquo; period means subfolder


<a id="org2cb7f70"></a>

## then comes = System.out.println(&ldquo;hello world!!&rdquo;); = this prints a string , if we use ctrl/cmd+click on this we get

    /**
     * Prints a String and then terminate the line.  This method behaves as
     * though it invokes {@link #print(String)} and then
     * {@link #println()}.
     *
     * @param x  The {@code String} to be printed.
     */
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


<a id="orgc5817bd"></a>

### to print stuff we have the <span class="underline">System</span> class , it is in file called System.java(since System starts with a capital letter hence we know it is a class) in the java.lang package. All the stuff available in the lang package can be accessed in the files created by the people who made java


<a id="org6f51cde"></a>

### <span class="underline">println</span> in the above src says that you will give a string and it&rsquo;ll print that string


<a id="orgbabd0af"></a>

### <span class="underline">out</span> is a variable contained in the System class, it is basically a type of PrintStream(will be expained later), and PrintStream has something called println. out is like a reference variable for PrintStream and by default value of the standard output stream i.e the out is the commandline i.e laptop (idk what that means) or the place where the output will be shown, out&rsquo;s original value is null (like this here) = public static final PrintStream out = null; which means that the output will be in the commandline but if we declare out = <span class="underline">some file or anything</span> then it will take the output of that println into that file or something


<a id="org6e0ba48"></a>

### ## so it means System has a variable called out which is of type PrintStream and this out has a method/function called println, since out is of type PrintStream so println is also in PrintStream : in the standard output stream print something


<a id="org39de136"></a>

## **NOTE** some of the reference  which can be added to the code itself instead of here are done in the file mentioned here


<a id="org898c538"></a>

### for input in Main.java the code: ~ Scanner input = new Scanner(System.in); ~  Scanner is a public class (it allows us to take input in simple sense) which is a simplet text scanner which can parse primitive types and strings using regular expressions, then the input is a variable and by using Scanner , this input will read everything we want ,then we add a new object i.e &rsquo;new&rsquo; which is a keyword then Scanner(), in the brackets here we need to pass from where we will pass the input (can be a file or keyboard) (the standard input System.in refers to the keyboard input) also the default value of System.in is null we can also define it to be something else . object is a type of scanner and it has a value of System.in whenever input asks for something you will take the value from the keyboard this is the meaning ; again scanner is basically a class that specifies an input stream and using the variable (object) of the class we can take input

1.  every class in java extends the object class , eg: Scanner ; important concept

        System.out.println(input.nextInt()); //whatever input we got , it is passed into the print statement

2.  input is a variable pointing to the object of scannner class so it&rsquo;ll contain all the functions provided by the scanner class ; whatever out will be given by the input it will be shown in output

