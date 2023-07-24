# Introduction to Programming

- To instruct a computer do tasks we use certain languages known as **Programming languages** and at the very base of those languages they are a bunch of 0s and 1s. We know that a computer only understands and reads data in 0s and 1s and since writing instructions in 0s and 1s will be impossible so we use Programming languages to write this instructions which are more human readable and understandable and the computer just translates it to 0s and 1s.

## Types Of Languages

- Procedural languages:
  - It specifies a series of well structured steps and procedures to compose a program.
  - It contains a systematic order of statements, functions and commands to complete a task.
  
- Fuctional languages:
  - Writing a program only in pure functions i.e never modify variables, but only create new ones as an output.
  - Used in situations where we have to perform lots of different operations on the same set of data, like ML
  - First class functions: Explaining with an example
    taking values with some variables a = 10, b = 30, c = b; // if we print the value of c we'll get the value as 30, since the value 30 of b is being reassigned to c and so c also gets the same value.
    So if we can do the same with functions like reassigning function variable names to other function, then these functions are known as first class functions. python is one example which has first class functions.

- Object oriented languages:
  - It revolves around objects
  - Code + Data = **Object**. The code and the data combined together forms the object
  - **Classes**: A class is like a template. It is a named group of properties and functions. When we need to store a no of different datatypes like that of a student (its name, roll no, DOB, etc) we need one single datatype to store all the different ones and it can be done using classes and **an instance of this class is called an object**. Eg: humans features like 2 eyes, ears, hands, legs, etc are like a template and using this template we are made and we are objects. like a = 30 , a is teh variable and 30 is the object inside the memory.
  - OOP in a nutshell, in case of programming languages, divides the code to different chunks so that it helps us developers make the different processes like develop, debug, reuse, and maintaining software easier. Like car parts repairing where we do not change the whole car to repair or replace that one specific part but we only change that part, OOP also helps in changing only that part in a codebase which has a problem and not the whole codebase and that makes the life of a dev easier.

## Static and Dynamic memory

|                  Static                       |                        Dynamic                          |
|-----------------------------------------------|---------------------------------------------------------|
|1. Perform type checking at compile time       |1. Perform type checking at runtime                      |
|2. Errors will show at compile time            |2. Error might not show till program is run              |
|3. Declare datatype before using it            |3. No need to declare datatype of variables              |
|4. More control                                |4. Saves time in writing code but might give error at    |
|                                               | runtime                                                 |
|                                               |                                                         |

## stack and heap memory

- Explaining stack and heap memory with an example. for example: a = 10.
  - a is a reference variable and it is stored in stack memory of the above example.
  - heap memory of the memory/ram is where the actual value of the object 10, is stored of the above example. a is in the stack memory and it is pointing towards the heap memory.
  - And a is only pointing to the address of the object, 10 in heap memory of the memory(in computer) but 10 is the actual value. Things to **note** here :-
    1. Every object has an address in the memory/ram
    2. more than 1 reference variables can point to the same object
    3. if original object is changed by a reference variable then it will be reflected to all the other variables
  - when an object with no reference variable is found then it is removed from the memory using ***garbage collection*** (it happens automatically) all the objects
