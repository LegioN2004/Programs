# CodeWithHarry C tutorial

I am continuing with the tutorial no 26, from the pointers concept since that is a bit confusing for me till now, yes you heard that right. And rest of the stuff has been already done so yeah.

# Pointers in C #26

- what is a pointer?
  - A pointer is a variable that stores the address of another variable.
  - It can be of any type, int, char, array, function, etc or any other pointer.
  - Size depends on the architecture of the system.
  - It is defined by using \* operator.

- Pointers in C: `&` and `*` operator
  - Whenever we run a program, it gets loaded in the memory. So when we'll define int, it will take some memory and that memory will be reserved for that variable.
  - Whenever we define a variable, it'll form a container like thing where the value will be stored. And that container will have an address. Let it be a1. So if we want to make another variable and store the address of a1 in it, we can do that too, using pointers.
  - Also note that a pointer will also have its own memory address where it has been created.
  - So as per the following example, we always say taht ptr is pointing to a. i.e the memory address of a.

  ```c
    int a = 7;
    int *ptr = &a;
    printf("The value of a is %d\n", a); // 7
    printf("The memory address of a is %d\n", &a); // 108723409
    printf("The pointer of a is %d\n", *ptr); // 7
  ```

  - `&` is termed as the **address** of operator. It is used to get the address of the variable.
    - `&` just means its location in the memory.
    - When we try to print any variable's address we can use it to print it.
  - `*` is termed as the **dereference** operator(also called **indirection** operator). It is used to get the value of the variable at a given address.
    - when we use a pointer to a variable that contains the address of another variable, then we'll get the value of a.
    - When we try to print the pointer variable without using the pointer symbol, then we'll output a hexadecimal number, using the `%x` specifier.

    ```c
    int a = 7;
    int *ptr = &a;
    printf("The value of a is %d\n", a); // to print a
    printf("The address of a is %x\n", &a); // to print address of a
    printf("The value of ptr is %x\n", ptr); // to print the address of a
    printf("The pointer of ptr is %d\n", *ptr); // to print the value of a
    printf("The address of ptr is %x\n", &ptr); // to print the address of ptr
    ```

    - the above gives the output below. The address values change as per the format specifier.

    ```shell
    The value of a is 7
    The address of a is c1ff83c
    The value of ptr is c1ff83c
    The pointer of ptr is 7
    The address of ptr is c1ff830
    ```

  - We can also use the `%p` which is a format specifier for printing pointer values using printf.
    - Then we can dereference the pointer to get the value.

## NULL pointers

- A pointer that is not assigned any value but NULL (pointing to nothing) is called a NULL pointer.
- In computer programming, a NULL pointer is a pointer that doesn't point to any object or function.
- We can use it to initialize a pointer variable when that pointer variable isn’t assigned any valid memory address yet.
- We need to do this: `int *ptr = NULL;`. Whenever we do this printing it out will give nothing on the stdout.

Uses of pointers

- Dynamic Memory Allocation: When you want to allocate and free memory during the runtime, then it is termed as dynamic memory allocation.
- Arrays, Functions and Structures
- Return multiple values from a function
- Pointer reduces the code and improves the performance

# Arrays and Pointer Arithmetic in C #27

There are four arithmetic operators that can be applied on pointers.

- `++`
- `--`
- `+`
- `-`

Now what happens when we do `ptr++` or `ptr--`? It will increment or decrement the pointer by the size of the data type it is pointing to. Eg: if it is an integer pointer lets say `int a = 4`, then it will increment or decrement by 4 bytes, i.e it outputs the original address as `595590804` and the incremented address as `595590808`. This size is dependent on the architecture of the system.

Also we can't dereference a pointer if it has no value or if we go to a memory location that doesn't exists, then it will give a segmentation fault.

## How arrays and pointers are related

let us consider an array `int arr[10]`.
arr[0] is the first element and the type is int. However arr by itself without any index subscripting can be assigned to an integer pointer. So we can do something like `int* ptr = arr;`, ptr will point to the first element in that array. ptr will store the address of arr. Printing `&arr[0]` or `ptr` will give the same output

Pointer arithmetic: If arr is a pointer to arr[0] then arr[i] will print arr[i] == *(arr + i)
