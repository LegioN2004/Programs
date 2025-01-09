# Chai Aur Code C++ series start

# Video no 1

## Introduction

- Once it is compiled, the program is ready to be executed anywhere. Although you will need binaries and other stuff to compile and run the cpp code. Good for high end applications. So **platform independent**.
- **Object Oriented Programming Language**. Everything is openly available and there is not many abstractions so we'll learn a lot of stuff using C++.
- **Statically typed language**. You need to define the type of the variable before using it. It is a good thing because it helps in catching errors at compile time.
- **Speed**. C++ is faster than most of the languages because it is a compiled language.

eg: Say you have made a lib of ML or some App dev library and so the API's of those are designed in C++. These are designed in cpp but since they are hard, you'll find abstractions in python or other languages. So, you can use those libraries in python or other languages. So, C++ is used in the backend of many libraries. But to tweak the library for certain optimizations, you need to know C++. You will also know how drivers are installed or written. Its interesting and fun to learn C++, and you will know how things work under the hood.

# Video no 2

## Parts of the code

- **Preprocessor Directives**: These are the lines that start with a hash (#). These are the instructions to the compiler. eg: #include<iostream> tells the compiler to include the iostream library. It consists of all sorts of input output operations.
- **using namespace std**: This is used to avoid writing std::cout and std::cin everytime. It is used to avoid writing std:: before cout and cin. Since the cout and cin can be written in another places as well so to avoid ambiguity, we use this. The devs also found this annoying so they introduced this. They introduced this **standard** "region" where the work we'll be doing in this region will be of the standard namespace. So these things don't affect each other when having cout from different places other than the std namespace. So as to keep stuff containerized. Eg: eigen, QT. We mostly use readymade libraries and we don't want to mess with the standard namespace.
  - It's just the way of writing code and opitmizing code
    - Sometimes calling the whole namespace can cause issues, good practice is to call the whole namespace and let cpp do the optimizations but in some cases we may need to do so, then we can do something like `std::cout;` and `std::endl;` to avoid calling the whole namespace(in cases of using the std namespace for calling the cout and endl). We can nitpick the things we want to use from the namespace.
    - or we can do `using std::cout;` and `using std::endl;` to avoid calling the whole namespace, before the main function.
  - We can also use our own namespace, like we do when we don't use the namespace std, like `std::cout..(rest of the stuff)`. We can also use our own namespace like `myNamespace::cout..(rest of the stuff)`. So, we can use our own namespace as well.

    ```cpp
    namespace myNamespace {
        int a = 10;
    }

    int main() {
        cout << myNamespace::a << endl;
    }
    ```

- **return 0**: This is used to return the exit status of the program. 0 means the program executed successfully, commonly known as exit codes. If there is an error, it will return a non-zero value. It is a good practice to return 0 at the end of the program.
- The **`<<`** is the insertion operator. It is used to insert the data into the output stream. The **`>>`** is the extraction operator. It is used to extract the data from the input stream.

# Video no 3

notes about the how the code is being compiled: When the code is being compiled, the compiler will convert the code into tokens. The tokens are the smallest unit of the code. The compiler will then convert the tokens into the AST(Abstract Syntax Tree). The AST is then converted into the machine code. The machine code is then executed by the machine. The machine code is the binary code that the machine can understand

- comments when not required don't write it. Make it meaningful when done.
- variable declaration: `int a;` is a variable declaration.
- variable initialization: `a = 10;` is a variable initialization
- variables should have meaningful names as well.
- normal variables can be updated, but the constant variables can't be updated. So, use `const` keyword to make the variable constant.

# Video no 4

## Data Types

**Primitive Data Types**: The basic unit that are stored in the memory.
    - **int**: It is used to store integer values. It is of 4 bytes.
    - **float**: It is used to store floating point values. It is of 4 bytes. For less precision.
    - **double**: It is used to store floating point values. It is of 8 bytes. For more precision
    - **char**: It is used to store characters. It is of 1 byte.
    - **bool**: It is used to store boolean values. It is of 1 byte.
    - **void**: It is used to represent the absence of type. It is of 1 byte. It's meaning is consistent in the C++ language. It is just empty.
    - **short**: It is used to store integer values. It is of 2 bytes.
    - **long**: It is used to store integer values. It is of 4 bytes.
    - **long long**: It is used to store integer values. It is of 8 bytes.

**Derived Data Types**: These are the data types that are derived from the primitive data types but a little enhanced version of the primitive data types.
    - **Array**: It is used to store multiple values of the same data type. It is of 4 bytes.
    - **Function**: It is used to store the block of code. It is of 4 bytes.
    - **Pointer**: It is used to store the address of the variable. It is of 4 bytes.
    - **Reference**: It is used to store the reference of the variable. It is of 4 bytes.
    - **Class**: It is used to define the user-defined data type. It is of 4 bytes.

user-defined data types: These are the data types that are defined by the user.
    - **Structure**: It is used to store multiple values of different data types. It is of 4 bytes.
    - **Union**: It is used to store multiple values of different data types. It is of 4 bytes.
    - **Enumeration**: It is used to define the user-defined data type. It is of 4 bytes.

used some data types and assigned some values.
    - using the incorrect value for a certain data type may give garbage values or errors often.

```cpp
int main() {
    int a = 10;
    float b = 10.5;
    double c = 29.99898989; // gives 30
    char d = 'A';
    unsigned int e = 10; // gives 10, must be always positive or gives garbage value on negative values
    // char d = 'AB'; // gives B
    // char d = 'ABC'; // gives C
    bool e = true;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;

    return 0;
}
```
