
# Table of Contents

1.  [complete git and github kunal kushwaha](#org888f49f)
    1.  [always use the name of the branch if you have multiple branches and you are creating files and pushing stuff and commits to a certain branch](#orgc40b4ef)
    2.  [upstream is the main repo from which the repo is forked for mods in my own account](#org7d139a4)
    3.  [syncing the forked repo&rsquo;s main with the upstream url repo&rsquo;s main if the forked repo&rsquo;s main branch is a few commits behind the upstream main due to merged commits from the forked repo&rsquo;s other branch](#org097f0bc)
        1.  [git fetch &#x2013;all &#x2013;prune](#orge7267fb)
        2.  [git reset &#x2013;hard upstream/main](#org8b0dcd6)
        3.  [upstream here pulls from the upstream url and main means from the main branch of the upstream url](#org8edbdc2)
        4.  [if you want to merge all the commits in one commit without doing a reset and then try git adding all the files aaaaaaand then commiting](#org706bffa)
2.  [#more things to be added#](#org20a5dfb)
3.  [stack and heap memory](#orgd56614a)
    1.  [for example: a = 10](#org4f60293)
        1.  [a (reference variable) is stored in stack memory of the above example .](#org318ec84)
        2.  [heap memory is where 10 (object) is stored of the above example .](#org0cb4e97)
        3.  [And a is only pointing to that object in heap memory but 10 is the actual value, pointing to the address of 10 in the memory(in computer)](#org89696e2)
        4.  [when an object with no reference variable is found then it is removed from the memory using garbage collection (it happens automatically) all the objects](#org24bda5e)
4.  [intro to java](#org806cb75)
    1.  [how java code executes](#org0c8ea68)
        1.  [.java  file has the source code which is in the human readable  format](#org6ae64a3)
        2.  [it gets into the compiler and converts the entire file to .class format](#org9ebd59c)
        3.  [.class (which is a BYTE CODE) is a file which is a java intermediary language / something else in the java stuff](#org54c0b4a)
        4.  [then the interpreter(line by line) converts it into machine code](#org39d8725)
    2.  [JDK vs JRE vs JVM vs JIT](#org01f02ec)
        1.  [JDK is java dev kit , it consists of JRE + Dev tools](#orgbf1a954)
        2.  [JRE is java runtime environment, it consists of JVM + library classes](#org6262d74)
        3.  [JVM is java virtual machine it consists of JIT just in time compiler](#org08b9e0e)
    3.  [how the all of the above works JDK, JRE, JVM, JIT](#org153bffb)
        1.  [at compile time [.java file] &#x2013;(javac compilation)&#x2013;&#x2014;> [.class file]](#org13f4a97)
        2.  [at runtime : class loader -> byte code verifier -> interpreter -> runtime -> hardware](#org1819a69)
    4.  [how everything points to work like that](#org6a03035)
        1.  [java source code -> JDK (has the javac compiler converts it into .class file) -> Bytecode -> JVM(converts the bytecode to an executable) -> JRE(then we run that executable in this)](#org3da6a3d)
5.  [structure of a java file](#orgedcb776)
    1.  [every file that ends with an extensions .java is a class itself; eg: main.java](#org13c05dc)
    2.  [since it&rsquo;s name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself](#org71c4bb1)
    3.  [all the code that we&rsquo;ll be writing will be in this class main/name](#orgd38fb97)
    4.  [remember if a variable name starts with a capital letter then it is a class name (by convention)](#orga9a815c)
    5.  [if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type](#orgcc5014b)
    6.  [public class means that this class will be accessible by all other files , classes, etc](#org1e9c985)
    7.  [like cpp , java also has a main function (by convention) from where the program starts , whenever we run the program the compiler will look for main , if it is not present then the compiler will throw error](#orga51c2e1)
        1.  [function is a block/collection of code which can be used again and again](#orgf34c14b)
    8.  [you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run](#orgda4d575)
    9.  [explanation of the main.java file](#org33f224b)
    10. [here class is name group of properties and functions , in the above eg&rsquo;s class we have this function](#org3558935)
    11. [all the functions that are in the classes are knows as methods](#org5c02ddd)
    12. [also the function name has to be main only #+begin<sub>src</sub> public static void main(String[] args) #+end<sub>src</sub>  it is reserved to be here if it is not main it will not run](#org38cb832)
    13. [here public means the same as in the class name part <s public static void main(String[] args) > since main is necessary to run the program so it makes sense to make it available to be executed from anywhere i.e public class type , if we make it private then it will not be available like the public class and hence it will not be valid](#org873f0d9)
        1.  [main function is the entry point of the function](#org36d5b54)
        2.  [here static means:this main function/method is a part of the -Main- class also main is required to be run without creating an object of this Main class ,so we use the static type . Since nothing is running before the main() function then there is no use of making an object there](#orgf4c9f4b)
        3.  [so static variables and functions are the variables and functions that don&rsquo;t depend on the object](#org5c1b75b)
        4.  [void is the return type of the function, since we don&rsquo;t want any value here so we have used void(like in cpp)](#org7e76768)
        5.  [(String[] args) are the arguments , collection of strings](#org70e9f36)
        6.  [here args is the arguments given in the terminal with java command (like java Main 50 100 &#x2026;) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array](#orga5585ee)
        7.  [javac -d <span class="underline">directory</span> <span class="underline">name</span>: this -d flag is used to give a directory to store the .class file](#org1b43399)
        8.  [package is the folder where the java file will lie, eg package com.kunal , this com.kunal is a subfolder in the com folder (you can make more of those subfolders) , &rsquo;.&rsquo; period means subfolder](#org96c1162)



<a id="org888f49f"></a>

# complete git and github kunal kushwaha


<a id="orgc40b4ef"></a>

## always use the name of the branch if you have multiple branches and you are creating files and pushing stuff and commits to a certain branch

---


<a id="org7d139a4"></a>

## upstream is the main repo from which the repo is forked for mods in my own account

---


<a id="org097f0bc"></a>

## syncing the forked repo&rsquo;s main with the upstream url repo&rsquo;s main if the forked repo&rsquo;s main branch is a few commits behind the upstream main due to merged commits from the forked repo&rsquo;s other branch


<a id="orge7267fb"></a>

### git fetch &#x2013;all &#x2013;prune

&#x2013;all &rsquo;here pulls all the branches , commits and other stuff created&rsquo;
&#x2013;prune &rsquo;here includes (fetches) the deleted stuff which &#x2013;all doesn&rsquo;t pull maybe&rsquo;


<a id="org8b0dcd6"></a>

### git reset &#x2013;hard upstream/main

this resets the origin/main branch of the forked repo with the upstream/main branch of the main repo so as to sync the repo fully

1.  then push in the origin/main branch in the local system or

2.  to reduce the 2 commands above you can use

    git pull upstream main


<a id="org8edbdc2"></a>

### upstream here pulls from the upstream url and main means from the main branch of the upstream url

1.  then you can push the changes to the origin/main branch so as to make the forked repo&rsquo;s main branch in sync with the upstream branch&rsquo;s main

    ---


<a id="org706bffa"></a>

### if you want to merge all the commits in one commit without doing a reset and then try git adding all the files aaaaaaand then commiting

1.  then use the &rsquo;git rebase -i <span class="underline">file</span>&rsquo; ( -i means interactive type i.e in nvim vim type and in the underline use the hash of the commit messaeg from the git log )

2.  you will get option pick and squash written in the front of the half hash of the file with the file names

3.  pick means taking the commit and squash/s means that it&rsquo;ll merge its commit( i.e the file where it is written as s ) from the bottom till the top until the first pick comes


<a id="org20a5dfb"></a>

# #more things to be added#


<a id="orgd56614a"></a>

# stack and heap memory


<a id="org4f60293"></a>

## for example: a = 10


<a id="org318ec84"></a>

### a (reference variable) is stored in stack memory of the above example .


<a id="org0cb4e97"></a>

### heap memory is where 10 (object) is stored of the above example .


<a id="org89696e2"></a>

### And a is only pointing to that object in heap memory but 10 is the actual value, pointing to the address of 10 in the memory(in computer)

1.  1. more than 1 reference variables can point to the same object

2.  2. if original object is changed by a reference variable then it will be reflected to all the other variables


<a id="org24bda5e"></a>

### when an object with no reference variable is found then it is removed from the memory using garbage collection (it happens automatically) all the objects


<a id="org806cb75"></a>

# intro to java


<a id="org0c8ea68"></a>

## how java code executes


<a id="org6ae64a3"></a>

### .java  file has the source code which is in the human readable  format


<a id="org9ebd59c"></a>

### it gets into the compiler and converts the entire file to .class format


<a id="org54c0b4a"></a>

### .class (which is a BYTE CODE) is a file which is a java intermediary language / something else in the java stuff

1.  it doesn&rsquo;t run in directly on a system

2.  it needs a jvm(Java virtual machine) to run

3.  it is the reason why Java is platform independent

    1.  note jvm is platform dependent we need to execute the .class file again in different platform using the platform dependent jvm
    
    2.  this bytecode can run on any machine , the executable is dependent in platform and architecture


<a id="org39d8725"></a>

### then the interpreter(line by line) converts it into machine code

1.  interpreter compiles the file line by line eg python which is a interpreted language can be excuted line by line


<a id="org01f02ec"></a>

## JDK vs JRE vs JVM vs JIT


<a id="orgbf1a954"></a>

### JDK is java dev kit , it consists of JRE + Dev tools

1.  provides package to run and develop java program

2.  it is a package that includes

    1.  dev tools = to provide an environment to develop your program
    2.  JRE = to execute your program
    3.  javac = a java compiler
    4.  jar = java archiver
    5.  javadoc = doc generator
    6.  interpreter / loader


<a id="org6262d74"></a>

### JRE is java runtime environment, it consists of JVM + library classes

1.  It is an installation package that provides environment to only run the program . It consists of :-

    1.  Deployment technology
    2.  User interface toolkit
    3.  Integration libraries
    4.  Base libraries
    5.  JVM :- Java virtual Machine
    
    1.  After we get the .class file the next thing happen at runtime :
    
        1.  Class loader loads all classes needed to execute the program.
        2.  JVM sends code to bytecode verifier to check the format of code.


<a id="org08b9e0e"></a>

### JVM is java virtual machine it consists of JIT just in time compiler


<a id="org153bffb"></a>

## how the all of the above works JDK, JRE, JVM, JIT


<a id="org13f4a97"></a>

### at compile time [.java file] &#x2013;(javac compilation)&#x2013;&#x2014;> [.class file]

1.  how jvm works
    -loading: reads .class file and generates binary data of , then object of the class is created in heap
    -linking: i. verifies the .class file | ii. allocates memory for the class variables and default values | iii. replaces symbolic references from the type with direct references (by replacing the variables and other stuff with the values directly)
    -initialization: all static variables are assigned with their values defined in the code and static block. static variables are those variables which do not depend on the object of the classes i.e object independent
                      jvm contains the stack and heap memory allocations , stack memory is created whenever a new program is run
2.  JVM execution
    Interpreter:
    -line by line execution (of the bytecode i.e the .class file)
    -when one method/function(block of code) is called many times it will interpret again and again (which is a limitation)
3.  JIT
    -those methods/functions that are repeated again and again , the jit directly provides the machine code once converted from the main code so that re-interpretation is not required and the code execution becomes a bit faster


<a id="org1819a69"></a>

### at runtime : class loader -> byte code verifier -> interpreter -> runtime -> hardware


<a id="org6a03035"></a>

## how everything points to work like that


<a id="org3da6a3d"></a>

### java source code -> JDK (has the javac compiler converts it into .class file) -> Bytecode -> JVM(converts the bytecode to an executable) -> JRE(then we run that executable in this)

here^^ somewhere lies the hardware


<a id="orgedcb776"></a>

# structure of a java file


<a id="org13c05dc"></a>

## every file that ends with an extensions .java is a class itself; eg: main.java


<a id="org71c4bb1"></a>

## since it&rsquo;s name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself


<a id="orgd38fb97"></a>

## all the code that we&rsquo;ll be writing will be in this class main/name


<a id="orga9a815c"></a>

## remember if a variable name starts with a capital letter then it is a class name (by convention)


<a id="orgcc5014b"></a>

## if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type


<a id="org1e9c985"></a>

## public class means that this class will be accessible by all other files , classes, etc


<a id="orga51c2e1"></a>

## like cpp , java also has a main function (by convention) from where the program starts , whenever we run the program the compiler will look for main , if it is not present then the compiler will throw error


<a id="orgf34c14b"></a>

### function is a block/collection of code which can be used again and again


<a id="orgda4d575"></a>

## you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run


<a id="org33f224b"></a>

## explanation of the main.java file

     public class main { // inside this block of {} is the int main of java as found in cpp
    	public static void main(String[] args) {
    		System.out.println("hello world!!");
    	}
    }


<a id="org3558935"></a>

## here class is name group of properties and functions , in the above eg&rsquo;s class we have this function

     public static void main(String[] args) {
    	System.out.println("hello world!!");
    }


<a id="org5c02ddd"></a>

## all the functions that are in the classes are knows as methods


<a id="org38cb832"></a>

## also the function name has to be main only #+begin<sub>src</sub> public static void main(String[] args) #+end<sub>src</sub>  it is reserved to be here if it is not main it will not run


<a id="org873f0d9"></a>

## here public means the same as in the class name part <s public static void main(String[] args) > since main is necessary to run the program so it makes sense to make it available to be executed from anywhere i.e public class type , if we make it private then it will not be available like the public class and hence it will not be valid


<a id="org36d5b54"></a>

### main function is the entry point of the function


<a id="orgf4c9f4b"></a>

### here static means:this main function/method is a part of the -Main- class also main is required to be run without creating an object of this Main class ,so we use the static type . Since nothing is running before the main() function then there is no use of making an object there


<a id="org5c1b75b"></a>

### so static variables and functions are the variables and functions that don&rsquo;t depend on the object


<a id="org7e76768"></a>

### void is the return type of the function, since we don&rsquo;t want any value here so we have used void(like in cpp)


<a id="org70e9f36"></a>

### (String[] args) are the arguments , collection of strings


<a id="orga5585ee"></a>

### here args is the arguments given in the terminal with java command (like java Main 50 100 &#x2026;) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array


<a id="org1b43399"></a>

### javac -d <span class="underline">directory</span> <span class="underline">name</span>: this -d flag is used to give a directory to store the .class file


<a id="org96c1162"></a>

### package is the folder where the java file will lie, eg package com.kunal , this com.kunal is a subfolder in the com folder (you can make more of those subfolders) , &rsquo;.&rsquo; period means subfolder

