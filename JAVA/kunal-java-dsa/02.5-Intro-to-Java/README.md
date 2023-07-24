# Introduction to JAVA

- how java code executes
  - .java  file has the source code which is in the human readable  format
  - it gets into the compiler and converts the entire file to .class format
  - .class (which is a BYTE CODE) is a file which is a java intermediary language / something else in the java stuff. Things to **note** here :-
    1. It doesn't run in directly on a system
    2. It needs a jvm(Java virtual machine) to run
    3. Since this byte code can run in any system as long as there is a jvm , that makes it the reason why Java is platform independent.
       - note jvm is platform dependent we need to execute the .class file again in different platform using the platform dependent jvm
       - this bytecode can run on any machine, but the executable that is made is dependent in platform and architecture
  - Then the interpreter(line by line) converts it into machine code
    - interpreter compiles the file line by line, eg: like python which is a interpreted language can be excuted line by line

## JDK vs JRE vs JVM vs JIT

- JDK is java dev kit , it consists of JRE + Dev tools
  1. provides package to run and develop java program
  2. it is a package that includes
     - dev tools = to provide an environment to develop your program
     - JRE = to execute your program
     - javac = a java compiler
     - jar = java archiver
     - javadoc = doc generator
     - interpreter / loader

- JRE is a java runtime environment, it consists of JVM + library classes
  - It is an installation package that provides environment to only run the program. It consists of :-
    1. Deployment technology
    2. User interface toolkit
    3. Integration libraries
    4. Base libraries
    5. JVM :- Java virtual Machine

  - After we get the .class file the next thing happen at runtime :
    - Class loader loads all classes needed to execute the program.
    - JVM sends code to bytecode verifier to check the format of code.

- JVM is java virtual machine it consists of JIT, the just in time compiler

- **how the all of the above works JDK, JRE, JVM, JIT**
  - at compile time [.java file] -----> (javac compilation)-----> [.class file]
- how jvm works
  1. ***loading***: reads .class file and generates binary data of , then object of the class is created in heap
  2. ***linking***: i. verifies the .class file | ii. allocates memory for the class variables and default values | iii. replaces symbolic references from the type with direct references (by replacing the variables and other stuff with the values directly)
  3. ***initialization***: all static variables are assigned with their values defined in the code and static block. static variables are those variables which do not depend on the object of the classes i.e object independent
                      jvm contains the stack and heap memory allocations , stack memory is created whenever a new program is run

- JVM execution
  - Interpreter:
    - line by line execution (of the bytecode i.e the .class file)
    - when one method/function(block of code) is called many times it will interpret again and again (which is a limitation)

- JIT
  - those methods/functions that are repeated again and again , the jit directly provides the machine code once converted from the main code so that re-interpretation is not required and the code execution becomes a bit faster
    - at runtime : class loader -> byte code verifier -> interpreter -> runtime -> hardware
  - how everything points to work like that
    - java source code -> JDK (has the javac compiler converts it into .class file) -> Bytecode -> JVM(converts the bytecode to an executable) -> JRE(then we run that executable in this)
