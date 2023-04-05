# Table of Contents

1.  [#more things to be added#](#orgd3c3523)
2.  [stack and heap memory](#orgc48cc28)
    1.  [for example: a = 10](#org843acf5)
        1.  [a (reference variable) is stored in stack memory of the above example .](#org3183c22)
        2.  [heap memory is where 10 (object) is stored of the above example .](#org7d9f662)
        3.  [And a is only pointing to that object in heap memory but 10 is the actual value, pointing to the address of 10 in the memory(in computer)](#org61137d1)
        4.  [when an object with no reference variable is found then it is removed from the memory using garbage collection (it happens automatically) all the objects](#org08c18fa)
3.  [intro to java](#org881bdb9)
    1.  [how java code executes](#org89e29bb)
        1.  [.java file has the source code which is in the human readable format](#orgcfffea1)
        2.  [it gets into the compiler and converts the entire file to .class format](#org83d265f)
        3.  [.class (which is a BYTE CODE) is a file which is a java intermediary language / something else in the java stuff](#org2182caf)
        4.  [then the interpreter(line by line) converts it into machine code](#org2f1faf8)
    2.  [JDK vs JRE vs JVM vs JIT](#orgbd466d0)
        1.  [JDK is java dev kit , it consists of JRE + Dev tools](#org965953f)
        2.  [JRE is java runtime environment, it consists of JVM + library classes](#org4581d86)
        3.  [JVM is java virtual machine it consists of JIT just in time compiler](#org637f73a)

<a id="orgd3c3523"></a>

# #more things to be added#

<a id="orgc48cc28"></a>

# stack and heap memory

<a id="org843acf5"></a>

## for example: a = 10

<a id="org3183c22"></a>

### a (reference variable) is stored in stack memory of the above example .

<a id="org7d9f662"></a>

### heap memory is where 10 (object) is stored of the above example .

<a id="org61137d1"></a>

### And a is only pointing to that object in heap memory but 10 is the actual value, pointing to the address of 10 in the memory(in computer)

1.  1. more than 1 reference variables can point to the same object

2.  2. if original object is changed by a reference variable then it will be reflected to all the other variables

<a id="org08c18fa"></a>

### when an object with no reference variable is found then it is removed from the memory using garbage collection (it happens automatically) all the objects

<a id="org881bdb9"></a>

# intro to java

<a id="org89e29bb"></a>

## how java code executes

<a id="orgcfffea1"></a>

### .java file has the source code which is in the human readable format

<a id="org83d265f"></a>

### it gets into the compiler and converts the entire file to .class format

<a id="org2182caf"></a>

### .class (which is a BYTE CODE) is a file which is a java intermediary language / something else in the java stuff

1.  it doesn't run in directly on a system

2.  it needs a jvm(Java virtual machine) to run

3.  it is the reason why Java is platform independent

    1.  note jvm is platform dependent we need to execute the .class file again in different platform using the platform dependent jvm

    2.  this bytecode can run on any machine , the executable is dependent in platform and architecture

<a id="org2f1faf8"></a>

### then the interpreter(line by line) converts it into machine code

1.  interpreter compiles the file line by line eg python which is a interpreted language can be excuted line by line

<a id="orgbd466d0"></a>

## JDK vs JRE vs JVM vs JIT

<a id="org965953f"></a>

### JDK is java dev kit , it consists of JRE + Dev tools

1.  provides package to run and develop java program

2.  it is a package that includes

    1.  dev tools = to provide an environment to develop your program
    2.  JRE = to execute your program
    3.  javac = a java compiler
    4.  jar = java archiver
    5.  javadoc = doc generator
    6.  interpreter / loader

<a id="org4581d86"></a>

### JRE is java runtime environment, it consists of JVM + library classes

1.  It is an installation package that provides environment to only run the program . It consists of :-

    1.  Deployment technology
    2.  User interface toolkit
    3.  Integration libraries
    4.  Base libraries
    5.  JVM :- Java virtual Machine

    6.  After we get the .class file the next thing happen at runtime :

        1.  Class loader loads all classes needed to execute the program.
        2.  JVM sends code to bytecode verifier to check the format of code.

<a id="org637f73a"></a>

### JVM is java virtual machine it consists of JIT just in time compiler
