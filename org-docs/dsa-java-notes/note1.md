# Table of Contents

1.  [#more things to be added#](#orgf588c1d)
2.  [stack and heap memory](#org177d3f0)
    1.  [for example: a = 10](#org6f0cdce)
        1.  [a (reference variable) is stored in stack memory of the above example .](#org9e86f44)
        2.  [heap memory is where 10 (object) is stored of the above example .](#org4dcb556)
        3.  [And a is only pointing to that object in heap memory but 10 is the actual value, pointing to the address of 10 in the memory(in computer)](#orgdc610a2)
        4.  [when an object with no reference variable is found then it is removed from the memory using garbage collection (it happens automatically) all the objects](#org6c6f3c3)
3.  [intro to java](#orgb512496)
    1.  [how java code executes](#org4db494d)
        1.  [.java file has the source code which is in the human readable format](#org5d3a030)
        2.  [it gets into the compiler and converts the entire file to .class format](#org0a5b956)
        3.  [.class (which is a BYTE CODE) is a file which is a java intermediary language / something else in the java stuff](#orgf6b7a6e)
        4.  [then the interpreter(line by line) converts it into machine code](#orgc2c9727)
    2.  [JDK vs JRE vs JVM vs JIT](#orgaf196a0)
        1.  [JDK is java dev kit , it consists of JRE + Dev tools](#orgcfccf07)
        2.  [JRE is java runtime environment, it consists of JVM + library classes](#org8bab48a)
        3.  [JVM is java virtual machine it consists of JIT just in time compiler](#org1072cc1)
    3.  [how the all of the above works JDK, JRE, JVM, JIT](#org83cdc1a)
        1.  [at compile time [.java file] &#x2013;(javac compilation)&#x2013;&#x2014;> [.class file]](#orgc74e0eb)
        2.  [at runtime : class loader -> byte code verifier -> interpreter -> runtime -> hardware](#org0ef9f3e)

<a id="orgf588c1d"></a>

# #more things to be added#

<a id="org177d3f0"></a>

# stack and heap memory

<a id="org6f0cdce"></a>

## for example: a = 10

<a id="org9e86f44"></a>

### a (reference variable) is stored in stack memory of the above example .

<a id="org4dcb556"></a>

### heap memory is where 10 (object) is stored of the above example .

<a id="orgdc610a2"></a>

### And a is only pointing to that object in heap memory but 10 is the actual value, pointing to the address of 10 in the memory(in computer)

1.  1. more than 1 reference variables can point to the same object

2.  2. if original object is changed by a reference variable then it will be reflected to all the other variables

<a id="org6c6f3c3"></a>

### when an object with no reference variable is found then it is removed from the memory using garbage collection (it happens automatically) all the objects

<a id="orgb512496"></a>

# intro to java

<a id="org4db494d"></a>

## how java code executes

<a id="org5d3a030"></a>

### .java file has the source code which is in the human readable format

<a id="org0a5b956"></a>

### it gets into the compiler and converts the entire file to .class format

<a id="orgf6b7a6e"></a>

### .class (which is a BYTE CODE) is a file which is a java intermediary language / something else in the java stuff

1.  it doesn't run in directly on a system

2.  it needs a jvm(Java virtual machine) to run

3.  it is the reason why Java is platform independent

    1.  note jvm is platform dependent we need to execute the .class file again in different platform using the platform dependent jvm

    2.  this bytecode can run on any machine , the executable is dependent in platform and architecture

<a id="orgc2c9727"></a>

### then the interpreter(line by line) converts it into machine code

1.  interpreter compiles the file line by line eg python which is a interpreted language can be excuted line by line

<a id="orgaf196a0"></a>

## JDK vs JRE vs JVM vs JIT

<a id="orgcfccf07"></a>

### JDK is java dev kit , it consists of JRE + Dev tools

1.  provides package to run and develop java program

2.  it is a package that includes

    1.  dev tools = to provide an environment to develop your program
    2.  JRE = to execute your program
    3.  javac = a java compiler
    4.  jar = java archiver
    5.  javadoc = doc generator
    6.  interpreter / loader

<a id="org8bab48a"></a>

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

<a id="org1072cc1"></a>

### JVM is java virtual machine it consists of JIT just in time compiler

<a id="org83cdc1a"></a>

## how the all of the above works JDK, JRE, JVM, JIT

<a id="orgc74e0eb"></a>

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
    -those methods/functions

<a id="org0ef9f3e"></a>

### at runtime : class loader -> byte code verifier -> interpreter -> runtime -> hardware
